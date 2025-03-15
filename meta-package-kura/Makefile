# $NetBSD$
#

DISTNAME=	meta-package-kura-0.1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	asteria.at@gmail.com
HOMEPAGE=	# empty
COMMENT=	Personal package collection for "kura"

META_PACKAGE=	yes

# archivers
DEPENDS+=	zopfli-[0-9]*:../../archivers/zopfli

# audio
DEPENDS+=	sox-[0-9]*:../../audio/sox

# databases
DEPENDS+=	openldap-[0-9]*:../../databases/openldap
DEPENDS+=	postgresql16-[0-9]*:../../databases/postgresql16

# devel
DYEPENDS+=	${PHP_PKG_PREFIX}-composer-[0-9]*:../../devel/php-composer
DYEPENDS+=	ccache-[0-9]*:../../devel/ccache

# graphics
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	pngquant-[0-9]*:../../graphics/pngquant
DEPENDS+=	${PHP_PKG_PREFIX}-imagick-[0-9]*:../../graphics/${PHP_PKG_PREFIX}-imagick

# meta-pkgs
DEPENDS+=	${PHP_PKG_PREFIX}-extensions-[0-9]*:../../meta-pkgs/${PHP_PKG_PREFIX}-extensions

# misc
DEPENDS+=	raspberrypi-userland-[0-9]*:../../misc/raspberrypi-userland

# multimedia
DEPENDS+=	ffmpeg7-[0-9]*:../../multimedia/ffmpeg7

# pkgtools
DEPENDS+=	mksandbox-[0-9]*:../../pkgtools/mksandbox
DEPENDS+=	pkgdiff-[0-9]*:../../pkgtools/pkgdiff
DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint
DEPENDS+=	url2pkg-[0-9]*:../../pkgtools/url2pkg

# security
DEPENDS+=	clamav-[0-9]*:../../security/clamav

# sysutils
DEPENDS+=	rsyslog-[0-9]*:../../sysutils/rsyslog

# www
DEPENDS+=	${PHP_PKG_PREFIX}-apcu-[0-9]*:../../www/php-apcu
DEPENDS+=	${PHP_PKG_PREFIX}-nextcloud-[0-9]*:../../www/php-nextcloud
DEPENDS+=	ikiwiki-[0-9]*:../../www/ikiwiki
DEPENDS+=	lighttpd-[0-9]*:../../www/lighttpd
DEPENDS+=	moodle-[0-9]*:../../www/moodle
DEPENDS+=	squid>=6<7:../../www/squid6

# wip
DEPENDS+=	libjxl-[0-9]*:../../wip/libjxl
DEPENDS+=	zpaq-[0-9]*:../../wip/zpaq

# private
DEPENDS+=	meta-package-minimum-[0-9]*:../../private/meta-package-minimum

.include "../../lang/php/phpversion.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"

