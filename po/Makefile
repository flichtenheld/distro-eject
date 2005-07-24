PKGNAME=eject
PREFIX=$(DESTDIR)/usr
INSTALL = install
MODIR = $(PREFIX)/share/locale
POTFILES = ../*.c ../*.h
#   ZH translation does not work
POFILES= de.po fr.po ja.po es.po
D_NLS= zh_TW.Big5

all:

fix-po-files:
	mv fr_FR.po fr.po
	mv de_DE.po de.po
	mv es_ES.po es.po
	mv ja_JP.eucJP.po ja.po
	mv zh_TW.Big5.po zh_TW.po

restitute-po-files:
	mv fr.po fr_FR.po
	mv de.po de_DE.po
	mv es.po es_ES.po
	mv ja.po ja_JP.eucJP.po
	mv zh_TW.po zh_TW.Big5.po

mo:
	files='$(POFILES)'; \
	for file in $$files;do \
	  echo compiling $$LOCALENAME ; \
	  msgfmt $$file -o `echo $$file |sed 's/\.po$$/.mo/g'`; \
	done

install:
	$(MAKE) fix-po-files
	$(MAKE) mo
	files='$(POFILES)'; \
	for file in $$files;do \
	  LOCALENAME=`echo $$file |sed 's/\.po$$//g'`; \
	  echo installing $$LOCALENAME ; \
	  MOPATH=$(MODIR)/$$LOCALENAME/LC_MESSAGES; \
	  if [ ! -d $$MOPATH ] ;then  \
	     mkdir -p $$MOPATH; \
	  fi; \
	  cp $$LOCALENAME.mo $$MOPATH/$(PKGNAME).mo; \
	done
	$(MAKE) restitute-po-files

pot:
	xgettext --keyword=_ --keyword=N_ $(POTFILES) -o $(PKGNAME).pot

merge:
	for i in *.po;do \
	   NN=`echo $$i |sed "s/\.po$$//g"` ;\
	   echo $$i $$NN ;\
	   msgmerge $$i $(PKGNAME).pot -o $$i.tmp.$$ && mv -vf $$i.tmp.$$ $$i;\
	done

clean:
	rm -fv *.mo

distclean: clean

distdir:
