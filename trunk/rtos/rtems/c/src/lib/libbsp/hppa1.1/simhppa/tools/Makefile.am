##
##  $Id: Makefile.am,v 1.2 2001-09-27 11:59:45 chris Exp $
##

AUTOMAKE_OPTIONS = foreign 1.4
ACLOCAL_AMFLAGS = -I $(RTEMS_TOPdir)/aclocal

noinst_PROGRAMS = print_dump

print_dump_SOURCES = print_dump.c

## HACK: install to build-tree
install-exec-local: $(PROGRAMS)
	$(mkinstalldirs) $(PROJECT_ROOT)/simhppa/bin
	$(INSTALL_PROGRAM) print_dump $(PROJECT_ROOT)/simhppa/bin

include $(top_srcdir)/../../../../../../../automake/local.am
