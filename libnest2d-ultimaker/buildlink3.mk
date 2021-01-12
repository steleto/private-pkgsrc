# $NetBSD$

BUILDLINK_TREE+=	libnest2d-ultimaker

.if !defined(LIBNEST2D_ULTIMAKER_BUILDLINK3_MK)
LIBNEST2D_ULTIMAKER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libnest2d-ultimaker?=	build
BUILDLINK_API_DEPENDS.libnest2d-ultimaker+=	libnest2d-ultimaker>=0.4
BUILDLINK_PKGSRCDIR.libnest2d-ultimaker?=	../../private/libnest2d-ultimaker

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../math/nlopt/buildlink3.mk"
.include "../../private/clipper/buildlink3.mk"
.endif	# LIBNEST2D_ULTIMAKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnest2d-ultimaker
