$NetBSD$

* Support pthread_setname_np for NetBSD
* Exclude undefined function.

--- src/myth_wrap_pthread.c.orig	2019-07-17 10:58:11.000000000 +0000
+++ src/myth_wrap_pthread.c
@@ -507,15 +507,23 @@ int __wrap(pthread_getname_np)(pthread_t
 
 /* pthread_setname_np (3) - set/get the name of a thread */
 int __wrap(pthread_setname_np)(
+#if defined(__NetBSD__)
+	pthread_t thread, const char *name, void *arg) {
+#else
 #if PTHREAD_SETNAME_ARITY == 2
 			       pthread_t thread,
 #endif
 			       const char *name) {
+#endif
+#if defined(__NetBSD__)
+  int _ = enter_wrapped_func("%x, %s, %s", thread, name, arg);
+#else
 #if PTHREAD_SETNAME_ARITY == 2
   int _ = enter_wrapped_func("%x, %s", thread, name);
 #else
   int _ = enter_wrapped_func("%s", name);
 #endif
+#endif
   int ret;
   (void)_;
   if (myth_should_wrap_pthread()) {
@@ -523,10 +531,14 @@ int __wrap(pthread_setname_np)(
     ret = ENOSYS;
   } else {
     ret = real_pthread_setname_np(
+#if defined(__NetBSD__)
+				  thread, name, arg);
+#else
 #if PTHREAD_SETNAME_ARITY == 2
 				  thread,
 #endif
 				  name);
+#endif
   }
   leave_wrapped_func("%d", ret);
   return ret;
@@ -927,6 +939,7 @@ int __wrap(pthread_mutexattr_destroy)(pt
   return ret;
 }
 
+#if defined(HAVE_PTHREAD_MUTEXATTR_PSHARED)
 /* pthread_mutexattr_getpshared (3posix) - get and set the process-shared attribute */
 int __wrap(pthread_mutexattr_getpshared)
      (const pthread_mutexattr_t *restrict attr, int *restrict pshared) {
@@ -946,6 +959,7 @@ int __wrap(pthread_mutexattr_setpshared)
   leave_wrapped_func("%d", ret);
   return ret;
 }
+#endif /* HAVE_PTHREAD_MUTEXATTR_PSHARED */
 
 /* pthread_mutexattr_gettype (3posix) - get and set the mutex type attribute */
 int __wrap(pthread_mutexattr_gettype)
@@ -1217,6 +1231,7 @@ int __wrap(pthread_rwlockattr_destroy)(p
   return ret;
 }
 
+#if defined(HAVE_PTHREAD_RWLOCKATTR_PSHARED)
 /* pthread_rwlockattr_getpshared (3posix) - get and set the process-shared attribute of the ... */
 int __wrap(pthread_rwlockattr_getpshared)
      (const pthread_rwlockattr_t *restrict attr, int *restrict pshared) {
@@ -1236,6 +1251,7 @@ int __wrap(pthread_rwlockattr_setpshared
   leave_wrapped_func("%d", ret);
   return ret;
 }
+#endif /* HAVE_PTHREAD_RWLOCKATTR_PSHARED */
 
 /* pthread_rwlockattr_getkind_np (3) - set/get the read-write lock kind of the thread read-w... */
 int __wrap(pthread_rwlockattr_getkind_np)(const pthread_rwlockattr_t *attr,
@@ -1382,6 +1398,7 @@ int __wrap(pthread_condattr_destroy)(pth
   return ret;
 }
 
+#if defined(HAVE_PTHREAD_CONDATTR_PSHARED)
 /* pthread_condattr_getpshared (3posix) - get and set the process-shared condition variable ... */
 int __wrap(pthread_condattr_getpshared)
      (const pthread_condattr_t *restrict attr, int *restrict pshared) {
@@ -1401,6 +1418,7 @@ int __wrap(pthread_condattr_setpshared)(
   leave_wrapped_func("%d", ret);
   return ret;
 }
+#endif /* HAVE_PTHREAD_CONDATTR_PSHARED */
 
 #if defined(HAVE_PTHREAD_CONDATTR_CLOCK)
 /* pthread_condattr_getclock (3posix) - get and set the clock selection condition variable a... */
@@ -1592,6 +1610,7 @@ int __wrap(pthread_barrierattr_destroy)(
   return ret;
 }
 
+#if defined(HAVE_PTHREAD_BARRIERATTR_PSHARED)
 /* pthread_barrierattr_getpshared (3posix) - get and set the process-shared attribute of the... */
 int __wrap(pthread_barrierattr_getpshared)
      (const pthread_barrierattr_t *restrict attr, int *restrict pshared) {
@@ -1610,6 +1629,7 @@ int __wrap(pthread_barrierattr_setpshare
   leave_wrapped_func("%d", ret);
   return ret;
 }
+#endif /* HAVE_PTHREAD_BARRIERATTR_PSHARED */
 
 #endif	/* HAVE_PTHREAD_BARRIER */
 
