#ifdef HAVE_CONFIG.H
#include<config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ouv.h"
#include<gtk/gtk.h>

enum
{
	ID,
	NOM,
	PRENOM,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	CIN,
	TELEPHONE,
	ADRESSE,
	COLUMNS
};

enum
{
	ID1,
	JOUR1,
	MOIS1,
	ANNEE1,
	RAISON,
	COLUMNS1
};

////fonction ajouter un ouvrier////

void Ajouter(Ouvrier p)
{
int id;
FILE *f;
FILE *k;
f=fopen("utilisateur.txt","a+");
p.id=Nombre_id(id);

	if(f!=NULL)
	{
	 fprintf(f," %d %s %s %s %d %s %d %s %s %s \n",p.id,p.nom,p.prenom,p.sexe,p.d.jour,p.d.mois,p.d.annee,p.cin,p.telephone,p.adresse);
	 fclose(f);
	}
}

int Nombre_id(int id)
{
int n=1;
FILE *f=NULL;

char nom[30];
char prenom[30];
char sexe [30];
int jour;
int identifiant;
char mois[20];
int annee;
char cin[30];
char telephone[30];
char adresse[30];

//ouvrir le fichier
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %s %d %s %d %s %s %s\n",&identifiant,nom,prenom,sexe,&jour,mois,&annee,cin,telephone,adresse)!=EOF)
{
n++;
}
if(n==1)
id=1;
else
{
id=n;
fclose(f);
}

}
else 
printf("\n Not found");

return id;
}


////fonction affichage ////

void afficher_ouvrier(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
int id;
char nom[30];
char sexe[30];
char prenom[30];
int jour;
char mois[20];
int annee;
char cin[30];
char telephone[30];
char adresse[30];
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
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
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
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateur.txt","a+");
while(fscanf(f," %d %s %s %s %d %s %d %s %s %s\n",&id,nom,prenom,sexe,&jour,mois,&annee,cin,telephone,adresse)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, ID,id , NOM,nom, PRENOM,prenom, SEXE,sexe , JOUR,jour, MOIS,mois, ANNEE,annee , CIN,cin, TELEPHONE,telephone , ADRESSE,adresse, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
//fonction supprimer
void supprimer_ouvrier (Ouvrier p)
{

int id;
char nom[30];
char sexe[30];
char prenom[30];
int jour;
char mois[20];
int annee;
char cin[30];
char telephone[30];
char adresse[30];
FILE *f,*g, *k, *m;
f=fopen("utilisateur.txt","r");
g=fopen("temp.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
    while(fscanf(f," %d %s %s %s %d %s %d %s %s %s\n",&id,nom,prenom,sexe,&jour,mois,&annee,cin,telephone,adresse)!=EOF)
    {
    if(p.id!=id || strcmp(p.nom,nom)!=0 ||strcmp(p.prenom,prenom)!=0 || strcmp(p.sexe,sexe)!=0 || p.d.jour!=jour || strcmp(p.d.mois,mois)!=0 || p.d.annee!=annee || strcmp(p.cin,cin)!=0 || strcmp(p.telephone,telephone)!=0 || strcmp(p.adresse,adresse)!=0)
    fprintf(g," %d %s %s %s %d %s %d %s %s %s\n",id,nom,prenom,sexe,jour,mois,annee,cin,telephone,adresse);
    }
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("temp.txt","utilisateur.txt");
}
}

///fonction modifier////

void Modifier(Ouvrier p)
{
FILE *f;
FILE *t;
    int id;
char nom[20];
char prenom[20];
 char sexe[20];
    int jour;
    char mois[20];
    int annee;
char cin[20];
char telephone[20];
char adresse[20];

f=fopen("utilisateur.txt","r");
t=fopen("utilis.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%d %s %s %s %d %s %d %s %s %s\n",&id,nom,prenom,sexe,&jour,mois,&annee,cin,telephone,adresse)!=EOF)
    {

        if(p.id==id)
        {
            fprintf(t," %d %s %s %s %d %s %d %s %s %s \n",p.id,p.nom,p.prenom,p.sexe,p.d.jour,p.d.mois,p.d.annee,p.cin,p.telephone,p.adresse);
        }
        else
            fprintf(t," %d %s %s %s %d %s %d %s %s %s \n",id,nom,prenom,sexe,jour,mois,annee,cin,telephone,adresse);
        }
    }

fclose(t);
fclose(f);
remove("utilisateur.txt");
rename("utilis.txt","utilisateur.txt");
}


