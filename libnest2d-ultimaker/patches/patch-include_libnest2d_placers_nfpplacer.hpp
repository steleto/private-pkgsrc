$NetBSD$

https://github.com/Ultimaker/libnest2d/commit/4d6fb4d3919aad653cbae0ae2e03c0e1ac00c64b.patch

- Align items to their starting position if all placed items are disallowed
    We shouldn't align items to disallowed areas. So place them in the
    starting position according to the alignment property.
    Lot of work to investigate. But very little code changes!
    Contributes to issue CURA-7754.

--- include/libnest2d/placers/nfpplacer.hpp.orig	2019-10-24 13:46:17.000000000 +0000
+++ include/libnest2d/placers/nfpplacer.hpp
@@ -101,7 +101,7 @@ struct NfpPConfig {
      * alignment with the candidate item or do anything else.
      *
      * \param remaining A container with the remaining items waiting to be
-     * placed. You can use some features about the remaining items to alter to
+     * placed. You can use some features about the remaining items to alter the
      * score of the current placement. If you know that you have to leave place
      * for other items as well, that might influence your decision about where
      * the current candidate should be placed. E.g. imagine three big circles
@@ -735,7 +735,8 @@ private:
             remlist.insert(remlist.end(), remaining.from, remaining.to);
         }
 
-        if(items_.empty()) {
+        if(std::all_of(items_.begin(), items_.end(),
+                [](const Item& item) { return item.isDisallowedArea(); })) {
             setInitialPosition(item);
             best_overfit = overfit(item.transformedShape(), bin_);
             can_pack = best_overfit <= 0;
