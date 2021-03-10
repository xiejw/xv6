include ../eva/eva.mk

# ------------------------------------------------------------------------------
# configurations.
# ------------------------------------------------------------------------------

SRC           =  xv6
CMD           =  cmd
FMT_FOLDERS   =  ${CMD}

.DEFAULT_GOAL = xv6

compile: ${BUILD}

xv6: compile ${BUILD}/xv6
	${EVA_EX} ${BUILD}/xv6

${BUILD}/xv6: cmd/xv6/main.c
	${EVA_LD} -o $@ $^
