#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "animal.h"
#include "equipement.h"
#include "capt.h"
#include "commande.h"
#include "reclamation.h"
#include "enregistrement.h"
#include "ouv.h"
#include "employe.h"
#include "plante.h"
#include "traitement.h"


				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE SOFIENE//###############################
				//////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////
void
on_button_ajouter_animal2_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
//Ajouter un animal
GtkWidget *mois;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *sexe;
GtkWidget *radio2;
GtkWidget *sortie;
GtkWidget *mouton;
GtkWidget *vache;
GtkWidget *poulet;
GtkWidget *cheval;
Animal A;

sortie=lookup_widget(objet,"label116");
mois=lookup_widget(objet,"combobox1");
jour=lookup_widget(objet,"spinbutton_jour_animal1");
annee=lookup_widget(objet,"spinbutton_annee_animal1");
sexe=lookup_widget(objet,"combobox13");
mouton=lookup_widget(objet,"radiobutton_mouton");
vache=lookup_widget(objet,"radiobutton_vache");
poulet=lookup_widget(objet,"radiobutton_poulet");
cheval=lookup_widget(objet,"radiobutton_cheval");

if(s==1)
{
	strcpy(A.type,"Cheval");
}
if(s==2)
{
	strcpy(A.type,"Mouton");
}
if(s==3)
{
	strcpy(A.type,"Vache");
}
if(s==4)
{
	strcpy(A.type,"Poulet");
}

A.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
A.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

strcpy(A.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(A.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Ajout réuissie");

Ajouter_A(A);

}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_ajouter_animal ======>> fenetre_afficher_animal
void
on_button_retour_animal2_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_animal;
GtkWidget *fenetre_afficher_animal;
GtkWidget *treeview_animal;

fenetre_ajouter_animal=lookup_widget(objet,"fenetre_ajouter_animal");

gtk_widget_destroy(fenetre_ajouter_animal);
fenetre_afficher_animal=create_fenetre_afficher_animal();

gtk_widget_show(fenetre_afficher_animal);
treeview_animal=lookup_widget(fenetre_afficher_animal,"treeview_animal");

Affichage(treeview_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_ajouter_animal
void
on_button_quitter_animal2_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_animal;

fenetre_ajouter_animal=lookup_widget(objet,"fenetre_ajouter_animal");

gtk_widget_destroy(fenetre_ajouter_animal);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
//gestion_des___quipement_agricoles ======>> liste_equipement
void
on_button_afficher_equipement1_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_equipement;
GtkWidget *gestion_des___quipement_agricoles;
GtkWidget *treeview_equipement;

gestion_des___quipement_agricoles=lookup_widget(objet,"gestion_des___quipement_agricoles");

gtk_widget_destroy(gestion_des___quipement_agricoles);
liste_equipement=lookup_widget(objet,"liste_equipement");
liste_equipement=create_liste_equipement();

gtk_widget_show(liste_equipement);

treeview_equipement=lookup_widget(liste_equipement,"treeview_equipement");

Afficher_E(treeview_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//gestion_des___quipement_agricoles ======>> fenetre_entretient_equipement
void
on_button_date_entretient_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_entretient_equipement;
GtkWidget *gestion_des___quipement_agricoles;
GtkWidget *treeview_entretient_equipement;

gestion_des___quipement_agricoles=lookup_widget(objet,"gestion_des___quipement_agricoles");

gtk_widget_destroy(gestion_des___quipement_agricoles);
fenetre_entretient_equipement=create_fenetre_entretient_equipement();

gtk_widget_show(fenetre_entretient_equipement);

treeview_entretient_equipement=lookup_widget(fenetre_entretient_equipement,"treeview_entretient_equipement");

Afficher_ent(treeview_entretient_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//gestion_des___quipement_agricoles ======>> fenetre_menu
void
on_button_retour_equipement1_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_des___quipement_agricoles;
GtkWidget *fenetre_menu;

gestion_des___quipement_agricoles=lookup_widget(objet,"gestion_des___quipement_agricoles");

gtk_widget_destroy(gestion_des___quipement_agricoles);
fenetre_menu=create_fenetre_menu();

gtk_widget_show(fenetre_menu);
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_quitter_equipement1_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{//quitter gestion_des___quipement_agricoles

GtkWidget *gestion_des___quipement_agricoles;

gestion_des___quipement_agricoles=lookup_widget(objet,"gestion_des___quipement_agricoles");

gtk_widget_destroy(gestion_des___quipement_agricoles);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);

}

//////////////////////////////////////////////////////////////////////////////////
//quitter liste_equipement
void
on_button_quitter_equipement2_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_equipement;

liste_equipement=lookup_widget(objet,"liste_equipement");

gtk_widget_destroy(liste_equipement);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
//liste_equipement ======>> gestion_des___quipement_agricoles
void
on_button_retour_equipement2_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_equipement;
GtkWidget *gestion_des___quipement_agricoles;

liste_equipement=lookup_widget(objet,"liste_equipement");

gtk_widget_destroy(liste_equipement);
gestion_des___quipement_agricoles=create_gestion_des___quipement_agricoles();

gtk_widget_show(gestion_des___quipement_agricoles);
}


//////////////////////////////////////////////////////////////////////////////////
//liste_equipement ======>> fenetre_modifier_equipement
void
on_button_modifier_equipement1_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_equipement;
GtkWidget *fenetre_modifier_equipement;

liste_equipement=lookup_widget(objet,"liste_equipement");

gtk_widget_destroy(liste_equipement);
fenetre_modifier_equipement=create_fenetre_modifier_equipement();

gtk_widget_show(fenetre_modifier_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_afficher_animal ======>> fenetre_modifier_animal
void
on_button_modifier_animal1_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_animal;
GtkWidget *fenetre_modifier_animal;

fenetre_afficher_animal=lookup_widget(objet,"fenetre_afficher_animal");

gtk_widget_destroy(fenetre_afficher_animal);
fenetre_modifier_animal=create_fenetre_modifier_animal();

gtk_widget_show(fenetre_modifier_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_afficher_animal
void
on_button_quitter_animal3_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_animal;

fenetre_afficher_animal=lookup_widget(objet,"fenetre_afficher_animal");

gtk_widget_destroy(fenetre_afficher_animal);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
//ajouter un equipement
void
on_button_ajouter_equipement2_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
Equipement E;
GtkWidget *input1,*input2;
GtkWidget *fenetre_ajouter_equipement;
GtkWidget *nom_equipement;
GtkWidget *marque_equipement;
GtkWidget *modele_equipement;
GtkWidget *transmission_equipement;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortie;
GtkWidget *etat1,*etat2;

fenetre_ajouter_equipement=lookup_widget(objet,"fenetre_ajouter_equipement");
sortie=lookup_widget(objet,"label115");
nom_equipement=lookup_widget(objet,"combobox2");
marque_equipement=lookup_widget(objet,"combobox3");
modele_equipement=lookup_widget(objet,"combobox4");
transmission_equipement=lookup_widget(objet,"combobox5");
jour=lookup_widget(objet,"combobox10");
mois=lookup_widget(objet,"combobox11");
annee=lookup_widget(objet,"combobox12");
etat1=lookup_widget(objet,"radiobutton_etat_ok");
etat2=lookup_widget(objet,"radiobutton_etat_mauvais");
if(etat_equip==1)
{
strcpy(E.etat,"OK");
}
if(etat_equip==2)
{
strcpy(E.etat,"Mauvais");
}

strcpy(E.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nom_equipement)));
strcpy(E.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(marque_equipement)));
strcpy(E.modele,gtk_combo_box_get_active_text(GTK_COMBO_BOX(modele_equipement)));
strcpy(E.transmission,gtk_combo_box_get_active_text(GTK_COMBO_BOX(transmission_equipement)));
strcpy(E.d.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
strcpy(E.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(E.d.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));

input1=lookup_widget(objet,"entry_puissance_equipement");
strcpy(E.puissance,gtk_entry_get_text(GTK_ENTRY(input1)));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Ajout reuissit");

Ajouter_E(E);
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_retour_equipement3_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{//Fenetre ajouter equipement =====>> Fenetre afficher equipement
GtkWidget *fenetre_ajouter_equipement;
GtkWidget *liste_equipement;
GtkWidget *treeview_equipement;

fenetre_ajouter_equipement=lookup_widget(objet,"fenetre_ajouter_equipement");

gtk_widget_destroy(fenetre_ajouter_equipement);
liste_equipement=create_liste_equipement();

gtk_widget_show(liste_equipement);
treeview_equipement=lookup_widget(liste_equipement,"treeview_equipement");

Afficher_E(treeview_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_ajouter_equipement
void
on_button_quitter_equipement3_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_equipement;

fenetre_ajouter_equipement=lookup_widget(objet,"fenetre_ajouter_equipement");

gtk_widget_destroy(fenetre_ajouter_equipement);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


//////////////////////////////////////////////////////////////////////////////////
//fenetre_entretient_equipement ======>> fenetre_modifier_entretient
void
on_button_modifier_equipement2_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_entretient_equipement;
GtkWidget *fenetre_modifier_entretient;

fenetre_entretient_equipement=lookup_widget(objet,"fenetre_entretient_equipement");

gtk_widget_destroy(fenetre_entretient_equipement);
fenetre_modifier_entretient=create_fenetre_modifier_entretient();

gtk_widget_show(fenetre_modifier_entretient);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_entretient_equipement ======>> fenetre_ajouter_date_entretient
void
on_button_ajouter_equipement3_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_entretient_equipement;
GtkWidget *fenetre_ajouter_date_entretient;

fenetre_entretient_equipement=lookup_widget(objet,"fenetre_entretient_equipement");

gtk_widget_destroy(fenetre_entretient_equipement);
fenetre_ajouter_date_entretient=create_fenetre_ajouter_date_entretient();

gtk_widget_show(fenetre_ajouter_date_entretient);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_entretient_equipement ======>> gestion_des___quipement_agricoles
void
on_button_retour_equipement4_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_entretient_equipement;
GtkWidget *gestion_des___quipement_agricoles;

fenetre_entretient_equipement=lookup_widget(objet,"fenetre_entretient_equipement");

gtk_widget_destroy(fenetre_entretient_equipement);
gestion_des___quipement_agricoles=create_gestion_des___quipement_agricoles();

gtk_widget_show(gestion_des___quipement_agricoles);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter dentre_entretient_equipement
void
on_button_quitter_equipement4_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_entretient_equipement;

fenetre_entretient_equipement=lookup_widget(objet,"fenetre_entretient_equipement");

gtk_widget_destroy(fenetre_entretient_equipement);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_ajouter_equipement4_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{//ajouter une date d'entretient
Equipement E;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortie;

identifiant=lookup_widget(objet,"spinbutton5");
jour=lookup_widget(objet,"combobox7");
mois=lookup_widget(objet,"combobox8");
annee=lookup_widget(objet,"combobox9");
sortie=lookup_widget(objet,"label159");

E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
strcpy(E.d.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
strcpy(E.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(E.d.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Ajout réuissite");

Ajouter_ent(E);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_ajouter_date_entretient ======>> fenetre_entretient_equipement
void
on_button_retour_equipement5_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_entretient_equipement;
GtkWidget *fenetre_ajouter_date_entretient;
GtkWidget *treeview_entretient_equipement;

fenetre_ajouter_date_entretient=lookup_widget(objet,"fenetre_ajouter_date_entretient");

gtk_widget_destroy(fenetre_ajouter_date_entretient);
fenetre_entretient_equipement=create_fenetre_entretient_equipement();

gtk_widget_show(fenetre_entretient_equipement);

treeview_entretient_equipement=lookup_widget(fenetre_entretient_equipement,"treeview_entretient_equipement");

Afficher_ent(treeview_entretient_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_ajouter_date_entretient
void
on_button_quitter_equipement5_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_date_entretient;

fenetre_ajouter_date_entretient=lookup_widget(objet,"fenetre_ajouter_date_entretient");

gtk_widget_destroy(fenetre_ajouter_date_entretient);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_menu ======>> fenetre_afficher_animal
void
on_button_gestion_troupeaux_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_menu;
GtkWidget *fenetre_afficher_animal;
GtkWidget *treeview_animal;

fenetre_menu=lookup_widget(objet,"fenetre_menu");

gtk_widget_destroy(fenetre_menu);
fenetre_afficher_animal=create_fenetre_afficher_animal();

gtk_widget_show(fenetre_afficher_animal);

treeview_animal=lookup_widget(fenetre_afficher_animal,"treeview_animal");

Affichage(treeview_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_menu ======>> gestion_des___quipement_agricoles
void
on_button_gestion_equipement_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu;
GtkWidget *gestion_des___quipement_agricoles;

fenetre_menu=lookup_widget(objet,"fenetre_menu");

gtk_widget_destroy(fenetre_menu);
gestion_des___quipement_agricoles=create_gestion_des___quipement_agricoles();

gtk_widget_show(gestion_des___quipement_agricoles);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_menu
void
on_button_quitter_menu_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu;

fenetre_menu=lookup_widget(objet,"fenetre_menu");

gtk_widget_destroy(fenetre_menu);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
//Treeview equipement agricole
void
on_treeview_equipement_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* nom;
	gchar* marque;
	gchar* modele;
	gchar* puissance;
	gchar* transmission;
	gint* identifiant;
	gchar* etat;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	Equipement E;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&identifiant,1,&nom,2,&marque,3,&modele,4,&puissance,5,&transmission,6,&etat,7,&jour,8,&mois,9,&annee,-1);
	strcpy(E.nom,nom);
	strcpy(E.marque,marque);
	strcpy(E.modele,modele);
	strcpy(E.puissance,puissance);
	strcpy(E.transmission,transmission);
	E.identifiant=identifiant;
	strcpy(E.etat,etat);
	strcpy(E.d.jour,jour);
	strcpy(E.d.mois,mois);
	strcpy(E.d.annee,annee);
	Supprimer_E(E);
	Afficher_E(treeview);
	}
}

//////////////////////////////////////////////////////////////////////////////////
//Treeview entretient equipement
void
on_treeview_entretient_equipement_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* identifiant;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	Equipement E;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &identifiant,1,&jour,2,&mois,3,&annee,4,-1);
	E.identifiant=identifiant;
	strcpy(E.d.jour,jour);
	strcpy(E.d.mois,mois);
	strcpy(E.d.annee,annee);
	Supprimer_ent(E);
	Afficher_ent(treeview);
	}
}

//////////////////////////////////////////////////////////////////////////////////
//Treeview animal
void
on_treeview_animal_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* identifiant;
	gchar* type;
	gchar* sexe;
	gint* jour;
	gchar* mois;
	gint* annee;
	Animal A;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&identifiant,1,&type,2,&sexe,3,&jour,4,&mois,5,&annee,-1);
	A.identifiant=identifiant;
	strcpy(A.type,type);
	strcpy(A.sexe,sexe);
	A.d.jour=jour;
	strcpy(A.d.mois,mois);
	A.d.annee=annee;
	Supprimer_A(A);
	Affichage(treeview);
	}
}


void
on_button3_modifier_animal_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
//Modifier un animal
GtkWidget *sortie;
GtkWidget *identifiant1;
GtkWidget *mois;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *sexe;
GtkWidget *type;
Animal A;
identifiant1=lookup_widget(objet,"spinbutton_id_modifier_animal");
A.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant1));
sortie=lookup_widget(objet,"label126");

