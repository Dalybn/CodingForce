#include <gtk/gtk.h>
//declaration de la structure Capteur 
typedef struct Capteur
{ 
	char type_capteur[30];
	char marque[30];
	char reference[30];
	char temps_reponse[30];
	char precision[30];
}Capteur;

void ajout_capteur(Capteur c);
void afficher_capteur(GtkWidget *liste);
void supprimer_capteur(Capteur c);
void rechercher_capt(Capteur c, char ref[20]);
void afficher_capteurCH(GtkWidget *liste);
void modif_capteur(Capteur c);
int type;
int nbr_alT();
int nbr_alH();
