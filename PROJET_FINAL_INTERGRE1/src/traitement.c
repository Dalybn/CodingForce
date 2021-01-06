#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "traitement.h"

enum
{
	IDENTIFIANT,
	ID,
	JOUR,
	MOIS,
	ANNEE,
	RECLAMATION1,
	ETAT,
	REPONSE,
	COLUMNS
};

/****************************gérer******************************************/
void gerer_reclamation(RECLAMATION r)
{
    //int identifiant1;
    int identifiant_reclamation;
        char identifiant[20];
	int jour;
	char mois[20];
 	int annee;
        char recl[1000];
    	char etat[100];
    	char rep[1000];
    //RECLAMATION rep;
    FILE * f_reclamation;
    FILE * f_reclamation1;
    f_reclamation=fopen("reclamation.txt","r");
    f_reclamation1=fopen("reclamation1.txt","w");
    if(f_reclamation!=NULL)
    {
while(fscanf(f_reclamation,"%d %s %d %s %d %s %s %s\n",&identifiant_reclamation,identifiant,&jour,mois,&annee,recl,etat,rep)!=EOF)
        {
            if(identifiant_reclamation == r.identifiant_reclamation)
            {
		strcpy(r.etat,"Traite");
                fprintf(f_reclamation1,"%d %s %d %s %d %s %s %s\n",r.identifiant_reclamation,identifiant,jour,mois,annee,recl,r.etat,r.rep);
            }
           else
           fprintf(f_reclamation1,"%d %s %d %s %d %s %s %s\n",identifiant_reclamation,identifiant,jour,mois,annee,recl,etat,rep);	
         }
    }
    fclose(f_reclamation1);
    fclose(f_reclamation);
    remove("reclamation.txt");
    rename("reclamation1.txt","reclamation.txt");
}

/****************************ajouter******************************************/
void ajouter_reclamation(RECLAMATION r)
{
    int id1;
    FILE *f_reclamation=NULL;
    f_reclamation=fopen("reclamation.txt","a+");
    if(f_reclamation!=NULL)
    {
    r.identifiant_reclamation=incrementation_IDrec(id1);
    fprintf(f_reclamation,"%d %s %d %s %d %s %s %s\n",r.identifiant_reclamation,r.identifiant,r.d.jour,r.d.mois,r.d.annee,r.recl,r.etat,r.rep);

    fclose(f_reclamation);
    }
}

/****************************afficher******************************************/
void afficher_reclamation(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	int identifiant_reclamation;
        char identifiant[20];
 int jour;
char mois[20];
int annee;
        char recl[1000];
    	char etat[100];
    	char rep[1000];
	store=NULL;
	
	FILE *f_reclamation;
 
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("identifiant_reclamation", renderer,"text",IDENTIFIANT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois", renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee", renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes("recl", renderer,"text",RECLAMATION1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("rep", renderer,"text",REPONSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
		store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f_reclamation = fopen("reclamation.txt","r");
	if(f_reclamation==NULL)
	{
	return;
	}
	else
	{
	 f_reclamation=fopen("reclamation.txt","a+");
		while(fscanf(f_reclamation,"%d %s %d %s %d %s %s %s\n",&identifiant_reclamation,identifiant,&jour,mois,&annee,recl,etat,rep)!=EOF)
		{
		gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter ,IDENTIFIANT,identifiant_reclamation,ID,identifiant,JOUR,jour,MOIS,mois,ANNEE,annee,RECLAMATION1,recl,ETAT,etat,REPONSE,rep,-1);		
		}
		fclose(f_reclamation);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}

/*=================================fonction incrementation ID=================================*/
int incrementation_IDrec(int id1)
{
int n=1;
FILE *f_reclamation=NULL;
int identifiant_reclamation;
    char identifiant[20];
int jour;
char mois[20];
int annee;
    char recl[1000];
    char etat[100];
    char rep[1000];

//ouvrir le fichier
f_reclamation=fopen("reclamation.txt","r");
if(f_reclamation!=NULL)
{
while(fscanf(f_reclamation,"%d %s %d %s %d %s %s %s\n",&identifiant_reclamation,identifiant,&jour,mois,&annee,recl,etat,rep)!=EOF)
{
n++;
}
if(n==1)
{
id1=1;
}
if(n!=1)
{
id1=n;
}
fclose(f_reclamation);
}
return id1;
}
//////////////////////////////
int rechercher_reclamation(char id[10])  
{
FILE* f; 
FILE* f1;
	int id_reclamation;
	char identifiant[20];
	int jour;
	char mois[20];
	int annee;
	char recl[1000];
	char etat[100];
	char rep[1000];
int t=0;
f=fopen("reclamation.txt","r");
f1=fopen("reclamationcher.txt","w");
 	while(fscanf(f,"%d %s  %d %s %d %s %s %s \n",&id_reclamation,identifiant,&jour,mois,&annee,recl,etat,rep)!=EOF)
	{
		if (strcmp(identifiant,id)==0)
		{
		fprintf(f1,"%d %s  %d %s %d %s %s %s\n",id_reclamation,identifiant,jour,mois,annee,recl,etat,rep);
		t=1;		
}
	}
	fclose(f);
	fclose(f1);
remove("reclamationchercher.txt");
rename ("reclamationcher.txt","reclamationchercher.txt");
return t;
}
void afficher_reclamation_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
int id_reclamation;
char identifiant[20];
/*char jour[20];
char mois[20];
char annee[20];*/
int jour;
char mois[20];
int annee;
char recl[1000];
char rep[1000];
char etat[100];
       
 store=NULL;

        FILE *f;
	store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id_reclamation", renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",ID,NULL);
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
column = gtk_tree_view_column_new_with_attributes("recl",renderer,"text",RECLAMATION1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("rep",renderer,"text",REPONSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	

	f = fopen("reclamationchercher.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ 
	f = fopen("reclamationchercher.txt","a+");
         while(fscanf(f," %d %s %d %s %d %s %s %s\n",&id_reclamation,identifiant,&jour,mois,&annee,recl,etat,rep)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,IDENTIFIANT,id_reclamation, ID,identifiant , JOUR,jour, MOIS,mois, ANNEE,annee , RECLAMATION1,recl, ETAT,etat ,REPONSE,rep, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

