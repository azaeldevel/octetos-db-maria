

AC_INIT(octetos-db-maria, 1.5.4-alpha,azael.devel@gmail.com)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CXX
AC_PROG_LIBTOOL







LT_INIT


PKG_CHECK_MODULES(OCTETOS_DB_ABSTRACT, octetos-db-abstract)

PKG_CHECK_MODULES(LIBMARIADB, libmariadb)



AC_ARG_WITH([archlinux], AS_HELP_STRING([--with-archlinux], [Activating compilation for ArchLinux.]))
AM_CONDITIONAL(WITH_ARCHLINUX, test x"$with_archlinux" = "xyes")


AC_ARG_WITH([gentoo], AS_HELP_STRING([--with-gentoo], [Activating compilation for Gentoo.]))
AM_CONDITIONAL(WITH_GENTOO, test x"$with_gentoo" = "xyes")

AC_ARG_WITH([debian], AS_HELP_STRING([--with-debian], [Activating compilation for Debian.]))
AM_CONDITIONAL(WITH_DEBIAN, test x"$with_debian" = "xyes")




AC_OUTPUT([
Makefile
src/Makefile
src/octetos-db-maria.pc
])
