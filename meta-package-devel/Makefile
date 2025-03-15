# $NetBSD$
#

DISTNAME=	meta-package-devel-0.1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	asteria.at@gmail.com
HOMEPAGE=	# empty
COMMENT=	Personal development package collection

META_PACKAGE=	yes

# converters
DEPENDS+=	help2man-[0-9]*:../../converters/help2man

# devel
DEPENDS+=	autoconf-[0-9]*:../../devel/autoconf
DEPENDS+=	automake-[0-9]*:../../devel/automake
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	ccache-[0-9]*:../../devel/ccache
DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	jdebp-redo-[0-9]*:../../devel/jdebp-redo
DEPENDS+=	glib2-[0-9]*:../../devel/glib2
DEPENDS+=	glib2-tools-[0-9]*:../../devel/glib2-tools
DEPENDS+=	gmake-[0-9]*:../../devel/gmake
DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base
DEPENDS+=	meson-[0-9]*:../../devel/meson
DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

# lang
DEPENDS+=	ats2-[0-9]*:../../lang/ats2
DEPENDS+=	go-[0-9]*:../../lang/go
DEPENDS+=	rust-[0-9]*:../../lang/rust
DEPENDS+=	vala-[0-9]*:../../lang/vala

# pkgtools
DEPENDS+=	cwrappers-[0-9]*:../../pkgtools/cwrappers
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest
DEPENDS+=	mktools-[0-9]*:../../pkgtools/mktools

.include "../../mk/bsd.pkg.mk"

