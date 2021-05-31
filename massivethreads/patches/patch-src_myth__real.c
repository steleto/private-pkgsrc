$NetBSD$

* Support pthread_setname_np for NetBSD.
* Exclude undefined function.

--- src/myth_real.c.orig	2019-07-17 10:58:11.000000000 +0000
+++ src/myth_real.c
@@ -115,7 +115,9 @@ typedef struct {
 #endif
 #if defined(HAVE_PTHREAD_NAME_NP)
   int (*pthread_getname_np)(pthread_t thread, char *name, size_t len);
-#if PTHREAD_SETNAME_ARITY == 2
+#if defined(__NetBSD__)
+  int (*pthread_setname_np)(pthread_t thread, const char *name, void *arg);
+#elif PTHREAD_SETNAME_ARITY == 2
   int (*pthread_setname_np)(pthread_t thread, const char *name);
 #elif PTHREAD_SETNAME_ARITY == 1
   int (*pthread_setname_np)(const char *name);
@@ -161,10 +163,12 @@ typedef struct {
 #endif
   int (*pthread_mutexattr_init)(pthread_mutexattr_t *attr);
   int (*pthread_mutexattr_destroy)(pthread_mutexattr_t *attr);
+#if defined(HAVE_PTHREAD_MUTEXATTR_PSHARED)
   int (*pthread_mutexattr_getpshared)(const pthread_mutexattr_t *restrict attr,
 				      int *restrict pshared);
   int (*pthread_mutexattr_setpshared)(pthread_mutexattr_t *attr,
 				      int pshared);
+#endif
   int (*pthread_mutexattr_gettype)(const pthread_mutexattr_t *restrict attr,
 				   int *restrict type);
   int (*pthread_mutexattr_settype)(pthread_mutexattr_t *attr, int type);
@@ -195,10 +199,12 @@ typedef struct {
   int (*pthread_rwlock_unlock)(pthread_rwlock_t *rwlock);
   int (*pthread_rwlockattr_init)(pthread_rwlockattr_t *attr);
   int (*pthread_rwlockattr_destroy)(pthread_rwlockattr_t *attr);
+#if defined(HAVE_PTHREAD_RWLOCKATTR_PSHARED)
   int (*pthread_rwlockattr_getpshared)(const pthread_rwlockattr_t *restrict attr,
 				       int *restrict pshared);
   int (*pthread_rwlockattr_setpshared)(pthread_rwlockattr_t *attr,
 				       int pshared);
+#endif
   int (*pthread_rwlockattr_getkind_np)(const pthread_rwlockattr_t *attr,
 				       int *pref);
   int (*pthread_rwlockattr_setkind_np)(pthread_rwlockattr_t *attr,
@@ -216,10 +222,12 @@ typedef struct {
 				const struct timespec *restrict abstime);
   int (*pthread_condattr_init)(pthread_condattr_t *attr);
   int (*pthread_condattr_destroy)(pthread_condattr_t *attr);
+#if defined(HAVE_PTHREAD_CONDATTR_PSHARED)
   int (*pthread_condattr_getpshared)(const pthread_condattr_t *restrict attr,
 				     int *restrict pshared);
   int (*pthread_condattr_setpshared)(pthread_condattr_t *attr,
 				     int pshared);
+#endif
 #if defined(HAVE_PTHREAD_CONDATTR_CLOCK)
   int (*pthread_condattr_getclock)(const pthread_condattr_t *restrict attr,
 				   clockid_t *restrict clock_id);
@@ -241,10 +249,12 @@ typedef struct {
   int (*pthread_barrier_wait)(pthread_barrier_t *barrier);
   int (*pthread_barrierattr_init)(pthread_barrierattr_t *attr);
   int (*pthread_barrierattr_destroy)(pthread_barrierattr_t *attr);
+#if defined(HAVE_PTHREAD_BARRIERATTR_PSHARED)
   int (*pthread_barrierattr_getpshared)(const pthread_barrierattr_t *restrict attr,
 					int *restrict pshared);
   int (*pthread_barrierattr_setpshared)(pthread_barrierattr_t *attr,
 					int pshared);
+#endif
 #endif	/* HAVE_PTHREAD_BARRIER */
   int (*pthread_key_create)(pthread_key_t *key, void (*destructor)(void*));
   int (*pthread_key_delete)(pthread_key_t key);
@@ -444,9 +454,11 @@ static shared_object_symbol s_so_syms[] 
 #endif
   so_symbol_entry(pthread_mutexattr_init, libpthread),
   so_symbol_entry(pthread_mutexattr_destroy, libpthread),
+#if defined(HAVE_PTHREAD_MUTEXATTR_PSHARED)
   so_symbol_entry(pthread_mutexattr_getpshared, libpthread),
 
   so_symbol_entry(pthread_mutexattr_setpshared, libpthread),
+#endif
 
   so_symbol_entry(pthread_mutexattr_gettype, libpthread),
 
@@ -478,9 +490,11 @@ static shared_object_symbol s_so_syms[] 
   so_symbol_entry(pthread_rwlock_unlock, libpthread),
   so_symbol_entry(pthread_rwlockattr_init, libpthread),
   so_symbol_entry(pthread_rwlockattr_destroy, libpthread),
+#if defined(HAVE_PTHREAD_RWLOCKATTR_PSHARED)
   so_symbol_entry(pthread_rwlockattr_getpshared, libpthread),
 
   so_symbol_entry(pthread_rwlockattr_setpshared, libpthread),
+#endif
 
   so_symbol_entry(pthread_rwlockattr_getkind_np, libpthread),
 
@@ -498,9 +512,11 @@ static shared_object_symbol s_so_syms[] 
 
   so_symbol_entry(pthread_condattr_init, libpthread),
   so_symbol_entry(pthread_condattr_destroy, libpthread),
+#if defined(HAVE_PTHREAD_CONDATTR_PSHARED)
   so_symbol_entry(pthread_condattr_getpshared, libpthread),
 
   so_symbol_entry(pthread_condattr_setpshared, libpthread),
+#endif
 
 #if defined(HAVE_PTHREAD_CONDATTR_CLOCK)
   so_symbol_entry(pthread_condattr_getclock, libpthread),
@@ -522,9 +538,11 @@ static shared_object_symbol s_so_syms[] 
   so_symbol_entry(pthread_barrier_wait, libpthread),
   so_symbol_entry(pthread_barrierattr_init, libpthread),
   so_symbol_entry(pthread_barrierattr_destroy, libpthread),
+#if defined(HAVE_PTHREAD_BARRIERATTR_PSHARED)
   so_symbol_entry(pthread_barrierattr_getpshared, libpthread),
 
   so_symbol_entry(pthread_barrierattr_setpshared, libpthread),
+#endif
 
 #endif	/* HAVE_PTHREAD_BARRIER */
   so_symbol_entry(pthread_key_create, libpthread),
@@ -1446,7 +1464,9 @@ int real_pthread_getname_np(pthread_t th
 }
 
 #if MYTH_WRAP == MYTH_WRAP_LD
-#if PTHREAD_SETNAME_ARITY == 2
+#if defined(__NetBSD__)
+int __real_pthread_setname_np(pthread_t thread, const char *name, void *arg);
+#elif PTHREAD_SETNAME_ARITY == 2
 int __real_pthread_setname_np(pthread_t thread, const char *name);
 #elif PTHREAD_SETNAME_ARITY == 1
 int __real_pthread_setname_np(const char *name);
@@ -1455,31 +1475,47 @@ int __real_pthread_setname_np(const char
 #endif
 #endif
 int real_pthread_setname_np(
+#if defined(__NetBSD__)
+			    pthread_t thread, const char *name, void *arg)
+#else
 #if PTHREAD_SETNAME_ARITY == 2
 			    pthread_t thread,
 #endif
 			    const char *name)
+#endif
 {
 #if MYTH_WRAP == MYTH_WRAP_VANILLA
+#if defined(__NetBSD__)
+  return pthread_setname_np(thread, name, arg);
+#else
   return pthread_setname_np(
 #if PTHREAD_SETNAME_ARITY == 2
 			    thread,
 #endif
 			    name);
+#endif	/* __NetBSD__ */
 #elif MYTH_WRAP == MYTH_WRAP_LD
+#if defined(__NetBSD__)
+  return __real_pthread_setname_np(thread, name, arg);
+#else
   return __real_pthread_setname_np(
 #if PTHREAD_SETNAME_ARITY == 2
 				   thread,
 #endif
 				   name);
+#endif
 #elif MYTH_WRAP == MYTH_WRAP_DL
   if (!real_function_table.pthread_setname_np) ensure_real_functions();
   assert(real_function_table.pthread_setname_np);
   return real_function_table.pthread_setname_np(
+#if defined(__NetBSD__)
+						thread, name, arg);
+#else
 #if PTHREAD_SETNAME_ARITY == 2
 						thread,
 #endif
 						name);
+#endif
 #else
 #error "MYTH_WRAP must be MYTH_WRAP_VANILLA, MYTH_WRAP_LD, or MYTH_WRAP_DL"
 #endif
@@ -1878,6 +1914,7 @@ int real_pthread_mutexattr_destroy(pthre
 #endif
 }
 
+#if defined(HAVE_PTHREAD_MUTEXATTR_PSHARED)
 #if MYTH_WRAP == MYTH_WRAP_LD
 int __real_pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,
 				      int *restrict pshared);
@@ -1915,6 +1952,7 @@ int real_pthread_mutexattr_setpshared(pt
 #error "MYTH_WRAP must be MYTH_WRAP_VANILLA, MYTH_WRAP_LD, or MYTH_WRAP_DL"
 #endif
 }
+#endif /* defined(HAVE_PTHREAD_MUTEXATTR_PSHARED) */
 
 #if MYTH_WRAP == MYTH_WRAP_LD
 int __real_pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict attr,
@@ -2260,6 +2298,7 @@ int real_pthread_rwlockattr_destroy(pthr
 #endif
 }
 
+#if defined(HAVE_PTHREAD_RWLOCKATTR_PSHARED)
 #if MYTH_WRAP == MYTH_WRAP_LD
 int __real_pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *restrict attr,
 				       int *restrict pshared);
@@ -2297,6 +2336,7 @@ int real_pthread_rwlockattr_setpshared(p
 #error "MYTH_WRAP must be MYTH_WRAP_VANILLA, MYTH_WRAP_LD, or MYTH_WRAP_DL"
 #endif
 }
+#endif /* defined(HAVE_PTHREAD_RWLOCKATTR_PSHARED) */
 
 #if MYTH_WRAP == MYTH_WRAP_LD
 int __real_pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *attr,
@@ -2481,6 +2521,7 @@ int real_pthread_condattr_destroy(pthrea
 #endif
 }
 
+#if defined(HAVE_PTHREAD_CONDATTR_PSHARED)
 #if MYTH_WRAP == MYTH_WRAP_LD
 int __real_pthread_condattr_getpshared(const pthread_condattr_t *restrict attr,
 				     int *restrict pshared);
@@ -2518,6 +2559,7 @@ int real_pthread_condattr_setpshared(pth
 #error "MYTH_WRAP must be MYTH_WRAP_VANILLA, MYTH_WRAP_LD, or MYTH_WRAP_DL"
 #endif
 }
+#endif /* defined(HAVE_PTHREAD_CONDATTR_PSHARED) */
 
 #if defined(HAVE_PTHREAD_CONDATTR_CLOCK)
 #if MYTH_WRAP == MYTH_WRAP_LD
@@ -2736,6 +2778,7 @@ int real_pthread_barrierattr_destroy(pth
 #endif
 }
 
+#if defined(HAVE_PTHREAD_BARRIERATTR)
 #if MYTH_WRAP == MYTH_WRAP_LD
 int __real_pthread_barrierattr_getpshared(const pthread_barrierattr_t *restrict attr,
 					int *restrict pshared);
@@ -2773,6 +2816,7 @@ int real_pthread_barrierattr_setpshared(
 #error "MYTH_WRAP must be MYTH_WRAP_VANILLA, MYTH_WRAP_LD, or MYTH_WRAP_DL"
 #endif
 }
+#endif /* defined(HAVE_PTHREAD_BARRIERATTR) */
 
 #endif	/* HAVE_PTHREAD_BARRIER */
 
