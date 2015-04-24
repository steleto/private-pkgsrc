# $NetBSD$

DISTNAME=	vc-fossil-20141031.22
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://melpa.org/packages/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://melpa.org/packages/
COMMENT=	VC backend for the fossil sofware configuraiton management system
#LICENSE=	# TODO: (see mk/license.mk)

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/vc-fossil
NO_CONFIGURE=	yes

USE_LANGUAGES=	# none

SRC=		vc-fossil.el
DOC=		index.wiki

do-build:
	set -e; \
	cd ${WRKSRC}; \
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${SRC}

do-install:
	set -e; \
	cd ${WRKSRC}; \
	${INSTALL_DATA} ${SRC} ${SRC:.el=.elc} ${DOC} \
		${DESTDIR}${EMACS_LISPPREFIX}/vc-fossil

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
