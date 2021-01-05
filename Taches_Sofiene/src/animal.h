#include<gtk/gtk.h>



typedef struct Date
{
int jour;
char mois[20];
int annee;
}Date;


typedef struct Animal
{
char type[20];
char sexe[20];
int identifiant;
Date d;
}Animal;

//Déclaration des fonctions
//fonction ajouter
void Ajouter_A(Animal A);

//fonction modifier
void Modifier_A(Animal A);

//fonction supprimer 
void Supprimer_A(Animal A);

//fonction nombre des animaux inscri
int Nombre_Animaux1(Animal A);

//fonction Affichage
void Affichage(GtkWidget *liste);
void afficher_A_rechercher(GtkWidget *liste);

//fonction rechercher
void rechercher_A(Animal A);

//fonction icrementation id
int incrementation_ID(int id);

//fonction verifier
int verifier(Animal A);

int s;
int x;

