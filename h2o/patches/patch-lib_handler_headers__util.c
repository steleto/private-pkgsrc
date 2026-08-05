$NetBSD$

STRLIT in a helper macro memcpy to avoid comma collision with 
-D_FORTIFY_SOURCE.

+++ lib/handler/headers_util.c
@@ -46,13 +46,13 @@ static void filter_cookie(h2o_mem_pool_t *pool, char *
         int found = is_in_list(token, token_len, cmd);
         if ((cmd->cmd == H2O_HEADERS_CMD_COOKIE_UNSETUNLESS && found) || (cmd->cmd == H2O_HEADERS_CMD_COOKIE_UNSET && !found)) {
             if (dst_len != 0) {
-                memcpy(dst + dst_len, H2O_STRLIT("; "));
+                h2o_memcpy(dst + dst_len, H2O_STRLIT("; "));
                 dst_len += 2;
             }
             memcpy(dst + dst_len, token, token_len);
             dst_len += token_len;
             if (token_value.len > 0) {
-                memcpy(dst + dst_len, H2O_STRLIT("="));
+                h2o_memcpy(dst + dst_len, H2O_STRLIT("="));
                 dst_len++;
                 memcpy(dst + dst_len, token_value.base, token_value.len);
                 dst_len += token_value.len;
