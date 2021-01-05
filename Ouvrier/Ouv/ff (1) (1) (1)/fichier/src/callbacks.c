#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ouv.h"

//treeview ouvrier
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
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

	treeview1=lookup_widget(treeview,"treeview1");
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






/*gtk_widget_destroy(treeview);
fenetre_modifier_informations=create_fenetre_modifier_informations();

gtk_widget_show(fenetre_modifier_informations);*/
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
treeview1=lookup_widget(objet,"treeview1");
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
treeview1=lookup_widget(treeview,"treeview1");

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
gtk_label_set_text(GTK_LABEL(label),"Ouvrier ajouter avec succès");
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

treeview1=lookup_widget(treeview,"treeview1");

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
ID=lookup_widget(objet,"spinbutton5_abs");
raison=lookup_widget(objet,"raison");
mois=lookup_widget(objet,"combobox4");
jour=lookup_widget(objet,"spinbutton4_abs");
annee=lookup_widget(objet,"spinbutton6_abs");

strcpy(p.da.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
p.ID=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (ID));
strcpy(p.raison,gtk_entry_get_text(GTK_ENTRY(raison)));
p.da.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.da.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

Ajouter_absence(p);

gtk_label_set_text(GTK_LABEL(label),"Absence ajouter avec succès");
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
treeview1=lookup_widget(treeview,"treeview1");

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
gtk_label_set_text(GTK_LABEL(label),"Ouvrier modifier avec succès");

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
treeview1=lookup_widget(treeview,"treeview1");

afficher_ouvrier(treeview1);

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=2;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=3;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=4;
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
on_taux_abs_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{FILE *f;
f=fopen("taux.txt","a+");
float taux;
taux=CalculeTaux();
fprintf(f,"Le taux est %.2f",taux);
fclose(f);
}