jour=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");
type=lookup_widget(objet,"entry_type_animal_modifier");
mois=lookup_widget(objet,"entry_mois_animal_modifier");
sexe=lookup_widget(objet,"entry_genre_animal_modifier");

strcpy(A.type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(A.sexe,gtk_entry_get_text(GTK_ENTRY(sexe)));
strcpy(A.d.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
A.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
A.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification réuissie");

Modifier_A(A);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_modifier_animal ======>> fenetre_afficher_animal
void
on_button2_retour_modifier_animal_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_animal;
GtkWidget *fenetre_afficher_animal;
GtkWidget *treeview_animal;

fenetre_modifier_animal=lookup_widget(objet,"fenetre_modifier_animal");

gtk_widget_destroy(fenetre_modifier_animal);
fenetre_afficher_animal=create_fenetre_afficher_animal();

gtk_widget_show(fenetre_afficher_animal);
treeview_animal=lookup_widget(fenetre_afficher_animal,"treeview_animal");

Affichage(treeview_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_modifier_animal
void
on_button4_quitter_modifier_animal_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_animal;

fenetre_modifier_animal=lookup_widget(objet,"fenetre_modifier_animal");

gtk_widget_destroy(fenetre_modifier_animal);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
//modifier un equipement
void
on_button7_modifier_equipement_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{

Equipement E;
GtkWidget *puissance,*identifiant;
GtkWidget *nom_equipement;
GtkWidget *marque_equipement;
GtkWidget *modele_equipement;
GtkWidget *transmission_equipement;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortie;
GtkWidget *etat1,*etat2;

sortie=lookup_widget(objet,"label139");
puissance=lookup_widget(objet,"entry_puissance_equipement_modifier");
strcpy(E.puissance,gtk_entry_get_text(GTK_ENTRY(puissance)));
identifiant=lookup_widget(objet,"spinbutton_id_modifier_equipement");
E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));

nom_equipement=lookup_widget(objet,"entry_nom_equipement_modifier");
marque_equipement=lookup_widget(objet,"entry_marque_equipement_modifier");
modele_equipement=lookup_widget(objet,"entry_modele_equipement_modifier");
transmission_equipement=lookup_widget(objet,"entry_transmission_equipement_modifier");
jour=lookup_widget(objet,"entry_jour_equipement_modifier");
mois=lookup_widget(objet,"entry_mois_equipement_modifier");
annee=lookup_widget(objet,"entry_annee_equipement_modifier");
etat1=lookup_widget(objet,"entry_etat_equipement_modifier");

strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom_equipement)));
strcpy(E.marque,gtk_entry_get_text(GTK_ENTRY(marque_equipement)));
strcpy(E.modele,gtk_entry_get_text(GTK_ENTRY(modele_equipement)));
strcpy(E.transmission,gtk_entry_get_text(GTK_ENTRY(transmission_equipement)));
strcpy(E.d.jour,gtk_entry_get_text(GTK_ENTRY(jour)));
strcpy(E.d.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
strcpy(E.d.annee,gtk_entry_get_text(GTK_ENTRY(annee)));
strcpy(E.etat,gtk_entry_get_text(GTK_ENTRY(etat1)));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification réuissite");

Modifier_E(E);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_modifier_equipement ======>> liste_equipement
void
on_button6_retour_modifier_equipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_equipement;
GtkWidget *liste_equipement;
GtkWidget *treeview_equipement;

fenetre_modifier_equipement=lookup_widget(objet,"fenetre_modifier_equipement");

gtk_widget_destroy(fenetre_modifier_equipement);
liste_equipement=create_liste_equipement();

gtk_widget_show(liste_equipement);
treeview_equipement=lookup_widget(liste_equipement,"treeview_equipement");

Afficher_E(treeview_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_modifier_equipement
void
on_button5_quitter_modifier_equipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_equipement;

fenetre_modifier_equipement=lookup_widget(objet,"fenetre_modifier_equipement");

gtk_widget_destroy(fenetre_modifier_equipement);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button8_modifier_entretient_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
//modifier un entretient 
Equipement E;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortie;

identifiant=lookup_widget(objet,"spinbutton_id_modifier_entretient");

E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
jour=lookup_widget(objet,"entry_jour_entretient_modifier");
mois=lookup_widget(objet,"entry_mois_entretient_modifier");
annee=lookup_widget(objet,"entry_annee_entretient_modifier");
sortie=lookup_widget(objet,"label158");

strcpy(E.d.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
strcpy(E.d.annee,gtk_entry_get_text(GTK_ENTRY(annee)));
strcpy(E.d.jour,gtk_entry_get_text(GTK_ENTRY(jour)));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification réuissite");

Modifier_ent(E);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_modifier_entretient ======>> fenetre_entretient_equipement
void
on_button9_retour_modifier_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_entretient;
GtkWidget *fenetre_entretient_equipement;
GtkWidget *treeview_entretient_equipement;

fenetre_modifier_entretient=lookup_widget(objet,"fenetre_modifier_entretient");

gtk_widget_destroy(fenetre_modifier_entretient);
fenetre_entretient_equipement=create_fenetre_entretient_equipement();

gtk_widget_show(fenetre_entretient_equipement);
treeview_entretient_equipement=lookup_widget(fenetre_entretient_equipement,"treeview_entretient_equipement");

Afficher_ent(treeview_entretient_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_modifier_entretient
void
on_button10_quitter_modifier_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_entretient;

fenetre_modifier_entretient=lookup_widget(objet,"fenetre_modifier_entretient");

gtk_widget_destroy(fenetre_modifier_entretient);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{//Rechercher un equipement
GtkWidget *identifiant;
GtkWidget *sortie;
Equipement E;

identifiant=lookup_widget(objet,"spinbutton8");
E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label184");

int y;
y=verifier_Equip(E);
if(y==1)
{
rechercher_E(E);
GtkWidget *treeview_equipement;
treeview_equipement=lookup_widget(objet,"treeview_equipement");
afficher_E_rechercher(treeview_equipement);
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}

}


//////////////////////////////////////////////////////////////////////////////////
void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{//Rechercher animal
GtkWidget *identifiant;
GtkWidget *sortie;
Animal A;

identifiant=lookup_widget(objet,"spinbutton9");
A.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label185");

int y;
y=verifier(A);
if(y==1)
{
rechercher_A(A);
GtkWidget *treeview_animal;
treeview_animal=lookup_widget(objet,"treeview_animal");
afficher_A_rechercher(treeview_animal);
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{//Rechercher entretient
GtkWidget *identifiant;
GtkWidget *sortie;
Equipement E;

identifiant=lookup_widget(objet,"spinbutton10");
E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label183");

int y;
y=verifier_Ent(E);
if(y==1)
{
rechercher_ent(E);
GtkWidget *treeview_entretient_equipement;
treeview_entretient_equipement=lookup_widget(objet,"treeview_entretient_equipement");
afficher_ent_rechercher(treeview_entretient_equipement);
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}

}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_cheval_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=1;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_mouton_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=2;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_vache_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=3;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_poulet_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=4;
}



//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton10_cheval_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x=1;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton11_mouton_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x=2;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton13_vache_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x=3;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton12_poulet_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x=4;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_verifier_animal_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
//Verifier ID_Animal
GtkWidget *sortie;
GtkWidget *identifiant1;
GtkWidget *mois;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *sexe;
GtkWidget *type;

Animal A;
identifiant1=lookup_widget(objet,"spinbutton_id_modifier_animal");
A.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant1));
sortie=lookup_widget(objet,"label177");

jour=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");
type=lookup_widget(objet,"entry_type_animal_modifier");
mois=lookup_widget(objet,"entry_mois_animal_modifier");
sexe=lookup_widget(objet,"entry_genre_animal_modifier");
int y;
y=verifier(A);
if(y==1)
{
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Existe");

  rechercher_A(A);

  FILE *f;
  f=fopen("animalcher.txt","r");
while(fscanf(f,"%d %s %s %d %s %d\n",&A.identifiant,A.type,A.sexe,&A.d.jour,A.d.mois,&A.d.annee)!=EOF)
	{

  gtk_entry_set_text (GTK_ENTRY(type),A.type);
  gtk_entry_set_text (GTK_ENTRY(sexe),A.sexe);
  gtk_entry_set_text (GTK_ENTRY(mois),A.d.mois);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),A.d.jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),A.d.annee);
	}
  fclose(f);
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_verifier_equipement_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
//Verifier ID_Equipement
GtkWidget *sortie;
GtkWidget *identifiant;
GtkWidget *puissance;
GtkWidget *nom_equipement;
GtkWidget *marque_equipement;
GtkWidget *modele_equipement;
GtkWidget *transmission_equipement;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *etat1;
Equipement E;

identifiant=lookup_widget(objet,"spinbutton_id_modifier_equipement");
E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label179");

nom_equipement=lookup_widget(objet,"entry_nom_equipement_modifier");
marque_equipement=lookup_widget(objet,"entry_marque_equipement_modifier");
modele_equipement=lookup_widget(objet,"entry_modele_equipement_modifier");
transmission_equipement=lookup_widget(objet,"entry_transmission_equipement_modifier");
jour=lookup_widget(objet,"entry_jour_equipement_modifier");
mois=lookup_widget(objet,"entry_mois_equipement_modifier");
annee=lookup_widget(objet,"entry_annee_equipement_modifier");
etat1=lookup_widget(objet,"entry_etat_equipement_modifier");
puissance=lookup_widget(objet,"entry_puissance_equipement_modifier");

rechercher_E(E);

  FILE *f;
  f=fopen("equipementcher.txt","r");
while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&E.identifiant,E.nom,E.marque,E.modele,E.puissance,E.transmission,E.etat,E.d.jour,E.d.mois,E.d.annee)!=EOF)
	{
  gtk_entry_set_text (GTK_ENTRY(nom_equipement),E.nom);
  gtk_entry_set_text (GTK_ENTRY(marque_equipement),E.marque);
  gtk_entry_set_text (GTK_ENTRY(modele_equipement),E.modele);
  gtk_entry_set_text (GTK_ENTRY(transmission_equipement),E.transmission);
  gtk_entry_set_text (GTK_ENTRY(puissance),E.puissance);
  gtk_entry_set_text (GTK_ENTRY(jour),E.d.jour);
  gtk_entry_set_text (GTK_ENTRY(mois),E.d.mois);
  gtk_entry_set_text (GTK_ENTRY(annee),E.d.annee);
  gtk_entry_set_text (GTK_ENTRY(etat1),E.etat);
	}
