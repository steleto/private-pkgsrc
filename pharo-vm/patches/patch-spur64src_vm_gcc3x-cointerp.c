$NetBSD$

--- spur64src/vm/gcc3x-cointerp.c.orig	2018-11-08 15:09:10.122448376 +0000
+++ spur64src/vm/gcc3x-cointerp.c
@@ -41082,8 +41082,8 @@ fetchClassTagOf(sqInt oop)
 static sqInt NoDbgRegParms
 fetchLong32ofFloatObject(sqInt fieldIndex, sqInt oop)
 {
-    usqLong bits;
-    usqLong rot;
+    volatile usqLong bits;
+    volatile usqLong rot;
 
 	if (!(oop & (smallFloatTag()))) {
 		return long32At((oop + BaseHeaderSize) + (((sqInt)((usqInt)(fieldIndex) << 2))));
