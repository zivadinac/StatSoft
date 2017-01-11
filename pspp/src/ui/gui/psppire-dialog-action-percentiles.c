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


#include <config.h>

#include "psppire-dialog-action-percentiles.h"
#include "psppire-value-entry.h"

#include "dialog-common.h"
#include <ui/syntax-gen.h>
#include "psppire-var-view.h"

#include "psppire-dialog.h"
#include "builder-wrapper.h"

#include "psppire-dict.h"
#include "libpspp/str.h"

#include "language/stats/chart-category.h"

static void
psppire_dialog_action_percentiles_class_init (PsppireDialogActionPercentilesClass *class);

G_DEFINE_TYPE (PsppireDialogActionPercentiles, psppire_dialog_action_percentiles, PSPPIRE_TYPE_DIALOG_ACTION);

static gboolean
dialog_state_valid (gpointer rd_)
{
  PsppireDialogActionPercentiles *rd = PSPPIRE_DIALOG_ACTION_PERCENTILES (rd_);

  if (0 == g_strcmp0 ("", gtk_entry_get_text (GTK_ENTRY (rd->percentiles_entry))))
  {
	return FALSE;
  }

  return TRUE;
}

static void
refresh (PsppireDialogAction *rd_)
{
  PsppireDialogActionPercentiles *rd = PSPPIRE_DIALOG_ACTION_PERCENTILES (rd_);

  gtk_entry_set_text (GTK_ENTRY (rd->percentiles_entry), "");

  /* Set summary_func to true, then let it get unset again.
     This ensures that the signal handler gets called.   */
  //gtk_toggle_button_set_active (GTK_BUTTON (rd->percentiles_add), TRUE);
  //gtk_toggle_button_set_active (GTK_BUTTON (rd->percentiles_cancel), TRUE);
  //gtk_toggle_button_set_active (GTK_BUTTON (rd->percentiles_change), TRUE);
  //gtk_toggle_button_set_active (GTK_BUTTON (rd->percentiles_remove), TRUE);
  //gtk_toggle_button_set_active (GTK_BUTTON (rd->percentiles_ok), TRUE);
  
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->percentiles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->deciles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->sextiles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->quantiles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->quintiles_checkbox), TRUE);

}

static void
percentiles_add_onclick (GtkButton* add, PsppireDialogActionPercentiles *act)
{
	g_print("add_onclick1");
	if(!gtk_toggle_button_get_active(GTK_CHECK_BUTTON(act->percentiles_checkbox)))
	{
		return;	
	}

	g_print("add_onclick2");
	gchar* percVal = gtk_entry_get_text(GTK_ENTRY(act->percentiles_entry));
	
	if(1 == g_strcmp0("", percVal))
	{
		return;
	}

	g_print("add_onclick3");
  	//PsppireDialogAction *pda = PSPPIRE_DIALOG_ACTION(act);

  	GtkTreeIter iter;
  	GtkListStore *list_store = gtk_list_store_new(1, G_TYPE_STRING);

//	GtkTreeModel* model = gtk_tree_view_get_model(GTK_TREE_VIEW(pda->source));

	/*GtkTreePath* path = gtk_tree_path_new();
	gtk_tree_model_get_iter(model, &iter, path);*/
	
	g_print("add_onclick4");
      	gtk_list_store_append(list_store, &iter);
      	gtk_list_store_set(list_store, &iter, 0, "21", -1);

	g_print("add_onclick5");
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_LIST_STORE(list_store));
	
	g_print("add_onclick6");
  	g_object_unref(list_store);
    //g_free(percVal);

	g_print("add_onclick7");
}

static void
psppire_dialog_action_percentiles_activate (PsppireDialogAction *a)
{
  PsppireDialogActionPercentiles *act = PSPPIRE_DIALOG_ACTION_PERCENTILES (a);
  PsppireDialogAction *pda = PSPPIRE_DIALOG_ACTION (a);

  GHashTable *thing = psppire_dialog_action_get_hash_table (pda);
  GtkBuilder *xml = g_hash_table_lookup (thing, a);
  if (!xml)
    {
      xml = gtk_builder_new_from_file("percentiles.ui");
      g_hash_table_insert (thing, a, xml);

      pda->dialog = get_widget_assert (xml, "percentiles-dialog");

      act->percentiles_treeview = get_widget_assert (xml, "percentiles-treeview");

      act->quantiles_checkbox = get_widget_assert (xml, "quartiles-checkbox");
      act->quintiles_checkbox=get_widget_assert(xml,"quintiles-checkbox");
      act->sextiles_checkbox=get_widget_assert(xml,"sextiles-checkbox");
      act->deciles_checkbox=get_widget_assert(xml,"deciles-checkbox");
      act->percentiles_checkbox=get_widget_assert(xml,"percentiles-checkbox");
       
      act->percentiles_entry=get_widget_assert(xml,"percentiles-entry");
     
      act->percentiles_add=get_widget_assert(xml,"percentiles-add");
      act->percentiles_change=get_widget_assert(xml,"percentiles-change");
      act->percentiles_remove=get_widget_assert(xml,"percentiles-remove");
      
      act->percentiles_ok=get_widget_assert(xml,"percentiles-ok");
      act->percentiles_cancel=get_widget_assert(xml,"percentiles-cancel");
      
      
      gtk_entry_set_visibility (GTK_ENTRY(act->percentiles_entry), true);
      gtk_entry_set_input_purpose(GTK_ENTRY(act->percentiles_entry), GTK_INPUT_PURPOSE_NUMBER);
  
      g_signal_connect(act->percentiles_add, "clicked",
				G_CALLBACK (percentiles_add_onclick), pda);

      psppire_dialog_action_set_refresh (pda, refresh);

      psppire_dialog_action_set_valid_predicate (pda,
						 dialog_state_valid);
    
  	GtkTreeIter iter;
  	GtkListStore *list_store = gtk_list_store_new(1, G_TYPE_STRING);

//	GtkTreeModel* model = gtk_tree_view_get_model(GTK_TREE_VIEW(pda->source));

	/*GtkTreePath* path = gtk_tree_path_new();
	gtk_tree_model_get_iter(model, &iter, path);*/
	
	g_print("add_onclick4");
      	gtk_list_store_append(list_store, &iter);
      	gtk_list_store_set(list_store, &iter, 0, "21", -1);

	g_print("add_onclick5");
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_LIST_STORE(list_store));
	
	g_print("add_onclick6");
  	g_object_unref(list_store);
    //g_free(percVal);

	g_print("add_onclick7");
    }

}

static char *
generate_syntax (const PsppireDialogAction *a)
{
  
}

static void
psppire_dialog_action_percentiles_class_init (PsppireDialogActionPercentilesClass *class)
{
  psppire_dialog_action_set_activation (class, psppire_dialog_action_percentiles_activate);

  PSPPIRE_DIALOG_ACTION_CLASS (class)->generate_syntax = generate_syntax;
}


static void
psppire_dialog_action_percentiles_init (PsppireDialogActionPercentiles *act)
{
}
