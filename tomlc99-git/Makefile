# $NetBSD$

DISTNAME=	tomlc99-git
CATEGORIES=	textproc
GIT_REPO=	https://github.com/cktan/tomlc99.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cktan/
COMMENT=	TOML C library
LICENSE=	mit

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

USE_LANGUAGES=	c99
USE_TOOLS+=	gmake

SUBST_CLASSES+=		fix-env
SUBST_STAGE.fix-env=	pre-build
SUBST_MESSAGE.fix-env=	Fixing environment.
SUBST_FILES.fix-env=	Makefile
SUBST_SED.fix-env+=	-e 's|/usr/local|${DESTDIR}${PREFIX}|'

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
