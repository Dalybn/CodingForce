#include <gtk/gtk.h>
#include <gtk/gtk.h>
typedef struct {
int j;
int m;
int an;
}date1;
//structure de reclamation
typedef struct En{
date1 d;
char heure[1000];
char reference[20];
int valeur;

}En;
void ajouter_enH(En a);
void afficher_enH(GtkWidget *liste);
void ajouter_enT(En a);
void afficher_enT(GtkWidget *liste);
void captALH();
void afficher_captDEFH(GtkWidget *liste);
void captALT();
void afficher_captDEFT(GtkWidget *liste);
