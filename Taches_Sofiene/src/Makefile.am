## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = les-taches-de-sofiene

les_taches_de_sofiene_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	animal.c animal.h \
	equipement.c equipement.h

les_taches_de_sofiene_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

