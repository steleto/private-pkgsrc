$NetBSD$

support NetBSD.

--- deps/neverbleed/neverbleed.c.orig	2026-08-05 08:19:11.192591278 +0000
+++ deps/neverbleed/neverbleed.c
@@ -1681,7 +1681,11 @@ int neverbleed_setaffinity(neverbleed_t *nb, NEVERBLEE
     size_t ret;
 
     iobuf_push_str(&buf, "setaffinity");
+#ifdef __NetBSD__
+    iobuf_push_bytes(&buf, cpuset, cpuset_size(cpuset));
+#else
     iobuf_push_bytes(&buf, cpuset, sizeof(*cpuset));
+#endif
     iobuf_transaction(&buf, thdata);
 
     if (iobuf_shift_num(&buf, &ret) != 0) {
@@ -1697,7 +1701,11 @@ static int setaffinity_stub(neverbleed_iobuf_t *buf)
 {
     char *cpuset_bytes;
     size_t cpuset_len;
+#ifdef __NetBSD__
+    NEVERBLEED_CPU_SET_T *cpuset;
+#else
     NEVERBLEED_CPU_SET_T cpuset;
+#endif
     int ret = 1;
 
     if ((cpuset_bytes = iobuf_shift_bytes(buf, &cpuset_len)) == NULL) {
@@ -1706,8 +1714,13 @@ static int setaffinity_stub(neverbleed_iobuf_t *buf)
         return -1;
     }
 
+#ifdef __NetBSD__
+    cpuset = (NEVERBLEED_CPU_SET_T *)cpuset_bytes;
+    assert(cpuset_len == cpuset_size(cpuset));
+#else
     assert(cpuset_len == sizeof(NEVERBLEED_CPU_SET_T));
     memcpy(&cpuset, cpuset_bytes, cpuset_len);
+#endif
 
 #ifdef __NetBSD__
     ret = pthread_setaffinity_np(pthread_self(), cpuset_size(cpuset), cpuset);
