# $NetBSD$

DISTNAME=	gitbucket
PKGNAME=	${DISTNAME}-${PKGVERSION}
PKGVERSION=	4.33.0
CATEGORIES=	private devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gitbucket/gitbucket/releases/download/${PKGVERSION}/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=gitbucket/gitbucket/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=gitbucket/}
#GITHUB_PROJECT=	gitbucket
#GITHUB_TAG=	4.33.0
EXTRACT_SUFX=	.war

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitbucket.github.io/
COMMENT=	Open source git platform on JVM
LICENSE=	apache-2.0

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/tomcat/webapps

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/tomcat/webapps/gitbucket.war

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
