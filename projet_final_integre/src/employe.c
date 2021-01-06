

#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "employe.h"

enum
{
	NOM,
	PRENOM,
	SEXE,
	CIN,
	JOUR,
	MOIS,
	ANNEE,
	NUMERO,
	ADRESSE,
	POSTE,
	COLUMNS
};
//////////////////////////////////////////

void ajouter_employe(employe E)
{FILE *f;
f=fopen("employe.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",E.nom,E.prenom,E.sexe,E.cin,E.date_naissance.jour,E.date_naissance.mois,E.date_naissance.annee,E.numero,E.adresse,E.poste);
fclose(f);
}
}

//////////////////////////////////////////
void afficher_employe(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char nom[30];
	char prenom[30];
	char sexe[30];
	char cin[30];
	int jour;
	int mois;
	int annee;
	char numero[30];
	char adresse[30];
	char poste[30];
	store=NULL;
	
	FILE *f;
 
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer,"text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	column = gtk_tree_view_column_new_with_attributes("numero", renderer,"text",NUMERO,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	column = gtk_tree_view_column_new_with_attributes("poste", renderer,"text",POSTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("employe.txt","r");
	if(f==NULL)
	{
	return;
	}
	else
	{
	 f=fopen("employe.txt","a+");
		while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",nom,prenom,sexe,cin,&jour,&mois,&annee,numero,adresse,poste)!=EOF)
		{
		gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter ,NOM,nom,PRENOM,prenom,SEXE,sexe,CIN,cin,JOUR,jour,MOIS,mois,ANNEE,annee,NUMERO,numero,ADRESSE,adresse,POSTE,poste,-1);		
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);

	}
	}

///////////////////////////////////////////////////
void modifier_employe(employe E)
{
FILE *f;
FILE *t;

employe s;
f=fopen("employe.txt","r");
t=fopen("temp.text","a");

    if (f!=NULL || t!=NULL)
    { 
    while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",s.nom,s.prenom,s.sexe,s.cin,&s.date_naissance.jour,&s.date_naissance.mois,&s.date_naissance.annee,s.numero,s.adresse,s.poste)!=EOF)
    {
	
	if(strcmp(s.cin,E.cin)==0)
        {
 	   

	fprintf(t,"%s %s %s %s %d/%d/%d %s %s %s \n",E.nom,E.prenom,E.sexe,E.cin,E.date_naissance.jour,E.date_naissance.mois,E.date_naissance.annee,E.numero,E.adresse,E.poste);
	}
	else
	fprintf(t,"%s %s %s %s %d/%d/%d %s %s %s \n",s.nom,s.prenom,s.sexe,s.cin,s.date_naissance.jour,s.date_naissance.mois,s.date_naissance.annee,s.numero,s.adresse,s.poste);
    	}
    }
	
fclose(t);
fclose(f);
remove("employe.txt");
rename("temp.text","employe.txt");
}

//**********************************Fonction Supprimer**********************************
void supprimer_employe(employe E)
{
	char nom[30];
	char prenom[30];
	char sexe[30];
	char cin[30];
	int jour;
	int mois;
	int annee;
	char numero[30];
	char adresse[30];
	char poste[30];
//employe s;
FILE *f,*g;
f=fopen("employe.txt","r");
g=fopen("temp.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",nom,prenom,sexe,cin,&jour,&mois,&annee,numero,adresse,poste)!=EOF)
	{
	if(strcmp(E.nom,nom)!=0 || strcmp(E.prenom,prenom)!=0 || strcmp(E.sexe,sexe)!=0 || strcmp(E.cin,cin)!=0 || E.date_naissance.jour!=jour || E.date_naissance.mois!=mois|| E.date_naissance.annee!=annee || strcmp(E.numero,numero)!=0 || strcmp(E.adresse,adresse)!=0 || strcmp(E.poste,poste)!=0)
	fprintf(g,"%s %s %s %s %d/%d/%d %s %s %s \n",nom,prenom,sexe,cin,jour,mois,annee,numero,adresse,poste);	
	}
fclose(f);
fclose(g);
remove("employe.txt");
rename("temp.txt","employe.txt");
}
}

//**********************************Fonction rechercher**********************************

void rechercher_employe(employe E)  
{
FILE* f;
FILE* f1;
	char nom[30];
	char prenom[30];
	char sexe[30];
	char cin[30];
	int jour;
	int mois;
	int annee;
	char numero[30];
	char adresse[30];
	char poste[30];

f=fopen("employe.txt","r");
f1=fopen("employecher.txt","w");
  while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",nom,prenom,sexe,cin,&jour,&mois,&annee,numero,adresse,poste)!=EOF)
{
if (strcmp(E.cin,cin)==0)
{
fprintf(f1,"%s %s %s %s %d/%d/%d %s %s %s \n",nom,prenom,sexe,cin,jour,mois,annee,numero,adresse,poste);
}
}
fclose(f);
fclose(f1);
}

