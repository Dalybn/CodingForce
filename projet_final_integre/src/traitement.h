#include<gtk/gtk.h>
typedef struct {
int jour;
char mois[20];
int  annee;
}date_reclamation;

typedef struct RECLAMATION
{
    int identifiant_reclamation;
    char identifiant[20];
	date_reclamation d;
    char recl [1000];
    char etat[100];
    char rep[1000];
}RECLAMATION;
void afficher_reclamation_rechercher(GtkWidget *liste);
void rechercher_reclamation(char id[10]);
void afficher_reclamation(GtkWidget *liste);
void gerer_reclamation(RECLAMATION r);
void ajouter_reclamation(RECLAMATION r);
int incrementation_IDrec(int id1);
int etat;
