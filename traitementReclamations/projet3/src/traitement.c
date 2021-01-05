#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "traitement.h"

enum
{
	IDENTIFIANT,
	ID,
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
        char id[20];
        char reclamation [1000];
    	char etat[10];
    	char reponse[1000];
    //RECLAMATION rep;
    FILE * f_reclamation;
    FILE * f_reclamation1;
    f_reclamation=fopen("reclamation.txt","r");
    f_reclamation1=fopen("reclamation1.txt","w");
    if(f_reclamation!=NULL)
    {
        while(fscanf(f_reclamation,"%d %s %s %s %s",&identifiant_reclamation,id,reclamation,etat,reponse)!=EOF)
        {
            if(identifiant_reclamation == r.identifiant_reclamation)
            {
		strcpy(r.etat,"oui");
                fprintf(f_reclamation1,"%d %s %s %s %s \n",identifiant_reclamation,id,reclamation,r.etat,r.reponse);
            }
           else
           fprintf(f_reclamation1,"%d %s %s %s %s \n",identifiant_reclamation,id,reclamation,etat,reponse);	
         }
    }
    fclose(f_reclamation1);
    fclose(f_reclamation);
    remove("reclamation.txt");
    rename("reclamation1.txt","reclamation.txt");
}

/****************************ajouter******************************************/
void ajouter_reclamation(RECLAMATION rec)
{
    int id1;
    FILE *f_reclamation=NULL;
    f_reclamation=fopen("reclamation.txt","a+");
    if(f_reclamation!=NULL)
    {
    rec.identifiant_reclamation=incrementation_ID(id1);
    fprintf(f_reclamation,"%d %s %s %s %s\n",rec.identifiant_reclamation,rec.id.identifiant,rec.reclamation,rec.etat,rec.reponse);

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
        char id[20];
        char reclamation [1000];
    	char etat[10];
    	char reponse[1000];
	store=NULL;
	
	FILE *f_reclamation;
 
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("identifiant_reclamation", renderer,"text",IDENTIFIANT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes("reclamation", renderer,"text",RECLAMATION1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("reponse", renderer,"text",REPONSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
		store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f_reclamation = fopen("reclamation.txt","r");
	if(f_reclamation==NULL)
	{
	return;
	}
	else
	{
	 f_reclamation=fopen("reclamation.txt","a+");
		while(fscanf(f_reclamation,"%d %s %s %s %s \n",&identifiant_reclamation,id,reclamation,etat,reponse)!=EOF)
		{
		gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter ,IDENTIFIANT,identifiant_reclamation,ID,id,RECLAMATION1,reclamation,ETAT,etat,REPONSE,reponse,-1);		
		}
		fclose(f_reclamation);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}

/*=================================fonction incrementation ID=================================*/
int incrementation_ID(int id1)
{
int n=1;
FILE *f_reclamation=NULL;
int identifiant_reclamation;
    char id[20];
    char reclamation [1000];
    char etat[10];
    char reponse[1000];

//ouvrir le fichier
f_reclamation=fopen("reclamation.txt","r");
if(f_reclamation!=NULL)
{
while(fscanf(f_reclamation,"%d %s %s %s %s \n",&identifiant_reclamation,id,reclamation,etat,reponse)!=EOF)
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
