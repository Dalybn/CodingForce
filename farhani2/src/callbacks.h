#include <gtk/gtk.h>


void
on_ajoutrec_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rechercher_reclamation_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_afficher_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifier_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rechercher_client_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gerer_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exit2_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_client_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exit_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_retour1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);
/*
void
on_retour1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_valider_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aff_reclamation_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_client_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_DISPO_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DISPOREC_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_aff_rec_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aff_cmd_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aff_client_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retout_principal_clicked            (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_disporecl_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouterCL_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewCL_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_client1_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_rec_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);
