##
##  $Id: Makefile.am,v 1.2 2001-09-27 12:01:15 chris Exp $
##

AUTOMAKE_OPTIONS = foreign 1.4

VPATH = @srcdir@:@srcdir@/../../../shared

PGM = ${ARCH}/startup.rel

if HAS_CXX
C_MAIN_C_FILES =
else
C_MAIN_C_FILES = main.c bootcard.c
endif

# C sources
C_FILES = bspclean.c bsplibc.c bspstart.c setvec.c $(C_MAIN_C_FILES)
C_O_FILES = $(C_FILES:%.c=${ARCH}/%.o)
startup_rel_OBJECTS = $(C_O_FILES)

# CC sources
CC_FILES = rtems-ctor.cc
CC_O_FILES = $(CC_FILES:%.cc=${ARCH}/%.o}

# We install the RTEMS constructor as a separate .o
# so it can be easily place correctly by the compiler config file.

include $(RTEMS_ROOT)/make/custom/@RTEMS_BSP@.cfg
include $(top_srcdir)/../../../../../../automake/lib.am

#
# (OPTIONAL) Add local stuff here using +=
#

AM_CFLAGS += $(LIBC_DEFINES)

$(PGM): $(startup_rel_OBJECTS)
	$(make-rel)

${ARCH}/libno-ctor.a: $(ARCH)/no-ctor.o
	$(AR) -cvr $@ $<

$(PROJECT_RELEASE)/lib/libno-ctor$(LIB_VARIANT).a: ${ARCH}/libno-ctor.a
	$(INSTALL_DATA) $< $@

$(PROJECT_RELEASE)/lib/rtems-ctor$(LIB_VARIANT).o: $(ARCH)/rtems-ctor.o
	$(INSTALL_DATA) $< $@

if HAS_CXX
all-local: $(ARCH) $(PGM) $(PROJECT_RELEASE)/lib/libno-ctor$(LIB_VARIANT).a \
    $(PROJECT_RELEASE)/lib/rtems-ctor$(LIB_VARIANT).o
else
all-local: $(ARCH) $(PGM)
endif

EXTRA_DIST = bspclean.c bspstart.c exit.c main.c no-ctor.c rtems-ctor.cc \
    setvec.c

include $(top_srcdir)/../../../../../../automake/local.am
