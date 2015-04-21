# $NetBSD$

DISTNAME=		zpaq705
PKGNAME=		zpaq-7.05
CATEGORIES=		archivers
MASTER_SITES=		http://mattmahoney.net/dc/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mattmahoney.net/dc/zpaq.html
COMMENT=		Incremental Journaling Backup Utility and Archiver
LICENSE=		public-domain

WRKSRC=			${WRKDIR}
USE_TOOLS+=		pod2man
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CXXFLAGS} ${LDFLAGS} -Dunix zpaq.cpp libzpaq.cpp -pthread -o zpaq
	cd ${WRKSRC} && \
	${POD2MAN} zpaq.pod > zpaq.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zpaq ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zpaq.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
