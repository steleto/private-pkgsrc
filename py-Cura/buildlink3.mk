# $NetBSD$

BUILDLINK_TREE+=	py-Cura

.if !defined(PY_CURA_BUILDLINK3_MK)
PY_CURA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-Cura+=	py-Cura>=4.8.0
BUILDLINK_PKGSRCDIR.py-Cura?=	../../private/py-Cura

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../private/CuraEngine/buildlink3.mk"
.include "../../private/fdm_materials/buildlink3.mk"
.include "../../private/libSavitar/buildlink3.mk"
.include "../../private/py-Uranium/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.endif	# PY_CURA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-Cura