int y;
y=verifier_Equip(E);
if(y==1)
{
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Existe");
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_id_equipement_pour_ajouter_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{//Verifier ID equipement pour ajouter une date d'entretient
GtkWidget *sortie;
GtkWidget *identifiant;
Equipement E;
identifiant=lookup_widget(objet,"spinbutton5");
E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label190");
int y;
y=verifier_Equip(E);
if(y==1)
{
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Existe");
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button_verifier_entretient_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
//Verifier ID_Entretient
GtkWidget *sortie;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
Equipement E;
identifiant=lookup_widget(objet,"spinbutton_id_modifier_entretient");
E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label181");

jour=lookup_widget(objet,"entry_jour_entretient_modifier");
mois=lookup_widget(objet,"entry_mois_entretient_modifier");
annee=lookup_widget(objet,"entry_annee_entretient_modifier");
int y;
y=verifier_Ent(E);
if(y==1)
{
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Existe");

  rechercher_ent(E);

  FILE *f;
  f=fopen("entretientcher.txt","r");
while(fscanf(f,"%d %s %s %s\n",&E.identifiant,E.d.jour,E.d.mois,E.d.annee)!=EOF)
	{
  gtk_entry_set_text (GTK_ENTRY(mois),E.d.mois);
  gtk_entry_set_text (GTK_ENTRY(annee),E.d.annee);
  gtk_entry_set_text (GTK_ENTRY(jour),E.d.jour);
	}
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_etat_ok_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_equip=1;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton3_ok_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_equip=1;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_etat_mauvais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_equip=2;
}

//////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton4_mauvais_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_equip=4;
}

//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
//fenetre afficher animal ======>> fenetre ajouter animal 
void
on_button_Ajouter_animal123_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_animal;
GtkWidget *fenetre_afficher_animal;

fenetre_afficher_animal=lookup_widget(objet,"fenetre_afficher_animal");

gtk_widget_destroy(fenetre_afficher_animal);
fenetre_ajouter_animal=create_fenetre_ajouter_animal();

gtk_widget_show(fenetre_ajouter_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre afficher equipement ======>> fenetre ajouter equipement 
void
on_button_ajouter_equipement123_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_equipement;
GtkWidget *liste_equipement;

liste_equipement=lookup_widget(objet,"liste_equipement");

gtk_widget_destroy(liste_equipement);
fenetre_ajouter_equipement=create_fenetre_ajouter_equipement();

gtk_widget_show(fenetre_ajouter_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//Reload tableau animal
void
on_button_actualiser_tableau_animal_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_animal;

treeview_animal=lookup_widget(objet,"treeview_animal");

Affichage(treeview_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//Reload tableau equipement
void
on_button_actualiser_tableau_equipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_equipement;

treeview_equipement=lookup_widget(objet,"treeview_equipement");

Afficher_E(treeview_equipement);
}

//////////////////////////////////////////////////////////////////////////////////
//Reload tableau entretient
void
on_button_actualiser_tableau_entretient_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_entretient_equipement;

treeview_entretient_equipement=lookup_widget(objet,"treeview_entretient_equipement");

Afficher_ent(treeview_entretient_equipement);
}


//////////////////////////////////////////////////////////////////////////////////
//Nombre des animaux
void
on_button99_nombre_animal_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *total,*mouton,*cheval,*vache,*poulet;
GtkWidget *tot,*chev,*poul,*mout,*vach;
total=lookup_widget(objet,"label155_nbr_total");
mouton=lookup_widget(objet,"label479_nbr_mouton");
cheval=lookup_widget(objet,"label480_nbr_cheval");
vache=lookup_widget(objet,"label481_nbr_vache");
poulet=lookup_widget(objet,"label482_nbr_poulet");
tot=lookup_widget(objet,"label639");
chev=lookup_widget(objet,"label502");
poul=lookup_widget(objet,"label503");
mout=lookup_widget(objet,"label500");
vach=lookup_widget(objet,"label501");

int nombre_total,nombre_mouton,nombre_cheval,nombre_poulet,nombre_vache;

char nbr_total[10],nbr_mouton[10],nbr_cheval[10],nbr_vache[10],nbr_poulet[10];
char resultat_nbr_total[]="Le nombre total des troupeaux :";
char resultat_nbr_mouton[]="Mouton :";
char resultat_nbr_Vache[]="Vache :";
char resultat_nbr_Chevall[]="Cheval :";
char resultat_nbr_Poulet[]="Poulet :";
GdkColor color;
gdk_color_parse("brown",&color);
gtk_widget_modify_fg(tot,GTK_STATE_NORMAL,&color);
gtk_widget_modify_fg(mout,GTK_STATE_NORMAL,&color);
gtk_widget_modify_fg(vach,GTK_STATE_NORMAL,&color);
gtk_widget_modify_fg(chev,GTK_STATE_NORMAL,&color);
gtk_widget_modify_fg(poul,GTK_STATE_NORMAL,&color);

gtk_label_set_text(GTK_LABEL(tot),resultat_nbr_total);
gtk_label_set_text(GTK_LABEL(mout),resultat_nbr_mouton);
gtk_label_set_text(GTK_LABEL(vach),resultat_nbr_Vache);
gtk_label_set_text(GTK_LABEL(chev),resultat_nbr_Chevall);
gtk_label_set_text(GTK_LABEL(poul),resultat_nbr_Poulet);

nombre_total=Nombre_Animaux1();
sprintf(nbr_total,"%d",nombre_total);
gtk_label_set_text(GTK_LABEL(total),nbr_total);

nombre_mouton=Nombre_mouton();
sprintf(nbr_mouton,"%d",nombre_mouton);
gtk_label_set_text(GTK_LABEL(mouton),nbr_mouton);

nombre_cheval=Nombre_cheval();
sprintf(nbr_cheval,"%d",nombre_cheval);
gtk_label_set_text(GTK_LABEL(cheval),nbr_cheval);

nombre_vache=Nombre_vache();
sprintf(nbr_vache,"%d",nombre_vache);
gtk_label_set_text(GTK_LABEL(vache),nbr_vache);

nombre_poulet=Nombre_poulet();
sprintf(nbr_poulet,"%d",nombre_poulet);
gtk_label_set_text(GTK_LABEL(poulet),nbr_poulet);
}




				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE HIBA + OUMAYMA###############################
				//////////////////////////////////////////////////////////////////////////////////


void
on_enregistrerA_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *type1, *type2, *input2, *input3, *input4, *input5, *sortie;
GtkWidget *ajouter_capteur;
GtkWidget *liste_capteurs;
GtkWidget *treeview1;

ajouter_capteur=lookup_widget(objet,"ajouter_capteur");
type1=lookup_widget(objet,"radiobutton1");
type2=lookup_widget(objet,"radiobutton2");
input2=lookup_widget(objet,"marque");
input3=lookup_widget(objet,"reference");
input4=lookup_widget(objet,"temps_reponse");
input5=lookup_widget(objet,"precision");
sortie=lookup_widget(objet,"label83");



if(type==1)
{
strcpy(c.type_capteur,"Temperature");
}
if(type==2)
{
strcpy(c.type_capteur,"Humidite");
}

strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input2))); 
strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.temps_reponse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.precision,gtk_entry_get_text(GTK_ENTRY(input5)));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Capteur ajouté");
ajout_capteur(c);


}


void
on_retourA_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_capteur;
GtkWidget *liste_capteurs;
GtkWidget *treeview1;

ajouter_capteur=lookup_widget(objet,"ajouter_capteur");

gtk_widget_destroy(ajouter_capteur);
liste_capteurs=lookup_widget(objet,"liste_capteur");
liste_capteurs=create_liste_capteurs();

gtk_widget_show(liste_capteurs);

treeview1=lookup_widget(liste_capteurs,"treeview1");

afficher_capteur(treeview1);

}


void
on_ajouterL_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget  *ajouter_capteur,*liste_capteurs;
liste_capteurs=lookup_widget(objet,"liste_capteurs");

gtk_widget_destroy(liste_capteurs);
ajouter_capteur=lookup_widget(objet,"ajouter_capteur");
ajouter_capteur=create_ajouter_capteur();
gtk_widget_show(ajouter_capteur);


}


void
on_modifierL_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *modifier_capteur,*liste_capteurs;
GtkWidget *treeview1;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;

	gchar* type_capteur;
	gchar* marque;
	gchar* reference;
	gchar* temps_reponse;
	gchar* precision;
Capteur c;
GtkWidget *input1,*input2,*input3,*input4,*input5;

liste_capteurs=lookup_widget(objet,"liste_capteurs");

   treeview1=lookup_widget(liste_capteurs,"treeview1");
   selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &type_capteur,1,&marque,2,&reference,3,&temps_reponse,4,&precision,-1);

	strcpy(c.type_capteur,type_capteur);
	strcpy(c.marque,marque);
	strcpy(c.reference,reference);
	strcpy(c.temps_reponse,temps_reponse);
	strcpy(c.precision,precision);
}

gtk_widget_destroy(liste_capteurs);

modifier_capteur=create_modifier_capteur();
gtk_widget_show(modifier_capteur);
input1=lookup_widget(modifier_capteur,"type_capteur");
input2=lookup_widget(modifier_capteur,"marque");
input3=lookup_widget(modifier_capteur,"reference");
input4=lookup_widget(modifier_capteur,"temps_reponse");
input5=lookup_widget(modifier_capteur,"precision");
gtk_entry_set_text(GTK_ENTRY(input1),c.type_capteur);
gtk_entry_set_text(GTK_ENTRY(input2),c.marque);
gtk_entry_set_text(GTK_ENTRY(input3),c.reference);
gtk_entry_set_text(GTK_ENTRY(input4),c.temps_reponse);
gtk_entry_set_text(GTK_ENTRY(input5),c.precision);



}




void
on_retourL_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *gestion_capteur,*liste_capteurs;
liste_capteurs=lookup_widget(objet,"liste_capteurs");

gtk_widget_destroy(liste_capteurs);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);


}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* type_capteur;
	gchar* marque;
	gchar* reference;
	gchar* temps_reponse;
	gchar* precision ;
	Capteur c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &type_capteur,1,&marque,2,&reference,3,&temps_reponse,4,&precision,-1);
	strcpy(c.type_capteur,type_capteur);
	strcpy(c.marque,marque);
	strcpy(c.reference,reference);
	strcpy(c.temps_reponse,temps_reponse);
	strcpy(c.precision,precision);
	supprimer_capteur(c);
	afficher_capteur(treeview);
	}
}






void
on_liste_capteur_clicked               (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur;
GtkWidget *liste_capteurs;
GtkWidget *treeview1;

gestion_capteur=lookup_widget(objet,"gestion_capteur");

gtk_widget_destroy(gestion_capteur);
liste_capteurs=lookup_widget(objet,"liste_capteur");
liste_capteurs=create_liste_capteurs();

gtk_widget_show(liste_capteurs);

treeview1=lookup_widget(liste_capteurs,"treeview1");

afficher_capteur(treeview1);
}





void
on_capteurH_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *enregistrement;
GtkWidget *fenetre_ajouter_enH;
GtkWidget *treeview3;

enregistrement=lookup_widget(objet,"enregistrement");

gtk_widget_destroy(enregistrement);
fenetre_ajouter_enH=lookup_widget(objet,"fenetre_ajouter_enH");
fenetre_ajouter_enH=create_fenetre_ajouter_enH();

gtk_widget_show(fenetre_ajouter_enH);

treeview3=lookup_widget(fenetre_ajouter_enH,"treeview3");

afficher_enH(treeview3);
}


void
on_capteurT_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *enregistrement;
GtkWidget *fenetre_ajouter_enT;
GtkWidget *treeview4;

enregistrement=lookup_widget(objet,"enregistrement");

gtk_widget_destroy(enregistrement);
fenetre_ajouter_enT=lookup_widget(objet,"fenetre_ajouter_enT");
fenetre_ajouter_enT=create_fenetre_ajouter_enT();

gtk_widget_show(fenetre_ajouter_enT);

treeview4=lookup_widget(fenetre_ajouter_enT,"treeview4");

afficher_enT(treeview4);
}



void
on_retourG_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget  *gestion_capteur,*capteur;
gestion_capteur=lookup_widget(objet,"gestion_capteur");

gtk_widget_destroy(gestion_capteur);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();
gtk_widget_show(capteur);

}


void
on_enregistrement_clicked              (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget  *enregistrement,*capteur;
capteur=lookup_widget(objet,"capteur");

gtk_widget_destroy(capteur);
enregistrement=lookup_widget(objet,"enregistrement");
enregistrement=create_enregistrement();
gtk_widget_show(enregistrement);
}


void
on_gestion_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget  *gestion_capteur,*capteur;
capteur=lookup_widget(objet,"capteur");

gtk_widget_destroy(capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);
}






void
on_dispo_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *ref;
ref=lookup_widget(objet, "combobox2");
FILE *f;
f=fopen("HUMIDITE.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s",c.reference)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(ref),_(c.reference));
    }
 }
}




void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *f_chercher_capteur,*liste_capteurs;
liste_capteurs=lookup_widget(objet,"liste_capteurs");

gtk_widget_destroy(liste_capteurs);
f_chercher_capteur=lookup_widget(objet,"f_chercher_capteur");
f_chercher_capteur=create_f_chercher_capteur();
gtk_widget_show(f_chercher_capteur);





}


