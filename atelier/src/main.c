/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *liste_capteurs;
  GtkWidget *ajouter_capteur;
  GtkWidget *fenetre_ajouter_enH;
  GtkWidget *fenetre_afficher_enH;
  GtkWidget *fenetre_ajouter_enT;
  GtkWidget *fenetre_afficher_enT;
  GtkWidget *modifier_capteur;
  GtkWidget *f_chercher_capteur;
  GtkWidget *capteur;
  GtkWidget *capteur_defect;
  GtkWidget *gestion_capteur;
  GtkWidget *gestion_client;
GtkWidget *fenetre_ajouter_client;
GtkWidget *fenetre_ajouter_reclamation;
 GtkWidget *fenetre_afficher_client;
 GtkWidget *fenetre_afficher_reclamation;
GtkWidget *fenetre_modifier_client;
  GtkWidget *fenetre_responsable;
  GtkWidget *liste_commande;
  GtkWidget *ajoute_commande;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */


  fenetre_responsable = create_fenetre_responsable();
  gtk_widget_show (fenetre_responsable);

  /*liste_capteurs = create_liste_capteurs ();
  gtk_widget_show (liste_capteurs);*/

  gtk_main ();
  return 0;
}
