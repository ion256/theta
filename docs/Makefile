FILES=README INSTALL CHANGELOG
all:
	doxygen Doxyfile
	install -d $(prefix)/share/doc/$(package)
	install $(FILES) $(prefix)/share/doc/$(package)
