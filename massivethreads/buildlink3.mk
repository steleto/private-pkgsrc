# $NetBSD$

BUILDLINK_TREE+=	massivethreads

.if !defined(MASSIVETHREADS_BUILDLINK3_MK)
MASSIVETHREADS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.massivethreads+=	massivethreads>=1.00
BUILDLINK_PKGSRCDIR.massivethreads?=	../../private/massivethreads
.endif	# MASSIVETHREADS_BUILDLINK3_MK

BUILDLINK_TREE+=	-massivethreads
