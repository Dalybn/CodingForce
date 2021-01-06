#include <gtk/gtk.h>



void
on_button_gerer_reclamation_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_valider_traitement_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_to_liste_des_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_reclamations_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_ajouter_reclamation_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_valider_ajout_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_ajout_to_liste_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_traitement_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);
