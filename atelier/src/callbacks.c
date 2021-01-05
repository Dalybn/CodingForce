#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capt.h"
#include "commande.h"
#include "reclamation.h"
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
GdkColor color;
gdk_color_parse("red",&color);
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
//gtk_label_set_text(GTK_LABEL(sortie),"Modification traitée");
strcpy(c.type_capteur,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input2))); 
strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.temps_reponse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.precision,gtk_entry_get_text(GTK_ENTRY(input5)));
GdkColor color;
gdk_color_parse("red",&color);
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
input3=lookup_widget(objet,"VALEUR");/////


strcpy(a.reference,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
a.d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
a.d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a.d.an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(a.heure,gtk_entry_get_text(GTK_ENTRY(input2)));
a.valeur=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));
GdkColor color;
gdk_color_parse("red",&color);
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
input3=lookup_widget(objet,"VALEUR");/////


strcpy(a.reference,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
a.d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
a.d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a.d.an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(a.heure,gtk_entry_get_text(GTK_ENTRY(input2)));
a.valeur=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));
GdkColor color;
gdk_color_parse("red",&color);
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


/*void
on_afficher_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

}
*/

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
GtkWidget *fenetre_afficher_reclamation;
GtkWidget *treeviewREC;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);
fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");
fenetre_afficher_reclamation=create_fenetre_afficher_reclamation();

gtk_widget_show(fenetre_afficher_reclamation);

treeviewREC=lookup_widget(fenetre_afficher_reclamation,"treeviewREC");

afficher_reclamation(treeviewREC);
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
//msg=lookup_widget(objet,"label17");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));

strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel1)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
/*GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(msg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(msg),"Ajout client reusssi");*/
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
	//strcpy(c.num,num);
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
sortie22=lookup_widget(objet,"label26");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input20)));

strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input40)));
strcpy(c.sexe,gtk_entry_get_text(GTK_ENTRY(input50)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input30)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(input60)));
GdkColor color;
gdk_color_parse("red",&color);
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
on_DISPOREC_clicked                    (GtkWidget      *objet,
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
on_ajouterec_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation;
RECLAMATION r;
GtkWidget *input1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *etat1, *etat2;
GtkWidget *input2, *input3, *input4;
GtkWidget *sortie;


fenetre_ajouter_reclamation=lookup_widget(objet,"fenetre_ajouter_reclamation");
input1=lookup_widget(objet,"ID");

jour=lookup_widget(objet,"JOUR");
mois=lookup_widget(objet,"MOIS");
annee=lookup_widget(objet,"ANNEE");

input2=lookup_widget(objet,"reclamation");
//input3=lookup_widget(objet,"combobox2");

etat1=lookup_widget(objet,"ETAT1");
etat2=lookup_widget(objet,"ETAT2");

input4=lookup_widget(objet,"rep");
//sortie=lookup_widget(objet,"label7");
strcpy(r.identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
//strcpy(r.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
r.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
r.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
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

//strcpy(r.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
/*strcpy(r.rep,gtk_entry_get_text(GTK_ENTRY(input4)));

GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Reclamation ajoutée");

*/
ajouter_reclamation(r);
}


void
on_disporecl_clicked                   (GtkWidget      *objet,
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
on_rechercher_reclamation_clicked      (GtkWidget      *objet,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *input;

input=lookup_widget(objet,"ID");

strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
 
rechercher_reclamation(id);

gtk_entry_set_text(GTK_ENTRY(input),"");
GtkWidget *treeviewREC;
treeviewREC=lookup_widget(objet,"treeviewREC");
afficher_reclamation_rechercher(treeviewREC);
}


void
on_treeviewREC_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* identifiant;
gint* jour;
gint* mois;
gint* annee;
gchar* reclamation;
gchar* etat;
gchar* rep;
RECLAMATION r;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&identifiant,1,&jour,2,&mois,3,&annee,4,&reclamation,5,&etat,6,&rep,-1);
strcpy(r.identifiant,identifiant);
r.d.jour=*jour;
r.d.mois=*mois;
r.d.jour=*annee;
strcpy(r.recl,reclamation);
strcpy(r.etat,etat);
strcpy(r.rep,rep);
supprimer_reclamation(r);
afficher_reclamation(treeview);
}
}


void
on_ajouter_rec_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation, *fenetre_afficher_reclamation;
fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");

gtk_widget_destroy(fenetre_afficher_reclamation);
fenetre_ajouter_reclamation=create_fenetre_ajouter_reclamation();
gtk_widget_show(fenetre_ajouter_reclamation);
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
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;

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
gtk_entry_set_text(GTK_ENTRY(input1),c.nom);
gtk_entry_set_text(GTK_ENTRY(input2),c.prenom);
gtk_entry_set_text(GTK_ENTRY(input5),c.tel);
gtk_entry_set_text(GTK_ENTRY(input3),c.sexe);
gtk_entry_set_text(GTK_ENTRY(input4),c.adresse);
gtk_entry_set_text(GTK_ENTRY(input6),c.identifiant);

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

