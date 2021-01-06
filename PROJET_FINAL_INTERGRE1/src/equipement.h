#include<gtk/gtk.h>


typedef struct date
{
char jour[30];
char mois[30];
char annee[30];
}date_equip;

typedef struct Equipement
{
char nom[20];
int identifiant;
char marque[20];
char modele[20];
char puissance[20];
date_equip d;
char transmission[20];
char etat[20];
}Equipement;


//Déclaration des fonctions
//fonction ajouter
void Ajouter_E(Equipement E);
void Ajouter_ent(Equipement E);

//fonction modifier
void Modifier_E(Equipement E);
void Modifier_ent(Equipement E);

//fonction supprimer 
void Supprimer_E(Equipement E);
void Supprimer_ent(Equipement E);

//fonction nombre des equipement
int Nombre_Equipenemt();

//fonction affichage
void Afficher_E(GtkWidget *liste);
void Afficher_ent(GtkWidget *liste);
void afficher_E_rechercher(GtkWidget *liste);
void afficher_ent_rechercher(GtkWidget *liste);

//fonction recherche
void rechercher_E(Equipement E);
void rechercher_ent(Equipement E);


//fonction incrementation id
int Nombre_id_equip(int id);

//fonction verifier ID
int verifier_Equip(Equipement E);
int verifier_Ent(Equipement E);

int etat_equip;





