# $NetBSD$

.include "../../graphics/opencv/Makefile.common"

DISTNAME=	opencv_contrib-${OPENCV_VERSION}
PKGNAME=	${DISTNAME:S/_contrib/-contrib-aruco/}
GITHUB_PROJECT=	opencv_contrib

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenCV ArUco and ChArUco Markers

DISTFILES=	${DEFAULT_DISTFILES} opencv-${PKGVERSION_NOREV}${EXTRACT_SUFX}

INSTALL_DIRS=	build/modules/aruco

WRKSRC=		${WRKDIR}/opencv-${PKGVERSION_NOREV}

CMAKE_ARGS+=	-DBUILD_DOCS=OFF
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
CMAKE_ARGS+=	-DWITH_JASPER=OFF

CMAKE_ARGS+=		-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/${DISTNAME}/modules

#CMAKE_ARGS+=		-DBUILD_opencv_aruco=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bgsegm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_bioinspired=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ccalib=OFF
CMAKE_ARGS+=		-DBUILD_opencv_cnn_3dobj=OFF
CMAKE_ARGS+=		-DBUILD_opencv_cvv=OFF
CMAKE_ARGS+=		-DBUILD_opencv_datasets=OFF
CMAKE_ARGS+=		-DBUILD_opencv_dnn_objdetect=OFF
CMAKE_ARGS+=		-DBUILD_opencv_dnns_easily_fooled=OFF
CMAKE_ARGS+=		-DBUILD_opencv_dpm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_face=OFF
CMAKE_ARGS+=		-DBUILD_opencv_freetype=OFF
CMAKE_ARGS+=		-DBUILD_opencv_fuzzy=OFF
CMAKE_ARGS+=		-DBUILD_opencv_hdf=OFF
CMAKE_ARGS+=		-DBUILD_opencv_hfs=OFF
CMAKE_ARGS+=		-DBUILD_opencv_img_hash=OFF
CMAKE_ARGS+=		-DBUILD_opencv_line_descriptor=OFF
CMAKE_ARGS+=		-DBUILD_opencv_matlab=OFF
CMAKE_ARGS+=		-DBUILD_opencv_optflow=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ovis=OFF
CMAKE_ARGS+=		-DBUILD_opencv_phase_unwrapping=OFF
CMAKE_ARGS+=		-DBUILD_opencv_plot=OFF
CMAKE_ARGS+=		-DBUILD_opencv_reg=OFF
CMAKE_ARGS+=		-DBUILD_opencv_rgbd=OFF
CMAKE_ARGS+=		-DBUILD_opencv_saliency=OFF
CMAKE_ARGS+=		-DBUILD_opencv_sfm=OFF
CMAKE_ARGS+=		-DBUILD_opencv_stereo=OFF
CMAKE_ARGS+=		-DBUILD_opencv_structured_light=OFF
CMAKE_ARGS+=		-DBUILD_opencv_surface_matching=OFF
CMAKE_ARGS+=		-DBUILD_opencv_text=OFF
CMAKE_ARGS+=		-DBUILD_opencv_tracking=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xfeatures2d=OFF
CMAKE_ARGS+=		-DBUILD_opencv_ximgproc=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xobjdetect=OFF
CMAKE_ARGS+=		-DBUILD_opencv_xphoto=OFF

# XXX: INSTALL_DIRS currently do not work as desired in cmake/build.mk.
USE_CMAKE=	yes
pre-configure:
	${MKDIR} ${WRKSRC}/build

BUILDLINK_API_DEPENDS.opencv+=	opencv>=${PKGVERSION_NOREV}
.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/gtk3/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
