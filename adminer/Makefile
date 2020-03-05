# $NetBSD$

DISTNAME=	adminer-4.7.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=vrana/adminer/releases/download/v4.7.6/}
EXTRACT_SUFX=	.php

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.adminer.org/
COMMENT=	Database managemant in a single PHP
LICENSE=	apache-2.0 OR gnu-gpl-v2

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/adminer

WRKSRC=		${WRKDIR}

#DEPENDS+=	${PHP_PKG_PREFIX}-mongo-[0-9]*:../../databases/php-mongo
#DEPENDS+=	${PHP_PKG_PREFIX}-mongodb-[0-9]*:../../databases/php-mongodb
#DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
#DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
#DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql-[0-9]*:../../databases/php-pdo_pgsql
#DEPENDS+=	${PHP_PKG_PREFIX}-sqlite3-[0-9]*:../../databases/php-sqlite3
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite-[0-9]*:../../databases/php-pdo_sqlite

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/adminer/adminer.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
