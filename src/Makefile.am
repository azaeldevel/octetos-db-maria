## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_DB_MARIA_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = octetos_db_maria

octetos_db_maria_SOURCES = \
	main.cc

octetos_db_maria_LDFLAGS = 

octetos_db_maria_LDADD = $(OCTETOS_DB_MARIA_LIBS)


