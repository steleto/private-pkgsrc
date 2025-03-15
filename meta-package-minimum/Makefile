# $NetBSD$
#

DISTNAME=	meta-package-minimum-0.1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	asteria.at@gmail.com
HOMEPAGE=	# empty
COMMENT=	Personal minimum package collection

META_PACKAGE=	yes

# archivers
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

# devel
DEPENDS+=	fossil-[0-9]*:../../devel/fossil
DEPENDS+=	git-[0-9]*:../../devel/git
DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline

# lang
DEPENDS+=	${RUBY_PKGPREFIX}-[0-9]*:../../lang/${RUBY_PKGPREFIX}

# misc
DEPENDS+=	fd-[0-9]*:../../misc/fd
DEPENDS+=	lv-[0-9]*:../../misc/lv

# net
DEPENDS+=	rsync-[0-9]*:../../net/rsync

# pkgtools
DEPENDS+=	pkgin-[0-9]*:../../pkgtools/pkgin
DEPENDS+=	pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives

# security
DEPENDS+=	mozilla-rootcerts-openssl-[0-9]*:../../security/mozilla-rootcerts-openssl
DEPENDS+=	doas-[0-9]*:../../security/doas

# www
DEPENDS+=	curl-[0-9]*:../../www/curl

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"

