include ${CURDIR}/Makefile.regions

all: clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscu
	$(MAKE) -f ${CURDIR}/Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/Makefile.pal
	$(MAKE) -f ${CURDIR}/Makefile.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscj
	$(MAKE) -f ${CURDIR}/Makefile.ntscj clean
	$(MAKE) -f ${CURDIR}/Makefile.ntsck
	$(MAKE) -f ${CURDIR}/Makefile.ntsck clean

clean:
	$(MAKE) -f ${CURDIR}/Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/Makefile.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscj clean
	$(MAKE) -f ${CURDIR}/Makefile.ntsck clean
	rm -f -r lib/

install: clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscu install
	$(MAKE) -f ${CURDIR}/Makefile.ntscu clean
	$(MAKE) -f ${CURDIR}/Makefile.pal install
	$(MAKE) -f ${CURDIR}/Makefile.pal clean
	$(MAKE) -f ${CURDIR}/Makefile.ntscj install
	$(MAKE) -f ${CURDIR}/Makefile.ntscj clean
	$(MAKE) -f ${CURDIR}/Makefile.ntsck install
	$(MAKE) -f ${CURDIR}/Makefile.ntsck clean
