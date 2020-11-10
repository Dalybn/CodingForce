/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_ProjetC (void)
{
  GtkWidget *ProjetC;
  GtkWidget *fixed1;
  GtkWidget *button2;
  GtkWidget *RQ;
  GtkWidget *button1;
  GtkWidget *button12;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label32;

  ProjetC = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (ProjetC), _("Projet C"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (ProjetC), fixed1);

  button2 = gtk_button_new_with_mnemonic (_("la gestion des equipements agricoles"));
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed1), button2, 48, 200);
  gtk_widget_set_size_request (button2, 320, 56);

  RQ = gtk_label_new (_("Responsable de Qualit\303\251"));
  gtk_widget_show (RQ);
  gtk_fixed_put (GTK_FIXED (fixed1), RQ, 96, 32);
  gtk_widget_set_size_request (RQ, 240, 48);

  button1 = gtk_button_new_with_mnemonic (_("la gestion des capteurs"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 48, 104);
  gtk_widget_set_size_request (button1, 320, 56);

  button12 = gtk_button_new ();
  gtk_widget_show (button12);
  gtk_fixed_put (GTK_FIXED (fixed1), button12, 32, 312);
  gtk_widget_set_size_request (button12, 112, 32);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (button12), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label32 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label32);
  gtk_box_pack_start (GTK_BOX (hbox8), label32, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (ProjetC, ProjetC, "ProjetC");
  GLADE_HOOKUP_OBJECT (ProjetC, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (ProjetC, button2, "button2");
  GLADE_HOOKUP_OBJECT (ProjetC, RQ, "RQ");
  GLADE_HOOKUP_OBJECT (ProjetC, button1, "button1");
  GLADE_HOOKUP_OBJECT (ProjetC, button12, "button12");
  GLADE_HOOKUP_OBJECT (ProjetC, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (ProjetC, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (ProjetC, image8, "image8");
  GLADE_HOOKUP_OBJECT (ProjetC, label32, "label32");

  return ProjetC;
}

GtkWidget*
create_Liste_des_capteurs (void)
{
  GtkWidget *Liste_des_capteurs;
  GtkWidget *fixed2;
  GtkWidget *table1;
  GtkWidget *label10;
  GtkWidget *label11;
  GtkWidget *label12;
  GtkWidget *label13;
  GtkWidget *label14;
  GtkWidget *label15;
  GtkWidget *checkbutton1;
  GtkWidget *checkbutton2;
  GtkWidget *label16;
  GtkWidget *button5;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label27;
  GtkWidget *button8;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label28;
  GtkWidget *button9;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label30;
  GtkWidget *button7;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label29;
  GtkWidget *button15;
  GtkWidget *alignment11;
  GtkWidget *hbox11;
  GtkWidget *image11;
  GtkWidget *label44;
  GtkWidget *label17;

  Liste_des_capteurs = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Liste_des_capteurs), _("Liste des capteurs"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (Liste_des_capteurs), fixed2);

  table1 = gtk_table_new (3, 7, FALSE);
  gtk_widget_show (table1);
  gtk_fixed_put (GTK_FIXED (fixed2), table1, 248, 72);
  gtk_widget_set_size_request (table1, 112, 48);

  label10 = gtk_label_new (_("Nom de capteur"));
  gtk_widget_show (label10);
  gtk_table_attach (GTK_TABLE (table1), label10, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label10), 0, 0.5);

  label11 = gtk_label_new (_("Marque"));
  gtk_widget_show (label11);
  gtk_table_attach (GTK_TABLE (table1), label11, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label11), 0, 0.5);

  label12 = gtk_label_new (_("Reference"));
  gtk_widget_show (label12);
  gtk_table_attach (GTK_TABLE (table1), label12, 3, 4, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label12), 0, 0.5);

  label13 = gtk_label_new (_("Stabilit\303\251 \303\240 long terme"));
  gtk_widget_show (label13);
  gtk_table_attach (GTK_TABLE (table1), label13, 4, 5, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label13), 0, 0.5);

  label14 = gtk_label_new (_("Temps de reponse"));
  gtk_widget_show (label14);
  gtk_table_attach (GTK_TABLE (table1), label14, 5, 6, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label14), 0, 0.5);

  label15 = gtk_label_new (_("Precision"));
  gtk_widget_show (label15);
  gtk_table_attach (GTK_TABLE (table1), label15, 6, 7, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label15), 0, 0.5);

  checkbutton1 = gtk_check_button_new_with_mnemonic ("");
  gtk_widget_show (checkbutton1);
  gtk_table_attach (GTK_TABLE (table1), checkbutton1, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  checkbutton2 = gtk_check_button_new_with_mnemonic ("");
  gtk_widget_show (checkbutton2);
  gtk_table_attach (GTK_TABLE (table1), checkbutton2, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label16 = gtk_label_new ("");
  gtk_widget_show (label16);
  gtk_table_attach (GTK_TABLE (table1), label16, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label16), 0, 0.5);

  button5 = gtk_button_new ();
  gtk_widget_show (button5);
  gtk_fixed_put (GTK_FIXED (fixed2), button5, 384, 216);
  gtk_widget_set_size_request (button5, 192, 32);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (button5), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label27 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label27);
  gtk_box_pack_start (GTK_BOX (hbox3), label27, FALSE, FALSE, 0);

  button8 = gtk_button_new ();
  gtk_widget_show (button8);
  gtk_fixed_put (GTK_FIXED (fixed2), button8, 656, 216);
  gtk_widget_set_size_request (button8, 192, 32);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (button8), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label28 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (hbox4), label28, FALSE, FALSE, 0);

  button9 = gtk_button_new ();
  gtk_widget_show (button9);
  gtk_fixed_put (GTK_FIXED (fixed2), button9, 120, 216);
  gtk_widget_set_size_request (button9, 192, 32);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (button9), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label30 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label30);
  gtk_box_pack_start (GTK_BOX (hbox6), label30, FALSE, FALSE, 0);

  button7 = gtk_button_new ();
  gtk_widget_show (button7);
  gtk_fixed_put (GTK_FIXED (fixed2), button7, 936, 216);
  gtk_widget_set_size_request (button7, 192, 32);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (button7), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label29 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label29);
  gtk_box_pack_start (GTK_BOX (hbox5), label29, FALSE, FALSE, 0);

  button15 = gtk_button_new ();
  gtk_widget_show (button15);
  gtk_fixed_put (GTK_FIXED (fixed2), button15, 536, 272);
  gtk_widget_set_size_request (button15, 192, 32);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (button15), alignment11);

  hbox11 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

  image11 = gtk_image_new_from_stock ("gtk-close", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox11), image11, FALSE, FALSE, 0);

  label44 = gtk_label_new_with_mnemonic (_("Quitter"));
  gtk_widget_show (label44);
  gtk_box_pack_start (GTK_BOX (hbox11), label44, FALSE, FALSE, 0);

  label17 = gtk_label_new (_("Liste des capteurs"));
  gtk_widget_show (label17);
  gtk_fixed_put (GTK_FIXED (fixed2), label17, 416, 16);
  gtk_widget_set_size_request (label17, 416, 40);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Liste_des_capteurs, Liste_des_capteurs, "Liste_des_capteurs");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, table1, "table1");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label10, "label10");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label11, "label11");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label12, "label12");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label13, "label13");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label14, "label14");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label15, "label15");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, checkbutton1, "checkbutton1");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, checkbutton2, "checkbutton2");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label16, "label16");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, button5, "button5");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, image3, "image3");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label27, "label27");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, button8, "button8");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, image4, "image4");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label28, "label28");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, button9, "button9");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, image6, "image6");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label30, "label30");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, button7, "button7");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, image5, "image5");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label29, "label29");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, button15, "button15");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, image11, "image11");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label44, "label44");
  GLADE_HOOKUP_OBJECT (Liste_des_capteurs, label17, "label17");

  return Liste_des_capteurs;
}