void
on_retourMC_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_capteur;
GtkWidget *liste_capteurs;
GtkWidget *treeview1;

modifier_capteur=lookup_widget(objet,"modifier_capteur");

gtk_widget_destroy(modifier_capteur);
liste_capteurs=lookup_widget(objet,"liste_capteur");
liste_capteurs=create_liste_capteurs();

gtk_widget_show(liste_capteurs);

treeview1=lookup_widget(liste_capteurs,"treeview1");

afficher_capteur(treeview1);
}


void
on_enregistrerMC_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{

Capteur c;
GtkWidget *input1, *input2, *input3, *input4, *input5, *sortie;
GtkWidget *modifier_capteur;
GtkWidget *liste_capteurs;
GtkWidget *treeview1;

modifier_capteur=lookup_widget(objet,"modifier_capteur");
input1=lookup_widget(objet,"type_capteur");
input2=lookup_widget(objet,"marque");
input3=lookup_widget(objet,"reference");
input4=lookup_widget(objet,"temps_reponse");
input5=lookup_widget(objet,"precision");
sortie=lookup_widget(objet,"label82");

strcpy(c.type_capteur,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input2))); 
strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.temps_reponse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.precision,gtk_entry_get_text(GTK_ENTRY(input5)));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification traitée");
modif_capteur(c);

}



void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* reference;
gint* jour;
gint* mois;
gint* annee;
gchar* heure;
gint* valeur;
En a;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&reference,1,&jour,2,&mois,3,&annee,4,&heure,5,&valeur,-1);
strcpy(a.reference,reference);
a.d.j=*jour;
a.d.m=*mois;
a.d.an=*annee;
strcpy(a.heure,heure);
a.valeur=*valeur;

//supprimer_reclamation(a);
afficher_enH(treeview);
}

}


void
on_ajouterEH_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_enH, *fenetre_afficher_enH;
fenetre_ajouter_enH=lookup_widget(objet,"fenetre_ajouter_enH");

gtk_widget_destroy(fenetre_ajouter_enH);
fenetre_afficher_enH=create_fenetre_afficher_enH();
gtk_widget_show(fenetre_afficher_enH);
}


void
on_enregistrerEH_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_enH;
En a;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortie;


fenetre_afficher_enH=lookup_widget(objet,"fenetre_afficher_enH");
input1=lookup_widget(objet,"REFERENCE");

jour=lookup_widget(objet,"spinbutton1");
mois=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");

input2=lookup_widget(objet,"HEURE");
sortie=lookup_widget(objet,"label51");
input3=lookup_widget(objet,"VALEUR");


strcpy(a.reference,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
a.d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
a.d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a.d.an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(a.heure,gtk_entry_get_text(GTK_ENTRY(input2)));
a.valeur=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Enregistrement ajoutée");


ajouter_enH(a);
}


void
on_afficherEH_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_enH;
GtkWidget *fenetre_afficher_enH;
GtkWidget *treeview3;

fenetre_afficher_enH=lookup_widget(objet,"fenetre_afficher_enH");

gtk_widget_destroy(fenetre_afficher_enH);
fenetre_ajouter_enH=lookup_widget(objet,"fenetre_ajouter_enH");
fenetre_ajouter_enH=create_fenetre_ajouter_enH();

gtk_widget_show(fenetre_ajouter_enH);

treeview3=lookup_widget(fenetre_ajouter_enH,"treeview3");

afficher_enH(treeview3);
}


void
on_enregistrerET_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_enT;
En a;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortie;


fenetre_afficher_enT=lookup_widget(objet,"fenetre_afficher_enT");
input1=lookup_widget(objet,"REFERENCE");

jour=lookup_widget(objet,"spinbutton7");
mois=lookup_widget(objet,"spinbutton8");
annee=lookup_widget(objet,"spinbutton9");

input2=lookup_widget(objet,"HEURE");
sortie=lookup_widget(objet,"label67");
input3=lookup_widget(objet,"VALEUR");


strcpy(a.reference,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
a.d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
a.d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a.d.an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(a.heure,gtk_entry_get_text(GTK_ENTRY(input2)));
a.valeur=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Enregistrement ajoutée");


ajouter_enT(a);
}


void
on_retourEH_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *enregistrement;
GtkWidget *fenetre_ajouter_enH;

fenetre_ajouter_enH=lookup_widget(objet,"fenetre_ajouter_enH");

gtk_widget_destroy(fenetre_ajouter_enH);
enregistrement=lookup_widget(objet,"enregistrement");
enregistrement=create_enregistrement();

gtk_widget_show(enregistrement);
}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* reference;
gint* jour;
gint* mois;
gint* annee;
gchar* heure;
gint* valeur;
En a;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&reference,1,&jour,2,&mois,3,&annee,4,&heure,5,&valeur,-1);
strcpy(a.reference,reference);
a.d.j=*jour;
a.d.m=*mois;
a.d.an=*annee;
strcpy(a.heure,heure);
a.valeur=*valeur;

//supprimer_reclamation(a);
afficher_enT(treeview);

}
}


void
on_ajouterET_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_enT, *fenetre_afficher_enT;
fenetre_ajouter_enT=lookup_widget(objet,"fenetre_ajouter_enT");

gtk_widget_destroy(fenetre_ajouter_enT);
fenetre_afficher_enT=create_fenetre_afficher_enT();
gtk_widget_show(fenetre_afficher_enT);
}


void
on_retourET_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *enregistrement;
GtkWidget *fenetre_ajouter_enT;

fenetre_ajouter_enT=lookup_widget(objet,"fenetre_ajouter_enT");

gtk_widget_destroy(fenetre_ajouter_enT);
enregistrement=lookup_widget(objet,"enregistrement");
enregistrement=create_enregistrement();

gtk_widget_show(enregistrement);
}


void
on_afficherT_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_enT;
GtkWidget *fenetre_afficher_enT;
GtkWidget *treeview4;

fenetre_afficher_enT=lookup_widget(objet,"fenetre_afficher_enT");

gtk_widget_destroy(fenetre_afficher_enT);
fenetre_ajouter_enT=lookup_widget(objet,"fenetre_ajouter_enT");
fenetre_ajouter_enT=create_fenetre_ajouter_enT();

gtk_widget_show(fenetre_ajouter_enT);

treeview4=lookup_widget(fenetre_ajouter_enT,"treeview4");

afficher_enT(treeview4);
}


void
on_DISPOH_clicked                      (GtkWidget        *objet,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *ref;
ref=lookup_widget(objet, "REFERENCE");
FILE *f;
f=fopen("HUMIDITE.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s",c.reference)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(ref),_(c.reference));
    }
 }
}


void
on_DISPOT_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *ref;
ref=lookup_widget(objet, "REFERENCE");
FILE *f;
f=fopen("TEMPERATURE.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s",c.reference)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(ref),_(c.reference));
    }
 }
}


void
on_retourE_clicked                     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget  *enregistrement,*capteur;
enregistrement=lookup_widget(objet,"enregistrement");

gtk_widget_destroy(enregistrement);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();
gtk_widget_show(capteur);
}


void
on_cher_clicked                        (GtkWidget         *objet,
                                        gpointer         user_data)
{
char ref[20];
Capteur c;
GtkWidget *input1;
GtkWidget *f_chercher_capteur;

f_chercher_capteur=lookup_widget(objet,"f_chercher_capteur");

input1=lookup_widget(objet,"REFERENCE");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));
rechercher_capt(c,ref);
gtk_entry_set_text(GTK_ENTRY(input1),"");

GtkWidget *treeview5;
treeview5=lookup_widget(objet,"treeview5");
afficher_capteurCH(treeview5);
}


void
on_retourCHE_clicked                   (GtkWidget         *objet,
                                        gpointer         user_data)
{
GtkWidget  *f_chercher_capteur,*liste_capteurs;
f_chercher_capteur=lookup_widget(objet,"f_chercher_capteur");

gtk_widget_destroy(f_chercher_capteur);
liste_capteurs=lookup_widget(objet,"liste_capteurs");
liste_capteurs=create_liste_capteurs();
gtk_widget_show(liste_capteurs);
}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* type_capteur;
	gchar* marque;
	gchar* reference;
	gchar* temps_reponse;
	gchar* precision ;
	Capteur c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &type_capteur,1,&marque,2,&reference,3,&temps_reponse,4,&precision,-1);
	strcpy(c.type_capteur,type_capteur);
	strcpy(c.marque,marque);
	strcpy(c.reference,reference);
	strcpy(c.temps_reponse,temps_reponse);
	strcpy(c.precision,precision);
	afficher_capteurCH(treeview);
	}
}


void
on_DISPOCH_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//temperature
type=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//humidite
type=2;
}


void
on_quitterL_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget  *liste_capteurs,*capteur;
liste_capteurs=lookup_widget(objet,"liste_capteurs");

gtk_widget_destroy(liste_capteurs);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();
gtk_widget_show(capteur);
}


void
on_quitterET_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_ajouter_enT,*capteur;
fenetre_ajouter_enT=lookup_widget(objet,"fenetre_ajouter_enT");

gtk_widget_destroy(fenetre_ajouter_enT);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();
gtk_widget_show(capteur);
}


void
on_quitterEH_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_ajouter_enH,*capteur;
fenetre_ajouter_enH=lookup_widget(objet,"fenetre_ajouter_enH");

gtk_widget_destroy(fenetre_ajouter_enH);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();
gtk_widget_show(capteur);
}


void
on_afficher_commande_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *liste_commande;
GtkWidget *treeviewCOM;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);
liste_commande=lookup_widget(objet,"liste_commande");
liste_commande=create_liste_commande();
gtk_widget_show(liste_commande);
treeviewCOM=lookup_widget(liste_commande,"treeviewCOM");

afficher_commande(treeviewCOM);
}


void
on_afficher_reclamation_clicked        (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_liste_des_reclamations;
GtkWidget *treeview_reclamations;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);
fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");
fenetre_liste_des_reclamations=create_fenetre_liste_des_reclamations();

gtk_widget_show(fenetre_liste_des_reclamations);

treeview_reclamations=lookup_widget(fenetre_liste_des_reclamations,"treeview_reclamations");

afficher_reclamation(treeview_reclamations);
}

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

GtkWidget *input1,*input2,*input3,*msg;


input1=lookup_widget(objet_graphique,"spinbutton1");
input2=lookup_widget(objet_graphique,"entry_traitement_reponse");
input3=lookup_widget(objet_graphique,"traite");
msg=lookup_widget(objet_graphique,"label20");
r.identifiant_reclamation=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
if(etat==3)
{
strcpy(r.etat,"Traite");
}

strcpy(r.rep,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy(rep.etat,"oui");


GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(msg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(msg),"Reclamation traité!!");

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
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
RECLAMATION r;
GtkWidget *fenetre_ajouter_reclamation;
GtkWidget *input1,*input2,*input3,*input4,*etat1,*etat2,*sortie;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
fenetre_ajouter_reclamation=lookup_widget(objet,"fenetre_ajouter_reclamation");
input1=lookup_widget(objet,"ID");
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");
input2=lookup_widget(objet,"entry_reclamation_ajoute");
etat1=lookup_widget(objet,"Etat1");
etat2=lookup_widget(objet,"Etat2");
input3=lookup_widget(objet,"entry_reponse_reclamation_ajoute");
sortie=lookup_widget(objet,"label15");
strcpy(r.identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));

r.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
strcpy(r.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
r.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(r.recl,gtk_entry_get_text(GTK_ENTRY(input2)));

if(etat==1)
{
strcpy(r.etat,"Traite");
}
if(etat==2)
{
strcpy(r.etat,"Non_traite");
}

strcpy(r.rep,gtk_entry_get_text(GTK_ENTRY(input3)));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Reclamation ajoutée");

       
ajouter_reclamation(r);
}


void
on_button_retour_ajout_to_liste_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data){
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
on_dispo_id_rechrech_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *id;
id=lookup_widget(objet, "ID");
FILE *f;
f=fopen("client.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s %s %s %s %s %s",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(id),_(c.identifiant));
    }
 }
}


void
on_recherch_recl_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *input;

input=lookup_widget(objet,"ID");

strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
 
rechercher_reclamation(id);

gtk_entry_set_text(GTK_ENTRY(input),"");
GtkWidget *treeview_reclamations;
treeview_reclamations=lookup_widget(objet,"treeview_reclamations");
afficher_reclamation_rechercher(treeview_reclamations);
}


void
on_Etat1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat=1;
}


void
on_Etat2_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat=2;
}


void
on_dispo_id_rec_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *id;
id=lookup_widget(objet, "ID");
FILE *f;
f=fopen("client.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s %s %s %s %s %s",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(id),_(c.identifiant));
    }
 }
}


void
on_refresh_tableau_reclamation_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_reclamations;
treeview_reclamations=lookup_widget(objet,"treeview_reclamations");
afficher_reclamation(treeview_reclamations);

}


void
on_retourDEF_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur;
GtkWidget *capteur_defect;

