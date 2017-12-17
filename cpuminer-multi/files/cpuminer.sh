#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: cpuminer
# REQUIRE: DAEMON

. /etc/rc.subr

name="cpuminer"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/cpuminer.conf"
cpuminer_flags="-B -S -c @PKG_SYSCONFDIR@/cpuminer.conf"

load_rc_config $name
run_rc_command "$1"
