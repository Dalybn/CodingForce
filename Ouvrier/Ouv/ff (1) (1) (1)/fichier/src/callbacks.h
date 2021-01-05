#include <gtk/gtk.h>


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button1_ajouter_ouvrier_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_modifier_ouvrier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_supprimer_ouvrier_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_retour_to_initial_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button14_chercher_ouvrier_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_retour_to_treeview_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_enregistrer_ouvrier_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_retour_to_treeview_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_enregistrer_modification_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_ajouter_absence_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button10_retour_to_treeview_clicked (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button12_retour_to_liste_responsable_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button11_gestion_ouvrier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_gestion_absence_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_absence_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_to_gestion_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button6_refresh_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_taux_abs_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);
