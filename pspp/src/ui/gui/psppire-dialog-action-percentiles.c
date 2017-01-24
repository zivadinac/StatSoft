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
static GObject *psppire_dialog_action_percentiles_constructor (GType type, guint,

                                                     GObjectConstructParam *);
static void psppire_dialog_action_percentiles_finalize (GObject *);

//static void repopulate_dialog (PsppireDialogActionPercentiles *act);

static gboolean remove_selected(PsppireDialogActionPercentiles *act);

//static void remove_elem(GList** list,GValue *str);

//static void change_elem(GList** list, gchar *str1,gchar *str2);

static gboolean get_iter_of_selected(PsppireDialogActionPercentiles *act, GtkTreeIter *iter);
  
static void
refresh (PsppireDialogAction *rd_)
{
  PsppireDialogActionPercentiles *rd = PSPPIRE_DIALOG_ACTION_PERCENTILES (rd_);

  gtk_entry_set_text (GTK_ENTRY (rd->percentiles_entry), "");

  /* Set summary_func to true, then let it get unset again.
     This ensures that the signal handler gets called.   */
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_add), TRUE);
//	gtk_toggle_button_set_sensitive (GTK_BUTTON (rd->percentiles_cancel), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_change), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_remove), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_discard), FALSE);
	//gtk_widget__set_active (GTK_BUTTON (rd->percentiles_ok), TRUE);
  
  
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->percentiles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->deciles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->sextiles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->quantiles_checkbox), TRUE);
  gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->quintiles_checkbox), TRUE);

}

static void
percentiles_cancel_onclick(GtkWidget*w,PsppireDialogActionPercentiles *act)
{
	
}

static void 
percentiles_remove_onclick ( GtkWidget*w, PsppireDialogActionPercentiles *act)
{
 remove_selected(act);
}

static void
percentiles_discard_onclick(GtkWidget *w,PsppireDialogActionPercentiles *act)
{
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_add), TRUE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_change), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_remove), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_discard), FALSE);
	
	gtk_entry_set_text (act->percentiles_entry,"");
	
}

static void 
percentiles_ok_onclick(GtkWidget *w,PsppireDialogActionPercentiles *act)
{
	
}

static void 
percentiles_change_onclick(GtkWidget *w,PsppireDialogActionPercentiles *act)
{
	gchar* str2=gtk_entry_get_text(GTK_ENTRY(act->percentiles_entry));
	//change_elem(&(act->treeview_vals),get_selected_value(act->treeview_vals), str2);
//	repopulate_dialog(act);
}

static void 
on_select_row(GtkWidget *w,PsppireDialogActionPercentiles *act)
{
	//gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_add), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_change), TRUE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_remove), TRUE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_discard), TRUE);
	
	//GValue *v=get_selected_value(act);
	//gtk_entry_set_text (act->percentiles_entry, g_value_get_string(&v));
	
	
}

static void
on_value_entry_change(GtkWidget *w,PsppireDialogActionPercentiles *act)
{
	
}

static void 
on_value_entry_activate(GtkWidget *w,PsppireDialogActionPercentiles *act)
{
	
}

static void
percentiles_add_onclick (GtkButton* add, PsppireDialogActionPercentiles *act)
{
	//union value v;
	
	if(!gtk_toggle_button_get_active(GTK_CHECK_BUTTON(act->percentiles_checkbox)))
	{
		return;	
	}
	
	gchar* percVal = gtk_entry_get_text(GTK_ENTRY(act->percentiles_entry));
	//text_to_value__ (perVal, &act->format, act->encoding, &v);
	
	if(0 == g_strcmp0("", percVal))
	{
		return;
	}
	GtkTreeIter iter;
	GtkTreeView *treeview = GTK_TREE_VIEW (act->percentiles_treeview);
	GtkTreeModel * model  = gtk_tree_view_get_model (treeview);
	
  	//PsppireDialogAction *pda = PSPPIRE_DIALOG_ACTION(act);
	//gchar* str= g_strdup(percVal);
	
	gtk_list_store_append(GTK_LIST_STORE(model), &iter);
	gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, percVal, -1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_TREE_MODEL(model));
	
	//g_print( "%x",&str);
		
	//act->treeview_vals = g_list_append (act->treeview_vals,str);
 	
 	//repopulate_dialog(act);
 	
 	gtk_entry_set_text (GTK_ENTRY (act->percentiles_entry), ""); 
 	gtk_widget_grab_focus (act->percentiles_entry);
	
}

