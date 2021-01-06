#include<gtk/gtk.h>


typedef struct
{
	char recmois[20];
	int mois;
	int id;
	char nom[20];
	int jour;
	int annee;
	char recjour[30];
	char type[20];
	

}plantation;


void modifier(plantation p); //Modifier le type de plantation 
void ajouter(plantation p); //Ajouter un type de plantation + la période de plantation
void supprimer(plantation p); //Supression d'un type de plantation
void affichage(GtkWidget *liste); //l'affichage d'un tableau de données
void chercher(plantation p); //chercher l'année la plus séche + chercher un type de plantation
void seche(); //Affichage de l'année la plus séche
void afficher_et_rechercher(GtkWidget *liste);
void afficher_annee_seche(GtkWidget *liste);

