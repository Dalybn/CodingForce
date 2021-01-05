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
	IDENTIFIANT,
	JOUR,
	MOIS,
	ANNEE,
	RECL,
	ETAT,
	REP,
	COLUMNS6
};


void ajouter_reclamation(RECLAMATION REC)
{
FILE *f;
f=fopen("reclamation.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f," %s %d %d %d %s %s %s \n",REC.identifiant,REC.d.jour,REC.d.mois,REC.d.annee,REC.recl,REC.etat,REC.rep);
	 fclose(f);
	}
}



void afficher_reclamation(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char recl[1000];
char etat[30];
char rep[1000];
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

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("rep",renderer,"text",REP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
f=fopen("reclamation.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("reclamation.txt","a+");
while(fscanf(f," %s %s %s %s %s %s %s \n",identifiant,jour,mois,annee,recl,etat,rep)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT,identifiant , JOUR,jour, MOIS,mois, ANNEE,annee , RECL,recl, ETAT,etat ,REP,rep, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
void supprimer_reclamation(RECLAMATION REC)
{


char identifiant[20];
int jour;
int mois;
int annee;
char recl[1000];
char etat[30];
char rep[1000];

FILE *f,*g;
f=fopen("reclamation.txt","r");
g=fopen("tempo.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s  %d %d %d %s %s %s \n",identifiant,&jour,&mois,&annee,recl,etat,rep)!=EOF)
{
if(strcmp(REC.identifiant,identifiant)!=0 || (REC.d.jour!=jour) || (REC.d.mois!=mois) ||(REC.d.annee!=annee) || strcmp(REC.recl,recl)!=0 || strcmp(REC.etat,etat)!=0 ||strcmp(REC.rep,rep)!=0 )
fprintf(g,"%s  %d %d %d %s %s %s \n",identifiant,jour,mois,annee,recl,etat,rep);
}
fclose(f);
fclose(g);
remove("reclamation.txt");
rename("tempo.txt","reclamation.txt");
}
}
void rechercher_reclamation(char id[10])  
{
FILE* f; 
FILE* f1;
	
	char identifiant[20];
	int jour;
	int mois;
	int annee;
	char recl[1000];
	char etat[30];
	char rep[1000];
f=fopen("reclamation.txt","r");
f1=fopen("reclamationcher.txt","w");
 	while(fscanf(f,"%s  %d %d %d %s %s %s \n",identifiant,&jour,&mois,&annee,recl,etat,rep)!=EOF)
	{
		if (strcmp(identifiant,id)==0)
		{
		fprintf(f1,"%s  %d %d %d %s %s %s\n",identifiant,jour,mois,annee,recl,etat,rep);
		}
	}
	fclose(f);
	fclose(f1);
remove("reclamationchercher.txt");
rename ("reclamationcher.txt","reclamationchercher.txt");
}
void afficher_reclamation_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char recl[1000];
char rep[1000];
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

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("rep",renderer,"text",REP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	

	f = fopen("reclamationchercher.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ 
	f = fopen("reclamationchercher.txt","a+");
         while(fscanf(f," %s %s %s %s %s %s %s\n",identifiant,jour,mois,annee,recl,etat,rep)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT,identifiant , JOUR,jour, MOIS,mois, ANNEE,annee , RECL,recl, ETAT,etat ,REP,rep, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


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
store=gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
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

