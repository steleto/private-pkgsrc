$NetBSD$

https://github.com/Ultimaker/libnest2d/commit/4d6fb4d3919aad653cbae0ae2e03c0e1ac00c64b

- Allow for an item to be a disallowed area
    Disallowed areas have slightly different behaviour from fixed items:
    Other items won't get packed closely around them. Implementation of
    that pending.
    Contributes to issue CURA-7754.

- Allow unsetting of being a disallowed area
    If you set the bin to -1 or set the item to be a simple fixed item
    afterwards, it'll no longer be a disallowed area.
    Contributes to issue CURA-7754.

--- include/libnest2d/nester.hpp.orig	2021-01-13 02:15:01.727431613 +0900
+++ include/libnest2d/nester.hpp
@@ -71,6 +71,15 @@
     int binid_{BIN_ID_UNSET}, priority_{0};
     bool fixed_{false};
 
+    /**
+     * \brief If this is a fixed area, indicates whether it is a disallowed area
+     * or a previously placed item.
+     *
+     * If this is a disallowed area, other objects will not get packed close
+     * together with this item. It only blocks other items in its area.
+     */
+    bool disallowed_{false};
+
 public:
 
     /// The type of the shape which was handed over as the template argument.
@@ -129,10 +138,18 @@
         sh_(sl::create<RawShape>(std::move(contour), std::move(holes))) {}
     
     inline bool isFixed() const noexcept { return fixed_; }
+    inline bool isDisallowedArea() const noexcept { return disallowed_; }
     inline void markAsFixedInBin(int binid)
     {
         fixed_ = binid >= 0;
         binid_ = binid;
+        disallowed_ = false;
+    }
+    inline void markAsDisallowedAreaInBin(int binid)
+    {
+        fixed_ = binid >= 0;
+        binid_ = binid;
+        disallowed_ = fixed_;
     }
 
     inline void binId(int idx) { binid_ = idx; }
