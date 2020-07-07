# $NetBSD$

GITHUB_PROJECT=	fstl
GITHUB_TAG=	v0.9.4
DISTNAME=	v0.9.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=mkeeter/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mattkeeter.com/projects/fstl/
COMMENT=	The fastest .stl file viewer
LICENSE=	mit

WRKSRC=		${WRKDIR}/fstl-0.9.4
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
