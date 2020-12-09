#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capt.h"
#include "enregistrement.h"

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
//input1=lookup_widget(objet,"combobox1");
type1=lookup_widget(objet,"radiobutton1");
type2=lookup_widget(objet,"radiobutton2");
input2=lookup_widget(objet,"marque");
input3=lookup_widget(objet,"reference");
input4=lookup_widget(objet,"temps_reponse");
input5=lookup_widget(objet,"precision");
sortie=lookup_widget(objet,"label83");



//strcpy(c.type_capteur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));


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
liste_capteurs=lookup_widget(objet,"liste_capteurs");

gtk_widget_destroy(liste_capteurs);
modifier_capteur=lookup_widget(objet,"modifier_capteur");
modifier_capteur=create_modifier_capteur();
gtk_widget_show(modifier_capteur);






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
input1=lookup_widget(objet,"combobox3");
input2=lookup_widget(objet,"marque");
input3=lookup_widget(objet,"reference");
input4=lookup_widget(objet,"temps_reponse");
input5=lookup_widget(objet,"precision");
sortie=lookup_widget(objet,"label82");
//gtk_label_set_text(GTK_LABEL(sortie),"Modification traitée");
strcpy(c.type_capteur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input2))); 
strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.temps_reponse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.precision,gtk_entry_get_text(GTK_ENTRY(input5)));

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
gchar* valeur;
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
strcpy(a.valeur,valeur);

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
input3=lookup_widget(objet,"VALEUR");/////


strcpy(a.reference,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
a.d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
a.d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a.d.an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(a.heure,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.valeur,gtk_entry_get_text(GTK_ENTRY(input3)));

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
input3=lookup_widget(objet,"VALEUR");/////


strcpy(a.reference,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
a.d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
a.d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a.d.an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(a.heure,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.valeur,gtk_entry_get_text(GTK_ENTRY(input3)));

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
gchar* valeur;
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
strcpy(a.valeur,valeur);

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
GtkWidget *input;
GtkWidget *f_chercher_capteur;

f_chercher_capteur=lookup_widget(objet,"f_chercher_capteur");

input=lookup_widget(objet,"REFERENCE");
strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
rechercher_capt(c,ref);
gtk_entry_set_text(GTK_ENTRY(input),"");
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
Capteur c;
GtkWidget *ref;
ref=lookup_widget(objet, "REFERENCE");
FILE *f;
f=fopen("capteur1.txt","r");
if (f!=NULL)
 {
	while(fscanf(f,"%s",c.reference)!=EOF)
   {	
	gtk_combo_box_append_text(GTK_COMBO_BOX(ref),_(c.reference));
    }
 }
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

