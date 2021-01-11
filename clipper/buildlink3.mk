# $NetBSD$

BUILDLINK_TREE+=	clipper

.if !defined(CLIPPER_BUILDLINK3_MK)
CLIPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clipper+=	clipper>=6.4.2
BUILDLINK_PKGSRCDIR.clipper?=	../../private/clipper
.endif	# CLIPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clipper
