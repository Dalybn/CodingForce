#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


void
on_ajoutrec_clicked                    (GtkWidget       *objet,
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

jour=lookup_widget(objet,"spinbutton1");
mois=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");

input2=lookup_widget(objet,"reclamation");
//input3=lookup_widget(objet,"combobox2");

etat1=lookup_widget(objet,"radiobutton1");
etat2=lookup_widget(objet,"radiobutton2");

input4=lookup_widget(objet,"rep");
sortie=lookup_widget(objet,"label7");
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
strcpy(r.rep,gtk_entry_get_text(GTK_ENTRY(input4)));

GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Reclamation ajoutée");


ajouter_reclamation(r);
}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation;
GtkWidget *fenetre_afficher_reclamation;
GtkWidget *treeview1;

fenetre_ajouter_reclamation=lookup_widget(objet,"fenetre_ajouter_reclamation");

gtk_widget_destroy(fenetre_ajouter_reclamation);
fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");
fenetre_afficher_reclamation=create_fenetre_afficher_reclamation();

gtk_widget_show(fenetre_afficher_reclamation);

treeview1=lookup_widget(fenetre_afficher_reclamation,"treeview1");

afficher_reclamation(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
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
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclamation, *fenetre_afficher_reclamation;
fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");

gtk_widget_destroy(fenetre_afficher_reclamation);
fenetre_ajouter_reclamation=create_fenetre_ajouter_reclamation();
gtk_widget_show(fenetre_ajouter_reclamation);
}


void
on_rechercher_reclamation_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *input;

input=lookup_widget(objet,"ID");

strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
 
rechercher_reclamation(id);

gtk_entry_set_text(GTK_ENTRY(input),"");
GtkWidget *treeview1;
treeview1=lookup_widget(objet,"treeview1");
afficher_reclamation_rechercher(treeview1);
}

/*
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_recl=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat_recl=2;
}*/


void
on_afficher_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client;
GtkWidget *fenetre_afficher_client;
GtkWidget *treeview2;

fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");

gtk_widget_destroy(fenetre_ajouter_client);
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");
fenetre_afficher_client=create_fenetre_afficher_client();

gtk_widget_show(fenetre_afficher_client);

treeview2=lookup_widget(fenetre_afficher_client,"treeview2");

afficher_client(treeview2);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* tel;
	gchar* adresse;
	gchar* identifiant;
	gchar* sexe;
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
on_modifier_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client, *fenetre_afficher_client;
GtkWidget *treeview;
treeview=lookup_widget(objet,"treeview");
/*fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");*/
gtk_widget_destroy(treeview);
/*gtk_widget_destroy(fenetre_afficher_client);*/
fenetre_modifier_client=create_fenetre_modifier_client();
gtk_widget_show(fenetre_modifier_client);
}


void
on_rechercher_client_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *input;

input=lookup_widget(objet,"ID");
strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
 
rechercher_client(id);

gtk_entry_set_text(GTK_ENTRY(input),"");
GtkWidget *treeview2;
treeview2=lookup_widget(objet,"treeview2");
afficher_client_rechercher(treeview2);
}


void
on_gerer_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_exit2_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_client, *fenetre_afficher_reclamation;
fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");

gtk_widget_destroy(fenetre_afficher_reclamation);
fenetre_afficher_client=create_fenetre_afficher_client();
gtk_widget_show(fenetre_afficher_client);
}


void
on_ajouter_client_clicked              (GtkWidget       *objet,
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
sexe1=lookup_widget(objet,"combobox1");
id1=lookup_widget(objet,"identifiant");
msg=lookup_widget(objet,"label17");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));

strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel1)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(msg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(msg),"Ajout client reusssi");
ajouter_client(c);

}


void
on_exit_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client, *fenetre_afficher_client;
fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");

gtk_widget_destroy(fenetre_ajouter_client);
fenetre_afficher_client=create_fenetre_afficher_client();
gtk_widget_show(fenetre_afficher_client);
}

/*
void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client, *fenetre_afficher_client;
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

gtk_widget_destroy(fenetre_afficher_client);
fenetre_ajouter_client=create_fenetre_ajouter_client();
gtk_widget_show(fenetre_ajouter_client);
}*/


void
on_retour1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_client, *fenetre_afficher_client;
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

