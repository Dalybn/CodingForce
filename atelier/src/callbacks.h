#include <gtk/gtk.h>


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
