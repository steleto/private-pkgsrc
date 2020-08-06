# $NetBSD$

BUILDLINK_TREE+=	opencv-contrib-aruco

.if !defined(OPENCV_CONTRIB_ARUCO_BUILDLINK3_MK)
OPENCV_CONTRIB_ARUCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencv-contrib-aruco+=	opencv-contrib-aruco>=3.0.0
BUILDLINK_ABI_DEPENDS.opencv-contrib-aruco?=	opencv-contrib-aruco>=3.4.9nb1
BUILDLINK_PKGSRCDIR.opencv-contrib-aruco?=	../../graphics/opencv-contrib-aruco

.include "../../graphics/opencv/buildlink3.mk"
.endif	# OPENCV_CONTRIB_ARUCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencv-contrib-aruco
