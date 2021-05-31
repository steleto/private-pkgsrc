$NetBSD$

* Support pthread_setname_np for NetBSD
* Exclude undefined function.

--- src/myth_real.h.orig	2019-07-17 10:58:11.000000000 +0000
+++ src/myth_real.h
@@ -88,7 +88,9 @@ int real_pthread_getschedparam(pthread_t
 int real_pthread_setschedprio(pthread_t thread, int prio);
 #if defined(HAVE_PTHREAD_NAME_NP)
 int real_pthread_getname_np(pthread_t thread, char *name, size_t len);
-#if PTHREAD_SETNAME_ARITY == 2
+#if defined(__NetBSD__)
+int real_pthread_setname_np(pthread_t thread, const char *name, void *arg);
+#elif PTHREAD_SETNAME_ARITY == 2
 int real_pthread_setname_np(pthread_t thread, const char *name);
 #elif PTHREAD_SETNAME_ARITY == 1
 int real_pthread_setname_np(const char *name);
@@ -135,10 +137,12 @@ int real_pthread_mutex_consistent(pthrea
 #endif
 int real_pthread_mutexattr_init(pthread_mutexattr_t *attr);
 int real_pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
+#if defined(HAVE_PTHREAD_MUTEXATTR_PSHARED)
 int real_pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,
 				      int *restrict pshared);
 int real_pthread_mutexattr_setpshared(pthread_mutexattr_t *attr,
 				      int pshared);
+#endif
 int real_pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict attr,
 				   int *restrict type);
 int real_pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);
@@ -168,10 +172,12 @@ int real_pthread_rwlock_timedwrlock(pthr
 int real_pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
 int real_pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
 int real_pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
+#if defined(HAVE_PTHREAD_RWLOCKATTR_PSHARED)
 int real_pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *restrict attr,
 				       int *restrict pshared);
 int real_pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr,
 				       int pshared);
+#endif
 int real_pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *attr,
 				       int *pref);
 int real_pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *attr,
@@ -188,10 +194,12 @@ int real_pthread_cond_timedwait(pthread_
 				const struct timespec *restrict abstime);
 int real_pthread_condattr_init(pthread_condattr_t *attr);
 int real_pthread_condattr_destroy(pthread_condattr_t *attr);
+#if defined(HAVE_PTHREAD_CONDATTR_PSHARED)
 int real_pthread_condattr_getpshared(const pthread_condattr_t *restrict attr,
 				     int *restrict pshared);
 int real_pthread_condattr_setpshared(pthread_condattr_t *attr,
 				     int pshared);
+#endif
 #if defined(HAVE_PTHREAD_CONDATTR_CLOCK)
 int real_pthread_condattr_getclock(const pthread_condattr_t *restrict attr,
 				   clockid_t *restrict clock_id);
@@ -214,10 +222,12 @@ int real_pthread_barrier_destroy(pthread
 int real_pthread_barrier_wait(pthread_barrier_t *barrier);
 int real_pthread_barrierattr_init(pthread_barrierattr_t *attr);
 int real_pthread_barrierattr_destroy(pthread_barrierattr_t *attr);
+#if defined(HAVE_PTHREAD_BARRIERATTR_PSHARED)
 int real_pthread_barrierattr_getpshared(const pthread_barrierattr_t *restrict attr,
 					int *restrict pshared);
 int real_pthread_barrierattr_setpshared(pthread_barrierattr_t *attr,
 					int pshared);
+#endif
 #endif	/* HAVE_PTHREAD_BARRIER */
 int real_pthread_key_create(pthread_key_t *key, void destructor(void*));
 int real_pthread_key_delete(pthread_key_t key);
@@ -248,8 +258,12 @@ void * real_realloc(void *ptr, size_t si
 int real_posix_memalign(void **memptr, size_t alignment, size_t size);
 void * real_aligned_alloc(size_t alignment, size_t size);
 void * real_valloc(size_t size);
+#if defined(HAVE_MEMALIGN)
 void * real_memalign(size_t alignment, size_t size);
+#endif /* HAVE_MEMALIGN */
+#if defined(HAVE_PVALLOC)
 void * real_pvalloc(size_t size);
+#endif /* HAVE_PVALLOC */
 
   /* socket */
 int real_socket(int domain, int type, int protocol);
