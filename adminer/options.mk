# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.adminer

PKG_SUPPORTED_OPTIONS=	mysql pgsql sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
.endif
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite-[0-9]*:../../databases/php-pdo_sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite3-[0-9]*:../../databases/php-sqlite3
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
.endif
