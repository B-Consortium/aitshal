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
CXX ?= g++
CFLAGS ?= -Wextra -Wall -O2
CXXFLAGS ?= -Wextra -Wall -O2

.PHONY: all install uninstall clean

AITSHAL_SRCS := $(wildcard $(SRC)/*.c $(SRC)/*.cpp)
AITSHAL_OBJS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(AITSHAL_SRCS)))

aitshal: $(OBJ)/functions.o $(OBJ)/aitshal.o $(AITSHAL_OBJS) | $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^ -lcurl

all: aitshal

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

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
