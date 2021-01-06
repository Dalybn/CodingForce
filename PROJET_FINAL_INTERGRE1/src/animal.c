#ifdef HAVE_CONFIG.H
#include<config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "animal.h"
#include<gtk/gtk.h>


enum
{
	IDENTIFIANT,
	TYPE,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	COLUMNS,
};




//**********************************Fonction Ajouter**********************************
void Ajouter_A(Animal A)
{
int id;
	char type[30];	
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;
FILE *f;
f=fopen("animal.txt","a+");

A.identifiant=incrementation_ID(id);
	if(f!=NULL)
	{
	 fprintf(f,"%d %s %s %d %s %d\n",A.identifiant,A.type,A.sexe,A.d.jour,A.d.mois,A.d.annee);
	 fclose(f);
	}
}

//**********************************Fonction Afficher**********************************
void Affichage(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;
	char type[30];	
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
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

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);
f=fopen("animal.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("animal.txt","a+");
		while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,IDENTIFIANT, identifiant,TYPE, type,SEXE, sexe, JOUR, jour, MOIS, mois, ANNEE, annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}


//**********************************Fonction Supprimer**********************************
void Supprimer_A(Animal A)
{
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;
FILE *f,*g;
f=fopen("animal.txt","r");
g=fopen("temp.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
	{
	if(A.identifiant!=identifiant || strcmp(A.type,type)!=0 || strcmp(A.sexe,sexe)!=0 || A.d.jour!=jour || strcmp(A.d.mois,mois)!=0 || A.d.annee!=annee)
	fprintf(g,"%d %s %s %d %s %d\n",identifiant,type,sexe,jour,mois,annee);	
	}
fclose(f);
fclose(g);
remove("animal.txt");
rename("temp.txt","animal.txt");
}
}

/*=================================fonction Modifier=================================*/
void Modifier_A(Animal A)
{
FILE *f;
FILE *t;
	int identifiant;
	char type[30];
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

f=fopen("animal.txt","r");
t=fopen("temp.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
	{
		
		if(A.identifiant==identifiant)
		{
			fprintf(t,"%d %s %s %d %s %d\n",A.identifiant,A.type,A.sexe,A.d.jour,A.d.mois,A.d.annee);
		}
		else
			fprintf(t,"%d %s %s %d %s %d\n",identifiant,type,sexe,jour,mois,annee);
    	}
    }
	
fclose(t);
fclose(f);
remove("animal.txt");
rename("temp.txt","animal.txt");
}

/*=================================fonction incrementation ID=================================*/
int incrementation_ID(int id)
{
int n=1;
FILE *f=NULL;
	int identifiant;
	char type[30];
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

//ouvrir le fichier
f=fopen("animal.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
n++;
}
if(n==1)
{
id=1;
}
if(n!=1)
{
id=n;
}
fclose(f);
}
return id;
}

/*=================================fonction verifier ID=================================*/
int verifier(Animal A)
{
FILE *f;
	char type[30];
	int identifiant1;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;
int t,test=0;

f=fopen("animal.txt","r");

    if (f!=NULL)
    {
    while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant1,type,sexe,&jour,mois,&annee)!=EOF)
	{
		if(A.identifiant==identifiant1)
		{
		test++;
		}
	}
		if(test!=0)
		{
		t=1;
		}
		if(test==0)
		t=2;
    }
return t;
}

/*=================================fonction rechercher animal=================================*/
void rechercher_A(Animal A)  
{
FILE* f; 
FILE* f1;
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

f=fopen("animal.txt","r");
f1=fopen("animalcher.txt","w");
 	while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
	{
		if (A.identifiant==identifiant)
		{
		fprintf(f1,"%d %s %s %d %s %d\n",identifiant,type,sexe,jour,mois,annee);
		}
	}
	fclose(f);
	fclose(f1);
}

/*=================================fonction afficher rechercher animal=================================*/
void afficher_A_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
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

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);
f=fopen("animalcher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("animalcher.txt","a+");
		while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,IDENTIFIANT, identifiant,TYPE, type,SEXE, sexe, JOUR, jour, MOIS, mois, ANNEE, annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

/*=================================fonction nombre des animaux inscri=================================*/
int Nombre_Animaux1()
{
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

int nbrAnimaux=0;

FILE *f=NULL;
//ouvrir le fichier
f=fopen("animal.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
nbrAnimaux++;
}

fclose(f);
}
return (nbrAnimaux);
}


/*=================================fonction nombre des moutons=================================*/
int Nombre_mouton()
{
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

int nbrAnimaux=0;

FILE *f=NULL;
//ouvrir le fichier
f=fopen("animal.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
if (strcmp("Mouton",type)==0)
nbrAnimaux++;
}

fclose(f);
}
return (nbrAnimaux);
}

/*=================================fonction nombre des Poulets=================================*/
int Nombre_poulet()
{
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

int nbrAnimaux=0;

FILE *f=NULL;
//ouvrir le fichier
f=fopen("animal.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
if (strcmp("Poulet",type)==0)
nbrAnimaux++;
}

fclose(f);
}
return (nbrAnimaux);
}

/*=================================fonction nombre des Vaches=================================*/
int Nombre_vache()
{
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

int nbrAnimaux=0;

FILE *f=NULL;
//ouvrir le fichier
f=fopen("animal.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
if (strcmp("Vache",type)==0)
nbrAnimaux++;
}

fclose(f);
}
return (nbrAnimaux);
}

/*=================================fonction nombre des Chevals=================================*/
int Nombre_cheval()
{
	char type[30];
	int identifiant;
	char sexe[30];
	int jour;
	char mois[30];
	int annee;

int nbrAnimaux=0;

FILE *f=NULL;
//ouvrir le fichier
f=fopen("animal.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %s %d\n",&identifiant,type,sexe,&jour,mois,&annee)!=EOF)
{
if (strcmp("Cheval",type)==0)
nbrAnimaux++;
}

fclose(f);
}
return (nbrAnimaux);
}