capteur_defect=lookup_widget(objet,"capteur_defect");

gtk_widget_destroy(capteur_defect);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);
}


void
on_captD_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *gestion_capteur;
GtkWidget *capteur_defect;
GtkWidget *treeview6;
GtkWidget *treeview7;

gestion_capteur=lookup_widget(objet,"gestion_capteur");

gtk_widget_destroy(gestion_capteur);
capteur_defect=lookup_widget(objet,"capteur_defect");
capteur_defect=create_capteur_defect();

gtk_widget_show(capteur_defect);

captALH();
captALT();
treeview6=lookup_widget(capteur_defect,"treeview6");

afficher_captDEFH(treeview6);

treeview7=lookup_widget(capteur_defect,"treeview7");

afficher_captDEFT(treeview7);

}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* reference;
En a;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&reference,-1);
strcpy(a.reference,reference);


}}


void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* reference;
En a;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&reference,-1);
strcpy(a.reference,reference);


}
}


void
on_quitterDEF_clicked                  (GtkWidget        *objet,
                                        gpointer         user_data)
{

GtkWidget *capteur;
GtkWidget *capteur_defect;

capteur_defect=lookup_widget(objet,"capteur_defect");

gtk_widget_destroy(capteur_defect);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();
gtk_widget_show(capteur);
}



void
on_ajouterCL_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{

client c;
GtkWidget *nom1, *prenom1, *adresse1, *tel1, *sexe1, *id1;
GtkWidget *msg;
GtkWidget *fenetre_ajouter_client;

fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");
nom1=lookup_widget(objet,"nom");
prenom1=lookup_widget(objet,"prenom");
adresse1=lookup_widget(objet,"adresse");
tel1=lookup_widget(objet,"tel");
sexe1=lookup_widget(objet,"sexe");
id1=lookup_widget(objet,"identifiant");
msg=lookup_widget(objet,"label255");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));

strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel1)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(msg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(msg),"Ajout client reusssi");
ajouter_client(c);
}


void
on_afficher_client_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client;
GtkWidget *fenetre_afficher_client;
GtkWidget *treeviewCL;

fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");

gtk_widget_destroy(fenetre_ajouter_client);
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");
fenetre_afficher_client=create_fenetre_afficher_client();

gtk_widget_show(fenetre_afficher_client);

treeviewCL=lookup_widget(fenetre_afficher_client,"treeviewCL");

afficher_client(treeviewCL);
}




void
on_DISPO_clicked                       (GtkWidget      *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *id;
id=lookup_widget(objet, "ID");
FILE *f;
f=fopen("client.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s %s %s %s %s %s",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(id),_(c.identifiant));
    }
 }
}


void
on_treeviewCL_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* tel;
	gchar* sexe;
	gchar* adresse;
	gchar* identifiant;
	
	client c;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&nom,1,&prenom,2,&tel,3,&sexe,4,&adresse,5,&identifiant,-1);
	
	strcpy(c.nom,nom);
	strcpy(c.prenom,prenom);
	
	strcpy(c.tel,tel);
	strcpy(c.sexe,sexe);
	strcpy(c.adresse,adresse);
	strcpy(c.identifiant,identifiant);
	supprimer_client(c);
	afficher_client(treeview);
	}
}


void
on_retourCL1_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_afficher_client;

fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

gtk_widget_destroy(fenetre_afficher_client);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_ajouter_client1_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client, *fenetre_afficher_client;
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

gtk_widget_destroy(fenetre_afficher_client);
fenetre_ajouter_client=create_fenetre_ajouter_client();
gtk_widget_show(fenetre_ajouter_client);
}


void
on_client_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewCL;
treeviewCL=lookup_widget(objet,"treeviewCL");
afficher_client(treeviewCL);
}


void
on_valider_modif_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client;
client c;
GtkWidget *input10, *input20, *input30, *input40, *input50, *input60;
GtkWidget *sortie22;


fenetre_modifier_client=lookup_widget(objet,"fenetre_modifier_client");
input10=lookup_widget(objet,"nom1");
input20=lookup_widget(objet,"prenom1");
input40=lookup_widget(objet,"tel1");
input50=lookup_widget(objet,"sexe1");
input30=lookup_widget(objet,"adresse1");
input60=lookup_widget(objet,"identifiant1");
sortie22=lookup_widget(objet,"label364");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input20)));

strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input40)));
strcpy(c.sexe,gtk_entry_get_text(GTK_ENTRY(input50)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input30)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(input60)));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie22,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie22),"client modifié avec succés");

modifier_client(c);

}


void
on_retour_modif_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client, *fenetre_afficher_client;
GtkWidget *treeviewCL;
fenetre_modifier_client=lookup_widget(objet,"fenetre_modifier_client");

gtk_widget_destroy(fenetre_modifier_client);
fenetre_afficher_client=create_fenetre_afficher_client();
gtk_widget_show(fenetre_afficher_client);
treeviewCL=lookup_widget(fenetre_afficher_client,"treeviewCL");

afficher_client(treeviewCL);
}


void
on_rechercher_client_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *input;

input=lookup_widget(objet,"ID");
strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
 
rechercher_client(id);

gtk_entry_set_text(GTK_ENTRY(input),"");
GtkWidget *treeviewCL;
treeviewCL=lookup_widget(objet,"treeviewCL");
afficher_client_rechercher(treeviewCL);
}


void
on_modifier_client_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client, *fenetre_afficher_client;
GtkWidget *treeviewCL;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;

	gchar* nom;
	gchar* prenom;
	gchar* tel;
	gchar* sexe;
	gchar* adresse;
	gchar* identifiant;
	
	client c;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;

fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

   treeviewCL=lookup_widget(fenetre_afficher_client,"treeviewCL");
   selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeviewCL));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom,1,&prenom,2,&tel,3,&sexe,4,&adresse,5,&identifiant,-1);
	
	strcpy(c.nom,nom);
	strcpy(c.prenom,prenom);
	strcpy(c.tel,tel);
	strcpy(c.sexe,sexe);
	strcpy(c.adresse,adresse);
	strcpy(c.identifiant,identifiant);
}

gtk_widget_destroy(fenetre_afficher_client);

fenetre_modifier_client=create_fenetre_modifier_client();
gtk_widget_show(fenetre_modifier_client);
input1=lookup_widget(fenetre_modifier_client,"nom1");
input2=lookup_widget(fenetre_modifier_client,"prenom1");
input3=lookup_widget(fenetre_modifier_client,"tel1");
input4=lookup_widget(fenetre_modifier_client,"sexe1");
input5=lookup_widget(fenetre_modifier_client,"adresse1");
input6=lookup_widget(fenetre_modifier_client,"identifiant1");
input7=lookup_widget(objet,"label364");
gtk_entry_set_text(GTK_ENTRY(input1),c.nom);
gtk_entry_set_text(GTK_ENTRY(input2),c.prenom);
gtk_entry_set_text(GTK_ENTRY(input5),c.tel);
gtk_entry_set_text(GTK_ENTRY(input3),c.sexe);
gtk_entry_set_text(GTK_ENTRY(input4),c.adresse);
gtk_entry_set_text(GTK_ENTRY(input6),c.identifiant);

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(input7,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(input7),"Reclamation ajoutée");

}


void
on_afficher_client1_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_afficher_client;
GtkWidget *treeviewCL;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");
fenetre_afficher_client=create_fenetre_afficher_client();

gtk_widget_show(fenetre_afficher_client);

treeviewCL=lookup_widget(fenetre_afficher_client,"treeviewCL");

afficher_client(treeviewCL);
}


void
on_retourRESCL_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_responsable;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);
fenetre_responsable=lookup_widget(objet,"fenetre_responsable");
fenetre_responsable=create_fenetre_responsable();

gtk_widget_show(fenetre_responsable);
}


void
on_responsable_client_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_responsable;

fenetre_responsable=lookup_widget(objet,"fenetre_responsable");

gtk_widget_destroy(fenetre_responsable);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();

gtk_widget_show(gestion_client);
}


void
on_responsable_qualite_clicked         (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *capteur;
GtkWidget *fenetre_responsable;

fenetre_responsable=lookup_widget(objet,"fenetre_responsable");

gtk_widget_destroy(fenetre_responsable);
capteur=lookup_widget(objet,"capteur");
capteur=create_capteur();

gtk_widget_show(capteur);
}


void
on_exitAC_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_ajouter_client;

fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");

gtk_widget_destroy(fenetre_ajouter_client);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_exitREC_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_afficher_reclamation;

fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");

gtk_widget_destroy(fenetre_afficher_reclamation);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_treeviewCOM_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* catalogue;
	gchar* nom;
	gchar* quantite;
	gchar* prix;
	gchar* reference ;
	gchar* identifiant ;
	Commande c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &catalogue,1,&nom,2,&quantite,3,&prix,4,&reference,5,&identifiant,-1);
	strcpy(c.ca.type,catalogue);
	strcpy(c.ca.nom,nom);
	strcpy(c.quantite,quantite);
	strcpy(c.prix,prix);
	strcpy(c.reference,reference);
	strcpy(c.identifiant,identifiant);
	afficher_commande(treeview);
	}
}


void
on_retourLCOM_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *liste_commande;

liste_commande=lookup_widget(objet,"liste_commande");

gtk_widget_destroy(liste_commande);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_ajouterLCOM_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoute_commande;
GtkWidget *liste_commande;

liste_commande=lookup_widget(objet,"liste_commande");

gtk_widget_destroy(liste_commande);
ajoute_commande=lookup_widget(objet,"ajoute_commande");
ajoute_commande=create_ajoute_commande();
gtk_widget_show(ajoute_commande);
}


void
on_retourACOM_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewCOM;
GtkWidget  *ajoute_commande,*liste_commande;
ajoute_commande=lookup_widget(objet,"ajoute_commande");

gtk_widget_destroy(ajoute_commande);
liste_commande=lookup_widget(objet,"liste_commande");
liste_commande=create_liste_commande();
gtk_widget_show(liste_commande);

treeviewCOM=lookup_widget(liste_commande,"treeviewCOM");

afficher_commande(treeviewCOM);
}


void
on_enregistrerACOM_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
Commande c;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *ajoute_commande;
GtkWidget *liste_commande;
GtkWidget *treeviewCOM;

ajoute_commande=lookup_widget(objet,"ajoute_commande");
input1=lookup_widget(objet,"CATALOGUE");

input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"quantite");
input4=lookup_widget(objet,"prix");
input5=lookup_widget(objet,"reference");
input6=lookup_widget(objet,"ID");

strcpy(c.ca.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(c.ca.nom,gtk_entry_get_text(GTK_ENTRY(input2))); 
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
ajout_commande(c);
}


void
on_exitACOM_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *ajoute_commande;

ajoute_commande=lookup_widget(objet,"ajoute_commande");

gtk_widget_destroy(ajoute_commande);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_exitCOM_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *liste_commande;

liste_commande=lookup_widget(objet,"liste_commande");

gtk_widget_destroy(liste_commande);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_dispoCOM_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *id;
id=lookup_widget(objet, "ID");
FILE *f;
f=fopen("client.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s %s %s %s %s %s",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(id),_(c.identifiant));
    }
 }
}


void
on_REFRECH_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet,"treeview1");
afficher_capteur(treeview1);
}


void
on_nbree_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
char nbr_T[20];
char nbr_H[20];
int nbr1,nbr2;
GtkWidget *s1, *s2;
En a;
s2=lookup_widget(objet,"sortie2");
nbr2=nbr_alT();
sprintf(nbr_T,"%d",nbr2);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(s2,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(s2),nbr_T);
s1=lookup_widget(objet,"sortie1");
nbr1=nbr_alH();
sprintf(nbr_H,"%d",nbr1);
gtk_widget_modify_fg(s1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(s1),nbr_H);
}


void
on_exit_client_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_exit_ajt_recl_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

}



void
on_button1_retour_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_liste_des_reclamations;
GtkWidget *treeview_reclamations;

fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");

gtk_widget_destroy(fenetre_liste_des_reclamations);
gestion_client=lookup_widget(objet,"gestion_client");
gestion_client=create_gestion_client();

gtk_widget_show(gestion_client);
}

				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE DALY//###############################
				//////////////////////////////////////////////////////////////////////////////////


//button qui ouvre la fenetre ajouter ouvrier
void
on_button1_ajouter_ouvrier_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_fiche_information_ajout;
GtkWidget *treeview;

treeview=lookup_widget(objet,"treeview");

gtk_widget_destroy(treeview);
fenetre_fiche_information_ajout=create_fenetre_fiche_information_ajout();

gtk_widget_show(fenetre_fiche_information_ajout);
}

//button qui ouvre la fenêtre modifier
void
on_button2_modifier_ouvrier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_informations,*treeview;
GtkWidget *treeview1;


GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;

	gint* id;
	gchar* nom;
	gchar* prenom;
	gchar* sexe;
	gint* jour;
	gchar* mois;
	gint* annee;
	gchar* cin;
	gchar* telephone;
	gchar* adresse;
	
	
	
Ouvrier p;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*jour1,*annee1,*input7,*input8;

