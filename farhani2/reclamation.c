#ifdef HAVE_CONFIG.H
#include<config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "reclamation.h"
#include<gtk/gtk.h>

enum
{
	RECL,
	JOUR,
	MOIS,
	ANNEE,
	IDENTIFIANT,
	ETAT,
	COLUMNS
};


void ajouter_reclamation(RECLAMATION REC)
{
FILE *f;
f=fopen("reclamation.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f," %s  %d  %d %d %s %s  \n",REC.identifiant,REC.date.jour,REC.date.mois,REC.date.annee,REC.RECL,REC.etat);
	 fclose(f);
	}
}



void afficher_reclamation(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;

char jour[20];
char mois[20];
char annee[20];
char recl[1000];
char identifiant[20];
char etat[30];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
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
column = gtk_tree_view_column_new_with_attributes("recl",renderer,"text",RECL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("reclamation.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("reclamation.txt","a+");
while(fscanf(f," %s %s %s %s %s %s \n",identifiant,jour,mois,annee,reclamation,etat)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT,identifiant , JOUR,jour, MOIS,mois, ANNEE,annee , RECL,reclamation, ETAT,etat , -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
void supprimer_reclamation(RECLAMATION REC)
{

char recl[1000];
char identifiant[20];
char etat[30];
int jour;
int mois;
int annee;


FILE *f,*g;
f=fopen("reclamation.txt","r");
g=fopen("tempo.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s  %d %d %d %s %s \n",id,&jour,&mois,&annee,recl,etat)!=EOF)
{
if(strcmp(REC.identifiant,id)!=0 || (REC.d.jour!=jour) || (REC.d.mois!=mois) ||(REC.d.annee!=annee) || strcmp(REC.recl,recl)!=0 || strcmp(REC.etat,etat)!=0)
fprintf(g,"%s  %d %d %d %s %s  \n",id,jour,mois,annee,recl,etat);
}
fclose(f);
fclose(g);
remove("reclamation.txt");
rename("tempo.txt","reclamation.txt");
}
}
