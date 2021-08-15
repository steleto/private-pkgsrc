# $NetBSD$

PHARO_BUILD=	1543
PHARO_SHA=	0934b1e
PHARO_ARCH=	64bit

DISTNAME=	Pharo9.0-SNAPSHOT.build.${PHARO_BUILD}.sha.${PHARO_SHA}.arch.${PHARO_ARCH}
PKGNAME=	pharo-9.0.0
CATEGORIES=	private
MASTER_SITES=	http://files.pharo.org/image/90/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://files.pharo.org/image/90/
COMMENT=	Pure object-oriented programming language and a powerful environment
LICENSE=	mit AND apache-2.0

DEPENDS+=	pharo-vm-[0-9]*:../../private/pharo-vm

ONLY_FOR_PLATFORM=	NetBSD-[0-9]*-x86_64

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/pharo

PHARO_SRC=	${WRKSRC}/Pharo9.0-SNAPSHOT-${PHARO_ARCH}-${PHARO_SHA}
PHARO_DST=	${DESTDIR}${PREFIX}/share/pharo/

do-install:
	${INSTALL_DATA} ${PHARO_SRC}.image   ${PHARO_DST}/Pharo.image
	${INSTALL_DATA} ${PHARO_SRC}.changes ${PHARO_DST}/Pharo.changes
	${INSTALL_DATA} ${PHARO_SRC:C/SNAPSHOT-//}.sources ${PHARO_DST}

.include "../../mk/bsd.pkg.mk"
