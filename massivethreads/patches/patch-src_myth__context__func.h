$NetBSD$

--- src/myth_context_func.h.orig	2024-10-28 15:24:15.000000000 +0000
+++ src/myth_context_func.h
@@ -793,7 +793,7 @@ static inline void myth_make_context_empty(myth_contex
 	 myth_unreachable(); \
 	}
 
-#elif MYTH_ARCH == MYTH_ARCH_UCONTEXT
+#elif MYTH_ARCH == MYTH_ARCH_UNIVERSAL
 
 #else /* UNSUPPORTED ARCH */
 
