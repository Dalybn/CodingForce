#ifdef HAVE_CONFIG.H
#include<config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "equipement.h"
#include<gtk/gtk.h>

enum
{
	IDENTIFIANT1,
	JOUR,
	MOIS,
	ANNEE,
	COLUMNS1
};

enum
{
	IDENTIFIANT,
	NOM,
	MARQUE,
	MODELE,
	PUISSANCE,
	TRANSMISSION,
	ETAT,
	JOUR1,
	MOIS1,
	ANNEE1,
	COLUMNS
};


//**********************************Fonction Ajouter Equipement**********************************
void Ajouter_E(Equipement E)
{
FILE *f;
int id;
f=fopen("equipement.txt","a+");
E.identifiant=Nombre_id_equip(id);

	if(f!=NULL)
	{
	 fprintf(f,"%d %s %s %s %s %s %s %s %s %s\n",E.identifiant,E.nom,E.marque,E.modele,E.puissance,E.transmission,E.etat,E.d.jour,E.d.mois,E.d.annee);
	 fclose(f);
	}
}

//**********************************Fonction Ajouter Entretient**********************************
void Ajouter_ent(Equipement E)
{
FILE *f;
f=fopen("entretient.txt","a+");


	if(f!=NULL)
	{
	 fprintf(f,"%d %s %s %s\n",E.identifiant,E.d.jour,E.d.mois,E.d.annee);
	 fclose(f);
	}
}

