#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "plante.h"
#include "enregistrement.h"





void
on_button1_verschoix_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix;
GtkWidget *Espace_responsable_de__production;

Espace_responsable_de__production=lookup_widget(objet,"Espace_responsable_de__production");

gtk_widget_destroy(Espace_responsable_de__production);
fenetre_choix=create_fenetre_choix();

gtk_widget_show(fenetre_choix);
}

////////////////////////////////////////////////////////////////////


void
on_retour1_responsable_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_choix;

Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");

gtk_widget_destroy(Calendrier_de_plantations);
fenetre_choix=create_fenetre_choix();

gtk_widget_show(fenetre_choix);
}

////////////////////////////////////////////////////////////////////

void
on_boutton_retour2_responsable_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Lannee_la_plus_seche;
GtkWidget *fenetre_choix;

Lannee_la_plus_seche=lookup_widget(objet,"Lannee_la_plus_seche");

gtk_widget_destroy(Lannee_la_plus_seche);
fenetre_choix=create_fenetre_choix();

gtk_widget_show(fenetre_choix);
}

////////////////////////////////////////////////////////////////////

void
on_button_retour3_responsable_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix;
GtkWidget *Espace_responsable_de__production;


fenetre_choix=lookup_widget(objet,"fenetre_choix");

gtk_widget_destroy(fenetre_choix);
Espace_responsable_de__production=create_Espace_responsable_de__production();

gtk_widget_show(Espace_responsable_de__production);
}

////////////////////////////////////////////////////////////////////

void
on_button_affichage_calendrier_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_choix;
GtkWidget *treeview1_cal;

fenetre_choix=lookup_widget(objet,"fenetre_choix");

gtk_widget_destroy(fenetre_choix);
Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");
Calendrier_de_plantations=create_Calendrier_de_plantations();

gtk_widget_show(Calendrier_de_plantations);

treeview1_cal=lookup_widget(Calendrier_de_plantations,"treeview1_cal");

affichage(treeview1_cal);
}

////////////////////////////////////////////////////////////////////

void
on_button_lannee_la_plusseche_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix;
GtkWidget *Lannee_la_plus_seche;

fenetre_choix=lookup_widget(objet,"fenetre_choix");

gtk_widget_destroy(fenetre_choix);
Lannee_la_plus_seche=create_Lannee_la_plus_seche();

gtk_widget_show(Lannee_la_plus_seche);
}





void
on_boutton_ajouter_plante_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
plantation p;
GtkWidget *input1, *input2, *input3, *input4, *label;
GtkWidget *fenetre_ajouter_plante;
GtkWidget *type_plante;

fenetre_ajouter_plante=lookup_widget(objet,"fenetre_ajouter_plante");

type_plante=lookup_widget(objet,"combobox2_type");

label=lookup_widget(objet, "sortie");
input1=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"jour");
input4=lookup_widget(objet,"mois");
input2=lookup_widget(objet,"spinbutton1_anneeajout");

strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.annee,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.jour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.mois,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_plante)));

ajouter(p);

gtk_label_set_text(GTK_LABEL(label),"Plante ajouter avec succès");
}

void
on_boutton_retour4_calendrier_clicked  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_ajouter_plante;

fenetre_ajouter_plante=lookup_widget(objet,"fenetre_ajouter_plante");

gtk_widget_destroy(fenetre_ajouter_plante);
Calendrier_de_plantations=create_Calendrier_de_plantations();

gtk_widget_show(Calendrier_de_plantations);
}



void
on_ajouter1_plante_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_ajouter_plante;

Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");

gtk_widget_destroy(Calendrier_de_plantations);
fenetre_ajouter_plante=create_fenetre_ajouter_plante();

gtk_widget_show(fenetre_ajouter_plante);
}



//


void
on_treeview1_cal_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gint* id;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* type;
plantation p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&nom,2,&jour,3,&mois,4,&annee,5,&type,-1);
strcpy(p.nom,nom);
p.id=id;
strcpy(p.jour,jour);
strcpy(p.mois,mois);
strcpy(p.annee,annee);
strcpy(p.type,type);

