##
## $Id: Makefile.am,v 1.2 2001-09-27 12:01:11 chris Exp $
##

AUTOMAKE_OPTIONS = foreign 1.4

PGM = $(ARCH)/scitab.rel

C_FILES = scitab.c
C_O_FILES = $(C_FILES:%.c=$(ARCH)/%.o)

OBJS = $(C_O_FILES)

include $(RTEMS_ROOT)/make/custom/@RTEMS_BSP@.cfg
include $(top_srcdir)/../../../../../../automake/lib.am

SHGEN = $(PROJECT_ROOT)/tools/cpu/sh/shgen

#
# (OPTIONAL) Add local stuff here using +=
#

CLEANFILES = scitab.c

$(PGM): $(OBJS)
	$(make-rel)

scitab.c: $(SHGEN)
	$(SHGEN) -H $(HZ) sci > $@

all-local: $(ARCH) $(OBJS) $(PGM)

.PRECIOUS: $(PGM)

include $(top_srcdir)/../../../../../../automake/local.am
