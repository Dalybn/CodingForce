#include <gtk/gtk.h>


void
on_button1_verschoix_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour1_responsable_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_boutton_retour2_responsable_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour3_responsable_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_affichage_calendrier_clicked (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_lannee_la_plusseche_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_boutton_ajouter_plante_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_boutton_retour4_calendrier_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter1_plante_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_cal_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview2_affi_cal_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficher1_tableau_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_boutton_modification_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_actualiser_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_anneeplus_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_annee_plus_seche_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
