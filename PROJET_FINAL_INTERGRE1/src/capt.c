#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "capt.h"
#include "commande.h"
#include "reclamation.h"
#include "enregistrement.h"
#include <gtk/gtk.h>
enum
{
	Type_Capteur,
	Marque,
	Reference,
	Temps_Reponse,
	Precision,
	COLUMNS
};
enum
{
	REFERENCE,
	JOUR,
	MOIS,
	ANNEE,
	HEURE,
	VALEUR,
	COLUMNS1
};

enum
{
	REFERENCE2,
	JOUR2,
	MOIS2,
	ANNEE2,
	HEURE2,
	VALEUR2,
	COLUMNS2
};
enum
{
	REFERENCE3,
	COLUMNS3
};

enum
{
	REFERENCE4,
	COLUMNS4
};
enum
{	
	NOM,
	PRENOM,
	ADRESSE,
	TEL,
	SEXE,
	IDENTIFIANT1,
	COLUMNS5
};

enum
{
	IDENTIFIANTREC,
	IDENTIFIANT,
	JOUR3,
	MOIS3,
	ANNEE3,
	RECL,
	ETAT,
	REP,
	COLUMNS6
};
enum
{
	Catalogue,
	Nom,
	Quantite,
	Prix,
	Reference1,
	Identifiant,
	COLUMNS7
};

///////////////////////////////////////////////////////////
void ajout_capteur(Capteur c)
{
 char temp[15]="Temperature";
char hum[9]="Humidite";
FILE *f;

FILE *H;
FILE *T;
f=fopen("capteur.txt","a+");
H=fopen("HUMIDITE.txt","a+");
T=fopen("TEMPERATURE.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",c.type_capteur,c.marque,c.reference,c.temps_reponse,c.precision);

if(strcmp(c.type_capteur,"Humidite")==0)
	fprintf(H,"%s\n",c.reference);
else
	{ if (strcmp(c.type_capteur,"Temperature")==0)
	fprintf(T,"%s \n",c.reference);
	}
fclose(f);

fclose(H);
fclose(T);
}
}
///////////////////////////////////////////////////////////
void afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char type_capteur[30];
	char marque[30];
	char reference[30];
	char temps_reponse[30];
	char precision[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" type_capteur",renderer,"text",Type_Capteur,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" marque",renderer,"text",Marque,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" reference",renderer,"text",Reference,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" temps_reponse",renderer,"text",Temps_Reponse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" precision",renderer,"text",Precision,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("capteur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, Type_Capteur, type_capteur, Marque, marque, Reference, reference, Temps_Reponse, temps_reponse, Precision, precision, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
///////////////////////////////////////////////////////////
void supprimer_capteur(Capteur c)
{
	char type_capteur[30];
	char marque[30];
	char reference[30];
	char temps_reponse[30];
	char precision[30];
FILE *f,*g;
FILE *T,*J;
FILE *H,*E;
f=fopen("capteur.txt","r");
g=fopen("dump.txt","w");
T=fopen("TEMPERATURE.txt","r");
J=fopen("TMP.txt","w");
H=fopen("HUMIDITE.txt","r");
E=fopen("HUM.txt","w");

if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision)!=EOF)
	{
		if(strcmp(c.type_capteur,type_capteur)!=0 || strcmp(c.marque,marque)!=0 ||strcmp( c.reference, reference)!=0 ||strcmp(c.temps_reponse,temps_reponse)!=0 ||strcmp( c.precision,precision)!=0 )
         {	fprintf(g,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision);	
			if(strcmp(type_capteur,"Humidite")==0)
		fprintf(E,"%s\n",reference);
	else
		{ if (strcmp(type_capteur,"Temperature")==0)
		fprintf(J,"%s \n",reference);
		}
         }
	}
}
fclose(f);
fclose(g);
fclose(T);
fclose(H);
fclose(J);
fclose(E);
remove("capteur.txt");
rename("dump.txt","capteur.txt");
remove("TEMPERATURE.txt");
rename("TMP.txt","TEMPERATURE.txt");
remove("HUMIDITE.txt");
rename("HUM.txt","HUMIDITE.txt");
}
//=========chercher capteur=======
int rechercher_capt(Capteur c,char ref[20])
{
	
	
	char type_capteur[30];
	char marque[30];
	char reference[30];
	char temps_reponse[30];
	char precision[30];	

int t=0;

FILE *f;
FILE *f1;
f=fopen("capteur.txt","r");
f1=fopen("captCH.txt","w");


    while(fscanf(f,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision)!=EOF)
  {
	if((strcmp(reference,ref)==0) || (strcmp(marque,ref)==0))
       {
fprintf(f1,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision);	
t=1;
	}
   }
	
	fclose(f);
	fclose(f1);
remove("captCH1.txt");
rename("captCH.txt","captCH1.txt");
return t;
}


