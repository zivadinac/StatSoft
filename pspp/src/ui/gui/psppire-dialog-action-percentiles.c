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
  GtkTreeIter notused;
  GtkTreeModel *model= gtk_tree_view_get_model(GTK_TREE_VIEW(rd->percentiles_treeview));
	
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(rd->quantiles_checkbox)) || 
						gtk_toggle_button_get_active(GTK_CHECK_BUTTON(rd->quintiles_checkbox)) || 
							gtk_toggle_button_get_active(GTK_CHECK_BUTTON(rd->sextiles_checkbox)) || 
								gtk_toggle_button_get_active(GTK_CHECK_BUTTON(rd->deciles_checkbox)) || 
									(gtk_tree_model_get_iter_first(model,&notused) && 
											gtk_toggle_button_get_active(GTK_CHECK_BUTTON(rd->percentiles_checkbox))))
  {
	return TRUE;
  }
  
  return FALSE;
}
static GObject *psppire_dialog_action_percentiles_constructor (GType type, guint,
                                                     GObjectConstructParam *);

static void psppire_dialog_action_percentiles_finalize (GObject *);

static gboolean remove_selected(PsppireDialogActionPercentiles *act);

static gboolean change_elem(PsppireDialogActionPercentiles *act,gchar* str);

static gboolean get_selected_value(PsppireDialogActionPercentiles *act,gchar** str);

static void checkbox_toggled (GtkCheckButton *checkbox, PsppireDialogActionPercentiles *rd);
  
static void
refresh (PsppireDialogAction *rd_)
{
  PsppireDialogActionPercentiles *rd = PSPPIRE_DIALOG_ACTION_PERCENTILES (rd_);
	g_list_free (rd->custom_percentiles);
	rd->custom_percentiles=NULL;
	gtk_entry_set_text (rd->percentiles_entry, "");
	
	GtkListStore* list_store = gtk_tree_view_get_model(GTK_TREE_VIEW(rd->percentiles_treeview));
	gtk_list_store_clear(list_store);
	gtk_tree_view_set_model(GTK_TREE_VIEW(rd->percentiles_treeview), GTK_TREE_MODEL(list_store));
	
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_add), TRUE);
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_change), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_remove), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (rd->percentiles_discard), FALSE);
	gtk_widget_set_sensitive (GTK_ENTRY (rd->percentiles_entry), FALSE);
    
	gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->percentiles_checkbox), FALSE);
	gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->deciles_checkbox), TRUE);
	gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->sextiles_checkbox), TRUE);
	gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->quantiles_checkbox), TRUE);
	gtk_toggle_button_set_active (GTK_CHECK_BUTTON (rd->quintiles_checkbox), TRUE);

}

static void
checkbox_toggled (GtkCheckButton *checkbox, PsppireDialogActionPercentiles *rd)
{
	if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON(rd->percentiles_checkbox)))
	{
		
		gtk_widget_set_sensitive  (rd->percentiles_entry, TRUE);
		
	}
	else 
	{
		
		gtk_widget_set_sensitive  (rd->percentiles_entry, FALSE);
			
	}
	
}
static gboolean on_unselect_all(gpointer data)
{
	PsppireDialogActionPercentiles* act = PSPPIRE_DIALOG_ACTION_PERCENTILES (data);
	
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_change), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_remove), FALSE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_discard), FALSE);

}

static void 
percentiles_remove_onclick ( GtkWidget *w, PsppireDialogActionPercentiles *act)
{
	
 remove_selected(act);
 
}

static void
percentiles_discard_onclick(GtkWidget *w, PsppireDialogActionPercentiles *act)
{	
	gtk_entry_set_text (act->percentiles_entry,"");
	
	GtkTreeSelection* sel =  gtk_tree_view_get_selection (act->percentiles_treeview);
	gtk_tree_selection_unselect_all (sel);	
	
	gtk_widget_grab_focus (act->percentiles_entry);	
	
	on_unselect_all(act);
	
}

static void 
percentiles_change_onclick(GtkWidget *w, PsppireDialogActionPercentiles *act)
{
	gchar* str=gtk_entry_get_text(GTK_ENTRY(act->percentiles_entry));
	change_elem(act, str);
	gtk_entry_set_text (act->percentiles_entry, "");
	
	gtk_widget_grab_focus (act->percentiles_entry);	

}

static void 
on_select_row(GtkWidget *w, PsppireDialogActionPercentiles *act)
{
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_change), TRUE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_remove), TRUE);
	gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_discard), TRUE);
	
	gchar* str;
	if(!get_selected_value(act,&str))
		return;
		
	gtk_entry_set_text (act->percentiles_entry, str);
		
}