treeview=lookup_widget(objet,"treeview");

	treeview1=lookup_widget(treeview,"treeview1_ouvrier");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));
if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &id,1,&nom,2,&prenom,3,&sexe,4,&jour,5,&mois,6,&annee,7,&cin,8,&telephone,9,&adresse,-1);


	p.id=id;
	strcpy(p.nom,nom);
	strcpy(p.prenom,prenom);
	strcpy(p.sexe,sexe);
	p.d.jour=jour;
	strcpy(p.d.mois,mois);
	p.d.annee=annee;
	strcpy(p.cin,cin);
	strcpy(p.telephone,telephone);
	strcpy(p.adresse,adresse);
	
	
}

gtk_widget_destroy(treeview);

fenetre_modifier_informations=create_fenetre_modifier_informations();
gtk_widget_show(fenetre_modifier_informations);

input1=lookup_widget(fenetre_modifier_informations,"id1");
input2=lookup_widget(fenetre_modifier_informations,"nom1");
input3=lookup_widget(fenetre_modifier_informations,"prenom1");
input4=lookup_widget(fenetre_modifier_informations,"sexe1");
jour=lookup_widget(fenetre_modifier_informations,"jour1");
input5=lookup_widget(fenetre_modifier_informations,"mois1");
annee=lookup_widget(fenetre_modifier_informations,"annee1");
input6=lookup_widget(fenetre_modifier_informations,"cin1");
input7=lookup_widget(fenetre_modifier_informations,"tel1");
input8=lookup_widget(fenetre_modifier_informations,"adresse1");




gtk_spin_button_set_value(GTK_SPIN_BUTTON(input1),p.id);
gtk_entry_set_text(GTK_ENTRY(input2),p.nom);
gtk_entry_set_text(GTK_ENTRY(input3),p.prenom);
gtk_entry_set_text(GTK_ENTRY(input4),p.sexe);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),p.d.jour);
gtk_entry_set_text(GTK_ENTRY(input5),p.d.mois);	
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),p.d.annee);
gtk_entry_set_text(GTK_ENTRY(input6),p.cin);
gtk_entry_set_text(GTK_ENTRY(input7),p.telephone);
gtk_entry_set_text(GTK_ENTRY(input8),p.adresse);


}


//button retour du treeview des ouvriers au menu responsable
void
on_button4_retour_to_initial_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_responsable_ouvrier;
GtkWidget *treeview;

treeview=lookup_widget(objet,"treeview");

gtk_widget_destroy(treeview);
fenetre_responsable_ouvrier=create_fenetre_responsable_ouvrier();

gtk_widget_show(fenetre_responsable_ouvrier);
}

/// button pour rechercher ouvrier
void
on_button14_chercher_ouvrier_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
GtkWidget *identifiant;
Ouvrier p;

identifiant=lookup_widget(objet,"spinbutton6");
p.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));

rechercher_ouvrier(p);

GtkWidget *treeview1;
treeview1=lookup_widget(objet,"treeview1_ouvrier");
afficher_ouvrier_rechercher(treeview1);
}


void
on_button5_retour_to_treeview_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *fenetre_fiche_information_ajout;
GtkWidget *treeview1;


fenetre_fiche_information_ajout=lookup_widget(objet,"fenetre_fiche_information_ajout");

gtk_widget_destroy(fenetre_fiche_information_ajout);
treeview=create_treeview();

gtk_widget_show(treeview);
treeview1=lookup_widget(treeview,"treeview1_ouvrier");

afficher_ouvrier(treeview1);
}

//button pour ajouter un ouvrier après avoir remplir le formulaire
void
on_button6_enregistrer_ouvrier_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
Ouvrier p;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *label;
GtkWidget *fenetre_fiche_information_ajout;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *homme;
GtkWidget *femme;



homme=lookup_widget(objet,"radiobutton1");
femme=lookup_widget(objet,"radiobutton2");
if(radio==2){
strcpy(p.sexe,"femme");
}
if(radio==1){
strcpy(p.sexe,"homme");
}
label=lookup_widget(objet,"sortie");
input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"prenom");
input3=lookup_widget(objet,"combobox3");
input4=lookup_widget(objet,"cin");
input5=lookup_widget(objet,"tel");
input6=lookup_widget(objet,"adresse");
jour=lookup_widget(objet,"jour");
annee=lookup_widget(objet,"annee");

strcpy(p.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
p.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.telephone,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));


Ajouter(p);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(label,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(label),"Ouvrier ajouté avec succès");
}


void
on_button7_retour_to_treeview_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *fenetre_modifier_informations;
GtkWidget *treeview1;


fenetre_modifier_informations=lookup_widget(objet,"fenetre_modifier_informations");

gtk_widget_destroy(fenetre_modifier_informations);
treeview=create_treeview();

gtk_widget_show(treeview);

treeview1=lookup_widget(treeview,"treeview1_ouvrier");

afficher_ouvrier(treeview1);
}


//button pour ajouter une absence
void
on_button9_ajouter_absence_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{

Absence p;
GtkWidget *fenetre_ajouter_absence;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *ID;
GtkWidget *raison;
GtkWidget *label;

label=lookup_widget(objet,"sortie2");
ID=lookup_widget(objet,"combobox6");
raison=lookup_widget(objet,"raison");
mois=lookup_widget(objet,"combobox4");
jour=lookup_widget(objet,"spinbutton4_abs");
annee=lookup_widget(objet,"spinbutton6_abs");

strcpy(p.da.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
p.ID=atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(ID)));

strcpy(p.raison,gtk_entry_get_text(GTK_ENTRY(raison)));
p.da.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.da.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

Ajouter_absence(p);

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(label,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(label),"Absence ajoutée avec succès");
}


//button pour retourner du fenetre ajouter une absence au treeview des absence
void
on_button10_retour_to_treeview_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_abs;
GtkWidget *fenetre_ajouter_absence;
GtkWidget *treeview2;


fenetre_ajouter_absence=lookup_widget(objet,"fenetre_ajouter_absence");

gtk_widget_destroy(fenetre_ajouter_absence);
treeview_abs=create_treeview_abs();

gtk_widget_show(treeview_abs);
treeview2=lookup_widget(treeview_abs,"treeview2");

afficher_absence(treeview2);
}

//button dans la fenetre responsable qui mêne au treeview des ouvriers
void
on_button11_gestion_ouvrier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *treeview;
GtkWidget *fenetre_responsable_ouvrier;

fenetre_responsable_ouvrier=lookup_widget(objet,"fenetre_responsable_ouvrier");

gtk_widget_destroy(fenetre_responsable_ouvrier);
treeview=create_treeview();

gtk_widget_show(treeview);
treeview1=lookup_widget(treeview,"treeview1_ouvrier");

afficher_ouvrier(treeview1);
}

//button du responsable ouvrier qui mêne au gestion des absences
void
on_button_gestion_absence_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
GtkWidget *treeview_abs;
GtkWidget *fenetre_responsable_ouvrier;

fenetre_responsable_ouvrier=lookup_widget(objet,"fenetre_responsable_ouvrier");

gtk_widget_destroy(fenetre_responsable_ouvrier);
treeview_abs=create_treeview_abs();

gtk_widget_show(treeview_abs);
treeview2=lookup_widget(treeview_abs,"treeview2");

afficher_absence(treeview2); 
}

//button de treeview pour aller à ajouter une absence
void
on_button_ajouter_absence_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_absence;
GtkWidget *treeview_abs;

treeview_abs=lookup_widget(objet,"treeview_abs");

gtk_widget_destroy(treeview_abs);
fenetre_ajouter_absence=create_fenetre_ajouter_absence();

gtk_widget_show(fenetre_ajouter_absence);

}

//button retour au treeview des abs
void
on_button_retour_to_gestion_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_responsable_ouvrier;
GtkWidget *treeview_abs;

treeview_abs=lookup_widget(objet,"treeview_abs");

gtk_widget_destroy(treeview_abs);
fenetre_responsable_ouvrier=create_fenetre_responsable_ouvrier();

gtk_widget_show(fenetre_responsable_ouvrier);

}

//treeview des abs
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gint* id;
gint* jour;
gchar* mois;
gint* annee;
gchar* raison;
Absence p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&jour,2,&mois,3,&annee,4,&raison,-1);
p.ID=id;
p.da.jour=jour;

strcpy(p.da.mois,mois);
p.da.annee=annee;
strcpy(p.raison,raison);
supprimer_absence(p);
afficher_absence(treeview);
}


}

//button pour enregistrer les modifications d'un ouvrier
void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

Ouvrier p;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;
GtkWidget *fenetre_modifier_informations;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *label;

label=lookup_widget(objet,"sortie1");
input1=lookup_widget(objet,"id1");
input2=lookup_widget(objet,"nom1");
input3=lookup_widget(objet,"prenom1");
input4=lookup_widget(objet,"sexe1");
jour=lookup_widget(objet,"jour1");
input5=lookup_widget(objet,"mois1");
annee=lookup_widget(objet,"annee1");
input6=lookup_widget(objet,"cin1");
input7=lookup_widget(objet,"tel1");
input8=lookup_widget(objet,"adresse1");




p.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
p.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
strcpy(p.d.mois,gtk_entry_get_text(GTK_ENTRY(input5)));

p.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.telephone,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input8)));


Modifier(p);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(label,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(label),"Ouvrier modifié avec succès");

}

//button de retour du fenêtre modifier un ouvrier au treeview des ouvriers
void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *fenetre_modifier_informations;
GtkWidget *treeview1;


fenetre_modifier_informations=lookup_widget(objet,"fenetre_modifier_informations");

gtk_widget_destroy(fenetre_modifier_informations);
treeview=create_treeview();

gtk_widget_show(treeview);
treeview1=lookup_widget(treeview,"treeview1_ouvrier");

afficher_ouvrier(treeview1);

}

//button refresh pour afficher la liste des ID
void
on_button6_refresh_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[30];
Ouvrier p;
GtkWidget *no;
no=lookup_widget(objet, "combobox6");
FILE *f;
f=fopen("utilisateur.txt","r");
if (f!=NULL)
 {
	while(fscanf(f," %s %s %s %s %d %s %d %s %s %s \n",id,p.nom,p.prenom,p.sexe,&p.d.jour,p.d.mois,&p.d.annee,p.cin,p.telephone,p.adresse)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(no),_(id));
    }
 }
}



void
on_radiobutton1_homme_ouvrier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=1;
}


void
on_radiobutton2_femme_ouvrier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=2;
}


//treeview ouvrier
void
on_treeview1_ouvrier_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gint* id;
gchar* nom;
gchar* prenom;
gchar* sexe;
gint* jour;
gchar* mois;
gint* annee;
gchar* telephone;
gchar* cin;
gchar* adresse;
Ouvrier p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &id,1,&nom,2,&prenom,3,&sexe,4,&jour,5,&mois,6,&annee,7,&cin,8,&telephone,9,&adresse,-1);
p.id=id;
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.sexe,sexe);
p.d.jour=jour;

strcpy(p.d.mois,mois);
p.d.annee=annee;
strcpy(p.cin,cin);
strcpy(p.telephone,telephone);
strcpy(p.adresse,adresse);
supprimer_ouvrier(p);
afficher_ouvrier(treeview);
}


}


void
on_taux_abs_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *sortie;
GtkWidget *taux;
float tx;
char Taux_abs[50];
sortie=lookup_widget(objet,"label_taux_abs");
tx=CalculeTaux();
sprintf(Taux_abs,"Le taux d'absentéisme est : %.1f%%",tx);
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),Taux_abs);

}

//reloed tableau des ouvrier
void
on_button68_refresh_treeview_ouvrier_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1_ouvrier;

treeview1_ouvrier=lookup_widget(objet,"treeview1_ouvrier");

afficher_ouvrier(treeview1_ouvrier);
}

//reloed tableau des absences
void
on_button69_refresh_treeview_absences_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2;

treeview2=lookup_widget(objet,"treeview2");

afficher_absence(treeview2);
}


void
on_button73_quitter_ajouter_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_capteur;

ajouter_capteur=lookup_widget(objet,"ajouter_capteur");

gtk_widget_destroy(ajouter_capteur);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button74_quitter_liste_capteurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_capteurs;

liste_capteurs=lookup_widget(objet,"liste_capteurs");

gtk_widget_destroy(liste_capteurs);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button75_quitter_gestion_capteurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteurs;

gestion_capteurs=lookup_widget(objet,"gestion_capteurs");

gtk_widget_destroy(gestion_capteurs);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button76_quitter_enregistrement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *enregistremen;

enregistremen=lookup_widget(objet,"enregistremen");

gtk_widget_destroy(enregistremen);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button77_quitter_capteur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *capteur;

capteur=lookup_widget(objet,"capteur");

gtk_widget_destroy(capteur);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button78_quitter_modifier_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_capteur;

modifier_capteur=lookup_widget(objet,"modifier_capteur");

gtk_widget_destroy(modifier_capteur);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button79_quitter_fenetre_ajouter_enH_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_enH;

fenetre_ajouter_enH=lookup_widget(objet,"fenetre_ajouter_enH");