supprimer(p);
affichage(treeview);
}
}


void
on_treeview2_affi_cal_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gint* id;
gchar* jour;
gchar* mois;
gchar* annee;
plantation p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &id,1,&nom,2,&jour,3,&mois,4,&annee,-1);
strcpy(p.nom,nom);
p.id=id;
strcpy(p.jour,jour);
strcpy(p.mois,mois);
strcpy(p.annee,annee);
supprimer(p);
affichage(treeview);
}
}



void
on_afficher1_tableau_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_ajouter_plante;
GtkWidget *treeview1_cal;

fenetre_ajouter_plante=lookup_widget(objet,"fenetre_ajouter_plante");

gtk_widget_destroy(fenetre_ajouter_plante);
Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");
Calendrier_de_plantations=create_Calendrier_de_plantations();

gtk_widget_show(Calendrier_de_plantations);

treeview1_cal=lookup_widget(Calendrier_de_plantations,"treeview1_cal");

affichage(treeview1_cal);
}
}


void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_modifier_plante;

Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");

gtk_widget_destroy(Calendrier_de_plantations);
fenetre_modifier_plante=create_fenetre_modifier_plante();

gtk_widget_show(fenetre_modifier_plante);
}


void
on_boutton_modification_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
plantation p;
GtkWidget *input1, *input2, *input3, *input4, *label, *input5;
GtkWidget *fenetre_modifier_plante;
GtkWidget *type_plante;

fenetre_modifier_plante=lookup_widget(objet,"fenetre_modifier_plante");

type_plante=lookup_widget(objet,"combobox3");

label=lookup_widget(objet, "sortie1");
input1=lookup_widget(objet,"nom1");
input3=lookup_widget(objet,"jour1");
input4=lookup_widget(objet,"mois1");
input2=lookup_widget(objet,"annee1");
input5=lookup_widget(objet,"spinbutton5_id2");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.annee,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.jour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.mois,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_plante)));
p.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));


Modifier(p);
gtk_label_set_text(GTK_LABEL(label),"Plante modifier avec succès");
}

void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Calendrier_de_plantations;
GtkWidget *fenetre_modifier_plante;
GtkWidget *treeview1_cal;

fenetre_modifier_plante=lookup_widget(objet,"fenetre_modifier_plante");

gtk_widget_destroy(fenetre_modifier_plante);
Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");
Calendrier_de_plantations=create_Calendrier_de_plantations();

gtk_widget_show(Calendrier_de_plantations);

treeview1_cal=lookup_widget(Calendrier_de_plantations,"treeview1_cal");

affichage(treeview1_cal);

}

void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *treeview1_cal;
plantation p;

identifiant=lookup_widget(objet,"spinbutton6_rech");
p.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));

chercher(p);

treeview1_cal=lookup_widget(objet,"treeview1_cal");
afficher_et_rechercher(treeview1_cal);
}


void
on_button7_actualiser_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Calendrier_de_plantations;
  GtkWidget *treeview1_cal;
  Calendrier_de_plantations = lookup_widget(objet, "button7_actualiser");
  treeview1_cal = lookup_widget(Calendrier_de_plantations, "treeview1_cal");
  gtk_widget_show(Calendrier_de_plantations);
  affichage(treeview1_cal);
}


void
on_treeview1_anneeplus_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gint *annee;
gint *valeur;

En a;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &annee,1,&valeur,-1);

a.d.an=*annee;
a.valeur=*valeur;
}
}


void
on_annee_plus_seche_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Lannee_la_plus_seche;
  GtkWidget *treeview1_anneeplus;
  Lannee_la_plus_seche = lookup_widget(objet, "Lannee_la_plus_seche");
  seche();
  treeview1_anneeplus = lookup_widget(objet, "treeview1_anneeplus");
  
  afficher_annee_seche(treeview1_anneeplus);
}

