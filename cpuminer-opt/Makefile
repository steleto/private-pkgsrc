# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	cpuminer-opt-3.8.8.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=JayDDee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JayDDee/cpuminer-opt/
COMMENT=	Optimized multi algo CPU miner 
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	cpuminer-opt
GITHUB_TAG=	v${PKGVERSION_NOREV}

CONFLICTS+=	cpuminer-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf autoheader automake gmp

RCD_SCRIPTS=	cpuminer

CONF_FILES+=	${PREFIX}/share/examples/cpuminer-opt/cpuminer.conf \
		${PKG_SYSCONFDIR}/cpuminer.conf

INSTALLATION_DIRS+=	share/examples/cpuminer-opt

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-crypto=${BUILDLINK_PREFIX.openssl}

USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
	${INSTALL_DATA} ${FILESDIR}/cpuminer.conf \
		${DESTDIR}${PREFIX}/share/examples/cpuminer-opt

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
