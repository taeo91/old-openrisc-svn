##
## $Id: Makefile.am,v 1.2 2001-09-27 12:02:52 chris Exp $
##

AUTOMAKE_OPTIONS = foreign 1.4

MKGCCNEWLIBSPEC = $(SHELL) $(top_builddir)/mkgccnewlibspec

SUBPACKAGES = gccnewlib.add \
    base-gcc.add target-gcc.add \
    base-chill.add target-chill.add \
    base-g77.add target-g77.add \
    base-gcj.add target-gcj.add \
    target-objc.add

gccnewlib.spec.in: $(SUBPACKAGES)
	cat $^ \
	| sed -e 's%@GCCLANGS@%%g' > $@
CLEANFILES += gccnewlib.spec.in

gccnewlib_c_only.spec.in: gccnewlib.add base-gcc.add target-gcc.add
	cat $^ \
	| sed -e "s%@GCCLANGS@%\'--enable-languages=c,c++\'%g" > $@
CLEANFILES += gccnewlib_c_only.spec.in

C_ONLY_ARG = -a $(top_builddir)/gccnewlib/gccnewlib_c_only.spec.in

MKGCCNEWLIBSPEC_DEPS = $(top_builddir)/mkgccnewlibspec gccnewlib.spec.in \
    $(top_builddir)/setup.cache
MKGCCNEWLIB_C_ONLY_SPEC_DEPS = $(top_builddir)/mkgccnewlibspec \
    gccnewlib_c_only.spec.in $(top_builddir)/setup.cache

hppa1.1-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . hppa1.1-rtems

i386-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . i386-rtems

i960-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIB_C_ONLY_SPEC_DEPS)
	$(MKGCCNEWLIBSPEC) $(C_ONLY_ARG) -cfg $(top_builddir)/setup.cache -o . i960-rtems

m68k-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . m68k-rtems

m68k-rtemself-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . m68k-rtemself

mips64orion-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . mips64orion-rtems

powerpc-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . powerpc-rtems

sh-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . sh-rtems

sh-rtemself-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . sh-rtemself

sparc-rtems-$(GCCNEWLIBVERS).spec: $(MKGCCNEWLIBSPEC_DEPS)
	$(MKGCCNEWLIBSPEC) -cfg $(top_builddir)/setup.cache -o . sparc-rtems

RPM_SPECS_DATA = hppa1.1-rtems-$(GCCNEWLIBVERS).spec \
    i386-rtems-$(GCCNEWLIBVERS).spec i960-rtems-$(GCCNEWLIBVERS).spec \
    m68k-rtems-$(GCCNEWLIBVERS).spec m68k-rtemself-$(GCCNEWLIBVERS).spec \
    mips64orion-rtems-$(GCCNEWLIBVERS).spec \
    powerpc-rtems-$(GCCNEWLIBVERS).spec sh-rtems-$(GCCNEWLIBVERS).spec \
    sh-rtemself-$(GCCNEWLIBVERS).spec sparc-rtems-$(GCCNEWLIBVERS).spec
CLEANFILES += $(RPM_SPECS_DATA)

EXTRA_DIST = $(SUBPACKAGES)

include $(top_srcdir)/../automake/local.am
