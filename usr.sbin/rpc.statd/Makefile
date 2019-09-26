# $FreeBSD$

PROG=	rpc.statd
MAN=	rpc.statd.8
SRCS=	file.c sm_inter_svc.c sm_inter.h statd.c procs.c

<<<<<<< HEAD
CFLAGS+= -I.
WARNS?= 2

CFI_OVERRIDE=	-fno-sanitize=cfi-icall

=======
CFLAGS+= -I${.OBJDIR}
>>>>>>> origin/freebsd/current/master
LIBADD=	rpcsvc

# XXX: mismatch between (xdrproc_t) and xdr_void().
WARNS?=	2

CLEANFILES= sm_inter_svc.c sm_inter.h

RPCSRC= ${SYSROOT:U${DESTDIR}}/usr/include/rpcsvc/sm_inter.x
RPCGEN= RPCGEN_CPP=${CPP:Q} rpcgen -L -C

sm_inter_svc.c: ${RPCSRC}
	${RPCGEN} -m -o ${.TARGET} ${.ALLSRC}

sm_inter.h: ${RPCSRC}
	${RPCGEN} -h -o ${.TARGET} ${.ALLSRC}

test: test.o
	${CC} ${LDFLAGS} -o ${.TARGET} ${.ALLSRC} ${LIBADD:S/^/-l/}
CLEANFILES+=	test test.o

.include <bsd.prog.mk>
