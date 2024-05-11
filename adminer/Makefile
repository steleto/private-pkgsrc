# $NetBSD$

DISTNAME=	adminer-4.8.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=vrana/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

EXTRACT_SUFX=	.php

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.adminer.org/
COMMENT=	Database managemant in a single PHP
LICENSE=	apache-2.0 OR gnu-gpl-v2

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/adminer

.include "options.mk"

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/adminer/adminer.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