static void
psppire_dialog_action_percentiles_activate (PsppireDialogAction *a)
{
	
   
}

static char *
generate_syntax (const PsppireDialogAction *a)
{
 return NULL;
}

static void
psppire_dialog_action_percentiles_class_init (PsppireDialogActionPercentilesClass *class)
{
  psppire_dialog_action_set_activation (class, psppire_dialog_action_percentiles_activate);

  PSPPIRE_DIALOG_ACTION_CLASS (class)->generate_syntax = generate_syntax;
  
  GObjectClass *gobject_class;
  
  gobject_class = G_OBJECT_CLASS (class);
  gobject_class->constructor = psppire_dialog_action_percentiles_constructor;
  gobject_class->finalize = psppire_dialog_action_percentiles_finalize;
  
 
  
}
static GObject *
psppire_dialog_action_percentiles_constructor(GType                  type,
                                     guint                  n_properties,
                                     GObjectConstructParam *properties)
 {

	PsppireDialogActionPercentiles *act;
	PsppireDialogAction *pda;
	GtkTreeViewColumn *column;
	GtkCellRenderer *renderer;
	
	
	
	GObject *obj;
	
	GtkBuilder *xml = gtk_builder_new_from_file("percentiles.ui");
	obj = G_OBJECT_CLASS (psppire_dialog_action_percentiles_parent_class)->constructor (
    type, n_properties, properties);
	act = PSPPIRE_DIALOG_ACTION_PERCENTILES (obj);
	pda=PSPPIRE_DIALOG_ACTION(obj);
	
	GHashTable *thing = psppire_dialog_action_get_hash_table (pda);
	g_hash_table_insert (thing, act, xml);
  

	pda->dialog = get_widget_assert (xml, "percentiles-dialog");

	act->percentiles_treeview = get_widget_assert (xml, "percentiles-treeview");
	gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (act->percentiles_treeview), FALSE); 
		
	act->quantiles_checkbox = get_widget_assert (xml, "quartiles-checkbox");
	act->quintiles_checkbox=get_widget_assert(xml,"quintiles-checkbox");
	act->sextiles_checkbox=get_widget_assert(xml,"sextiles-checkbox");
	act->deciles_checkbox=get_widget_assert(xml,"deciles-checkbox");
	act->percentiles_checkbox=get_widget_assert(xml,"percentiles-checkbox");
       
	act->percentiles_entry=get_widget_assert(xml,"percentiles-entry");
     
	act->percentiles_add=get_widget_assert(xml,"percentiles-add");
    act->percentiles_change=get_widget_assert(xml,"percentiles-change");
    act->percentiles_remove=get_widget_assert(xml,"percentiles-remove");
    act->percentiles_discard=get_widget_assert(xml,"percentiles-discard");  
    act->percentiles_ok=get_widget_assert(xml,"percentiles-ok");
    act->percentiles_cancel=get_widget_assert(xml,"percentiles-cancel");
      
     act->treeview_vals=NULL;
      
    gtk_entry_set_visibility (GTK_ENTRY(act->percentiles_entry), true);
    gtk_entry_set_input_purpose(GTK_ENTRY(act->percentiles_entry), GTK_INPUT_PURPOSE_NUMBER);
  
    g_signal_connect(act->percentiles_add, "clicked",
			G_CALLBACK (percentiles_add_onclick), pda);
	g_signal_connect(act->percentiles_discard, "clicked",
			G_CALLBACK (percentiles_discard_onclick), pda);
	g_signal_connect(act->percentiles_remove, "clicked",
			G_CALLBACK (percentiles_remove_onclick), pda);		
	g_signal_connect(act->percentiles_cancel, "clicked",
			G_CALLBACK (percentiles_cancel_onclick), pda);
	g_signal_connect(act->percentiles_ok, "clicked",
			G_CALLBACK (percentiles_ok_onclick), pda);
	g_signal_connect(act->percentiles_change, "clicked",
			G_CALLBACK (percentiles_change_onclick), pda);
	g_signal_connect (act->percentiles_treeview, "cursor-changed",
		   G_CALLBACK (on_select_row), pda);
	act->value_handler_id  = g_signal_connect (act->percentiles_entry,"changed",
									G_CALLBACK (on_value_entry_change), pda);
	g_signal_connect (act->percentiles_entry, "activate",
                    G_CALLBACK (on_value_entry_activate), pda);

    psppire_dialog_action_set_refresh (act, refresh);
	psppire_dialog_action_set_valid_predicate (act, dialog_state_valid);
    
    renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes ("Values", renderer, "text", 0, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (act->percentiles_treeview), column); 
	
	GtkListStore* list_store = gtk_list_store_new(1, G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_TREE_MODEL(list_store));
 
 return obj;
 }
