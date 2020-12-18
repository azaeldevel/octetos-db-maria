AUTOMAKE_OPTIONS=foreign 1.4


lib_LTLIBRARIES = liboctetos-db-maria.la

DEFINITIONS = 

if WITH_ARCHLINUX
DEFINITIONS += -DLINUX_ARCH
endif
if WITH_GENTOO
DEFINITIONS += -DLINUX_GENTOO
endif
if WITH_DEBIAN
DEFINITIONS += -DLINUX_DEBIAN
endif

if WITH_MEDIUMWORD
DEFINITIONS += -DOCTETOS_DB_MEDIUMWORD
endif
if WITH_HIGHWORD
DEFINITIONS += -DOCTETOS_DB_HIGHWORD
endif
if WITH_LOWWORD
DEFINITIONS += -DOCTETOS_DB_LOWWORD
endif

liboctetos_db_maria_la_CXXFLAGS = $(OCTETOS_DB_ABSTRACT_CFLAGS) $(LIBMARIADB_CFLAGS) $(DEFINITIONS)
liboctetos_db_maria_la_LIBADD = $(OCTETOS_DB_ABSTRACT_LIBS) $(LIBMARIADB_LIBS)
liboctetos_db_maria_la_SOURCES = clientdb-maria.cc

octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = clientdb-maria.hh
pkgconfig_DATA = octetos-db-maria.pc
EXTRA_DIST = octetos-db-maria.pc.in