$NetBSD$

--- platforms/unix/plugins/FT2Plugin/acinclude.m4.orig	2018-11-08 15:14:17.518030381 +0000
+++ platforms/unix/plugins/FT2Plugin/acinclude.m4
@@ -0,0 +1,5 @@
+# -*- sh -*-
+
+PKG_CHECK_MODULES([freetype2], [freetype2])
+CFLAGS="$CFLAGS $freetype2_CFLAGS"
+LIBS="$LIBS $freetype2_LIBS"
