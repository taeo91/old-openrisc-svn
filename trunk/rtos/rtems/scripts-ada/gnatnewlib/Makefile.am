## $Id: Makefile.am,v 1.2 2001-09-27 12:02:53 chris Exp $

AUTOMAKE_OPTIONS = foreign 1.4

MKGNATNEWLIBSPEC = $(SHELL) $(top_builddir)/mkgnatnewlibspec

MKGNATNEWLIBSPEC_DEPS = $(top_builddir)/mkgnatnewlibspec gnatnewlib.spec.in \
    $(top_builddir)/setup.cache

powerpc-rtems-$(GNATNEWLIBVERS).spec: $(MKGNATNEWLIBSPEC_DEPS)
	$(MKGNATNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . powerpc-rtems

sparc-rtems-$(GNATNEWLIBVERS).spec: $(MKGNATNEWLIBSPEC_DEPS)
	$(MKGNATNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . sparc-rtems

TEMPLATES = gnatnewlib.spec.in

RPM_SPECS_DATA = powerpc-rtems-$(GNATNEWLIBVERS).spec \
    sparc-rtems-$(GNATNEWLIBVERS).spec

noinst_DATA = $(TEMPLATES)

EXTRA_DIST = $(TEMPLATES)

CLEANFILES = $(RPM_SPECS_DATA)
include $(top_srcdir)/../automake/local.am