GtkWidget*
create_Ajouter_un_capteur (void)
{
  GtkWidget *Ajouter_un_capteur;
  GtkWidget *fixed3;
  GtkWidget *label21;
  GtkWidget *label22;
  GtkWidget *label23;
  GtkWidget *label24;
  GtkWidget *entry1;
  GtkWidget *label20;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *entry5;
  GtkWidget *entry6;
  GtkWidget *label19;
  GtkWidget *label18;
  GtkWidget *button10;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label26;
  GtkWidget *button11;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label25;

  Ajouter_un_capteur = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Ajouter_un_capteur), _("Ajouter un capteur"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (Ajouter_un_capteur), fixed3);

  label21 = gtk_label_new (_("Reference :"));
  gtk_widget_show (label21);
  gtk_fixed_put (GTK_FIXED (fixed3), label21, 8, 160);
  gtk_widget_set_size_request (label21, 104, 24);

  label22 = gtk_label_new (_("Stabilit\303\251 \303\240 long terme :"));
  gtk_widget_show (label22);
  gtk_fixed_put (GTK_FIXED (fixed3), label22, 8, 200);
  gtk_widget_set_size_request (label22, 200, 32);

  label23 = gtk_label_new (_("Temps de reponse :"));
  gtk_widget_show (label23);
  gtk_fixed_put (GTK_FIXED (fixed3), label23, 8, 248);
  gtk_widget_set_size_request (label23, 168, 30);

  label24 = gtk_label_new (_("Precision :"));
  gtk_widget_show (label24);
  gtk_fixed_put (GTK_FIXED (fixed3), label24, 8, 296);
  gtk_widget_set_size_request (label24, 101, 30);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed3), entry1, 216, 64);
  gtk_widget_set_size_request (entry1, 192, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  label20 = gtk_label_new (_("Marque :"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed3), label20, 0, 112);
  gtk_widget_set_size_request (label20, 96, 24);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed3), entry2, 216, 104);
  gtk_widget_set_size_request (entry2, 192, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed3), entry3, 216, 160);
  gtk_widget_set_size_request (entry3, 192, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_fixed_put (GTK_FIXED (fixed3), entry4, 216, 208);
  gtk_widget_set_size_request (entry4, 192, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry4), 8226);

  entry5 = gtk_entry_new ();
  gtk_widget_show (entry5);
  gtk_fixed_put (GTK_FIXED (fixed3), entry5, 216, 256);
  gtk_widget_set_size_request (entry5, 192, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry5), 8226);

  entry6 = gtk_entry_new ();
  gtk_widget_show (entry6);
  gtk_fixed_put (GTK_FIXED (fixed3), entry6, 216, 304);
  gtk_widget_set_size_request (entry6, 192, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry6), 8226);

  label19 = gtk_label_new (_("Nom de capteur :"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed3), label19, 8, 64);
  gtk_widget_set_size_request (label19, 152, 24);

  label18 = gtk_label_new (_("Ajouter un capteur"));
  gtk_widget_show (label18);
  gtk_fixed_put (GTK_FIXED (fixed3), label18, 120, 16);
  gtk_widget_set_size_request (label18, 181, 22);

  button10 = gtk_button_new ();
  gtk_widget_show (button10);
  gtk_fixed_put (GTK_FIXED (fixed3), button10, 256, 352);
  gtk_widget_set_size_request (button10, 120, 32);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (button10), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-floppy", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label26 = gtk_label_new_with_mnemonic (_("Enregistrer"));
  gtk_widget_show (label26);
  gtk_box_pack_start (GTK_BOX (hbox2), label26, FALSE, FALSE, 0);

  button11 = gtk_button_new ();
  gtk_widget_show (button11);
  gtk_fixed_put (GTK_FIXED (fixed3), button11, 48, 352);
  gtk_widget_set_size_request (button11, 120, 32);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (button11), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label25 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label25);
  gtk_box_pack_start (GTK_BOX (hbox1), label25, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Ajouter_un_capteur, Ajouter_un_capteur, "Ajouter_un_capteur");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label21, "label21");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label22, "label22");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label23, "label23");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label24, "label24");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label20, "label20");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, entry5, "entry5");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, entry6, "entry6");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label19, "label19");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label18, "label18");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, button10, "button10");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, image2, "image2");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label26, "label26");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, button11, "button11");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, image1, "image1");
  GLADE_HOOKUP_OBJECT (Ajouter_un_capteur, label25, "label25");

  return Ajouter_un_capteur;
}

