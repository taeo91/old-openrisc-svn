##
## $Id: Makefile.am,v 1.2 2001-09-27 12:01:29 chris Exp $
##

AUTOMAKE_OPTIONS = foreign 1.4

PGM = $(ARCH)/console-generic.rel

C_FILES = console-generic.c

console_generic_rel_OBJECTS = $(C_FILES:%.c=$(ARCH)/%.o)

include $(RTEMS_ROOT)/make/custom/@RTEMS_BSP@.cfg
include $(top_srcdir)/../../../../../automake/lib.am

#
# (OPTIONAL) Add local stuff here using +=
#

$(PGM): $(console_generic_rel_OBJECTS)
	$(make-rel)

all-local: $(ARCH) $(console_generic_rel_OBJECTS) $(PGM)

.PRECIOUS: $(PGM)

EXTRA_DIST = console-generic.c

include $(top_srcdir)/../../../../../automake/local.am
