# $NetBSD$

DISTNAME=	tomlc99-20260130
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cktan/}
GITHUB_TAG=	29076dfd095bbbbd50a3c1b2760d29f4b83e74ac

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cktan/
COMMENT=	TOML C library
LICENSE=	mit

NO_CONFIGURE=	yes

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake

MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
