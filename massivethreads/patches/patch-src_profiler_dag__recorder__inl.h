$NetBSD$

Exclude undefined function.

--- src/profiler/dag_recorder_inl.h.orig	2019-07-17 10:58:11.000000000 +0000
+++ src/profiler/dag_recorder_inl.h
@@ -497,6 +497,14 @@ extern "C" {
     return u;
   }
 
+#elif defined(__arm__)
+
+  static unsigned long long dr_rdtsc(void) {
+    unsigned long long u;
+    asm volatile("mrrc p15, 1, %Q0, %R0, c14" : "=r" (u));
+    return u;
+  }
+
 #else
   
   static unsigned long long dr_rdtsc() {
@@ -638,6 +646,7 @@ extern "C" {
     return t;
   }
 
+#if defined(HAVE_SCHED_GETCPU)
 #if __cplusplus 
   extern "C" {
 #endif
@@ -645,13 +654,18 @@ extern "C" {
 #if __cplusplus 
   }
 #endif
+#endif
 
   static int dr_getcpu() {
+#if defined(HAVE_SCHED_GETCPU)
     if (DAG_RECORDER_RECORD_CPU) {
       return sched_getcpu();
     } else {
       return 0;
     }
+#else
+    return 0;
+#endif
   }
 
   static inline dr_clock_t
