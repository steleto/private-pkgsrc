# $NetBSD$

BUILDLINK_TREE+=	py-Uranium

.if !defined(PY_URANIUM_BUILDLINK3_MK)
PY_URANIUM_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-Uranium+=	${PYPKGPREFIX}-Uranium>=4.8.0
BUILDLINK_PKGSRCDIR.py-Uranium?=	../../private/py-Uranium

.include "../../math/py-numpy/buildlink3.mk"
.include "../../private/libArcus/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.endif	# PY_URANIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-Uranium
