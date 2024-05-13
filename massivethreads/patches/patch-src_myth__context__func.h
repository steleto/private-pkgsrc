$NetBSD$

--- src/myth_context_func.h.orig	2019-07-17 10:58:11.000000000 +0000
+++ src/myth_context_func.h
@@ -652,7 +652,7 @@ static inline void myth_make_context_emp
 
 #elif MYTH_ARCH == MYTH_ARCH_sparc_v8
 
-#elif MYTH_ARCH == MYTH_ARCH_UCONTEXT
+#elif MYTH_ARCH == MYTH_ARCH_UNIVERSAL
 
 #else /* UNSUPPORTED ARCH */
 