//verifier l'existance 

int exist_cin(char* cin){
FILE*f=NULL;
employe E;
f=fopen("employe.txt","r");// ouverture du fichier plante en  mode lecture 
while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",E.nom,E.prenom,E.sexe,E.cin,&E.date_naissance.jour,&E.date_naissance.mois,&E.date_naissance.annee,E.numero,E.adresse,E.poste)!=EOF){
if(strcmp(E.cin,cin)==0)
return 1;   //cin existe deja 
}
fclose(f);
return 0;
}

/*=================================fonction afficher rechercher employe==============================*/
void afficher_emp_rechercher(GtkWidget *liste)
{
      GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char nom[30];
	char prenom[30];
	char sexe[30];
	char cin[30];
	int jour;
	int mois;
	int annee;
	char numero[30];
	char adresse[30];
	char poste[30];
	store=NULL;
	
	FILE *f;
 
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer,"text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	column = gtk_tree_view_column_new_with_attributes("numero", renderer,"text",NUMERO,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	column = gtk_tree_view_column_new_with_attributes("poste", renderer,"text",POSTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("employecher.txt","r");
	if(f==NULL)
	{
	return;
	}
	else
	{
	 f=fopen("employecher.txt","a+");
		while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",nom,prenom,sexe,cin,&jour,&mois,&annee,numero,adresse,poste)!=EOF)
		{
		gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter ,NOM,nom,PRENOM,prenom,SEXE,sexe,CIN,cin,JOUR,jour,MOIS,mois,ANNEE,annee,NUMERO,numero,ADRESSE,adresse,POSTE,poste,-1);		
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);

	}
}


//fonction verifier CIN
int verifier_CIN_inscrit(char cin[30])
{ 
FILE*f=NULL;
employe E;
f=fopen("employe.txt","r");
while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",E.nom,E.prenom,E.sexe,E.cin,&E.date_naissance.jour,&E.date_naissance.mois,&E.date_naissance.annee,E.numero,E.adresse,E.poste)!=EOF){
if((strcmp(E.cin,cin)==0)||(strcmp(cin,"admin")==0))
return 1; //existe   
}
fclose(f);
return 0; //n'existe pas
}


//fonction verifier PASSEWORD
int verifier_PASSEWORD_inscrit(char passeword[30])
{ 
if(strcmp("admin",passeword)==0)
	{
	return 0; //Administrateur  
	}else
if(strcmp("troupeaux",passeword)==0)
	{
	return 1; //responsable des troupeaux 
	}else
if(strcmp("ouvrier",passeword)==0)
	{
	return 2; //responsable ouvrier  
	}else
if(strcmp("equipement",passeword)==0)
	{
	return 3; //responsable equipement agricole  
	}else
if(strcmp("client",passeword)==0)
	{
	return 4; //responsable client  
	}else
if(strcmp("plantation",passeword)==0)
	{
	return 5; //responsable plantation  
	}else
if(strcmp("capteur",passeword)==0)
	{
	return 6; //responsable des capteurs  
	}else
if(strcmp("employe",passeword)==0)
	{
	return 7; //responsable des employées  
	}else
{ return 8; }

}

//fonction verifier ACCEE
int verifier_ACCEE_inscrit(char cin[30])
{
FILE*f=NULL;
employe E;
f=fopen("employe.txt","r");
 while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",E.nom,E.prenom,E.sexe,E.cin,&E.date_naissance.jour,&E.date_naissance.mois,&E.date_naissance.annee,E.numero,E.adresse,E.poste)!=EOF)
	{
	if (strcmp(E.cin,cin)==0)
		{
		if (strcmp(E.poste,"Responsable_des_troupeaux")==0)
		return 1;
		if (strcmp(E.poste,"Responsable_des_ouvriers")==0)
		return 2;
		if (strcmp(E.poste,"Responsable_équipements")==0)
		return 3;
		if (strcmp(E.poste,"Responsable_client")==0)
		return 4;
		if (strcmp(E.poste,"Responsable_des_plantations")==0)
		return 5;
		if (strcmp(E.poste,"Responsable_des_capteurs")==0)
		return 6;
		if (strcmp(E.poste,"Responsable_des_employées")==0)
		return 7;
		}
	}
}
