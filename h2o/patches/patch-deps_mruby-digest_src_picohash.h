$NetBSD$

fix path

--- deps/mruby-digest/src/picohash.h.orig	2026-08-04 04:56:33.000000000 +0000
+++ deps/mruby-digest/src/picohash.h
@@ -26,7 +26,7 @@
 #define _PICOHASH_BIG_ENDIAN
 #endif
 #elif !defined(_WIN32)
-#include <endian.h> // machine/endian.h
+#include <sys/endian.h> // machine/endian.h
 #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
 #define _PICOHASH_BIG_ENDIAN
 #endif
