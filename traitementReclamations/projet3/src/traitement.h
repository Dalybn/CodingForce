#include<gtk/gtk.h>


typedef struct client
{
char nom[20];
char prenom[20];
int tel;
char identifiant[20];
}client;
typedef struct RECLAMATION
{
    int identifiant_reclamation;
    client id;
    char reclamation [1000];
    char etat[10];
    char reponse[1000];
}RECLAMATION;

void afficher_reclamation(GtkWidget *liste);
void gerer_reclamation(RECLAMATION r);
void ajouter_reclamation(RECLAMATION rec);
int incrementation_ID(int id1);
