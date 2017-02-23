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

#include "output/charts/percentiles.h"
#include "output/charts/piechart.h"

#include <stdlib.h>

#include "libpspp/cast.h"
#include "libpspp/str.h"
#include "libpspp/array.h"
#include "output/chart-item-provider.h"

#include "gl/xalloc.h"
#include "data/variable.h"
#include "language/stats/freq.h"


static int
compare_category_3way (const void *a_, const void *b_, const void *bc_)
{
	return 0; //just for compilation
}


static unsigned int
hash_freq_2level_ptr (const void *a_, const void *bc_)
{
	return 0; //just for compilation
}


static int
compare_freq_2level_ptr_3way (const void *a_, const void *b_, const void *bc_)
{
	return 0; //just for compilation
}



/* Creates and returns a chart that will render a percentiles with
   the given TITLE and the N_CATS described in CATS. 

   VAR is an array containing the categorical variables, and N_VAR 
   the number of them. N_VAR must be exactly 1 or 2.

   CATS are the counts of the values of those variables. N_CATS is the
   number of distinct values.
*/
struct percentiles *
percentiles_create (const struct variable **var, int n_vars,
		 const char *ylabel, bool percent, 
		 struct freq *const *cats, int n_cats)
{
  struct percentiles *bar;
  chart_item_init (&bar->chart_item, &percentiles_class, var_to_string (var[0]));
  return bar;
}

static void
destroy_cat_map (struct hmap *m)
{
  //deleted code just for compilation
  hmap_destroy (m);
}

static void
percentiles_destroy (struct chart_item *chart_item)
{
  struct percentiles *bar = to_percentiles (chart_item);
  free (bar);
}

const struct chart_item_class percentiles_class =
  {
    percentiles_destroy
  };
