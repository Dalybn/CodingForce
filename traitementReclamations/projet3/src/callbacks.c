#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "traitement.h"


void
on_button_gerer_reclamation_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_traitement_des_reclamations;
GtkWidget *fenetre_liste_des_reclamations;


fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");
gtk_widget_destroy(fenetre_liste_des_reclamations);
fenetre_traitement_des_reclamations=create_fenetre_traitement_des_reclamations();
gtk_widget_show(fenetre_traitement_des_reclamations);
}


void
on_button_valider_traitement_reclamation_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
RECLAMATION r;
//RECLAMATION rep;
int identifiant1;

GtkWidget *input1,*input2;


input1=lookup_widget(objet_graphique,"spinbutton1");
input2=lookup_widget(objet_graphique,"entry_traitement_reponse");
r.identifiant_reclamation=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
//strcpy(identifiant1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.reponse,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy(rep.etat,"oui");

gerer_reclamation(r);
}


void
on_button_retour_to_liste_des_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_reclamations;
GtkWidget *fenetre_traitement_des_reclamations;
GtkWidget *treeview_reclamations;

fenetre_traitement_des_reclamations=lookup_widget(objet,"fenetre_traitement_des_reclamations");
gtk_widget_destroy(fenetre_traitement_des_reclamations);
fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");
fenetre_liste_des_reclamations=create_fenetre_liste_des_reclamations();
gtk_widget_show(fenetre_liste_des_reclamations);
treeview_reclamations=lookup_widget(fenetre_liste_des_reclamations,"treeview_reclamations");
afficher_reclamation(treeview_reclamations);
}


void
on_treeview_reclamations_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_reclamation_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation;
GtkWidget *fenetre_liste_des_reclamations;


fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");
gtk_widget_destroy(fenetre_liste_des_reclamations);
fenetre_ajouter_reclamation=create_fenetre_ajouter_reclamation();
gtk_widget_show(fenetre_ajouter_reclamation);
}


void
on_button_valider_ajout_reclamation_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
RECLAMATION rec;

GtkWidget *input1,*input2,*input3,*input4;

input1=lookup_widget(objet_graphique,"entry_identifiant_client_ajout_reclamation");
input2=lookup_widget(objet_graphique,"entry_reclamation_ajoute");
input3=lookup_widget(objet_graphique,"entry_etat_reclamation_ajoute");
input4=lookup_widget(objet_graphique,"entry_reponse_reclamation_ajoute");

strcpy(rec.id.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(rec.reclamation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(rec.etat,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(rec.reponse,gtk_entry_get_text(GTK_ENTRY(input4)));
       
ajouter_reclamation(rec);
}


void
on_button_retour_ajout_to_liste_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_reclamations;
GtkWidget *fenetre_ajouter_reclamation;
GtkWidget *treeview_reclamations;

fenetre_ajouter_reclamation=lookup_widget(objet,"fenetre_ajouter_reclamation");
gtk_widget_destroy(fenetre_ajouter_reclamation);
fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");
fenetre_liste_des_reclamations=create_fenetre_liste_des_reclamations();
gtk_widget_show(fenetre_liste_des_reclamations);
treeview_reclamations=lookup_widget(fenetre_liste_des_reclamations,"treeview_reclamations");
afficher_reclamation(treeview_reclamations);
}


void
on_button_traitement_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
/*GtkWidget *fenetre_liste_des_reclamations;
GtkWidget *fenetre_entrer;
GtkWidget *treeview_reclamations;

fenetre_entrer=lookup_widget(objet,"fenetre_entrer");
gtk_widget_destroy(fenetre_entrer);
fenetre_entrer=lookup_widget(objet,"fenetre_liste_des_reclamations");
fenetre_liste_des_reclamations=create_fenetre_liste_des_reclamations();
gtk_widget_show(fenetre_liste_des_reclamations);
treeview_reclamations=lookup_widget(fenetre_liste_des_reclamations,"treeview_reclamations");
afficher_employe(treeview_reclamations);*/
}

