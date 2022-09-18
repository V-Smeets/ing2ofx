# Autoconf requirements

# AC_INIT(package, version, bug-report-address)
AC_INIT([ing2ofx], [0.0.1], [ing2ofx@vsmeets.nl])
AC_CONFIG_SRCDIR([src/ing2ofx.cpp])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# information on the package

# checks for programs
AC_PROG_CXX
AM_PROG_AR
AC_PROG_RANLIB

DX_INIT_DOXYGEN([ing2ofx])

# checks for libraries

# checks for header files
AC_CHECK_HEADERS([csv.h], , [AC_MSG_ERROR([required headers not available])])

# checks for types

# checks for structures

# checks for compiler characteristics

# checks for library functions
AC_CHECK_LIB([csv], [csv_init], , [AC_MSG_ERROR([required library not available])])

# checks for system services

# AC_CONFIG_FILES([file…])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([doc/Makefile])
AC_CONFIG_FILES([man/Makefile])
AC_CONFIG_FILES([src/Makefile])
AC_CONFIG_FILES([xsd/Makefile])

# AC_OUTPUT
AC_OUTPUT