void afficher_capteurCH(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char type_capteur[30];
	char marque[30];
	char reference[30];
	char temps_reponse[30];
	char precision[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" type_capteur",renderer,"text",Type_Capteur,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" marque",renderer,"text",Marque,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" reference",renderer,"text",Reference,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" temps_reponse",renderer,"text",Temps_Reponse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" precision",renderer,"text",Precision,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("captCH1.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("captCH1.txt","a+");
		while(fscanf(f,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, Type_Capteur, type_capteur, Marque, marque, Reference, reference, Temps_Reponse, temps_reponse, Precision, precision, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}



//======modifier==========
void modif_capteur(Capteur c)

{
	char type_capteur1[30];
	char marque1[30];
	char reference1[30];
	char temps_reponse1[30];
	char precision1[30];	

FILE *f;
FILE *k;

f=fopen("capteur.txt","r");

k=fopen("tempo.txt","a");


    if (f==NULL || k==NULL )
    {
	return;
    }
    else{


    while (fscanf(f,"%s %s %s %s %s\n",type_capteur1,marque1,reference1,temps_reponse1,precision1)!=EOF)
    {
	if(strcmp(c.reference,reference1)==0)
        {
 
   
	fprintf(k,"%s %s %s %s %s\n",c.type_capteur,c.marque,c.reference,c.temps_reponse,c.precision);	
	
	}
	else
	fprintf(k,"%s %s %s %s %s\n",type_capteur1,marque1,reference1,temps_reponse1,precision1);	
	
    
    }
	
fclose(k);
fclose(f);
remove("capteur.txt");
rename("tempo.txt","capteur.txt");
}

}

//======================ENREGISTREMENT================================
//********************HUMIDITE*************************************

void ajouter_enH(En a)
{
FILE *f;
f=fopen("enH.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f," %s  %d  %d %d %s %d  \n",a.reference,a.d.j,a.d.m,a.d.an,a.heure,a.valeur);
	 fclose(f);
	}
}



void afficher_enH(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
char reference[20];
char jour[20];
char mois[20];
char annee[20];
char heure[1000];
char valeur[30];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",HEURE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("enH.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("enH.txt","a+");
while(fscanf(f," %s %s %s %s %s %s \n",reference,jour,mois,annee,heure,valeur)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, REFERENCE,reference, JOUR,jour, MOIS,mois, ANNEE,annee , HEURE,heure, VALEUR,valeur , -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

//********************TEMPERATURE************************************

void ajouter_enT(En a)
{
FILE *f;
f=fopen("enT.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f," %s  %d  %d %d %s %d  \n",a.reference,a.d.j,a.d.m,a.d.an,a.heure,a.valeur);
	 fclose(f);
	}
}



void afficher_enT(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
char reference[20];
char jour[20];
char mois[20];
char annee[20];
char heure[1000];

char valeur[30];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REFERENCE2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",HEURE2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("enT.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("enT.txt","a+");
while(fscanf(f," %s %s %s %s %s %s \n",reference,jour,mois,annee,heure,valeur)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, REFERENCE2,reference, JOUR2,jour, MOIS2,mois, ANNEE2,annee , HEURE2,heure, VALEUR2,valeur , -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

//*************les references des capteurs ayant des valeurs alarmantes**********************************

//*******Humidite************

void captALH()
{
	
	
	char reference[30];
	int jour;
	int mois;
	int annee;
	char heure[30];	
	int valeur;



FILE *f;
FILE *f1;
f=fopen("enH.txt","r");
f1=fopen("captALH.txt","w");


    while(fscanf(f,"%s %d %d %d %s %d \n",reference,&jour,&mois,&annee,heure,&valeur)!=EOF)
  {
	if(valeur < -6 || valeur>50)
{
	fprintf(f1," %s \n",reference);
}
}
fclose(f);
fclose(f1);
}


void afficher_captDEFH(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
char reference[20];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REFERENCE3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS3, G_TYPE_STRING);
f=fopen("captALH.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("captALH.txt","a+");
while(fscanf(f," %s \n",reference)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, REFERENCE3,reference, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
int nbr_alH()
{	
	char reference[30];
	int jour;
	int mois;
	int annee;
	char heure[30];	
	int valeur;
	int nb=0;



FILE *f1;
f1=fopen("captALH.txt","r");


    while(fscanf(f1,"%s \n",reference)!=EOF)
 
{
	nb+=1;

}
fclose(f1);
return nb ;

}
//*******Temperature************

void captALT()
{
	
	
	char reference[30];
	int jour;
	int mois;
	int annee;
	char heure[30];	
	int valeur;



FILE *f;
FILE *f1;
f=fopen("enT.txt","r");
f1=fopen("captALT.txt","w");


    while(fscanf(f,"%s %d %d %d %s %d \n",reference,&jour,&mois,&annee,heure,&valeur)!=EOF)
  {
	if(valeur < -6 || valeur>50)
{
	fprintf(f1," %s \n",reference);
}
}
fclose(f);
fclose(f1);
}


void afficher_captDEFT(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
char reference[20];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REFERENCE4,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS4, G_TYPE_STRING);
f=fopen("captALT.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("captALT.txt","a+");
while(fscanf(f," %s \n",reference)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, REFERENCE4,reference, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
int nbr_alT()
{	
	char reference[30];
	int jour;
	int mois;
	int annee;
	char heure[30];	
	int valeur;
	int nb=0;



FILE *f1;
f1=fopen("captALT.txt","r");


    while(fscanf(f1,"%s \n",reference)!=EOF)
 
{
	nb+=1;

}
fclose(f1);
return nb ;
}

//**************************Client******************************************

void ajouter_client(client c)
{
int numm;
FILE *f;

f=fopen("client.txt","a+");
//c.num=numero_client(numm);
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant);
fclose(f);
}
}
///////////////////////////////////////////////////////////
void afficher_client(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char nom[30];
	char prenom[30];
	char adresse[30];
	char tel[30];
	char sexe[30];
	char identifiant[30];
	//char num[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{

/*renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" num",renderer,"text",NUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
*/

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",IDENTIFIANT1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("client.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("client.txt","a+");
		while(fscanf(f," %s %s %s %s %s %s\n",nom,prenom,adresse,tel,sexe,identifiant)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, NOM, nom, PRENOM, prenom, ADRESSE, adresse, TEL, tel, SEXE, sexe, IDENTIFIANT1, identifiant, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
///////////////////////////////////////////////////////////
void supprimer_client(client c)
{
	//char num[30];
	char nom[30];
	char prenom[30];
	char adresse[30];
	char tel[30];
	char sexe[30];
	char identifiant[30];
FILE *f,*g;
f=fopen("client.txt","r");
g=fopen("dump.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f," %s %s %s %s %s %s\n",nom,prenom,tel,sexe,adresse,identifiant)!=EOF)
	{
	if(  strcmp(c.nom,nom)!=0 || strcmp(c.prenom,prenom)!=0 || strcmp(c.adresse,adresse)!=0 || strcmp(c.tel,tel)!=0 || strcmp(c.sexe,sexe)!=0 || strcmp(c.identifiant,identifiant)!=0)
	fprintf(g,"%s %s %s %s %s %s\n",nom,prenom,tel,sexe,adresse,identifiant);	
	}
fclose(f);
fclose(g);
remove("client.txt");
rename("dump.txt","client.txt");
}
}
void rechercher_client(char id[20])  
{
FILE* f; 
FILE* f1;
	char nom[30];
	char prenom[30];
	char adresse[30];
	char tel[30];
	char sexe[30];
	char identifiant[30];
	//char num[30];

f=fopen("client.txt","r");
f1=fopen("clientcher.txt","w");
 	while(fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,adresse,tel,sexe,identifiant)!=EOF)
	{
		if (strcmp(id,identifiant)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s\n",nom,prenom,adresse,tel,sexe,identifiant);
		}
	}
	fclose(f);
	fclose(f1);
remove("clientchercher.txt");
rename ("clientcher.txt","clientchercher.txt");
}
void afficher_client_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[30];
	char prenom[30];
	char adresse[30];
	char tel[30];
	char sexe[30];
	char identifiant[30];
	//char num[30];
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	/*renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" num",renderer,"text",NUM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
*/

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",IDENTIFIANT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
	}


	store=gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("clientchercher.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("clientchercher.txt","a+");
              while(fscanf(f," %s %s %s %s %s %s\n",nom,prenom,adresse,tel,sexe,identifiant)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set(store, &iter, NOM, nom, PRENOM, prenom, ADRESSE, adresse, TEL, tel, SEXE, sexe, IDENTIFIANT1, identifiant, -1);
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
void modifier_client(client c)
{
FILE *f;
FILE *t;
	 char nom[30];
	char prenom[30];
	char adresse[30];
	char tel[30];
	char sexe[30];
	char identifiant[30];
	//char num[30];

f=fopen("client.txt","r");
t=fopen("utilis.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,adresse,tel,sexe,identifiant)!=EOF)
    {

        if(strcmp(c.identifiant,identifiant)==0)
        {
            fprintf(t,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.adresse,c.tel,c.sexe,c.identifiant);
        }
        else
            fprintf(t,"%s %s %s %s %s %s\n",nom,prenom,adresse,tel,sexe,identifiant);
        }
    }

fclose(t);
fclose(f);
remove("client.txt");
rename("utilis.txt","client.txt");
}
//**********************Commande************************************

void ajout_commande(Commande c)
{
FILE *f;
f=fopen("commande.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",c.ca.type,c.ca.nom,c.quantite,c.prix,c.reference,c.identifiant);
fclose(f);
}
}
///////////////////////////////////////////////////////////
void afficher_commande(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char catalogue[30];
	char nom[30];
	char quantite[30];
	char prix[30];
	char reference[30];
	char identifiant[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" catalogue",renderer,"text",Catalogue,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",Nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" quantite",renderer,"text",Quantite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",Prix,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" reference",renderer,"text",Reference1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",Identifiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS7, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
f=fopen("commande.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("commande.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",catalogue,nom,quantite,prix,reference,identifiant)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, Catalogue, catalogue, Nom, nom, Quantite, quantite, Prix, prix, Reference1, reference, Identifiant, identifiant, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}


int rechercher_commande(Commande c,char id[20])
{
	
	
	char catalogue[30];
	char nom[30];
	char quantite[30];
	char prix[30];
	char reference[30];
	char identifiant[30];	


int t=0;
FILE *f;
FILE *f1;
f=fopen("commande.txt","r");
f1=fopen("commandeCH.txt","w");


    while(fscanf(f,"%s %s %s %s %s %s\n",catalogue,nom,quantite,prix,reference,identifiant)!=EOF)
  {
	if((strcmp(identifiant,id)==0) ||(strcmp(catalogue,id)==0) )
       {
fprintf(f1,"%s %s %s %s %s %s\n",catalogue,nom,quantite,prix,reference,identifiant);	
t=1;
	}
   }
	
	fclose(f);
	fclose(f1);
remove("commandeCH1.txt");
rename("commandeCH.txt","commandeCH1.txt");

return t;
}

void afficher_commandeCH(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char catalogue[30];
	char nom[30];
	char quantite[30];
	char prix[30];
	char reference[30];
	char identifiant[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" catalogue",renderer,"text",Catalogue,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",Nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" quantite",renderer,"text",Quantite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",Prix,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" reference",renderer,"text",Reference1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",Identifiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS7, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

f=fopen("commandeCH1.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("commandeCH1.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",catalogue,nom,quantite,prix,reference,identifiant)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, Catalogue, catalogue, Nom, nom, Quantite, quantite, Prix, prix, Reference1, reference, Identifiant, identifiant, -1);
}


fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}



