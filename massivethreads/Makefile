# $NetBSD$

GITHUB_PROJECT=	massivethreads
GITHUB_TAG=	v1.00
DISTNAME=	1.00
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	private
MASTER_SITES=	${MASTER_SITE_GITHUB:=massivethreads/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.eidos.ic.i.u-tokyo.ac.jp/research/massivethreads/
COMMENT=	Light weight thread library
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGSRC_USE_FORTIFY=	no

CFLAGS.NetBSD+=			-D_NETBSD_SOURCE
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
