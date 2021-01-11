# $NetBSD$

BUILDLINK_TREE+=	libSavitar

.if !defined(LIBSAVITAR_BUILDLINK3_MK)
LIBSAVITAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libSavitar+=	libSavitar>=4.8.0
BUILDLINK_PKGSRCDIR.libSavitar?=	../../private/libSavitar

.include "../../x11/py-sip/buildlink3.mk"
.endif	# LIBSAVITAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libSavitar
