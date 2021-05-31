$NetBSD$

Exclude undefined function.

--- src/myth_wrap_malloc.c.orig	2019-07-17 10:58:11.000000000 +0000
+++ src/myth_wrap_malloc.c
@@ -63,6 +63,7 @@ void * __wrap(valloc)(size_t size) {
   return x;
 }
 
+#if defined(HAVE_MEMALIGN)
 void * __wrap(memalign)(size_t alignment, size_t size) {
   int _ = enter_wrapped_func("%lu, %lu", alignment, size);
   void * x = real_memalign(alignment, size);
@@ -70,7 +71,9 @@ void * __wrap(memalign)(size_t alignment
   leave_wrapped_func("%p", x);
   return x;
 }
+#endif /* HAVE_MEMALIGN */
 
+#if defined(HAVE_PVALLOC)
 void * __wrap(pvalloc)(size_t size) {
   int _ = enter_wrapped_func("%lu", size);
   void * x = real_pvalloc(size);
@@ -78,3 +81,4 @@ void * __wrap(pvalloc)(size_t size) {
   leave_wrapped_func("%p", x);
   return x;
 }
+#endif /* HAVE_PVALLOC */