GtkWidget*
create_Modifier (void)
{
  GtkWidget *Modifier;
  GtkWidget *fixed4;
  GtkWidget *label33;
  GtkWidget *label37;
  GtkWidget *label35;
  GtkWidget *label36;
  GtkWidget *label34;
  GtkWidget *label39;
  GtkWidget *label38;
  GtkWidget *label40;
  GtkWidget *entry7;
  GtkWidget *entry8;
  GtkWidget *entry9;
  GtkWidget *entry10;
  GtkWidget *entry11;
  GtkWidget *entry12;
  GtkWidget *button14;
  GtkWidget *alignment10;
  GtkWidget *hbox10;
  GtkWidget *image10;
  GtkWidget *label43;
  GtkWidget *button13;
  GtkWidget *alignment9;
  GtkWidget *hbox9;
  GtkWidget *image9;
  GtkWidget *label41;

  Modifier = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Modifier), _("Modifier"));

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (Modifier), fixed4);

  label33 = gtk_label_new (_("Modifier le capteur"));
  gtk_widget_show (label33);
  gtk_fixed_put (GTK_FIXED (fixed4), label33, 104, 24);
  gtk_widget_set_size_request (label33, 184, 24);

  label37 = gtk_label_new ("");
  gtk_widget_show (label37);
  gtk_fixed_put (GTK_FIXED (fixed4), label37, 64, 176);
  gtk_widget_set_size_request (label37, 61, 22);

  label35 = gtk_label_new (_("Marque :"));
  gtk_widget_show (label35);
  gtk_fixed_put (GTK_FIXED (fixed4), label35, 0, 104);
  gtk_widget_set_size_request (label35, 96, 32);

  label36 = gtk_label_new (_("Reference :"));
  gtk_widget_show (label36);
  gtk_fixed_put (GTK_FIXED (fixed4), label36, 0, 152);
  gtk_widget_set_size_request (label36, 112, 24);

  label34 = gtk_label_new (_("Nom de capteur :"));
  gtk_widget_show (label34);
  gtk_fixed_put (GTK_FIXED (fixed4), label34, 0, 64);
  gtk_widget_set_size_request (label34, 160, 32);

  label39 = gtk_label_new (_("Temps de reponse :"));
  gtk_widget_show (label39);
  gtk_fixed_put (GTK_FIXED (fixed4), label39, 0, 192);
  gtk_widget_set_size_request (label39, 168, 32);

  label38 = gtk_label_new (_("Stabilit\303\251 \303\240 long terme :"));
  gtk_widget_show (label38);
  gtk_fixed_put (GTK_FIXED (fixed4), label38, 8, 240);
  gtk_widget_set_size_request (label38, 192, 32);

  label40 = gtk_label_new (_("Precision :"));
  gtk_widget_show (label40);
  gtk_fixed_put (GTK_FIXED (fixed4), label40, 0, 280);
  gtk_widget_set_size_request (label40, 96, 32);

  entry7 = gtk_entry_new ();
  gtk_widget_show (entry7);
  gtk_fixed_put (GTK_FIXED (fixed4), entry7, 216, 64);
  gtk_widget_set_size_request (entry7, 184, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry7), 8226);

  entry8 = gtk_entry_new ();
  gtk_widget_show (entry8);
  gtk_fixed_put (GTK_FIXED (fixed4), entry8, 216, 112);
  gtk_widget_set_size_request (entry8, 184, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry8), 8226);

  entry9 = gtk_entry_new ();
  gtk_widget_show (entry9);
  gtk_fixed_put (GTK_FIXED (fixed4), entry9, 216, 152);
  gtk_widget_set_size_request (entry9, 184, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry9), 8226);

  entry10 = gtk_entry_new ();
  gtk_widget_show (entry10);
  gtk_fixed_put (GTK_FIXED (fixed4), entry10, 216, 200);
  gtk_widget_set_size_request (entry10, 184, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry10), 8226);

  entry11 = gtk_entry_new ();
  gtk_widget_show (entry11);
  gtk_fixed_put (GTK_FIXED (fixed4), entry11, 216, 248);
  gtk_widget_set_size_request (entry11, 184, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry11), 8226);

  entry12 = gtk_entry_new ();
  gtk_widget_show (entry12);
  gtk_fixed_put (GTK_FIXED (fixed4), entry12, 216, 288);
  gtk_widget_set_size_request (entry12, 184, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry12), 8226);

  button14 = gtk_button_new ();
  gtk_widget_show (button14);
  gtk_fixed_put (GTK_FIXED (fixed4), button14, 32, 352);
  gtk_widget_set_size_request (button14, 128, 32);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (button14), alignment10);

  hbox10 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox10);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

  image10 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox10), image10, FALSE, FALSE, 0);

  label43 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label43);
  gtk_box_pack_start (GTK_BOX (hbox10), label43, FALSE, FALSE, 0);

  button13 = gtk_button_new ();
  gtk_widget_show (button13);
  gtk_fixed_put (GTK_FIXED (fixed4), button13, 240, 352);
  gtk_widget_set_size_request (button13, 128, 32);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (button13), alignment9);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

  image9 = gtk_image_new_from_stock ("gtk-floppy", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image9);
  gtk_box_pack_start (GTK_BOX (hbox9), image9, FALSE, FALSE, 0);

  label41 = gtk_label_new_with_mnemonic (_("Enregistrer"));
  gtk_widget_show (label41);
  gtk_box_pack_start (GTK_BOX (hbox9), label41, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Modifier, Modifier, "Modifier");
  GLADE_HOOKUP_OBJECT (Modifier, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (Modifier, label33, "label33");
  GLADE_HOOKUP_OBJECT (Modifier, label37, "label37");
  GLADE_HOOKUP_OBJECT (Modifier, label35, "label35");
  GLADE_HOOKUP_OBJECT (Modifier, label36, "label36");
  GLADE_HOOKUP_OBJECT (Modifier, label34, "label34");
  GLADE_HOOKUP_OBJECT (Modifier, label39, "label39");
  GLADE_HOOKUP_OBJECT (Modifier, label38, "label38");
  GLADE_HOOKUP_OBJECT (Modifier, label40, "label40");
  GLADE_HOOKUP_OBJECT (Modifier, entry7, "entry7");
  GLADE_HOOKUP_OBJECT (Modifier, entry8, "entry8");
  GLADE_HOOKUP_OBJECT (Modifier, entry9, "entry9");
  GLADE_HOOKUP_OBJECT (Modifier, entry10, "entry10");
  GLADE_HOOKUP_OBJECT (Modifier, entry11, "entry11");
  GLADE_HOOKUP_OBJECT (Modifier, entry12, "entry12");
  GLADE_HOOKUP_OBJECT (Modifier, button14, "button14");
  GLADE_HOOKUP_OBJECT (Modifier, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (Modifier, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (Modifier, image10, "image10");
  GLADE_HOOKUP_OBJECT (Modifier, label43, "label43");
  GLADE_HOOKUP_OBJECT (Modifier, button13, "button13");
  GLADE_HOOKUP_OBJECT (Modifier, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (Modifier, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (Modifier, image9, "image9");
  GLADE_HOOKUP_OBJECT (Modifier, label41, "label41");

  return Modifier;
}

GtkWidget*
create_gestion_des_capteur (void)
{
  GtkWidget *gestion_des_capteur;
  GtkWidget *fixed5;
  GtkWidget *button16;
  GtkWidget *button17;
  GtkWidget *button18;
  GtkWidget *button19;
  GtkWidget *alignment12;
  GtkWidget *hbox12;
  GtkWidget *image12;
  GtkWidget *label45;

  gestion_des_capteur = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (gestion_des_capteur), _("Gestion des capteurs"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (gestion_des_capteur), fixed5);

  button16 = gtk_button_new_with_mnemonic (_("Liste des capteurs"));
  gtk_widget_show (button16);
  gtk_fixed_put (GTK_FIXED (fixed5), button16, 48, 56);
  gtk_widget_set_size_request (button16, 360, 48);

  button17 = gtk_button_new_with_mnemonic (_("Les capteurs ayant des valeur alarmantes"));
  gtk_widget_show (button17);
  gtk_fixed_put (GTK_FIXED (fixed5), button17, 48, 144);
  gtk_widget_set_size_request (button17, 360, 48);

  button18 = gtk_button_new_with_mnemonic (_("Les capteurs defectueux"));
  gtk_widget_show (button18);
  gtk_fixed_put (GTK_FIXED (fixed5), button18, 48, 232);
  gtk_widget_set_size_request (button18, 360, 48);

  button19 = gtk_button_new ();
  gtk_widget_show (button19);
  gtk_fixed_put (GTK_FIXED (fixed5), button19, 32, 344);
  gtk_widget_set_size_request (button19, 128, 32);

  alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (button19), alignment12);

  hbox12 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox12);
  gtk_container_add (GTK_CONTAINER (alignment12), hbox12);

  image12 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image12);
  gtk_box_pack_start (GTK_BOX (hbox12), image12, FALSE, FALSE, 0);

  label45 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label45);
  gtk_box_pack_start (GTK_BOX (hbox12), label45, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (gestion_des_capteur, gestion_des_capteur, "gestion_des_capteur");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, button16, "button16");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, button17, "button17");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, button18, "button18");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, button19, "button19");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, image12, "image12");
  GLADE_HOOKUP_OBJECT (gestion_des_capteur, label45, "label45");

  return gestion_des_capteur;
}

