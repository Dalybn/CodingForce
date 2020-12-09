#include <gtk/gtk.h>
#include <gtk/gtk.h>
typedef struct {
int j;
int m;
int an;
}date;
//structure de reclamation
typedef struct En{
date d;
char heure[1000];
char reference[20];
char valeur[30];

}En;
void ajouter_enH(En a);
void afficher_enH(GtkWidget *liste);
void ajouter_enT(En a);
void afficher_enT(GtkWidget *liste);