static void
percentiles_add_onclick (GtkButton* add, PsppireDialogActionPercentiles *act)
{
	if(!gtk_toggle_button_get_active(GTK_CHECK_BUTTON(act->percentiles_checkbox)))
		return;	
	
	gchar* percVal = gtk_entry_get_text(GTK_ENTRY(act->percentiles_entry));
	if(0 == g_strcmp0("", percVal))
		return;
		
	gint int_data=atoi(percVal);
	g_print("%d",int_data);
	if(int_data>=100 || int_data<1) 
	{
		
		GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
		GtkWidget* dialog = gtk_message_dialog_new (gtk_widget_get_toplevel (add),
                                 flags,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CANCEL,
                                 "Percentiles values \n should be between \n 0 and 100");
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	
		return;
	
	}
	if(g_list_find(act->custom_percentiles,GINT_TO_POINTER(int_data))!=NULL)
	{
		
		GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
		GtkWidget* dialog = gtk_message_dialog_new (gtk_widget_get_toplevel (add),
                                 flags,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CANCEL,
                                 "Duplicate value!");
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
		
		return;
	}
		
		GtkTreeIter iter;
		GtkTreeView *treeview = GTK_TREE_VIEW (act->percentiles_treeview);
		GtkTreeModel * model  = gtk_tree_view_get_model (treeview);
	
		gtk_list_store_append(GTK_LIST_STORE(model), &iter);
		gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, percVal, -1);
		gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(model));
	
		gtk_entry_set_text (GTK_ENTRY (act->percentiles_entry), ""); 
		gtk_widget_grab_focus (act->percentiles_entry);	
 	
		gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_change), FALSE);
		gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_remove), FALSE);
		gtk_widget_set_sensitive (GTK_BUTTON (act->percentiles_discard), FALSE);
		act->custom_percentiles=g_list_append(act->custom_percentiles,GINT_TO_POINTER(int_data));
			
}

static void
psppire_dialog_action_percentiles_activate (PsppireDialogAction *a)
{
	
}

