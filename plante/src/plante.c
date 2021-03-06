#ifdef HAVE_CONFIG.H
#include<config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "plante.h"
#include<gtk/gtk.h>
#include "enregistrement.h"


enum
{
	ID,
	NOM,
	JOUR,
	MOIS,
	ANNEE,
	TYPE,
	COLUMNS
};
enum
{
	ANNEE1,
	VALEUR,
	COLUMNS1
};
//////////////////////////////////////////
void ajouter(plantation p)
{
FILE *f;
int id;
f=fopen("utilisateur.txt","a+");
p.id=plante_id(id);
	if(f!=NULL)
	{
	 fprintf(f,"%d %s %s %s %s %s\n",p.id,p.nom,p.jour,p.mois,p.annee,p.type);
	 fclose(f);
	}
}
//////////////////////////////////////////
int plante_id(int id1)
{
int n=1;
FILE *f=NULL;
	char nom[30];
	int id;
	char jour[30];
	char mois[30];
	char annee[30];
	char type[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %s %s %s\n",&id,nom,jour,mois,type,annee)!=EOF)
{
n++;
}
if(n==1)
id1=1;
else
{
id1=n;
fclose(f);
}
}
else
printf("\n Not Found");
return id1;

}
//////////////////////////////////////////
void affichage(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;

char nom[30];
int id;
char jour[30];
char mois[30];
char annee[30];
char type[20];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
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
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateur.txt","a+");
while(fscanf(f,"%d %s %s %s %s %s\n",&id,nom,jour,mois,annee,type)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, ID, id, NOM, nom, JOUR, jour, MOIS, mois, ANNEE, annee, TYPE, type, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
//////////////////////////////////////////
void supprimer(plantation p)
{
char nom[30];
int id;
char jour[30];
char mois[30];
char type[20];
char annee[30];
FILE *f,*g;
f=fopen("utilisateur.txt","r");
g=fopen("dump.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%d %s %s %s %s %s\n",&id,nom,jour,mois,annee,type)!=EOF)
{
if(p.id!=id || strcmp(p.nom,nom)!=0 || strcmp(p.jour,jour)!=0 || strcmp(p.mois,mois)!=0 || strcmp(p.annee,annee)!=0 || strcmp(p.type,type)!=0)
fprintf(g,"%d %s %s %s %s %s\n",id,nom,jour,mois,annee,type);
}
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("dump.txt","utilisateur.txt");
}
}
////////////////////////////
void Modifier(plantation p)
{
FILE *f;
FILE *t;
int id;
char nom[20];
char jour[20];
char mois[20];
char annee[20];
char type[20];

f=fopen("utilisateur.txt","r");
t=fopen("utilis.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%d %s %s %s %s %s\n",&id,nom,jour,mois,annee,type)!=EOF)
    {

        if(p.id==id)
        {
            fprintf(t," %d %s %s %s %s %s\n",p.id,p.nom,p.jour,p.mois,p.annee,p.type);
        }
        else
            fprintf(t,"%d %s %s %s %s %s\n",id,nom,jour,mois,annee,type);
        }
    }

fclose(t);
fclose(f);
remove("utilisateur.txt");
rename("utilis.txt","utilisateur.txt");
}
/////////////////////////////
void chercher(plantation p)
{
FILE* f;
FILE* f1;
        char mois[20];
	int id;
	char nom[20];
	char jour[30];
	char annee[30];
	char recjour[30];
	char type[20];

f=fopen("utilisateur.txt","r");
f1=fopen("utilichercher.txt","w");
     while(fscanf(f,"%d %s %s %s %s %s\n",&id,nom,jour,mois,annee,type)!=EOF)
    {
        if (p.id==id)
        {
        fprintf(f1,"%d %s %s %s %s %s\n",id,nom,jour,mois,annee,type);
        }
    }
    fclose(f);
    fclose(f1);
}
////////////////////////////
void afficher_et_rechercher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;

char nom[30];
int id;
char jour[30];
char mois[30];
char annee[30];
char type[20];
store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
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
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("utilichercher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilichercher.txt","a+");
while(fscanf(f,"%d %s %s %s %s %s\n",&id,nom,jour,mois,annee,type)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, ID, id, NOM, nom, JOUR, jour, MOIS, mois, ANNEE, annee, TYPE, type, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
//////////////////////////////////////////
/////L'année la plus séche////////
void seche()
{
FILE *f;
FILE *f1;
En a;
char annee[10];
int valeur;
int max;
int annees;

f=fopen("enT.txt","r");
f1=fopen("anneeseches.txt","w");
max=0;

while (fscanf(f,"%s %d %d %d %s %d \n",a.reference,&a.d.j,&a.d.m,&a.d.an,a.heure,&a.valeur)!=EOF)
{
if (max<a.valeur)
{
max=a.valeur;
annees=a.d.an;
}
}
fprintf(f1,"%d %d \n",annees,max);
}

/////////////////////////////////
//////////afficher annee seche//////

void afficher_annee_seche(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
int annees;
int max;

store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS1, G_TYPE_INT, G_TYPE_INT);
f=fopen("anneeseches.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen,("anneeseches.txt","a+");
	while(fscanf(f,"%d %d",&annees,&max)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, ANNEE1, annees, VALEUR, max, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

