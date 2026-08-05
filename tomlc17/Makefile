# $NetBSD$

DISTNAME=	tomlc17-260618
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cktan/}
GITHUB_TAG=	R${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cktan/tomlc17
COMMENT=	Lightweight, strictly compliant TOML v1.1 parser for C and C++
LICENSE=	mit

NO_CONFIGURE=	yes

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c17
USE_CXX_FEATURES=	c++20
USE_TOOLS+=		gmake

MAKE_JOBS_SAFE=	no
MAKE_ENV=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
