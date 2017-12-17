$NetBSD$

--- yescrypt/yescrypt-platform.h.orig	2017-01-26 19:27:43.000000000 +0000
+++ yescrypt/yescrypt-platform.h
@@ -18,6 +18,8 @@
  * SUCH DAMAGE.
  */
 
+#include <cpuminer-config.h>
+
 #ifdef MAP_ANON
 #include <sys/mman.h>
 #endif
@@ -31,6 +33,7 @@
 #undef HUGEPAGE_SIZE
 #endif
 
+#ifndef HAVE_DECL_LE32DEC
 static __inline uint32_t
 le32dec(const void *pp)
 {
@@ -39,7 +42,9 @@ le32dec(const void *pp)
 	return ((uint32_t)(p[0]) + ((uint32_t)(p[1]) << 8) +
 	    ((uint32_t)(p[2]) << 16) + ((uint32_t)(p[3]) << 24));
 }
+#endif
 
+#ifndef HAVE_DECL_LE32ENC
 static __inline void
 le32enc(void *pp, uint32_t x)
 {
@@ -50,6 +55,7 @@ le32enc(void *pp, uint32_t x)
 	p[2] = (x >> 16) & 0xff;
 	p[3] = (x >> 24) & 0xff;
 }
+#endif
 
 static void *
 alloc_region(yescrypt_region_t * region, size_t size)
