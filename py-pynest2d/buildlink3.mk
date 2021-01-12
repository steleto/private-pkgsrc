# $NetBSD$

BUILDLINK_TREE+=	py37-pynest2d

.if !defined(PY37_PYNEST2D_BUILDLINK3_MK)
PY37_PYNEST2D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py37-pynest2d+=	py37-pynest2d>=4.8.0
BUILDLINK_PKGSRCDIR.py37-pynest2d?=	../../private/py-pynest2d

.include "../../private/libnest2d-ultimaker/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.endif	# PY37_PYNEST2D_BUILDLINK3_MK

BUILDLINK_TREE+=	-py37-pynest2d
