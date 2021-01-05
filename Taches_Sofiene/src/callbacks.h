#include <gtk/gtk.h>


void
on_button_ajouter_animal1_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_afficher_animal_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_animal1_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_animal1_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_animal2_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_animal2_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_animal2_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_afficher_equipement1_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_equipement1_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_date_entretient_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_equipement1_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_equipement1_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_equipement2_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_equipement2_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_supprimer_equipement1_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_modifier_equipement1_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_modifier_animal1_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_supprimer_animal1_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour3_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_animal3_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_equipement2_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_equipement3_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_equipement3_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_supprimer_equipement2_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_modifier_equipement2_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_equipement3_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_equipement4_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_equipement4_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_equipement4_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_equipement5_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_equipement5_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_gestion_troupeaux_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_gestion_equipement_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_menu_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_equipement_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_entretient_equipement_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_animal_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_modifier_animal_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_retour_modifier_animal_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_quitter_modifier_animal_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_modifier_equipement_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_retour_modifier_equipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_quitter_modifier_equipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_modifier_entretient_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_retour_modifier_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button10_quitter_modifier_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_nombre_equipement_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_nombre_animal_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button13_activate                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_cheval_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mouton_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_vache_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_poulet_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_radiobutton10_cheval_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_mouton_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton13_vache_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_poulet_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_fait_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_non_fait_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_verifier_animal_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_verifier_equipement_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_verifier_entretient_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_etat_ok_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_etat_mauvais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_mauvais_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_ok_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_Ajouter_animal123_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_equipement123_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_actualiser_tableau_animal_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_actualiser_tableau_equipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_actualiser_tableau_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_id_equipement_pour_ajouter_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_nombre_equipement_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);