gtk_widget_destroy(fenetre_ajouter_enH);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button80_quitter_fenetre_afficher_enH_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_enH;

fenetre_afficher_enH=lookup_widget(objet,"fenetre_afficher_enH");

gtk_widget_destroy(fenetre_afficher_enH);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button82_quitter_fenetre_afficher_enT_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_enT;

fenetre_afficher_enT=lookup_widget(objet,"fenetre_afficher_enT");

gtk_widget_destroy(fenetre_afficher_enT);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button81_quitter_ajouter_enT_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_enT;

fenetre_ajouter_enT=lookup_widget(objet,"fenetre_ajouter_enT");

gtk_widget_destroy(fenetre_ajouter_enT);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button83_quitter_f_chercher_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *f_chercher_capteur;

f_chercher_capteur=lookup_widget(objet,"f_chercher_capteur");

gtk_widget_destroy(f_chercher_capteur);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button84_quitter_gestion_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button85_quitter_capteur_defect_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *capteur_defect;

capteur_defect=lookup_widget(objet,"capteur_defect");

gtk_widget_destroy(capteur_defect);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button86_quitter_fenetre_ajouter_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client;

fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");

gtk_widget_destroy(fenetre_ajouter_client);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button87_quitter_fenetre_afficher_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_client;

fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

gtk_widget_destroy(fenetre_afficher_client);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button88_quitter_fenetre_modifier_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client;

fenetre_modifier_client=lookup_widget(objet,"fenetre_modifier_client");

gtk_widget_destroy(fenetre_modifier_client);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button89_quitter_fenetre_ajouter_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation;

fenetre_ajouter_reclamation=lookup_widget(objet,"fenetre_ajouter_reclamation");

gtk_widget_destroy(fenetre_ajouter_reclamation);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button90_quitter_fenetre_responsable_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_responsable;

fenetre_responsable=lookup_widget(objet,"fenetre_responsable");

gtk_widget_destroy(fenetre_responsable);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button91_quitter_liste_commande_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *liste_commande;

liste_commande=lookup_widget(objet,"liste_commande");

gtk_widget_destroy(liste_commande);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button92_quitter_ajoute_commande_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoute_commande;

ajoute_commande=lookup_widget(objet,"ajoute_commande");

gtk_widget_destroy(ajoute_commande);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button93_quitter_treeview_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(objet,"treeview");

gtk_widget_destroy(treeview);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button94_quitter_fenetre_fiche_information_ajout_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_fiche_information_ajout;

fenetre_fiche_information_ajout=lookup_widget(objet,"fenetre_fiche_information_ajout");

gtk_widget_destroy(fenetre_fiche_information_ajout);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button95_quitter_fenetre_ajouter_absence_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_absence;

fenetre_ajouter_absence=lookup_widget(objet,"fenetre_ajouter_absence");

gtk_widget_destroy(fenetre_ajouter_absence);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button96_quitter_fenetre_responsable_ouvrier_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_responsable_ouvrier;

fenetre_responsable_ouvrier=lookup_widget(objet,"fenetre_responsable_ouvrier");

gtk_widget_destroy(fenetre_responsable_ouvrier);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button97_quitter_treeview_abs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_abs;

treeview_abs=lookup_widget(objet,"treeview_abs");

gtk_widget_destroy(treeview_abs);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button98_quitter_fenetre_modifier_informations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_informations;

fenetre_modifier_informations=lookup_widget(objet,"fenetre_modifier_informations");

gtk_widget_destroy(fenetre_modifier_informations);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


//boutton connexion avec une compte pour ouvrir l'application
void
on_button70_connexion_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cin,*passeword,*resultat;
GtkWidget *fenetre_afficher_animal;
GtkWidget *gestion_des___quipement_agricoles;
GtkWidget *capteur;
GtkWidget *gestion_client;
GtkWidget *fenetre_responsable_ouvrier;
GtkWidget *fenetre_liste_des_employees;
GtkWidget *fenetre_menu;
GtkWidget *Espace_responsable_de_production;
employe E;
char mot_de_passe[30];
char cin1[30];
int verif_cin_inscrit,verif_passeword_inscrit,verif_accee_inscrit;
resultat=lookup_widget(objet,"label409");
cin=lookup_widget(objet,"entry1_cin_login");
passeword=lookup_widget(objet,"entry2_mot_de_passe_login");

strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(mot_de_passe,gtk_entry_get_text(GTK_ENTRY(passeword)));

verif_cin_inscrit=verifier_CIN_inscrit(cin1);
verif_passeword_inscrit=verifier_PASSEWORD_inscrit(mot_de_passe);
verif_accee_inscrit=verifier_ACCEE_inscrit(cin1);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(resultat,GTK_STATE_NORMAL,&color);
if(verif_passeword_inscrit==8)
gtk_label_set_text(GTK_LABEL(resultat),"Mot de passe incorrecte");
if(verif_cin_inscrit==0)
gtk_label_set_text(GTK_LABEL(resultat),"CIN n'éxiste pas");
if(verif_cin_inscrit==1)
{
	if(verif_passeword_inscrit==0)
	{
	GtkWidget *fenetre_afficher_animal;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	fenetre_menu=create_fenetre_menu();
	gtk_widget_show(fenetre_menu);
	}

	if(verif_passeword_inscrit==1)
	{
		if(verif_accee_inscrit==1)
		{
	GtkWidget *fenetre_afficher_animal;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	fenetre_afficher_animal=create_fenetre_afficher_animal();
	gtk_widget_show(fenetre_afficher_animal);
	GtkWidget *treeview_animal;
	treeview_animal=lookup_widget(fenetre_afficher_animal,"treeview_animal");
	Affichage(treeview_animal);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

	if(verif_passeword_inscrit==2)
	{
		if(verif_accee_inscrit==2)
		{
	GtkWidget *fenetre_afficher_animal;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	fenetre_responsable_ouvrier=create_fenetre_responsable_ouvrier();
	gtk_widget_show(fenetre_responsable_ouvrier);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

	if(verif_passeword_inscrit==3)
	{
		if(verif_accee_inscrit==3)
		{
	GtkWidget *fenetre_afficher_animal;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	gestion_des___quipement_agricoles=create_gestion_des___quipement_agricoles();
	gtk_widget_show(gestion_des___quipement_agricoles);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

	if(verif_passeword_inscrit==4)
	{
		if(verif_accee_inscrit==4)
		{
	GtkWidget *fenetre_afficher_animal;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	gestion_client=create_gestion_client();
	gtk_widget_show(gestion_client);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

	if(verif_passeword_inscrit==5)
	{
		if(verif_accee_inscrit==5)
		{
	//GtkWidget *fenetre_afficher_animal;
	GtkWidget *fenetre_login_principale;
	GtkWidget *fenetre_choix;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	fenetre_choix=create_fenetre_choix();
	gtk_widget_show(fenetre_choix);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

	if(verif_passeword_inscrit==6)
	{
		if(verif_accee_inscrit==6)
		{
	GtkWidget *capteur;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	capteur=create_capteur();
	gtk_widget_show(capteur);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

	if(verif_passeword_inscrit==7)
	{
		if(verif_accee_inscrit==7)
		{
	GtkWidget *fenetre_liste_des_employees;
	GtkWidget *fenetre_login_principale;
	fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
	gtk_widget_destroy(fenetre_login_principale);
	fenetre_liste_des_employees=create_fenetre_liste_des_employees();
	gtk_widget_show(fenetre_liste_des_employees);
	GtkWidget *treeview_employees;
	treeview_employees=lookup_widget(fenetre_liste_des_employees,"treeview_employees");
	afficher_employe(treeview_employees);
		}
		else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

}
}
/////////////////////////////*******************OUMAYMA*********************//////////////////////////////////////////


void
on_dispo_rech_com_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *id;
id=lookup_widget(objet, "ID");
FILE *f;
f=fopen("client.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s %s %s %s %s %s",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(id),_(c.identifiant));
    }
 }
}


void
on_rech_com_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[20];
Commande c;
GtkWidget *input1;
GtkWidget *liste_commande;

liste_commande=lookup_widget(objet,"liste_commande");

input1=lookup_widget(objet,"ID");
strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
rechercher_commande(c,id);
gtk_entry_set_text(GTK_ENTRY(input1),"");

GtkWidget *treeviewCOM;
treeviewCOM=lookup_widget(objet,"treeviewCOM");
afficher_commandeCH(treeviewCOM);
}



				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE TOUIHRI//###############################
				//////////////////////////////////////////////////////////////////////////////////

//bouton meilleur ouvrier 
void
on_button68_meilleur_ouvrier_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
Ouvrier p;

rechercher_meilleur_ouvrier(p);

GtkWidget *treeview1_ouvrier;
treeview1_ouvrier=lookup_widget(objet,"treeview1_ouvrier");
afficher_meilleur_ouvrier(treeview1_ouvrier);

remove("listeabs.txt");
remove("meilleurouvrier.txt");
}

GtkTreeSelection *selection1;

void
on_button_retour_to_gestion_des_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_gestion_des_employees;
GtkWidget *fenetre_liste_des_employees;

fenetre_liste_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");
gtk_widget_destroy(fenetre_liste_des_employees);
fenetre_gestion_des_employees=create_fenetre_gestion_des_employees();
gtk_widget_show(fenetre_gestion_des_employees);
}




void
on_button_rechercher_employe_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{

employe E;
GtkWidget *input11;
GtkWidget *nonexiste;

input11=lookup_widget(objet,"entry1_rech");
nonexiste=lookup_widget(objet,"label_cin_non_existant");


strcpy(E.cin,gtk_entry_get_text(GTK_ENTRY(input11)));

if (exist_cin(E.cin)==0)
{ 
    gtk_label_set_text(GTK_LABEL(nonexiste),"CIN non existant");
}
else 
{
    gtk_label_set_text(GTK_LABEL(nonexiste),"");
}

rechercher_employe(E);
 


gtk_entry_set_text(GTK_ENTRY(input11),"");
GtkWidget *treeview_employees;
treeview_employees=lookup_widget(objet,"treeview_employees");
afficher_emp_rechercher(treeview_employees);


}


void
on_button_retour_to_liste_des_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_employees;
GtkWidget *fenetre_ajouter_employe;
GtkWidget *treeview_employees;

fenetre_ajouter_employe=lookup_widget(objet,"fenetre_ajouter_employe");
gtk_widget_destroy(fenetre_ajouter_employe);
fenetre_liste_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");
fenetre_liste_des_employees=create_fenetre_liste_des_employees();
gtk_widget_show(fenetre_liste_des_employees);
treeview_employees=lookup_widget(fenetre_liste_des_employees,"treeview_employees");
afficher_employe(treeview_employees);
}


void
on_button_valider_ajout_employe_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
employe E;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
GtkWidget* success;
GtkWidget *fenetre_ajouter_employe;

input1=lookup_widget(objet_graphique,"entry_nom_ajout_employe");
input2=lookup_widget(objet_graphique,"entry_prenom_ajout_employe");
input3=lookup_widget(objet_graphique,"entry_cin_ajout_employe");

input4=lookup_widget(objet_graphique, "spinbutton_jour_naissance_ajout_employe");
input5=lookup_widget(objet_graphique, "spinbutton_mois_naissance_ajout_employe");
input6=lookup_widget(objet_graphique, "spinbutton_annee_naissance_ajout_employe");

input7=lookup_widget(objet_graphique,"entry_numero_ajout_employe");
input8=lookup_widget(objet_graphique,"entry_adresse_ajout_employe");

input9=lookup_widget(objet_graphique,"combobox_poste_ajout_employe");

input10=lookup_widget(objet_graphique,"radiobutton_homme_ajout_employe");
input11=lookup_widget(objet_graphique,"radiobutton_femme_ajout_employe");

success=lookup_widget(objet_graphique,"label80_resultat");


if(x==1)
{
strcpy(E.sexe,"homme");
}
if(x==2)
{
strcpy(E.sexe,"femme");
}

strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E.cin,gtk_entry_get_text(GTK_ENTRY(input3)));

E.date_naissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input4));
E.date_naissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input5));
E.date_naissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input6));

strcpy(E.numero,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(E.adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

strcpy(E.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input9)));

gtk_label_set_text(GTK_LABEL(success),"Ajout réuissite");      
ajouter_employe(E);

}




void
on_button_retour2_to_liste_des_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_employees;
GtkWidget *fenetre_modifier_employe;
GtkWidget *treeview_employees;

fenetre_modifier_employe=lookup_widget(objet,"fenetre_modifier_employe");
gtk_widget_destroy(fenetre_modifier_employe);
fenetre_liste_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");
fenetre_liste_des_employees=create_fenetre_liste_des_employees();
gtk_widget_show(fenetre_liste_des_employees);
treeview_employees=lookup_widget(fenetre_liste_des_employees,"treeview_employees");
afficher_employe(treeview_employees);
}


void
on_button_valider_modification_employe_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
employe E;
//employe s;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*success;


