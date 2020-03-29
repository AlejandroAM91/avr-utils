# OPTIONS
CPU_TYPE ?= atmega328p
CPU_FREQ ?= 4000000UL

# DEFAULT CONFIG
## Programs
INSTALL := cp -a
INSTALL_PROGRAM := $(INSTALL)
INSTALL_DATA := ${INSTALL}
MKDIR := mkdir -p
SHELL := /bin/sh

## Compilers
AR	:= avr-ar
CXX := avr-g++

## Directories
outdir := ./out
objdir := $(CURDIR)/obj
incdir := $(CURDIR)/inc
srcdir := $(CURDIR)/src

## Install directories
prefix		?= /usr/local
exec_prefix ?= $(prefix)
includedir  ?= $(prefix)/include
libdir 		?= $(exec_prefix)/lib

## Targets files
TARGET	 := avrutils
LIBFILE	 := $(outdir)/lib$(TARGET).a
SRCFILES := $(shell find $(srcdir) -type f -name *.cpp)
DEPFILES := $(patsubst $(srcdir)/%,$(objdir)/%,$(SRCFILES:.cpp=.d))
OBJFILES := $(patsubst $(srcdir)/%,$(objdir)/%,$(SRCFILES:.cpp=.o))

## Default flags
CPPFLAGS += -MMD -DF_CPU=$(CPU_FREQ) -I$(incdir)
CXXFLAGS += -Os -mmcu=$(CPU_TYPE)

# RULES
## General
.PHONY: all
all: $(LIBFILE)

.PHONY: clean
clean:
	$(info Removing files...)
	-@$(RM) $(LIBFILE) $(OBJFILES) $(DEPFILES)

.PHONY: distclean
distclean:
	$(info Removing files and directories...)
	-@$(RM) -r $(objdir) $(outdir)

.PHONY: install
install: $(LIBFILE) installdirs
	$(info Installing...)
	@$(INSTALL_DATA) $< $(DESTDIR)$(libdir)
	@$(INSTALL_DATA) $(incdir)/* $(DESTDIR)$(includedir)

.PHONY: installdirs
installdirs:
	@$(MKDIR) $(DESTDIR)$(includedir)
	@$(MKDIR) $(DESTDIR)$(libdir)

.PHONY: uninstall
uninstall:
	$(info Uninstalling...)
	-@$(RM) -r $(patsubst $(incdir)/%,$(DESTDIR)$(includedir)/%,$(wildcard $(incdir)/*))
	-@$(RM) -r $(patsubst $(outdir)/%,$(DESTDIR)$(libdir)/%,$(LIBFILE))

## Output
$(LIBFILE): $(OBJFILES)
	$(info Linking $(notdir $@)...)
	@$(MKDIR) $(dir $@)
	@$(AR) rcs $@ $^

## Patterns
$(objdir)/%.o: $(srcdir)/%.cpp $(CURDIR)/Makefile
	$(info Compiling $(patsubst $(CURDIR)/%,./%,$<)...)
	@$(MKDIR) $(dir $@)
	@$(CXX) -c -MMD $(CPPFLAGS) $(CXXFLAGS) -o $@ $< 

## Dependencies
-include $(DEPFILES)