//**********************************Fonction Afficher Equipement**********************************
void Afficher_E(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("modele",renderer,"text",MODELE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("puissance",renderer,"text",PUISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("transmission",renderer,"text",TRANSMISSION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
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
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("equipement.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("equipement.txt","a+");
		while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT, identifiant, NOM, nom, MARQUE, marque, MODELE, modele, PUISSANCE, puissance, TRANSMISSION, transmission, ETAT, etat,JOUR1,jour,MOIS1,mois,ANNEE1,annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

//**********************************Fonction Afficher Entretient**********************************
void Afficher_ent(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	int identifiant;
	char jour[30];
	char mois[30];
	char annee[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT1,NULL);
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
store=gtk_list_store_new(COLUMNS1, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("entretient.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("entretient.txt","a+");
		while(fscanf(f,"%d %s %s %s\n",&identifiant,jour,mois,annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT1, identifiant, JOUR, jour, MOIS, mois, ANNEE, annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}


//**********************************Fonction Supprimer Equipement**********************************
void Supprimer_E(Equipement E)
{
	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];
FILE *f,*g;
f=fopen("equipement.txt","r");
g=fopen("dump.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
	{
	if(E.identifiant!=identifiant || strcmp(E.nom,nom)!=0 || strcmp(E.marque,marque)!=0 || strcmp(E.modele,modele)!=0 || strcmp(E.puissance,puissance)!=0 || strcmp(E.transmission,transmission) || strcmp(E.etat,etat)!=0 || strcmp(E.d.jour,jour)!=0 || strcmp(E.d.mois,mois)!=0 || strcmp(E.d.annee,annee)!=0)
	fprintf(g,"%d %s %s %s %s %s %s %s %s %s\n",identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee);	
	}

fclose(f);
fclose(g);
remove("equipement.txt");
rename("dump.txt","equipement.txt");
}
}

//**********************************Fonction Supprimer Entretient**********************************
void Supprimer_ent(Equipement E)
{
	int identifiant;
	char jour[30];
	char mois[30];
	char annee[30];
FILE *f,*g;
f=fopen("entretient.txt","r");
g=fopen("dump.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%d %s %s %s\n",&identifiant,jour,mois,annee)!=EOF)
	{
	if(E.identifiant!=identifiant || strcmp(E.d.jour,jour)!=0 || strcmp(E.d.mois,mois)!=0 || strcmp(E.d.annee,annee)!=0)
	fprintf(g,"%d %s %s %s\n",identifiant,jour,mois,annee);	
	}
fclose(f);
fclose(g);
remove("entretient.txt");
rename("dump.txt","entretient.txt");
}
}

/*=================================fonction nombre des equipements=================================*/
int Nombre_Equipenemt()
{
int n=0;
Equipement E;
FILE *f=NULL;
//ouvrir le fichier
f=fopen("equipement.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&E.identifiant,E.nom,E.marque,E.modele,E.puissance,E.transmission,E.etat,E.d.jour,E.d.mois,E.d.annee)!=EOF)
{
n+=1;
}
fclose(f);

}
return n;
}

/*=================================fonction Modifier equipement=================================*/
void Modifier_E(Equipement E)
{
FILE *f;
FILE *t;
	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];

f=fopen("equipement.txt","r");
t=fopen("temp.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
	{
		
		if(E.identifiant==identifiant)
		{
			fprintf(t,"%d %s %s %s %s %s %s %s %s %s\n",E.identifiant,E.nom,E.marque,E.modele,E.puissance,E.transmission,E.etat,E.d.jour,E.d.mois,E.d.annee);
		}
		else
			fprintf(t,"%d %s %s %s %s %s %s %s %s %s\n",identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee);	
    	}
    }
	
fclose(t);
fclose(f);
remove("equipement.txt");
rename("temp.txt","equipement.txt");
}


/*=================================fonction Modifier entretient=================================*/
void Modifier_ent(Equipement E)
{
FILE *f;
FILE *t;
	int identifiant;
	char jour[30];
	char mois[30];
	char annee[30];
f=fopen("entretient.txt","r");
t=fopen("temp.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%d %s %s %s\n",&identifiant,jour,mois,annee)!=EOF)
	{
		
		if(E.identifiant==identifiant)
		{
			fprintf(t,"%d %s %s %s\n",E.identifiant,E.d.jour,E.d.mois,E.d.annee);
		}
		else
			fprintf(t,"%d %s %s %s\n",identifiant,jour,mois,annee);	
    	}
    }
	
fclose(t);
fclose(f);
remove("entretient.txt");
rename("temp.txt","entretient.txt");
}

/*=================================fonction incrementation ID=================================*/
int Nombre_id_equip(int id)
{
int n=1;
FILE *f=NULL;
	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];

//ouvrir le fichier
f=fopen("equipement.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
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


/*=================================fonction rechercher equipement=================================*/
void rechercher_E(Equipement E)  
{
FILE* f; 
FILE* f1;
	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];

f=fopen("equipement.txt","r");
f1=fopen("equipementcher.txt","w");
 	while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
	{
		if (E.identifiant==identifiant)
		{
		fprintf(f1,"%d %s %s %s %s %s %s %s %s %s\n",identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee);
		}
	}
	fclose(f);
	fclose(f1);
}

/*=================================fonction afficher rechercher equipement=================================*/
void afficher_E_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("modele",renderer,"text",MODELE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("puissance",renderer,"text",PUISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("transmission",renderer,"text",TRANSMISSION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
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
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("equipementcher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("equipementcher.txt","a+");
		while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT, identifiant, NOM, nom, MARQUE, marque, MODELE, modele, PUISSANCE, puissance, TRANSMISSION, transmission, ETAT, etat,JOUR1,jour,MOIS1,mois,ANNEE1,annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


/*=================================fonction rechercher entretient=================================*/
void rechercher_ent(Equipement E)  
{
FILE* f; 
FILE* f1;
	int identifiant;
	char jour[30];
	char mois[30];
	char annee[30];

f=fopen("entretient.txt","r");
f1=fopen("entretientcher.txt","w");
 	while(fscanf(f,"%d %s %s %s\n",&identifiant,jour,mois,annee)!=EOF)
	{
		if (E.identifiant==identifiant)
		{
		fprintf(f1,"%d %s %s %s\n",identifiant,jour,mois,annee);
		}
	}
	fclose(f);
	fclose(f1);
}

/*=================================fonction afficher rechercher entretient=================================*/
void afficher_ent_rechercher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	int identifiant;
	char jour[30];
	char mois[30];
	char annee[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT1,NULL);
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
store=gtk_list_store_new(COLUMNS1, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("entretientcher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("entretientcher.txt","a+");
		while(fscanf(f,"%d %s %s %s\n",&identifiant,jour,mois,annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, IDENTIFIANT1, identifiant, JOUR, jour, MOIS, mois, ANNEE, annee, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

/*=================================fonction verifier ID_Equipement=================================*/
int verifier_Equip(Equipement E)
{
FILE *f;
	char nom[30];
	char marque[30];
	char modele[30];
	char puissance[30];
	char transmission[30];
	int identifiant;
	char etat[30];
	char jour[20];
	char mois[20];
	char annee[20];
int t,test=0;

f=fopen("equipement.txt","r");

    if (f!=NULL)
    {
    while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s\n",&identifiant,nom,marque,modele,puissance,transmission,etat,jour,mois,annee)!=EOF)
	{
		if(E.identifiant==identifiant)
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

/*=================================fonction verifier ID_Entretient=================================*/
int verifier_Ent(Equipement E)
{
FILE *f;
	int identifiant;
	char jour[30];
	char mois[30];
	char annee[30];
int t,test=0;

f=fopen("entretient.txt","r");

    if (f!=NULL)
    {
    while(fscanf(f,"%d %s %s %s\n",&identifiant,jour,mois,annee)!=EOF)
	{
		if(E.identifiant==identifiant)
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


