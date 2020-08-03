$NetBSD$

--- platforms/unix/vm/sqUnixMain.c.orig	2020-03-02 17:30:55.000000000 +0000
+++ platforms/unix/vm/sqUnixMain.c
@@ -933,6 +933,9 @@ reportStackState(char *msg, char *date, 
 # elif __FreeBSD__ && __amd64__
 			void *fp = (void *)(uap ? uap->uc_mcontext.mc_rbp : 0);
 			void *sp = (void *)(uap ? uap->uc_mcontext.mc_rsp : 0);
+# elif __NetBSD__ && __x86_64__
+			void *fp = (void *)(uap ? uap->uc_mcontext.__gregs[_REG_RBP] : 0);
+			void *sp = (void *)(uap ? uap->uc_mcontext.__gregs[_REG_RSP] : 0);
 # elif __OpenBSD__ && __i386__
 			void *fp = (void *)(uap ? uap->sc_ebp : 0);
 			void *sp = (void *)(uap ? uap->sc_esp : 0);
