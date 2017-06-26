/* PSPP - a program for statistical analysis.
   Copyright (C) 2015 Free Software Foundation, Inc.

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

#include "output/charts/qq.h"
#include "output/charts/piechart.h"

#include <stdlib.h>

#include "libpspp/cast.h"
#include "libpspp/str.h"
#include "libpspp/array.h"
#include "libpspp/assertion.h"

#include "data/variable.h"
#include "data/case.h"
#include "data/casereader.h"
#include "language/stats/freq.h"

#include "output/chart-item-provider.h"

#include "gl/xalloc.h"
#include <gsl/gsl_cdf.h>


struct qq_chart *
qq_chart_create (struct casereader *reader,
	   const char *xlabel, const char *xlabel_detrended,
	   const char *ylabel, const char *ylabel_detrended,
	   const struct variable *byvar,
	   const char *label,
	   const int distribution,
	   const double *distribution_params,
	   const int value_num,
	   double xmin, double xmax, double ymin, double ymax)
{
  struct qq_chart *qqc;

  qqc = xzalloc (sizeof *qqc);
  chart_item_init (&qqc->chart_item, &qq_chart_class, label);
  qqc->data = reader;

  qqc->y_min = ymin;
  qqc->y_max = ymax;

  qqc->x_min = xmin;
  qqc->x_max = xmax;
  
  qqc->value_num = value_num;

  qqc->distribution = distribution;
  qqc->distribution_params = distribution_params;
  qqc->distribution_percentiles = xzalloc (sizeof(double) * value_num);
  calculate_distribution_percentiles (qqc);
  qqc->deviation = xzalloc (sizeof(double) * value_num);
  calculate_deviation_qq(qqc);

  qqc->draw_detrended = false;

  qqc->xlabel = xstrdup (xlabel);
  qqc->xlabel_detrended = xstrdup (xlabel_detrended);
  qqc->ylabel = xstrdup (ylabel);
  qqc->ylabel_detrended = xstrdup (ylabel_detrended);
  qqc->byvar = byvar != NULL ? var_clone (byvar) : NULL;

  return qqc;
}

static void
qq_chart_destroy (struct chart_item *chart_item)
{
  struct qq_chart *spc = to_qq_chart (chart_item);
  casereader_destroy (spc->data);
  free (spc->xlabel);
  free (spc->xlabel_detrended);
  free (spc->ylabel);
  free (spc->ylabel_detrended);
  if (spc->byvar)
    var_destroy (spc->byvar);
  free (spc);
}

const struct chart_item_class qq_chart_class =
  {
    qq_chart_destroy
  };

void calculate_distribution_percentiles (struct qq_chart *qqc)
{
	switch (qqc->distribution)
	{
		case NORMAL:
			calculate_normal_percentiles(qqc->distribution_percentiles, qqc->value_num, qqc->distribution_params[NORMAL_MEAN], qqc->distribution_params[NORMAL_VAR]);
			break;
		default:
			NOT_REACHED();
			break;
	}
}

void calculate_normal_percentiles(double* distribution_percentiles, const int value_num, const double mean, const double variance)
{
	for (int i = 1; i <= value_num; i++)
		distribution_percentiles[i-1] = mean + gsl_cdf_gaussian_Pinv((i-0.5)/value_num, variance);
}

void calculate_deviation_qq(struct qq_chart *qqc)
{
  struct casereader *data = casereader_clone (qqc->data);
  struct ccase *c;
  int i = 0;

  for (; (c = casereader_read (data)) != NULL; case_unref (c))
    {
      qqc->deviation[i] =  qqc->distribution_percentiles[i++] - case_data_idx (c, 0)->f;
    }
  casereader_destroy (data);  
}
