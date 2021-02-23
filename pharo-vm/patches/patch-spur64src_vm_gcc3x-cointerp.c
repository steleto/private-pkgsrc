$NetBSD$

--- spur64src/vm/cogitX64SysV.c.orig	2021-02-18 16:42:20.999184653 +0000
+++ spur64src/vm/cogitX64SysV.c
@@ -22288,9 +22288,7 @@ dispatchConcretize(AbstractInstruction *
 			((self_in_dispatchConcretize->operands))[2] = 0;
 			return savedSize1;
 		}
-		if ((reg20 == RAX)
-		 || ((reg20 == RBP)
-		 || (reg20 == RSP))) {
+		if (reg20 == RAX) {
 			offset38 = 0;
 		}
 		else {
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