///rechercher ouvrier///

void rechercher_ouvrier(Ouvrier p)  
{
FILE* f; 
FILE* f1;
    int id;
char nom[20];
char prenom[20];
 char sexe[20];
    int jour;
    char mois[20];
    int annee;
char cin[20];
char telephone[20];
char adresse[20];

f=fopen("utilisateur.txt","r");
f1=fopen("utilisateurcher.txt","w");
     while(fscanf(f,"%d %s %s %s %d %s %d %s %s %s\n",&id,nom,prenom,sexe,&jour,mois,&annee,cin,telephone,adresse)!=EOF)
    {
        if (p.id==id)
        {
        fprintf(f1,"%d %s %s %s %d %s %d %s %s %s \n",id,nom,prenom,sexe,jour,mois,annee,cin,telephone,adresse);
        }
    }
    fclose(f);
    fclose(f1);
}
////affichage rechercher
void afficher_ouvrier_rechercher(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
int id;
char nom[30];
char sexe[30];
char prenom[30];
char jour[20];
char mois[20];
char annee[20];
char cin[30];
char telephone[30];
char adresse[30];
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
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
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
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("utilisateurcher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateurcher.txt","a+");
while(fscanf(f," %d %s %s %s %s %s %s %s %s %s\n",&id,nom,prenom,sexe,jour,mois,annee,cin,telephone,adresse)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, ID,id , NOM,nom, PRENOM,prenom, SEXE,sexe , JOUR,jour, MOIS,mois, ANNEE,annee , CIN,cin, TELEPHONE,telephone , ADRESSE,adresse, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


/////fonction ajouter une absence//////

void Ajouter_absence(Absence p)
{

FILE *f;
f=fopen("absence.txt","a+");


	if(f!=NULL)
	{
	 fprintf(f," %d %d %s %d %s \n",p.ID,p.da.jour,p.da.mois,p.da.annee,p.raison);
	 fclose(f);
	}
}


////fonction affichage absence ////

void afficher_absence(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


GtkListStore *store;
int ID;
int jour;
char mois[20];
int annee;
char raison[1000];

store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("raison",renderer,"text",RAISON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS1, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);
f=fopen("absence.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("absence.txt","a+");
while(fscanf(f," %d %d %s %d %s\n",&ID,&jour,mois,&annee,raison)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, ID1,ID , JOUR1,jour, MOIS1,mois, ANNEE1,annee , RAISON,raison, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}


//supprimer absence//

void supprimer_absence (Absence p)
{

int ID;
int jour;
char mois[20];
int annee;
char raison[1000];
FILE *f,*g;
f=fopen("absence.txt","r");
g=fopen("tempabs.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
    while(fscanf(f," %d %d %s %d %s\n",&ID,&jour,mois,&annee,raison)!=EOF)
    {
    if(p.ID!=ID || p.da.jour!=jour || strcmp(p.da.mois,mois)!=0 || p.da.annee!=annee || strcmp(p.raison,raison)!=0)
    fprintf(g," %d %d %s %d %s\n",ID,jour,mois,annee,raison);
    }
fclose(f);
fclose(g);
remove("absence.txt");
rename("tempabs.txt","absence.txt");
}
}

int CalculerNbrOuvrier() {

FILE *k=NULL;
int nbr=0;
Ouvrier p;
k=fopen("utilisateur.txt","r");
while (fscanf(k,"%d %s %s %s %d %s %d %s %s %s \n",&p.id,p.nom,p.prenom,p.sexe,&p.d.jour,p.d.mois,&p.d.annee,p.cin,p.telephone,p.adresse)!=EOF)
{
nbr=nbr+1; 

}

fclose(k);
return nbr;

}

///*****************************

int CalculerNbrOuvrierAbsent() {

FILE *f=NULL;
int nbr=0;
Absence p;
f=fopen("absence.txt","r");
while (fscanf(f,"%d %d %s %d %s\n",&p.ID,&p.da.jour,p.da.mois,&p.da.annee,p.raison)!=EOF)
//{if(annee==p.anneee)))) { tot=tot+1;}
nbr=nbr+1; 
fclose(f);
return nbr;

}




//***********************************************


float CalculeTaux()

{FILE *f=NULL;
int nbr_abs;
int nbr_ouv;
double taux;
nbr_abs=CalculerNbrOuvrierAbsent();
nbr_ouv=CalculerNbrOuvrier();
taux=(float) nbr_abs/nbr_ouv;
//fprintf(f,"%.2f",taux);

return taux*100;

}

