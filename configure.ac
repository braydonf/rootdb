AC_INIT([librootdb],[0.1])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AM_INIT_AUTOMAKE([foreign])
LT_INIT
AC_CHECK_HEADERS([lmdb.h], [rootdb_found_lmdb_headers=yes; break;])
AS_IF([test "x$rootdb_found_lmdb_headers" != "xyes"],
        [AC_MSG_ERROR([Unable to find the lmdb headers. Try running apt-get install liblmdb-dev])])
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
AC_OUTPUT
