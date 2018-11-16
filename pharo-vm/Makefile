# $NetBSD$

DISTNAME=	opensmalltak-vm
PKGNAME=	pharo-vm-${PKGVERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenSmalltalk/}
GITHUB_PROJECT=	opensmalltalk-vm
GITHUB_TAG=	201810190412
PKGVERSION=	5.0-${GITHUB_TAG}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opensmalltalk.org/
COMMENT=	Cross-platform VM for Squeak, Pharo, Cuis, and Newspeak
LICENSE=	mit

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	PharoV50.sources.zip
SITES.PharoV50.sources.zip=	\
		http://files.pharo.org/sources/

USE_LANGUAGES=	c
USE_TOOLS+=	autoreconf autoconf automake pkg-config bash
AUTOCONF_REQD=	2.69

NO_CONFIGURE=	yes

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=	platforms/unix/plugins/SqueakSSL/openssl_overlay.h
SUBST_SED.fix-paths=	-e "s,@pkglibdir@,'${PREFIX}/lib',g"

SUBST_CLASSES+=		sccs
SUBST_STAGE.sccs=	pre-build
SUBST_MESSAGE.sccs=	Set version infomation to the VM.
SUBST_FILES.sccs=	platforms/Cross/vm/sqSCCSVersion.h
SUBST_FILES.sccs+=	platforms/Cross/plugins/sqPluginsSCCSVersion.h
SUBST_SED.sccs=		-e "s,\$$Rev,\$$Rev: ${GITHUB_TAG} ,g"
SUBST_SED.sccs+=	-e "s,\$$Date,\$$Date: Thu Oct 18 21:12:21 2018 -0700 ,g"
SUBST_SED.sccs+=	-e "s,\$$URL,\$$URL: ${WRKSRC} ,g"
SUBST_SED.sccs+=	-e "s,\$$CommitHash,\$$CommitHash: 15341b579 ,g"

pre-build:
	cd ${WRKSRC}/platforms/unix/config && ${MAKE_PROGRAM}
	${INSTALL_DATA_DIR} ${WRKSRC}/sources
	${INSTALL_DATA} ${WRKDIR}/PharoV50.sources ${WRKSRC}/sources/PharoV50.sources

do-build:
	cd ${WRKSRC}/build.linux64x64/pharo.cog.spur/build && yes | ${BASH} ./mvm

do-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/products/cogspur64linuxht && find bin -type f | while read file; do \
		${INSTALL_SCRIPT} $$file ${DESTDIR}${PREFIX}/$$file; \
	done
	cd ${WRKSRC}/products/cogspur64linuxht && find lib -type d | while read dir; do \
		${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/$$dir; \
	done
	cd ${WRKSRC}/products/cogspur64linuxht && find lib -type f | while read file; do \
		${INSTALL_LIB} $$file ${DESTDIR}${PREFIX}/$$file; \
	done

.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../pkgtools/x11-links/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
