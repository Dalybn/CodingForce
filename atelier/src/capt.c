#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "capt.h"
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

///////////////////////////////////////////////////////////
void ajout_capteur(Capteur c)
{
 char temp[15]="Temperature";
char hum[9]="Humidite";
FILE *f;
FILE *f1;
FILE *H;
FILE *T;
f=fopen("capteur.txt","a+");
f1=fopen("capteur1.txt","a+");
H=fopen("HUMIDITE.txt","a+");
T=fopen("TEMPERATURE.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",c.type_capteur,c.marque,c.reference,c.temps_reponse,c.precision);
fprintf(f1,"%s \n",c.reference);
if(strcmp(c.type_capteur,"Humidite")==0)
	fprintf(H,"%s\n",c.reference);
else
	{ if (strcmp(c.type_capteur,"Temperature")==0)
	fprintf(T,"%s \n",c.reference);
	}
fclose(f);
fclose(f1);
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
f=fopen("capteur.txt","r");
g=fopen("dump.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision)!=EOF)
{
	if(strcmp(c.type_capteur,type_capteur)!=0 || strcmp(c.marque,marque)!=0 ||strcmp( c.reference, reference)!=0 ||strcmp(c.temps_reponse,temps_reponse)!=0 ||strcmp( c.precision,precision)!=0 )
	fprintf(g,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision);	
	}
fclose(f);
fclose(g);
remove("capteur.txt");
rename("dump.txt","capteur.txt");
}
}
//=========chercher capteur=======
void rechercher_capt(Capteur c,char ref[20])
{
	
	
	char type_capteur[30];
	char marque[30];
	char reference[30];
	char temps_reponse[30];
	char precision[30];	



FILE *f;
FILE *f1;
f=fopen("capteur.txt","r");
f1=fopen("captCH.txt","w");


    while(fscanf(f,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision)!=EOF)
  {
	if((strcmp(reference,ref)==0))
       {
fprintf(f1,"%s %s %s %s %s\n",type_capteur,marque,reference,temps_reponse,precision);	

	}
   }
	
	fclose(f);
	fclose(f1);
remove("captCH1.txt");
rename("captCH.txt","captCH1.txt");
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
	 fprintf(f," %s  %d  %d %d %s %s  \n",a.reference,a.d.j,a.d.m,a.d.an,a.heure,a.valeur);
	 fclose(f);
	}
}



void afficher_enH(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;

char jour[20];
char mois[20];
char annee[20];
char heure[1000];
char reference[20];
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
	 fprintf(f," %s  %d  %d %d %s %s  \n",a.reference,a.d.j,a.d.m,a.d.an,a.heure,a.valeur);
	 fclose(f);
	}
}



void afficher_enT(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;

char jour[20];
char mois[20];
char annee[20];
char heure[1000];
char reference[20];
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
/*
//*************les references des capteurs ayant des valeurs alarmantes**********************************

//*******Humidite************

void captALH(Capteur c)
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


    while(fscanf(f,"%s %d %d %d %s %d \n",reference,jour,mois,annee,heure,valeur)!=EOF)
  {
	if(valeur < -6 || valeur>50)
{
	fprintf(f1," %s \n",reference);
}
}
fclose(f);
fclose(f1);
}
//*******Temperature************
void captALT(Capteur c)
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


    while(fscanf(f,"%s %d %d %d %s %d \n",reference,jour,mois,annee,heure,valeur)!=EOF)
  {
	if(valeur < -6 || valeur>50)
{
	fprintf(f1," %s \n",reference);
}
}
fclose(f);
fclose(f1);
}	

*/

