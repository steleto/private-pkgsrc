$NetBSD$

--- libzpaq.cpp.orig	2018-11-16 14:47:24.755731734 +0000
+++ libzpaq.cpp
@@ -81,7 +81,7 @@ void allocx(U8* &p, int &n, int newsize)
   }
   if (newsize>0) {
 #ifdef unix
-    p=(U8*)mmap(0, newsize, PROT_READ|PROT_WRITE|PROT_EXEC,
+    p=(U8*)mmap(0, newsize, PROT_READ|PROT_WRITE,
                 MAP_PRIVATE|MAP_ANON, -1, 0);
     if ((void*)p==MAP_FAILED) p=0;
 #else
@@ -3807,6 +3807,12 @@ int ZPAQL::assemble() {
   // Jump to start
   o=0;
   put1a(0xe9, start-5);  // jmp near start
+
+#ifdef unix
+  // Allow executable
+  mprotect(rcode, rsize, PROT_READ|PROT_EXEC);
+#endif  // unix
+
   return rsize;
 }
 
@@ -4579,6 +4585,11 @@ int Predictor::assemble_p() {
   put1(0x5b);                 // pop ebx
   put1(0xc3);                 // ret
 
+#ifdef unix
+  // Allow executable
+  mprotect(pcode, o, PROT_READ|PROT_EXEC);
+#endif  // unix
+
   return o;
 }
 
