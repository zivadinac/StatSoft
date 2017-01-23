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

#ifndef __PSPPIRE_DIALOG_ACTION_PERCENTILES_H__
#define __PSPPIRE_DIALOG_ACTION_PERCENTILES_H__

G_BEGIN_DECLS


#define PSPPIRE_TYPE_DIALOG_ACTION_PERCENTILES (psppire_dialog_action_percentiles_get_type ())

#define PSPPIRE_DIALOG_ACTION_PERCENTILES(obj)	\
                     (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
						  PSPPIRE_TYPE_DIALOG_ACTION_PERCENTILES, PsppireDialogActionPercentiles))

#define PSPPIRE_DIALOG_ACTION_PERCENTILES_CLASS(klass) \
                     (G_TYPE_CHECK_CLASS_CAST ((klass), \
				 PSPPIRE_TYPE_DIALOG_ACTION_PERCENTILES, \
                                 PsppireDialogActionPercentilesClass))


#define PSPPIRE_IS_DIALOG_ACTION_PERCENTILES(obj) \
	             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PSPPIRE_TYPE_DIALOG_ACTION_PERCENTILES))

#define PSPPIRE_IS_DIALOG_ACTION_PERCENTILES_CLASS(klass) \
                     (G_TYPE_CHECK_CLASS_TYPE ((klass), PSPPIRE_TYPE_DIALOG_ACTION_PERCENTILES))


#define PSPPIRE_DIALOG_ACTION_PERCENTILES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
				   PSPPIRE_TYPE_DIALOG_ACTION_PERCENTILES, \
				   PsppireDialogActionPercentilesClass))

typedef struct _PsppireDialogActionPercentiles       PsppireDialogActionPercentiles;
typedef struct _PsppireDialogActionPercentilesClass  PsppireDialogActionPercentilesClass;


struct _PsppireDialogActionPercentiles
{
  PsppireDialogAction parent;

  GList *treeview_vals;
  
  /* Signal handler ids */
  //gint change_handler_id;
  gint value_handler_id;
  
  gchar *encoding;
  
  /*< Check Boxes >*/
  GtkWidget *quantiles_checkbox;
  GtkWidget *quintiles_checkbox;
  GtkWidget *sextiles_checkbox;
  GtkWidget *deciles_checkbox;
  GtkWidget *percentiles_checkbox;
  
  /* Entry Box */
  GtkWidget *percentiles_entry;
  
  /* Actions */
  GtkWidget *percentiles_add;
  GtkWidget *percentiles_change;
  GtkWidget *percentiles_remove;
  GtkWidget *percentiles_ok;
  GtkWidget *percentiles_cancel;
  GtkWidget *percentiles_discard;
  
  GtkWidget *percentiles_treeview;
	
};


struct _PsppireDialogActionPercentilesClass
{
  PsppireDialogActionClass parent_class;
};


GType psppire_dialog_action_percentiles_get_type (void) ;

G_END_DECLS

#endif /* __PSPPIRE_DIALOG_ACTION_PERCENTILES_H__ */