input1=lookup_widget(objet_graphique,"entry_nom_modifie_employe");
input2=lookup_widget(objet_graphique,"entry_prenom_modifie_employe");
input3=lookup_widget(objet_graphique,"entry_sexe_modifie_employe");
input4=lookup_widget(objet_graphique,"entry_cin_modifie_employe");

input5=lookup_widget(objet_graphique, "spinbutton_jour_modifie_employe");
input6=lookup_widget(objet_graphique, "spinbutton_mois_modifie_employe");
input7=lookup_widget(objet_graphique, "spinbutton_annee_modifie_employe");

input8=lookup_widget(objet_graphique,"entry_num_telephone_modifie_employe");
input9=lookup_widget(objet_graphique,"entry_adresse_de_residence");
input10=lookup_widget(objet_graphique,"entry_poste_modifie_employe");

success=lookup_widget(objet_graphique,"label80_resultat58");

strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E.cin,gtk_entry_get_text(GTK_ENTRY(input4)));

E.date_naissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input5));
E.date_naissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input6));
E.date_naissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input7));

strcpy(E.numero,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(E.adresse,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(E.poste,gtk_entry_get_text(GTK_ENTRY(input10)));

gtk_label_set_text(GTK_LABEL(success),"Modification réuissite"); 

modifier_employe(E);
}


void
on_button_modifier_employe_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *fenetre_modifier_employe,*fenetre_liste_des_employees;
GtkWidget *treeview_employees;


GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;

gchar* nom;
gchar* prenom;
gchar* sexe;
gchar* cin;
gint* jour;
gint* mois;
gint* annee;
gchar* numero;
gchar* adresse;
gchar* poste;


employe E;
GtkWidget *input1,*input2,*input3,*input4,*jour2,*mois2,*annee2,*input5,*input6,*input7;

fenetre_liste_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");

treeview_employees=lookup_widget(fenetre_liste_des_employees,"treeview_employees");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_employees));
if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &nom,1,&prenom,2,&sexe,3,&cin,4,&jour,5,&mois,6,&annee,7,&numero,8,&adresse,9,&poste,-1);


strcpy(E.nom,nom);
strcpy(E.prenom,prenom);
strcpy(E.sexe,sexe);
E.date_naissance.jour=jour;
E.date_naissance.mois=mois;
E.date_naissance.annee=annee;
strcpy(E.cin,cin);
strcpy(E.numero,numero);
strcpy(E.adresse,adresse);
strcpy(E.poste,poste);

}

gtk_widget_destroy(fenetre_liste_des_employees);

fenetre_modifier_employe=create_fenetre_modifier_employe();
gtk_widget_show(fenetre_modifier_employe);

input1=lookup_widget(fenetre_modifier_employe,"entry_nom_modifie_employe");
input2=lookup_widget(fenetre_modifier_employe,"entry_prenom_modifie_employe");
input3=lookup_widget(fenetre_modifier_employe,"entry_sexe_modifie_employe");
input4=lookup_widget(fenetre_modifier_employe,"entry_cin_modifie_employe");
jour2=lookup_widget(fenetre_modifier_employe,"spinbutton_jour_modifie_employe");
mois2=lookup_widget(fenetre_modifier_employe,"spinbutton_mois_modifie_employe");
annee2=lookup_widget(fenetre_modifier_employe,"spinbutton_annee_modifie_employe");
input5=lookup_widget(fenetre_modifier_employe,"entry_num_telephone_modifie_employe");
input6=lookup_widget(fenetre_modifier_employe,"entry_adresse_de_residence");
input7=lookup_widget(fenetre_modifier_employe,"entry_poste_modifie_employe");





gtk_entry_set_text(GTK_ENTRY(input1),E.nom);
gtk_entry_set_text(GTK_ENTRY(input2),E.prenom);
gtk_entry_set_text(GTK_ENTRY(input3),E.sexe);
gtk_entry_set_text(GTK_ENTRY(input4),E.cin);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour2),E.date_naissance.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois2),E.date_naissance.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee2),E.date_naissance.annee);

gtk_entry_set_text(GTK_ENTRY(input5),E.numero);
gtk_entry_set_text(GTK_ENTRY(input6),E.adresse);
gtk_entry_set_text(GTK_ENTRY(input7),E.poste);

}


void
on_button_ajouter_employe_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_employe;
GtkWidget *fenetre_liste_des_employees;


fenetre_liste_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");
gtk_widget_destroy(fenetre_liste_des_employees);
fenetre_ajouter_employe=create_fenetre_ajouter_employe();
gtk_widget_show(fenetre_ajouter_employe);
}


void
on_button_gestion_des_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_employees;
GtkWidget *fenetre_gestion_des_employees;
GtkWidget *treeview_employees;

fenetre_gestion_des_employees=lookup_widget(objet,"fenetre_gestion_des_employees");
gtk_widget_destroy(fenetre_gestion_des_employees);
fenetre_gestion_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");
fenetre_liste_des_employees=create_fenetre_liste_des_employees();
gtk_widget_show(fenetre_liste_des_employees);
treeview_employees=lookup_widget(fenetre_liste_des_employees,"treeview_employees");
afficher_employe(treeview_employees);
}


void
on_treeview_employees_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* sexe;
        gchar* cin;
	gint* jour;
	gint* mois;
	gint* annee;
        gchar* numero;
        gchar* adresse;
        gchar* poste;
	employe E;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&nom,1,&prenom,2,&sexe,3,&cin,4,&jour,5,&mois,6,&annee,7,&numero,8,&adresse,9,&poste,-1);
        strcpy(E.nom,nom);
        strcpy(E.prenom,prenom);
	strcpy(E.sexe,sexe);
        strcpy(E.cin,cin);
	E.date_naissance.jour=jour;
	E.date_naissance.mois=mois;
	E.date_naissance.annee=annee;
        strcpy(E.numero,numero);
        strcpy(E.adresse,adresse);
        strcpy(E.poste,poste);
	supprimer_employe(E);
	afficher_employe(treeview);
	}
}


void
on_radiobutton_homme_ajout_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x=1;
}


void
on_radiobutton_femme_ajout_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x=2;
}


void
on_radiobutton_homme_modifie_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y=1;
}


void
on_radiobutton_femme_modifie_employe_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y=2;
}


void
on_button_quitter_liste_employees_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_employees;
fenetre_liste_des_employees=lookup_widget(objet,"fenetre_liste_des_employees");
gtk_widget_destroy(fenetre_liste_des_employees);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button_quitter_ajout_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_employe;

fenetre_ajouter_employe=lookup_widget(objet,"fenetre_ajouter_employe");
gtk_widget_destroy(fenetre_ajouter_employe);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button_quitter_modification_employe_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_employe;

fenetre_modifier_employe=lookup_widget(objet,"fenetre_modifier_employe");
gtk_widget_destroy(fenetre_modifier_employe);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}



void
on_button68_gestion_des_ouvriers_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_liste_des_employees;
GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

GtkWidget *fenetre_responsable_ouvrier;
fenetre_responsable_ouvrier=create_fenetre_responsable_ouvrier();
gtk_widget_show(fenetre_responsable_ouvrier);
}


void
on_button71_gestion_des_clients_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

GtkWidget *gestion_client;
gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);
}


void
on_button70_gestion_des_plantations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

GtkWidget *fenetre_choix;
fenetre_choix=create_fenetre_choix();
gtk_widget_show(fenetre_choix);
}


void
on_button69_gestion_des_capteurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

GtkWidget *capteur;
capteur=create_capteur();
gtk_widget_show(capteur);
}


void
on_button73_gestion_des_employes_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

GtkWidget *fenetre_liste_des_employees;
fenetre_liste_des_employees=create_fenetre_liste_des_employees();
gtk_widget_show(fenetre_liste_des_employees);
GtkWidget *treeview_employees;
treeview_employees=lookup_widget(fenetre_liste_des_employees,"treeview_employees");
afficher_employe(treeview_employees);
}



				//////////////////////////////////////////////////////////////////////////////////
				//###############################PARTIE AZIZ//###############################
				//////////////////////////////////////////////////////////////////////////////////

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

label=lookup_widget(objet, "sortie");
input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"jour");
input3=lookup_widget(objet,"mois");
input4=lookup_widget(objet,"spinbutton1_anneeajout");
type_plante=lookup_widget(objet,"combobox2_type");

strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
p.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
p.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));
p.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
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
gint* jour;
gint* mois;
gint* annee;
gchar* type;
plantation p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&nom,2,&jour,3,&mois,4,&annee,5,&type,-1);
strcpy(p.nom,nom);
p.id=id;
p.jour=jour;
p.mois=mois;
p.annee=annee;
strcpy(p.type,type);

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

GtkWidget *fenetre_modifier_plante,*Calendrier_de_plantations;
GtkWidget *treeview1_cal;


GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;

gchar* nom;
gint* id;
gint* jour;
gint* mois;
gint* annee;
gchar* type;
plantation p;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;

Calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");

	treeview1_cal=lookup_widget(Calendrier_de_plantations,"treeview1_cal");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1_cal));
if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&nom,2,&jour,3,&mois,4,&annee,5,&type,-1);


	strcpy(p.nom,nom);
	p.id=id;
	p.jour=jour;
	p.mois=mois;
	p.annee=annee;
	strcpy(p.type,type);	
}

gtk_widget_destroy(Calendrier_de_plantations);

fenetre_modifier_plante=create_fenetre_modifier_plante();
gtk_widget_show(fenetre_modifier_plante);


input1=lookup_widget(fenetre_modifier_plante,"nom1");
input3=lookup_widget(fenetre_modifier_plante,"jour1");
input4=lookup_widget(fenetre_modifier_plante,"mois1");
input2=lookup_widget(fenetre_modifier_plante,"annee1");
input5=lookup_widget(fenetre_modifier_plante,"spinbutton5_id2");
input6=lookup_widget(fenetre_modifier_plante,"entry2_type_plante");


gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),p.id);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3),p.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),p.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),p.annee);
gtk_entry_set_text(GTK_ENTRY(input1),p.nom);
gtk_entry_set_text(GTK_ENTRY(input6),p.type);

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

type_plante=lookup_widget(objet,"entry2_type_plante");

label=lookup_widget(objet, "sortie1");
input1=lookup_widget(objet,"nom1");
input3=lookup_widget(objet,"jour1");
input4=lookup_widget(objet,"mois1");
input2=lookup_widget(objet,"annee1");
input5=lookup_widget(objet,"spinbutton5_id2");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
p.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));
p.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
p.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
strcpy(p.type,gtk_entry_get_text(GTK_ENTRY(type_plante)));
p.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));
modifier(p);
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
Lannee_la_plus_seche= lookup_widget(objet,"Lannee_la_plus_seche");
  seche();
  treeview1_anneeplus = lookup_widget(objet, "treeview1_anneeplus");
  
  afficher_annee_seche(treeview1_anneeplus);
}



void
on_recherche_plante_clicked            (GtkWidget      *objet,
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
on_traite_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat=3;
}


void
on_radiobutton3_etat_ok_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

etat_equip=3;

}




void
on_button2_exit_reclamation_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_liste_des_reclamations;

fenetre_liste_des_reclamations=lookup_widget(objet,"fenetre_liste_des_reclamations");

gtk_widget_destroy(fenetre_liste_des_reclamations);
GtkWidget *fenetre_login_principale;
fenetre_login_principale=lookup_widget(objet,"fenetre_login_principale");
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button102_quitter_calendrier_de_plantation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *calendrier_de_plantations;

calendrier_de_plantations=lookup_widget(objet,"Calendrier_de_plantations");

gtk_widget_destroy(calendrier_de_plantations);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button103_quitter_fenetre_ajouter_plante_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_plante;

fenetre_ajouter_plante=lookup_widget(objet,"fenetre_ajouter_plante");

gtk_widget_destroy(fenetre_ajouter_plante);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button105_quitter_fenetre_choix_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix;

fenetre_choix=lookup_widget(objet,"fenetre_choix");

gtk_widget_destroy(fenetre_choix);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button106_quitter_fenetre_modifier_plante_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_plante;

fenetre_modifier_plante=lookup_widget(objet,"fenetre_modifier_plante");

gtk_widget_destroy(fenetre_modifier_plante);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button107_quitter_fenetre_Lannee_la_plus_seche_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Lannee_la_plus_seche;

Lannee_la_plus_seche=lookup_widget(objet,"Lannee_la_plus_seche");

gtk_widget_destroy(Lannee_la_plus_seche);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}




void
on_button105_quitter_fenetre_traitement_des_reclamations_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_traitement_des_reclamations;

fenetre_traitement_des_reclamations=lookup_widget(objet,"fenetre_traitement_des_reclamations");

gtk_widget_destroy(fenetre_traitement_des_reclamations);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}


void
on_button106_quitter_fenetre_ajouter_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation;

fenetre_ajouter_reclamation=lookup_widget(objet,"fenetre_ajouter_reclamation");

gtk_widget_destroy(fenetre_ajouter_reclamation);

GtkWidget *fenetre_login_principale;
fenetre_login_principale=create_fenetre_login_principale();

gtk_widget_show(fenetre_login_principale);
}

