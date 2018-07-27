# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	cpuminer-multi-1.3.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=tpruvot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tpruvot/cpuminer-multi/
COMMENT=	Multi-threaded CPU miner
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	cpuminer-multi
GITHUB_TAG=	v${PKGVERSION_NOREV}-multi

CONFLICTS+=	cpuminer-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf autoheader automake

RCD_SCRIPTS=	cpuminer

CONF_FILES+=	${PREFIX}/share/examples/cpuminer-multi/cpuminer.conf \
		${PKG_SYSCONFDIR}/cpuminer.conf

INSTALLATION_DIRS+=	share/examples/cpuminer-multi

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-crypto=${BUILDLINK_PREFIX.openssl}

USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
	${INSTALL_DATA} ${FILESDIR}/cpuminer.conf \
		${DESTDIR}${PREFIX}/share/examples/cpuminer-multi

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
