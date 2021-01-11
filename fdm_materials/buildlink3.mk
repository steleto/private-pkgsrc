# $NetBSD$

BUILDLINK_TREE+=	fdm_materials

.if !defined(FDM_MATERIALS_BUILDLINK3_MK)
FDM_MATERIALS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fdm_materials+=	fdm_materials>=4.8.0
BUILDLINK_PKGSRCDIR.fdm_materials?=	../../private/fdm_materials
.endif	# FDM_MATERIALS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fdm_materials
