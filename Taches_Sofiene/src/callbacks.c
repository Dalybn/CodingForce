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



//////////////////////////////////////////////////////////////////////////////////
//fenetre_gestion_des_troupeaux ======>> fenetre_afficher_animal
void
on_button_afficher_animal_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_animal;
GtkWidget *fenetre_gestion_des_troupeaux;
GtkWidget *treeview_animal;

fenetre_gestion_des_troupeaux=lookup_widget(objet,"fenetre_gestion_des_troupeaux");

gtk_widget_destroy(fenetre_gestion_des_troupeaux);
fenetre_afficher_animal=create_fenetre_afficher_animal();

gtk_widget_show(fenetre_afficher_animal);

treeview_animal=lookup_widget(fenetre_afficher_animal,"treeview_animal");

Affichage(treeview_animal);
}

//////////////////////////////////////////////////////////////////////////////////
//fenetre_gestion_des_troupeaux ======>> fenetre_menu
void
on_button_retour_animal1_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_gestion_des_troupeaux;
GtkWidget *fenetre_menu;

fenetre_gestion_des_troupeaux=lookup_widget(objet,"fenetre_gestion_des_troupeaux");

gtk_widget_destroy(fenetre_gestion_des_troupeaux);
fenetre_menu=create_fenetre_menu();

gtk_widget_show(fenetre_menu);
}

//////////////////////////////////////////////////////////////////////////////////
//quitter fenetre_gestion_des_troupeaux
void
on_button_quitter_animal1_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_gestion_des_troupeaux;

fenetre_gestion_des_troupeaux=lookup_widget(objet,"fenetre_gestion_des_troupeaux");

gtk_widget_destroy(fenetre_gestion_des_troupeaux);

}

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
//quitter dentre_ajouter_animal
void
on_button_quitter_animal2_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_animal;

fenetre_ajouter_animal=lookup_widget(objet,"fenetre_ajouter_animal");

gtk_widget_destroy(fenetre_ajouter_animal);
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
//fenetre_afficher_animal ======>> fenetre_gestion_des_troupeaux
void
on_button_retour3_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_animal;
GtkWidget *fenetre_gestion_des_troupeaux;

fenetre_afficher_animal=lookup_widget(objet,"fenetre_afficher_animal");

gtk_widget_destroy(fenetre_afficher_animal);
fenetre_gestion_des_troupeaux=create_fenetre_gestion_des_troupeaux();

gtk_widget_show(fenetre_gestion_des_troupeaux);
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
//fenetre_menu ======>> fenetre_gestion_des_troupeaux
void
on_button_gestion_troupeaux_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_menu;
GtkWidget *fenetre_gestion_des_troupeaux;

fenetre_menu=lookup_widget(objet,"fenetre_menu");

gtk_widget_destroy(fenetre_menu);
fenetre_gestion_des_troupeaux=create_fenetre_gestion_des_troupeaux();

gtk_widget_show(fenetre_gestion_des_troupeaux);
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
/*GtkWidget *mois;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *sexe;
GtkWidget *radio2;
GtkWidget *sortie;
GtkWidget *identifiant;
GtkWidget *mouton;
GtkWidget *vache;
GtkWidget *poulet;
GtkWidget *cheval;
Animal A;

sortie=lookup_widget(objet,"label126");
mois=lookup_widget(objet,"combobox15");
jour=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");
sexe=lookup_widget(objet,"combobox16");
identifiant=lookup_widget(objet,"spinbutton_id_modifier_animal");
mouton=lookup_widget(objet,"radiobutton11_mouton");
vache=lookup_widget(objet,"radiobutton13_vache");
poulet=lookup_widget(objet,"radiobutton12_poulet");
cheval=lookup_widget(objet,"radiobutton10_cheval");

if(x==1)
{
	strcpy(A.type,"Cheval");
}
if(x==2)
{
	strcpy(A.type,"Mouton");
}
if(x==3)
{
	strcpy(A.type,"Vache");
}
if(x==4)
{
	strcpy(A.type,"Poulet");
}

A.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
A.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
A.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));

strcpy(A.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(A.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));*/

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
/*
sortie=lookup_widget(objet,"label139");
nom_equipement=lookup_widget(objet,"combobox21");
marque_equipement=lookup_widget(objet,"combobox20");
modele_equipement=lookup_widget(objet,"combobox22");
transmission_equipement=lookup_widget(objet,"combobox23");
jour=lookup_widget(objet,"combobox17");
mois=lookup_widget(objet,"combobox18");
annee=lookup_widget(objet,"combobox19");
etat1=lookup_widget(objet,"radiobutton3_ok");
etat2=lookup_widget(objet,"radiobutton4_mauvais");
if(etat_equip==3)
{
strcpy(E.etat,"OK");
}
if(etat_equip==4)
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
*/
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
/*jour=lookup_widget(objet,"combobox25");
mois=lookup_widget(objet,"combobox27");
annee=lookup_widget(objet,"combobox26");
sortie=lookup_widget(objet,"label158");

E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
strcpy(E.d.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
strcpy(E.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(E.d.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));*/

E.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
jour=lookup_widget(objet,"entry_jour_entretient_modifier");
mois=lookup_widget(objet,"entry_mois_entretient_modifier");
annee=lookup_widget(objet,"entry_annee_entretient_modifier");
sortie=lookup_widget(objet,"label158");

strcpy(E.d.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
strcpy(E.d.annee,gtk_entry_get_text(GTK_ENTRY(annee)));
strcpy(E.d.jour,gtk_entry_get_text(GTK_ENTRY(jour)));

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
gtk_label_set_text(GTK_LABEL(sortie),"Existe");
}
if(y==2)
{
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
gtk_label_set_text(GTK_LABEL(sortie),"Existe");
}
if(y==2)
{
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
void
on_radiobutton3_ok_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_equip=3;
}

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


