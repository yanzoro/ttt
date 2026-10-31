CC ?= cc
PREFIX ?= /usr/local

ttt: src/ttt.c
	$(CC) -Wall -Wextra src/ttt.c -o ttt

install: ttt
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f ttt $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/ttt

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/ttt

clean:
	rm -f ttt

.PHONY: install uninstall clean