static void 
psppire_dialog_action_percentiles_finalize (GObject* o)
{
	PsppireDialogActionPercentiles *rd = PSPPIRE_DIALOG_ACTION_PERCENTILES (o);
	
	gtk_entry_set_text (GTK_ENTRY (rd->percentiles_entry), "");
}

static void
psppire_dialog_action_percentiles_init (PsppireDialogActionPercentiles *act)
{
}
/*
static void repopulate_dialog(PsppireDialogActionPercentiles *act)
{
	
	GtkTreeIter iter;
  	GtkListStore* list_store = gtk_list_store_new(1, G_TYPE_STRING);

	for ( GList* l = act->treeview_vals; l != NULL; l = l->next)
	{
		gpointer g = l->data;
		gtk_list_store_append(list_store, &iter);
		gtk_list_store_set(list_store, &iter, 0, g, -1);
		g_print("%s %x",l->data,&(l->data));
		g_print("\n",&(l->data));
	}
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_TREE_MODEL(list_store));
	}
  	
  	*/
static gboolean remove_selected(PsppireDialogActionPercentiles *act)
{
	GtkTreeIter iter ;
	
	GtkTreeView *treeview = GTK_TREE_VIEW (act->percentiles_treeview);
	GtkTreeSelection* sel =  gtk_tree_view_get_selection (treeview);
	GtkTreeModel * model  = gtk_tree_view_get_model (treeview);

	if (! gtk_tree_selection_get_selected (sel, &model, &iter))
		return FALSE;
	
	
	gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_TREE_MODEL(model));
	 	
	return TRUE;
  }
 
/*static gboolean 
get_iter_of_selected(PsppireDialogActionPercentiles *act, GtkTreeIter iter)
{
	
	
	return TRUE;
} 
* 
 /*
  * static void 
  remove_elem(GList** list, GValue *str){
	  g_print("posle je for");
	for ( GList* l = *list; l != NULL; l = l->next)
	{
		g_print("\n %s ulaz u for \n ",l->data);
		
  if(*list == NULL || l == NULL)
    break;
 if(str==l->data)
 {
	 g_print("ovaj je oout %s \n",l->data);
	*list=g_list_delete_link  (*list,l);
	break;

 
	}
}
}
static void change_elem(GList** list,gchar *str1,gchar *str2)
{
	for ( GList* l = *list; l != NULL; l = l->next)
	{
		g_print("\n %s ulaz u for \n ",l->data);
		if(*list == NULL || l == NULL)
			break;
		if(0 == g_strcmp0(str1, l->data))
		{
			l->data=g_strdup(str2);
			g_print(l->data);
			break;

 
	}
}

}
*/
