#include<gtk/gtk.h>
//declaration de structure catalogue(contient les element vendu dans la ferme)

typedef struct CatalogueC
{
char type[10]; //1:animal |2:legume |3:fruit |4:cerial
char nom[10];
}CatalogueC;

//declaration de structure commande

typedef struct Commande
{
CatalogueC ca;
char quantite[10];
char prix[10];
char reference[10];
char identifiant[20];
}Commande;

//passer une commande
void ajout_commande(Commande c);
void afficher_commande();
int rechercher_commande(Commande c,char id[20]);
void afficher_commandeCH(GtkWidget *liste);
