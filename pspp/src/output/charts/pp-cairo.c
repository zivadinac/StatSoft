/* PSPP - a program for statistical analysis.
   Copyright (C) 2014, 2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include <config.h>

#include "output/charts/pp.h"

#include "math/np.h"

#include "data/case.h"
#include "data/casereader.h"
#include "data/variable.h"
#include "output/cairo-chart.h"
#include "libpspp/str.h"
#include "libpspp/message.h"

#include "gettext.h"
#define _(msgid) gettext (msgid)

static const struct xrchart_colour black = {0,0,0};

enum
{
  NORMAL
};

#define NORMAL_PARAMS_NUM 2
#define NORMAL_MEAN 0
#define NORMAL_VAR 1

void
xrchart_draw_pp (const struct chart_item *chart_item, cairo_t *cr,
			  struct xrchart_geometry *geom)
{
  struct pp_chart *ppc = to_pp_chart (chart_item);

  /* if (ppc->draw_detrended)
    xrchart_draw_pp_detrended(ppc, cr, geom);
  else */
    xrchart_draw_pp_(ppc, cr, geom);

  ppc->draw_detrended = !ppc->draw_detrended;
}

void xrchart_draw_pp_ ( struct pp_chart *ppc, cairo_t *cr,
			  struct xrchart_geometry *geom)
{
  struct casereader *data;
  struct ccase *c;
  int i = 0;
  const struct xrchart_colour *colour;

  xrchart_write_xscale (cr, geom, ppc->x_min, ppc->x_max);
  xrchart_write_yscale (cr, geom, ppc->y_min, ppc->y_max);
  xrchart_write_title (cr, geom, _("PP plot %s"), ppc->chart_item.title);
  xrchart_write_xlabel (cr, geom, ppc->xlabel);
  xrchart_write_ylabel (cr, geom, ppc->ylabel);

  data = casereader_clone (ppc->data);
  for (i = 0; i < ppc->value_num; ++i)
    {
      colour = &black;

      cairo_set_source_rgb (cr,
                            colour->red / 255.0,
                            colour->green / 255.0,
                            colour->blue / 255.0);
    
      xrchart_datum (cr, geom, 0,
		     ppc->distribution_percentages[i],
		     ppc->cfd_values[i]);
    }

  draw_distribuiton_line_pp(ppc, cr, geom);

  cairo_save (cr);

  casereader_destroy (data);
  cairo_restore (cr);
  
}

double findMaxPP(const double *array, int n)
{
  double max = array[0];

  for (int i=0; i<n; ++i)
    max = (array[i] > max) ? array[i] : max;

  return max;
}

double findMinPP(const double *array, int n)
{
  double min = array[0];

  for (int i=0; i<n; ++i)
    min = (array[i] < min) ? array[i] : min;

  return min;
}

void
xrchart_draw_pp_detrended (const struct pp_chart *ppc, cairo_t *cr,
			  struct xrchart_geometry *geom)
{
  struct casereader *data;
  struct ccase *c;
  int i = 0;
  const struct xrchart_colour *colour;

  xrchart_write_xscale (cr, geom, ppc->x_min, ppc->x_max);
  double y_min = findMinPP(ppc->deviation, ppc->value_num);
  double y_max = findMaxPP(ppc->deviation, ppc->value_num);
  xrchart_write_yscale (cr, geom, y_min, y_max);
  xrchart_write_title (cr, geom, _("Detrended PP plot %s"), ppc->chart_item.title);
  xrchart_write_xlabel (cr, geom, ppc->xlabel_detrended);
  xrchart_write_ylabel (cr, geom, ppc->ylabel_detrended);

  data = casereader_clone (ppc->data);
  for (i = 0; i < ppc->value_num; ++i)
    {
      colour = &black;

      cairo_set_source_rgb (cr,
                            colour->red / 255.0,
                            colour->green / 255.0,
                            colour->blue / 255.0);
    
      xrchart_datum (cr, geom, 0,
		     ppc->distribution_percentages[i],
		     ppc->deviation[i]
		     );
    }

  draw_deviation_line_pp(ppc, cr, geom);

  cairo_save (cr);

  casereader_destroy (data);
  cairo_restore (cr);
}

void draw_deviation_line_pp (struct pp_chart *ppc, cairo_t *cr, struct xrchart_geometry *geom)
{
  if (ppc->distribution == NORMAL)
	draw_normal_deviation_line_pp(ppc, cr, geom);
  else xrchart_label(cr, 'l', 'b', geom->font_size, "Not supported distribution type.");
}

void draw_normal_deviation_line_pp (struct pp_chart *ppc, cairo_t *cr, struct xrchart_geometry *geom)
{
  xrchart_line (cr, geom, 0, 0, ppc->x_min, ppc->x_max, XRCHART_DIM_X);
}

void draw_distribuiton_line_pp(struct pp_chart *ppc, cairo_t *cr, struct xrchart_geometry *geom)
{
  if (ppc->distribution == NORMAL)
	draw_normal_distribution_line_pp(ppc, cr, geom);
  else xrchart_label(cr, 'l', 'b', geom->font_size, "Not supported distribution type.");
}

void draw_normal_distribution_line_pp(struct pp_chart *ppc, cairo_t *cr, struct xrchart_geometry *geom)
{
  double mean = ppc->distribution_params[NORMAL_MEAN];
  double var = ppc->distribution_params[NORMAL_VAR];
  double stddev = sqrt(var);

  double oldGeomMin = geom->axis[XRCHART_DIM_Y].min;
  double oldGeomMax = geom->axis[XRCHART_DIM_Y].max;

  double slope = 1.0 / (stddev);
  double intercept = (-mean / stddev);

  xrchart_line (cr, geom, slope, intercept, ppc->x_min, ppc->x_max, XRCHART_DIM_X);
}

