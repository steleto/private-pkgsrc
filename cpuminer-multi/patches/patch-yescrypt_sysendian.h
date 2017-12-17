$NetBSD$

--- yescrypt/sysendian.h.orig	2017-01-26 19:27:43.000000000 +0000
+++ yescrypt/sysendian.h
@@ -29,6 +29,8 @@
 #ifndef _SYSENDIAN_H_
 #define _SYSENDIAN_H_
 
+#include <cpuminer-config.h>
+
 /* If we don't have be64enc, the <sys/endian.h> we have isn't usable. */
 #if !HAVE_DECL_BE64ENC
 #undef HAVE_SYS_ENDIAN_H
