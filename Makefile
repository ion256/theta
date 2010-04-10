#!/usr/bin/make
CC=g++
binary=theta
source=theta
prefix=/usr/
package=theta# Comment me on debian package builds
srcdir=src
datadir=$(prefix)/share# Comment me on debian package builds
INCLUDES = -DSHAREDDIR="\"$(datadir)/$(package)\""

binary:
	$(CC) $(INCLUDES) $(srcdir)/$(source).cpp -o $(srcdir)/$(binary)

docs:
	make prefix=$(prefix) package=$(package) -C docs/

clean: clean-docs
	rm $(srcdir)/$(binary)

install: binary
	install $(srcdir)/$(binary) $(prefix)/bin/
	install $(srcdir)/$(binary)_updater $(prefix)/bin/
	install -d $(datadir)/$(package)
	install $(srcdir)/scoretemplate.ly $(datadir)/$(package)

all: install docs clean

.PHONY: all install clean docs
