#include<gtk/gtk.h>
typedef struct {
int jour;
char mois[20];
int annee;
}date;

typedef struct {
int id;
char nom[20];
char prenom[20];
char sexe[20];
date d;
char telephone[20];
char adresse[20];
char  cin[20];

}Ouvrier;
typedef struct{
int ID;
date da;
char raison[1000];
}Absence;




void Ajouter(Ouvrier p); // ajouter un ouvrier

void Modifier(Ouvrier p); // modifier les informations d'un ouvrier

void supprimer_ouvrier (Ouvrier p); //supprimer un ouvrier

void afficher_ouvrier(GtkWidget *liste); // afficher la liste des ouvriers

void Ajouter_absence(Absence p); //fonction pour ajouter une absence

void afficher_absence(GtkWidget *liste);

void supprimer_absence(Absence p);

int Nombre_id(int id);

void rechercher_ouvrier(Ouvrier p);

void afficher_ouvrier_rechercher(GtkWidget *liste);

void supprimer_absence (Absence p);

float CalculeTaux();

int CalculerNbrOuvrierAbsent();

int CalculerNbrOuvrier();

int radio;