static char *
generate_syntax (const PsppireDialogAction *a)
{
	
	PsppireDialogActionPercentiles *rd = PSPPIRE_DIALOG_ACTION_PERCENTILES (a);
	gchar *text;
	GString *string = g_string_new ("FREQUENCIES \n \t /VARIABLES =  ");
  	gchar * str_data;
  	gboolean valid;
  	GtkTreeIter iter ;
	GtkTreeView *treeview;
	GtkTreeModel *model;
	
	psppire_var_view_append_names (PSPPIRE_VAR_VIEW (rd->selected_variables_treeview), 0, string);
	if (!gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->frequency_checkbox)))
    {
		g_string_append (string, "\n \t /FORMAT = NOTABLE");
    }
    else
    {
		g_string_append (string, "\n  \t /FORMAT = TABLE");
	}
	
	g_string_append (string, "\n \t /STATISTICS = NONE ");
	g_string_append (string, "\n \t /PERCENTILES = ");
	
	GList* list=NULL;
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->quantiles_checkbox)))
	{
		
		list=g_list_append(list,GINT_TO_POINTER(25));
		list=g_list_append(list,GINT_TO_POINTER(75));
		
		g_string_append (string, "25 75 ");
		
		if(!(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->deciles_checkbox))))
		{
			list=g_list_append(list,GINT_TO_POINTER(75));
			g_string_append (string, "50 ");
		}
		
	}
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->quintiles_checkbox)))
	{
		if(!(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->deciles_checkbox))))
		{
		list=g_list_append(list,GINT_TO_POINTER(20));
		list=g_list_append(list,GINT_TO_POINTER(40));
		list=g_list_append(list,GINT_TO_POINTER(60));
		list=g_list_append(list,GINT_TO_POINTER(80));
		g_string_append (string, "20 40 60 80 ");
		}
		
	}
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->sextiles_checkbox)))
	{
		
		list=g_list_append(list,GINT_TO_POINTER(17));
		list=g_list_append(list,GINT_TO_POINTER(34));
		list=g_list_append(list,GINT_TO_POINTER(51));
		list=g_list_append(list,GINT_TO_POINTER(68));
		list=g_list_append(list,GINT_TO_POINTER(85));
		g_string_append (string, "17 34 51 68 85 ");
		
	}
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->deciles_checkbox)))
	{
	
		list=g_list_append(list,GINT_TO_POINTER(10));
		list=g_list_append(list,GINT_TO_POINTER(20));
		list=g_list_append(list,GINT_TO_POINTER(30));
		list=g_list_append(list,GINT_TO_POINTER(40));
		list=g_list_append(list,GINT_TO_POINTER(50));
		list=g_list_append(list,GINT_TO_POINTER(60));
		list=g_list_append(list,GINT_TO_POINTER(70));
		list=g_list_append(list,GINT_TO_POINTER(80));
		list=g_list_append(list,GINT_TO_POINTER(90));
		g_string_append (string, "10 20 30 40 50 60 70 80 90 ");
		
	}
	
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (rd->percentiles_checkbox)))
	{
		GList *l;
		for (l = rd->custom_percentiles; l != NULL; l = l->next)
		{
			if(g_list_find (list,GINT_TO_POINTER(l->data))==NULL)
				{
					gchar *my_string = g_strdup_printf("%i", l->data);
					g_string_append (string,my_string);
					g_string_append (string," ");
					
				}
		}
	}
	  	  
	g_string_append (string, ".");	
	text=string->str;
	return text;
	
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
	pda->source = get_widget_assert   (xml, "dictview");
	act->percentiles_treeview = get_widget_assert (xml, "percentiles-treeview");
	act->selected_variables_treeview = get_widget_assert (xml, "selected-varibales-treeview");
	gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (act->percentiles_treeview), FALSE); 
		
	act->quantiles_checkbox = get_widget_assert (xml, "quartiles-checkbox");
	act->quintiles_checkbox=get_widget_assert(xml,"quintiles-checkbox");
	act->sextiles_checkbox=get_widget_assert(xml,"sextiles-checkbox");
	act->deciles_checkbox=get_widget_assert(xml,"deciles-checkbox");
	act->percentiles_checkbox=get_widget_assert(xml,"percentiles-checkbox");
	act->frequency_checkbox=get_widget_assert(xml,"frequency-checkbox");
       
	act->percentiles_entry=get_widget_assert(xml,"percentiles-entry");
     
	act->percentiles_add=get_widget_assert(xml,"percentiles-add");
    act->percentiles_change=get_widget_assert(xml,"percentiles-change");
    act->percentiles_remove=get_widget_assert(xml,"percentiles-remove");
    act->percentiles_discard=get_widget_assert(xml,"percentiles-discard");  
      
	gtk_entry_set_visibility (GTK_ENTRY(act->percentiles_entry), true);
    gtk_entry_set_input_purpose(GTK_ENTRY(act->percentiles_entry), GTK_INPUT_PURPOSE_NUMBER);
  
    g_signal_connect(act->percentiles_add, "clicked",
			G_CALLBACK (percentiles_add_onclick), pda);
	g_signal_connect(act->percentiles_discard, "clicked",
			G_CALLBACK (percentiles_discard_onclick), pda);
	g_signal_connect(act->percentiles_remove, "clicked",
			G_CALLBACK (percentiles_remove_onclick), pda);		
	g_signal_connect(act->percentiles_change, "clicked",
			G_CALLBACK (percentiles_change_onclick), pda);
	g_signal_connect (act->percentiles_treeview, "cursor-changed",
			G_CALLBACK (on_select_row), pda);
	g_signal_connect (act->percentiles_treeview, "unselect-all",
			G_CALLBACK (on_unselect_all), pda);
    g_signal_connect(act->percentiles_checkbox, "toggled", 
			G_CALLBACK (checkbox_toggled), pda);
                    

    psppire_dialog_action_set_refresh (act, refresh);
	psppire_dialog_action_set_valid_predicate (act, dialog_state_valid);
    
    renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes ("Values", renderer, "text", 0, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (act->percentiles_treeview), column); 
	
	GtkListStore* list_store = gtk_list_store_new(1, G_TYPE_STRING);
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_TREE_MODEL(list_store));
	act->custom_percentiles=NULL;
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
	gtk_tree_selection_unselect_all (sel);
	
	on_unselect_all(act);
	 	 	
	return TRUE;
  
}
 
static gboolean get_selected_value(PsppireDialogActionPercentiles *act,gchar** str)
{
	GtkTreeIter iter;
	GValue value={0};
	GtkTreeView *treeview = GTK_TREE_VIEW (act->percentiles_treeview);
	GtkTreeSelection* sel =  gtk_tree_view_get_selection (treeview);
	GtkTreeModel * model  = gtk_tree_view_get_model (treeview);

	if (! gtk_tree_selection_get_selected (sel, &model, &iter))
	{	
		on_unselect_all(act);
		return FALSE;
	}	
	gtk_tree_model_get_value (model, &iter, 0, &value);	
	*str=g_strdup ( g_value_get_string(&value));
	
	return TRUE;
	
}

static gboolean change_elem(PsppireDialogActionPercentiles *act,gchar * str)
{
	GtkTreeIter iter ;
	
	GtkTreeView *treeview = GTK_TREE_VIEW (act->percentiles_treeview);
	GtkTreeSelection* sel =  gtk_tree_view_get_selection (treeview);
	GtkTreeModel * model  = gtk_tree_view_get_model (treeview);
	
	if (! gtk_tree_selection_get_selected (sel, &model, &iter))
		return FALSE;
	
	gchar *strr;
	get_selected_value(act,&strr);
	gint int_data=atoi(strr);
	GList *elem=g_list_find (act->custom_percentiles,GINT_TO_POINTER(int_data));
	elem->data=atoi(str);
		
	gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, str, -1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(act->percentiles_treeview), GTK_TREE_MODEL(model));
		
	gtk_tree_selection_unselect_all (sel); 	
	on_unselect_all(act);
		
	return TRUE;
	
}
