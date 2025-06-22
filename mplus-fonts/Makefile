# $NetBSD$

DISTNAME=	mplus-fonts-git
CATEGORIES=	fonts
GIT_REPO=	https://github.com/coz-m/MPLUS_FONTS
GIT_ENV=        GIT_SSL_NO_VERIFY=true

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mplusfonts.github.io/
COMMENT=	M+ FONTS
LICENSE=	ofl-v1.1

NO_CHECKSUM=	yes
NO_BUILD=	yes

TTF_FONTS_DIR?=		${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS+=	${TTF_FONTS_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/Mplus*.ttf ${DESTDIR}${TTF_FONTS_DIR}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
