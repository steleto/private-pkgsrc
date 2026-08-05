# $NetBSD$

INSTALL_DIRS=		modules/aruco

.include "../../graphics/opencv/Makefile.common"

DISTNAME=	opencv_contrib-${OPENCV_VERSION}
PKGNAME=	${DISTNAME:S/_contrib/-contrib-aruco/}
GITHUB_PROJECT=	opencv_contrib

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenCV ArUco and ChArUco Markers

DISTFILES=	${DEFAULT_DISTFILES} opencv-${PKGVERSION_NOREV}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/opencv-${PKGVERSION_NOREV}

CMAKE_CONFIGURE_ARGS+=		-DBUILD_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_FFMPEG=OFF
CMAKE_CONFIGURE_ARGS+=		-DWITH_JASPER=OFF

CMAKE_CONFIGURE_ARGS+=		-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/${DISTNAME}/modules
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_adas=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_bgsegm=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_bioinspired=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ccalib=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_contrib_world=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_cvv=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_datasets=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dnn_objdetect=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dpm=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_fuzzy=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_hdf=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_hfs=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_imgcodecs=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_img_hash=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_intensity_transform=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_latentsvm=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_line_descriptor=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_matlab=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_optflow=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_phase_unwrapping=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_rapid=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_reg=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_rgbd=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_saliency=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_shape=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_signal=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_stereo=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_structured_light=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_surface_matching=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_text=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_tracking=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_video=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_xfeatures2d=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ximgproc=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_xobjdetect=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_xphoto=OFF

CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dnn=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_highgui=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ml=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_python2=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_python3=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_stitching=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_superres=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_ts=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_videoio=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_videostab=OFF

CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_dnn_superres=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_face=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_mcc=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_photo=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_plot=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_quality=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_wechat_qrcode=OFF

CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_aruco=ON
# needed by aruco
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_objdetect=ON
# needed by aruco, objdetect
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_calib3d=ON
# needed by calib3d
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_feature2d=ON
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_flann=ON
# needed by aruco, calib3d, objdetect, feature2d
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_imgproc=ON
# needed by aruco, imgproc, objdetect, feature2d, flann
CMAKE_CONFIGURE_ARGS+=		-DBUILD_opencv_core=ON

## XXX: INSTALL_DIRS currently do not work as desired in cmake/build.mk.
#USE_CMAKE=	yes
#pre-configure:
#	${MKDIR} ${WRKSRC}/build

BUILDLINK_API_DEPENDS.opencv+=	opencv>=${PKGVERSION_NOREV}
.include "../../graphics/opencv/buildlink3.mk"
#.include "../../lang/python/extension.mk"
#.include "../../math/py-numpy/buildlink3.mk"
#.if ${OPSYS} != "Darwin"
#.include "../../x11/gtk3/buildlink3.mk"
#.endif
.include "../../mk/bsd.pkg.mk"