gtk_widget_destroy(fenetre_afficher_client);
fenetre_ajouter_client=create_fenetre_ajouter_client();
gtk_widget_show(fenetre_ajouter_client);
}

/*
void
on_retour1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}*/


void
on_valider_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client;
client c;
GtkWidget *input10, *input20, *input30, *input40, *input50, *input60;
GtkWidget *sortie22;


fenetre_modifier_client=lookup_widget(objet,"fenetre_modifier_client");
input10=lookup_widget(objet,"nom1");
input20=lookup_widget(objet,"prenom1");
input30=lookup_widget(objet,"adresse1");
input40=lookup_widget(objet,"tel1");
input50=lookup_widget(objet,"combobox3");
input60=lookup_widget(objet,"identifiant1");
sortie22=lookup_widget(objet,"label26");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input20)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input30)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input40)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input50)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(input60)));
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie22,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie22),"client modifié avec succés");

modifier_client(c);

}


void
on_retour_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_client, *fenetre_afficher_client;
GtkWidget *treeview2;
fenetre_modifier_client=lookup_widget(objet,"fenetre_modifier_client");

gtk_widget_destroy(fenetre_modifier_client);
fenetre_afficher_client=create_fenetre_afficher_client();
gtk_widget_show(fenetre_afficher_client);
treeview2=lookup_widget(fenetre_afficher_client,"treeview2");

afficher_client(treeview2);
}


void
on_aff_reclamation_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_client;
GtkWidget *fenetre_afficher_reclamation;
GtkWidget *treeview1;

fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");

gtk_widget_destroy(fenetre_afficher_client);
fenetre_afficher_client=lookup_widget(objet,"fenetre_afficher_client");
fenetre_afficher_reclamation=create_fenetre_afficher_reclamation();

gtk_widget_show(fenetre_afficher_reclamation);

treeview1=lookup_widget(fenetre_afficher_reclamation,"treeview1");

afficher_reclamation(treeview1);
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *nom1, *prenom1, *adresse1, *tel1, *sexe1, *id1;
GtkWidget *msg,s;
GtkWidget *fenetre_ajouter_client;

fenetre_ajouter_client=lookup_widget(objet,"fenetre_ajouter_client");
nom1=lookup_widget(objet,"nom");
prenom1=lookup_widget(objet,"prenom");
adresse1=lookup_widget(objet,"adresse");
tel1=lookup_widget(objet,"tel");
sexe1=lookup_widget(objet,"combobox1");
id1=lookup_widget(objet,"identifiant");
msg=lookup_widget(objet,"label17");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));

strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel1)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(msg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(msg),"Ajout client reusssi");
ajouter_client(c);
}


void
on_client_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
treeview2=lookup_widget(objet,"treeview2");
afficher_client(treeview2);
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
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
etat=2;
}


void
on_DISPOREC_clicked                    (GtkWidget       *objet,
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
on_aff_rec_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_afficher_reclamation;
GtkWidget *treeview1;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);

fenetre_afficher_reclamation=create_fenetre_afficher_reclamation();

gtk_widget_show(fenetre_afficher_reclamation);

treeview1=lookup_widget(fenetre_afficher_reclamation,"treeview1");

afficher_reclamation(treeview1);
}


void
on_aff_cmd_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_aff_client_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_client;
GtkWidget *fenetre_afficher_client;
GtkWidget *treeview2;

gestion_client=lookup_widget(objet,"gestion_client");

gtk_widget_destroy(gestion_client);

fenetre_afficher_client=create_fenetre_afficher_client();

gtk_widget_show(fenetre_afficher_client);

treeview2=lookup_widget(fenetre_afficher_client,"treeview2");

afficher_client(treeview2);
}


void
on_retout_principal_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_disporecl_clicked                   (GtkWidget       *objet,
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
on_ajouterCL_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewCL_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ajouter_client1_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_rec_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *fenetre_ajouter_reclamation, *fenetre_afficher_reclamation;
fenetre_afficher_reclamation=lookup_widget(objet,"fenetre_afficher_reclamation");

gtk_widget_destroy(fenetre_afficher_reclamation);
fenetre_ajouter_reclamation=create_fenetre_ajouter_reclamation();
gtk_widget_show(fenetre_ajouter_reclamation);

}

