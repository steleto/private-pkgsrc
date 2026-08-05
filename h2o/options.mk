# $NetBSD: $

PKG_OPTIONS_VAR=	PKG_OPTIONS.h2o
PKG_SUPPORTED_OPTIONS=	mruby
PKG_SUGGESTED_OPTIONS=	mruby

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mruby

.if !empty(PKG_OPTIONS:Mmruby)
.include "../../lang/ruby/buildlink3.mk"
CONFIGURE_ARGS+=        --WITH_MRUBY=on
USE_TOOLS+=		bison
PLIST.mruby=		yes
.else
CONFIGURE_ARGS+=        --WITH_MRUBY=off
.endif
