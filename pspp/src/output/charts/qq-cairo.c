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

#include "output/charts/scatterplot.h"
#include "output/charts/qq.h"

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

void
xrchart_draw_qq (const struct chart_item *chart_item, cairo_t *cr,
			  struct xrchart_geometry *geom)
{
  struct qq_chart *qqc = to_qq_chart (chart_item);

  if (qqc->draw_detrended)
    xrchart_draw_qq_detrended(qqc, cr, geom);
  else xrchart_draw_qq_(qqc, cr, geom);

  qqc->draw_detrended = !qqc->draw_detrended;
}

void xrchart_draw_qq_ (const struct qq_chart *qqc, cairo_t *cr,
			  struct xrchart_geometry *geom)
{
  struct casereader *data;
  struct ccase *c;
  int i = 0;
  const struct xrchart_colour *colour;

  xrchart_write_xscale (cr, geom, qqc->x_min, qqc->x_max);
  xrchart_write_yscale (cr, geom, qqc->y_min, qqc->y_max);
  xrchart_write_title (cr, geom, _("QQ plot %s"), qqc->chart_item.title);
  xrchart_write_xlabel (cr, geom, qqc->xlabel);
  xrchart_write_ylabel (cr, geom, qqc->ylabel);

  data = casereader_clone (qqc->data);
  for (; (c = casereader_read (data)) != NULL; case_unref (c))
    {
      colour = &black;

      cairo_set_source_rgb (cr,
                            colour->red / 255.0,
                            colour->green / 255.0,
                            colour->blue / 255.0);
    
      xrchart_datum (cr, geom, 0,
		     case_data_idx (c, SP_IDX_X)->f,
		     qqc->distribution_percentiles[i++]);
    }

  draw_distribuiton_line(qqc, cr, geom);

  cairo_save (cr);

  casereader_destroy (data);
  cairo_restore (cr);
}

void
xrchart_draw_qq_detrended (const struct qq_chart *qqc, cairo_t *cr,
			  struct xrchart_geometry *geom)
{
  struct casereader *data;
  struct ccase *c;
  int i = 0;
  const struct xrchart_colour *colour;

  xrchart_write_xscale (cr, geom, qqc->x_min, qqc->x_max);
  xrchart_write_yscale (cr, geom, qqc->deviation[0], qqc->deviation[qqc->value_num-1]);
  xrchart_write_title (cr, geom, _("Detrended QQ plot %s"), qqc->chart_item.title);
  xrchart_write_xlabel (cr, geom, qqc->xlabel_detrended);
  xrchart_write_ylabel (cr, geom, qqc->ylabel_detrended);

  data = casereader_clone (qqc->data);
  for (; (c = casereader_read (data)) != NULL; case_unref (c))
    {
      colour = &black;

      cairo_set_source_rgb (cr,
                            colour->red / 255.0,
                            colour->green / 255.0,
                            colour->blue / 255.0);
    
      xrchart_datum (cr, geom, 0,
		     case_data_idx (c, SP_IDX_X)->f,
		     qqc->deviation[i++]);
    }

  draw_deviation_line(qqc, cr, geom);

  cairo_save (cr);

  casereader_destroy (data);
  cairo_restore (cr);
}

void draw_deviation_line (struct qq_chart *qqc, cairo_t *cr, struct xrchart_geometry *geom)
{
  if (qqc->distribution == NORMAL)
	draw_normal_deviation_line(qqc, cr, geom);
  else xrchart_label(cr, 'l', 'b', geom->font_size, "Not supported distribution type.");
}

void draw_normal_deviation_line (struct qq_chart *qqc, cairo_t *cr, struct xrchart_geometry *geom)
{
  //xrchart_line (cr, geom, 90, qqc->distribution_params[NORMAL_MEAN], qqc->x_min, qqc->x_max, XRCHART_DIM_X);

  cairo_move_to (cr, qqc->x_min, qqc->distribution_params[NORMAL_MEAN]);
  cairo_line_to (cr, qqc->x_max, qqc->distribution_params[NORMAL_MEAN]);
  cairo_stroke (cr);
}

void draw_distribuiton_line(struct qq_chart *qqc, cairo_t *cr, struct xrchart_geometry *geom)
{
  if (qqc->distribution == NORMAL)
	draw_normal_distribution_line(qqc, cr, geom);
  else xrchart_label(cr, 'l', 'b', geom->font_size, "Not supported distribution type.");
}

void change_geom_axis(struct xrchart_geometry *geom, enum tick_orientation orientation, double min, double max)
{
  double lower, interval;
  int ticks;
  chart_get_scale (max, min, &lower, &interval, &ticks);
  double upper = lower+interval*(ticks+1);

  geom->axis[orientation].min = lower;
  geom->axis[orientation].max = upper;
  geom->axis[orientation].scale = (fabs (geom->axis[orientation].data_max - geom->axis[orientation].data_min)
			      / fabs (geom->axis[orientation].max - geom->axis[orientation].min));
}

void draw_normal_distribution_line(struct qq_chart *qqc, cairo_t *cr, struct xrchart_geometry *geom)
{
  double mean = qqc->distribution_params[NORMAL_MEAN];
  double var = qqc->distribution_params[NORMAL_VAR];
  double stddev = sqrt(var);

  double oldGeomMin = geom->axis[XRCHART_DIM_Y].min;
  double oldGeomMax = geom->axis[XRCHART_DIM_Y].max;

  change_geom_axis(geom, XRCHART_DIM_Y, qqc->x_min, qqc->x_max);
//  double y_len = qqc->y_max - qqc->y_min;
//  double scale_ratio = (geom->axis[XRCHART_DIM_Y].max - geom->axis[XRCHART_DIM_Y].min)/y_len;

  double slope = 1.0 / (stddev);
  double intercept = (-mean / stddev);

g_print("\nslope: %f\n", slope);
  //xrchart_write_yscale (cr, geom, qqc->x_min, qqc->x_max);
  xrchart_line (cr, geom, slope, intercept, qqc->x_min, qqc->x_max, XRCHART_DIM_X);
  //xrchart_write_yscale (cr, geom, qqc->y_min, qqc->y_max);
  change_geom_axis(geom, XRCHART_DIM_Y, qqc->y_min, qqc->y_max);

}

