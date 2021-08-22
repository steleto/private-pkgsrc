# $NetBSD$

BUILDLINK_TREE+=	CuraEngine

.if !defined(CURAENGINE_BUILDLINK3_MK)
CURAENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.CuraEngine+=	CuraEngine>=4.10.0
BUILDLINK_PKGSRCDIR.CuraEngine?=	../../private/CuraEngine

.include "../../devel/protobuf/buildlink3.mk"
.include "../../private/libArcus/buildlink3.mk"
.endif	# CURAENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-CuraEngine
