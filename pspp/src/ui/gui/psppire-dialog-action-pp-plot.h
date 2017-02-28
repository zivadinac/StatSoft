/* PSPPIRE - a graphical user interface for PSPP.
   Copyright (C) 2015  Free Software Foundation

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


#include <glib-object.h>
#include <glib.h>

#include "psppire-dialog-action.h"

#ifndef __PSPPIRE_DIALOG_ACTION_PP_PLOT_H__
#define __PSPPIRE_DIALOG_ACTION_PP_PLOT_H__

G_BEGIN_DECLS


#define PSPPIRE_TYPE_DIALOG_ACTION_PP_PLOT (psppire_dialog_action_pp_plot_get_type ())

#define PSPPIRE_DIALOG_ACTION_PP_PLOT(obj)	\
                     (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
						  PSPPIRE_TYPE_DIALOG_ACTION_PP_PLOT, PsppireDialogActionPPPlot))

#define PSPPIRE_DIALOG_ACTION_PP_PLOT_CLASS(klass) \
                     (G_TYPE_CHECK_CLASS_CAST ((klass), \
				 PSPPIRE_TYPE_DIALOG_ACTION_PP_PLOT, \
                                 PsppireDialogActionPPPlotClass))


#define PSPPIRE_IS_DIALOG_ACTION_PP_PLOT(obj) \
	             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PSPPIRE_TYPE_DIALOG_ACTION_PP_PLOT))

#define PSPPIRE_IS_DIALOG_ACTION_PP_PLOT_CLASS(klass) \
                     (G_TYPE_CHECK_CLASS_TYPE ((klass), PSPPIRE_TYPE_DIALOG_ACTION_PP_PLOT))


#define PSPPIRE_DIALOG_ACTION_PP_PLOT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
				   PSPPIRE_TYPE_DIALOG_ACTION_PP_PLOT, \
				   PsppireDialogActionPPPlotClass))

typedef struct _PsppireDialogActionPPPlot       PsppireDialogActionPPPlot;
typedef struct _PsppireDialogActionPPPlotClass  PsppireDialogActionPPPlotClass;


struct _PsppireDialogActionPPPlot
{
  PsppireDialogAction parent;

  GList *treeview_vals;
  GtkWidget *selected_variables_treeview;
  
  /* Signal handler ids */
  gint change_handler_id;
  gint value_handler_id;
  
  /*< Check Boxes >*/
  GtkWidget *estimate_from_data_checkbox;
 
  /* Entry Box */
  GtkWidget *parameter1_entry;
  GtkWidget *parameter2_entry;
  
  /* Combobox */
  GtkWidget *distribution_combobox;
   
  
  /* Workaround za combobox */
   int not_first_run;
  
 	
};


struct _PsppireDialogActionPPPlotClass
{
  PsppireDialogActionClass parent_class;
};


GType psppire_dialog_action_pp_plot_get_type (void) ;

G_END_DECLS

#endif /* __PSPPIRE_DIALOG_ACTION_PP_PLOT_H__ */
