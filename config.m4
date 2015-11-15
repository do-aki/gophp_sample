dnl $Id$
dnl config.m4 for extension gophp

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(gophp, for gophp support,
dnl Make sure that the comment is aligned:
dnl [  --with-gophp             Include gophp support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(gophp, whether to enable gophp support,
dnl Make sure that the comment is aligned:
dnl [  --enable-gophp           Enable gophp support])

if test "$PHP_GOPHP" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-gophp -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/gophp.h"  # you most likely want to change this
  dnl if test -r $PHP_GOPHP/$SEARCH_FOR; then # path given as parameter
  dnl   GOPHP_DIR=$PHP_GOPHP
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for gophp files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GOPHP_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GOPHP_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the gophp distribution])
  dnl fi

  dnl # --with-gophp -> add include path
  dnl PHP_ADD_INCLUDE($GOPHP_DIR/include)

  dnl # --with-gophp -> check for lib and symbol presence
  dnl LIBNAME=gophp # you may want to change this
  dnl LIBSYMBOL=gophp # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $GOPHP_DIR/$PHP_LIBDIR, GOPHP_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GOPHPLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong gophp lib version or lib not found])
  dnl ],[
  dnl   -L$GOPHP_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GOPHP_SHARED_LIBADD)

  PHP_NEW_EXTENSION(gophp, gophp.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