GtkWidget*
create_Capteur_ayant_des_valeurs_alarmantes (void)
{
  GtkWidget *Capteur_ayant_des_valeurs_alarmantes;
  GtkWidget *fixed6;
  GtkWidget *table2;
  GtkWidget *label51;
  GtkWidget *label52;
  GtkWidget *label53;
  GtkWidget *label54;
  GtkWidget *label55;
  GtkWidget *label56;
  GtkWidget *label46;
  GtkWidget *button20;
  GtkWidget *alignment13;
  GtkWidget *hbox13;
  GtkWidget *image13;
  GtkWidget *label50;

  Capteur_ayant_des_valeurs_alarmantes = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Capteur_ayant_des_valeurs_alarmantes), _("Capteur ayant des valeurs alarmantes"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (Capteur_ayant_des_valeurs_alarmantes), fixed6);

  table2 = gtk_table_new (3, 4, FALSE);
  gtk_widget_show (table2);
  gtk_fixed_put (GTK_FIXED (fixed6), table2, 64, 64);
  gtk_widget_set_size_request (table2, 64, 48);

  label51 = gtk_label_new (_("Numero"));
  gtk_widget_show (label51);
  gtk_table_attach (GTK_TABLE (table2), label51, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label51), 0, 0.5);

  label52 = gtk_label_new (_("Nom de capteur"));
  gtk_widget_show (label52);
  gtk_table_attach (GTK_TABLE (table2), label52, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label52), 0, 0.5);

  label53 = gtk_label_new (_("Marque"));
  gtk_widget_show (label53);
  gtk_table_attach (GTK_TABLE (table2), label53, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label53), 0, 0.5);

  label54 = gtk_label_new (_("Reference"));
  gtk_widget_show (label54);
  gtk_table_attach (GTK_TABLE (table2), label54, 3, 4, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label54), 0, 0.5);

  label55 = gtk_label_new (_("1"));
  gtk_widget_show (label55);
  gtk_table_attach (GTK_TABLE (table2), label55, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label55), 0, 0.5);

  label56 = gtk_label_new (_("2"));
  gtk_widget_show (label56);
  gtk_table_attach (GTK_TABLE (table2), label56, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label56), 0, 0.5);

  label46 = gtk_label_new (_("Capteur ayant des valeurs alarmantes :"));
  gtk_widget_show (label46);
  gtk_fixed_put (GTK_FIXED (fixed6), label46, 80, 0);
  gtk_widget_set_size_request (label46, 336, 40);

  button20 = gtk_button_new ();
  gtk_widget_show (button20);
  gtk_fixed_put (GTK_FIXED (fixed6), button20, 32, 240);
  gtk_widget_set_size_request (button20, 104, 26);

  alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (button20), alignment13);

  hbox13 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox13);
  gtk_container_add (GTK_CONTAINER (alignment13), hbox13);

  image13 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image13);
  gtk_box_pack_start (GTK_BOX (hbox13), image13, FALSE, FALSE, 0);

  label50 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label50);
  gtk_box_pack_start (GTK_BOX (hbox13), label50, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Capteur_ayant_des_valeurs_alarmantes, Capteur_ayant_des_valeurs_alarmantes, "Capteur_ayant_des_valeurs_alarmantes");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, table2, "table2");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label51, "label51");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label52, "label52");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label53, "label53");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label54, "label54");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label55, "label55");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label56, "label56");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label46, "label46");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, button20, "button20");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, image13, "image13");
  GLADE_HOOKUP_OBJECT (Capteur_ayant_des_valeurs_alarmantes, label50, "label50");

  return Capteur_ayant_des_valeurs_alarmantes;
}

GtkWidget*
create_window7 (void)
{
  GtkWidget *window7;

  window7 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window7), _("window7"));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window7, window7, "window7");

  return window7;
}

