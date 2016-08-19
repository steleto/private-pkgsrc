# $NetBSD$

DISTNAME=		zpaq715
PKGNAME=		zpaq-7.15
CATEGORIES=		archivers
MASTER_SITES=		http://mattmahoney.net/dc/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mattmahoney.net/dc/zpaq.html
COMMENT=		Incremental Journaling Backup Utility and Archiver
LICENSE=		public-domain

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
USE_TOOLS+=		gmake pod2man
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zpaq ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zpaq.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
