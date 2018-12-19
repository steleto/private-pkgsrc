# $NetBSD$

DISTNAME=	# empty
PKGNAME=	mgenplus-ttf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	# empty
EXTRACT_SUFX=	.zip
VERSION=	20150602
DISTFILES=	mgenplus-1-${VERSION}${EXTRACT_SUFX} \
		mgenplus-1m-${VERSION}${EXTRACT_SUFX} \
		mgenplus-1p-${VERSION}${EXTRACT_SUFX} \
		mgenplus-2-${VERSION}${EXTRACT_SUFX} \
		mgenplus-2m-${VERSION}${EXTRACT_SUFX} \
		mgenplus-2p-${VERSION}${EXTRACT_SUFX}
SITES.mgenplus-1-${VERSION}${EXTRACT_SUFX}=${MASTER_SITE_OSDN:=users/8/8593/}
SITES.mgenplus-1m-${VERSION}${EXTRACT_SUFX}=${MASTER_SITE_OSDN:=users/8/8592/}
SITES.mgenplus-1p-${VERSION}${EXTRACT_SUFX}=${MASTER_SITE_OSDN:=users/8/8594/}
SITES.mgenplus-2-${VERSION}${EXTRACT_SUFX}=${MASTER_SITE_OSDN:=users/8/8596/}
SITES.mgenplus-2m-${VERSION}${EXTRACT_SUFX}=${MASTER_SITE_OSDN:=users/8/8591/}
SITES.mgenplus-2p-${VERSION}${EXTRACT_SUFX}=${MASTER_SITE_OSDN:=users/8/8595/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jikasei.me/font/mgenplus/
COMMENT=	Fonts generated from M+ and Noto gothic
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${FONTDIR} ${DOCDIR}

INSTALL_FONTS=	mgenplus-1c-black.ttf \
		mgenplus-1c-bold.ttf \
		mgenplus-1c-heavy.ttf \
		mgenplus-1c-light.ttf \
		mgenplus-1c-medium.ttf \
		mgenplus-1c-regular.ttf	\
		mgenplus-1c-thin.ttf \
		mgenplus-1cp-black.ttf \
		mgenplus-1cp-bold.ttf \
		mgenplus-1cp-heavy.ttf \
		mgenplus-1cp-light.ttf \
		mgenplus-1cp-medium.ttf \
		mgenplus-1cp-regular.ttf \
		mgenplus-1cp-thin.ttf \
		mgenplus-1m-bold.ttf \
		mgenplus-1m-light.ttf \
		mgenplus-1m-medium.ttf \
		mgenplus-1m-regular.ttf \
		mgenplus-1m-thin.ttf \
		mgenplus-1mn-bold.ttf \
		mgenplus-1mn-light.ttf \
		mgenplus-1mn-medium.ttf \
		mgenplus-1mn-regular.ttf \
		mgenplus-1mn-thin.ttf \
		mgenplus-1p-black.ttf \
		mgenplus-1p-bold.ttf \
		mgenplus-1p-heavy.ttf \
		mgenplus-1p-light.ttf \
		mgenplus-1p-medium.ttf \
		mgenplus-1p-regular.ttf \
		mgenplus-1p-thin.ttf \
		mgenplus-1pp-black.ttf \
		mgenplus-1pp-bold.ttf \
		mgenplus-1pp-heavy.ttf \
		mgenplus-1pp-light.ttf \
		mgenplus-1pp-medium.ttf \
		mgenplus-1pp-regular.ttf \
		mgenplus-1pp-thin.ttf \
		mgenplus-2c-black.ttf \
		mgenplus-2c-bold.ttf \
		mgenplus-2c-heavy.ttf \
		mgenplus-2c-light.ttf \
		mgenplus-2c-medium.ttf \
		mgenplus-2c-regular.ttf \
		mgenplus-2c-thin.ttf \
		mgenplus-2cp-black.ttf \
		mgenplus-2cp-bold.ttf \
		mgenplus-2cp-heavy.ttf \
		mgenplus-2cp-light.ttf \
		mgenplus-2cp-medium.ttf \
		mgenplus-2cp-regular.ttf \
		mgenplus-2cp-thin.ttf \
		mgenplus-2m-bold.ttf \
		mgenplus-2m-light.ttf \
		mgenplus-2m-medium.ttf \
		mgenplus-2m-regular.ttf \
		mgenplus-2m-thin.ttf \
		mgenplus-2p-black.ttf \
		mgenplus-2p-bold.ttf \
		mgenplus-2p-heavy.ttf \
		mgenplus-2p-light.ttf \
		mgenplus-2p-medium.ttf \
		mgenplus-2p-regular.ttf \
		mgenplus-2p-thin.ttf \
		mgenplus-2pp-black.ttf \
		mgenplus-2pp-bold.ttf \
		mgenplus-2pp-heavy.ttf \
		mgenplus-2pp-light.ttf \
		mgenplus-2pp-medium.ttf \
		mgenplus-2pp-regular.ttf \
		mgenplus-2pp-thin.ttf

INSTALL_DOCS=	README_MgenPlus.txt \
		SIL_Open_Font_License_1.1.txt

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
