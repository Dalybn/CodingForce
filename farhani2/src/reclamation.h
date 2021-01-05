#include <gtk/gtk.h>
typedef struct {
int jour;
int mois;
int  annee;
}date;
//structure de reclamation
typedef struct RECLAMATION{
date d;
char recl[1000];
char identifiant[20];
char etat[30];
char rep[1000];

}RECLAMATION;
typedef struct{
//char num[30];
char nom[30];
char prenom[30];
char adresse[30];
char tel[30];
char sexe[30];
char identifiant[30];
} client;
void ajouter_reclamation(RECLAMATION REC);
void afficher_reclamation(GtkWidget *liste);
void supprimer_reclamation(RECLAMATION REC);
void modifier_reclamation(RECLAMATION REC);
void afficher_reclamation_rechercher(GtkWidget *liste);
void rechercher_reclamation(char id[10]);
void ajouter_client(client c);
void afficher_client(GtkWidget *liste);
//int numero_client(int numm);
void supprimer_client(client c);
void modifier_client(client c);
void rechercher_client(char id[20]);
void afficher_client_rechercher(GtkWidget *liste);
int etat;
