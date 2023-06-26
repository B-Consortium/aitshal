# Installation directories following GNU conventions
prefix ?= /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
sbindir = $(exec_prefix)/sbin
datarootdir = $(prefix)/share
datadir = $(datarootdir)
includedir = $(prefix)/include
mandir = $(datarootdir)/man

BIN=bin
OBJ=obj
SRC=src

CC ?= gcc
CFLAGS ?= -Wextra -Wall -O2

.PHONY: all install uninstall clean

aitshal: $(OBJ)/functions.o $(OBJ)/aitshal.o | $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

all: aitshal

all-ncurses: aitshal-ncurses

aitshal-ncurses: $(OBJ)/functions.o $(OBJ)/aitshal.o | $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/aitshal $^ -lncursesw

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN):
	mkdir $(BIN)

$(OBJ):
	mkdir $(OBJ)

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)

install:
	install -d $(DESTDIR)$(mandir)/man6
	install -m644 aitshal.6 $(DESTDIR)$(mandir)/man6 
	install -d $(DESTDIR)$(bindir)
	cd $(BIN) && install * $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/aitshal;
	rm -f $(DESTDIR)$(mandir)/man6/aitshal.6
