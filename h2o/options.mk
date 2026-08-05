# $NetBSD: $

PKG_OPTIONS_VAR=	PKG_OPTIONS.h2o
PKG_SUPPORTED_OPTIONS=	mruby
PKG_SUGGESTED_OPTIONS=	mruby

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mruby

.if !empty(PKG_OPTIONS:Mmruby)
.include "../../lang/ruby/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_MRUBY=on
PLIST.mruby=		yes
BUILDLINK_TARGETS+=	buildlink-bin-rake

buildlink-bin-rake:
	${RUN} \
	f=${BUILDLINK_PREFIX.${RUBY_BASE}}"/bin/rake${RUBY_SUFFIX}"; \
	if ${TEST} -f $$f; then \
		${RM} -f ${BUILDLINK_DIR}/bin/rake; \
		${LN} -s $$f ${BUILDLINK_DIR}/bin/rake; \
	fi
.else
CONFIGURE_ARGS+=        --WITH_MRUBY=off
.endif
