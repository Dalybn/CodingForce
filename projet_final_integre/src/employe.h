#include<gtk/gtk.h>

typedef struct date_employe{
int jour;
int mois;
int annee;
}date_employe;

typedef struct employe {
char nom[30];
char prenom[30];
char sexe[30];
char cin[30];
date_employe date_naissance;
char numero[30];
char adresse[30];
char poste[30];
}employe;
int x;
int y;

void ajouter_employe(employe E);
void afficher_employe(GtkWidget *liste);
void supprimer_employe(employe E);
int exist_cin(char* cin);
void modifier_employe(employe E);
void rechercher_employe(employe E);
void afficher_emp_rechercher(GtkWidget *liste);

//fonction verifier ID
int verifier_CIN_inscrit(char cin[30]);

//fonction verifier PASSEWORD
int verifier_PASSEWORD_inscrit(char passeword[30]);

//fonction verifier ACCEE
int verifier_ACCEE_inscrit(char cin[30]);
