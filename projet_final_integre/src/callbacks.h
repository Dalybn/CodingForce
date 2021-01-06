#include <gtk/gtk.h>

				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE SOFIENE//###############################
				//////////////////////////////////////////////////////////////////////////////////
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
on_radiobutton3_ok_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_etat_mauvais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_mauvais_toggled        (GtkToggleButton *togglebutton,
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

				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE HIBA + OUMAYMA//###############################
				//////////////////////////////////////////////////////////////////////////////////

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retourL_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_ajouterL_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_modifierL_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_retourA_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_enregistrerA_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_liste_capteur_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_capteurH_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_capteurT_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data);


void
on_retourG_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_enregistrement_clicked              (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_gestion_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data);



void
on_dispo_clicked                       (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourMC_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_enregistrerMC_clicked               (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouterEH_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_enregistrerEH_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherEH_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_enregistrerET_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_retourEH_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouterET_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourET_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_afficherT_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_DISPOH_clicked                      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_DISPOT_clicked                      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_retourE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_cher_clicked                        (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_retourCHE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_DISPOCH_clicked                     (GtkWidget         *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_quitterL_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_quitterET_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_quitterEH_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data);

/*void
on_afficher_client_clicked             (GtkWidget        *objet,
                                        gpointer         user_data);
*/
void
on_afficher_commande_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficher_reclamation_clicked        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_retourDEF_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_captD_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_quitterDEF_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_ajouterCL_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_afficher_client_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);


void
on_DISPO_clicked                       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_treeviewCL_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retourCL1_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_ajouter_client1_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_client_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_valider_modif_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_retour_modif_clicked                (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_DISPOREC_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_ajouterec_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_disporecl_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_rechercher_reclamation_clicked      (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_treeviewREC_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_rec_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data);


void
on_Etat1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Etat2_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rechercher_client_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_modifier_client_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_afficher_client1_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_retourRESCL_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_responsable_client_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_responsable_qualite_clicked         (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_exitAC_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_exitREC_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_treeviewCOM_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retourLCOM_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouterLCOM_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourACOM_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_enregistrerACOM_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exitACOM_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exitCOM_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dispoCOM_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_REFRECH_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_nbree_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exit_client_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exit_ajt_recl_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherREC_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_recl_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_affichage_recl_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

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
on_dispo_id_rechrech_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_recherch_recl_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Etat1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Etat2_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_dispo_id_rec_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refresh_tableau_reclamation_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);


				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE DALY//###############################
				//////////////////////////////////////////////////////////////////////////////////

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
on_button6_refresh_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_homme_ouvrier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_femme_ouvrier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_ouvrier_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button68_refresh_treeview_ouvrier_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button69_refresh_treeview_absences_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button73_quitter_ajouter_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button74_quitter_liste_capteurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button75_quitter_gestion_capteurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button76_quitter_enregistrement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button77_quitter_capteur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button78_quitter_modifier_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button79_quitter_fenetre_ajouter_enH_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button80_quitter_fenetre_afficher_enH_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button82_quitter_fenetre_afficher_enT_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button81_quitter_ajouter_enT_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button83_quitter_f_chercher_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button84_quitter_gestion_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button85_quitter_capteur_defect_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button86_quitter_fenetre_ajouter_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button87_quitter_fenetre_afficher_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button88_quitter_fenetre_modifier_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button89_quitter_fenetre_ajouter_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button90_quitter_fenetre_responsable_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button91_quitter_liste_commande_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button92_quitter_ajoute_commande_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button93_quitter_treeview_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button94_quitter_fenetre_fiche_information_ajout_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button95_quitter_fenetre_ajouter_absence_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button96_quitter_fenetre_responsable_ouvrier_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button97_quitter_treeview_abs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button98_quitter_fenetre_modifier_informations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button70_connexion_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button71_inscription_application_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button69_retour_vers_login_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button68_enregistrer_inscription_application_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gerer_recl_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_enreg_gerer_recl_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_return_reclama_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_dispo_rech_com_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_com_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_taux_abs_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE TOUIHRI//###############################
				//////////////////////////////////////////////////////////////////////////////////
void
on_button68_meilleur_ouvrier_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_to_gestion_des_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button_rechercher_employe_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_to_liste_des_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_valider_ajout_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button_retour2_to_liste_des_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_valider_modification_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_modifier_employe_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_supprimer_employe_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_employe_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_gestion_des_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_employees_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobutton_homme_ajout_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_ajout_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme_modifie_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_modifie_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_quitter_liste_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_ajout_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_modification_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button68_gestion_des_ouvriers_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button71_gestion_des_clients_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button70_gestion_des_plantations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button69_gestion_des_capteurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button73_gestion_des_employes_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

////////////////////////////////aziz//////////////////////////////////////


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

void
on_recherche_plante_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button99_nombre_animal_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_retour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_traite_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_etat_ok_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_button2_exit_reclamation_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button102_quitter_calendrier_de_plantation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button103_quitter_fenetre_ajouter_plante_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button105_quitter_fenetre_choix_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button106_quitter_fenetre_modifier_plante_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button107_quitter_fenetre_Lannee_la_plus_seche_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button105_quitter_fenetre_traitement_des_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button106_quitter_fenetre_ajouter_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);
