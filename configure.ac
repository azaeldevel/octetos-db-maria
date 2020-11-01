

AC_INIT(octetos-db-maria, 0.1.0-alpha)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CXX
AC_PROG_LIBTOOL







LT_INIT


PKG_CHECK_MODULES(OCTETOS_DB_ABSTRACT, octetos-db-abstract)

PKG_CHECK_MODULES(LIBMARIADB, libmariadb)




AC_OUTPUT([
Makefile
src/Makefile
src/octetos-db-maria.pc
])
