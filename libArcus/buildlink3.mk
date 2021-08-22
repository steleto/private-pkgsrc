# $NetBSD$

BUILDLINK_TREE+=	libArcus

.if !defined(LIBARCUS_BUILDLINK3_MK)
LIBARCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libArcus+=	libArcus>=4.10.0
BUILDLINK_PKGSRCDIR.libArcus?=	../../private/libArcus

.include "../../lang/python/extension.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.endif	# LIBARCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libArcus
