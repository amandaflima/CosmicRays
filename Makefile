######################################################################
#
#
#
######################################################################
 
SHELL           = /bin/bash
 
######################################################################
 
VERSION         = 1
PATCHLEVEL      = 0
SUBLEVEL        = 0
 
VERSIONNR       = $(VERSION).$(PATCHLEVEL).$(SUBLEVEL)
 
PACKAGE         = COSMIC RAYS
 
######################################################################
 
srcdir          = .
 
prefix          = $(HOME)
 
bindir          = $(prefix)/bin
 
mandir          = $(prefix)/man
infodir         = $(prefix)/info
 
includedir      = -I$(srcdir) 
 
######################################################################
#C compiler
CC              = gcc
 
#C++ compiler
CXX             = g++
 
# Fortran 77 compiler
F77             = g77
 
 
RM              = rm
LN              = ln
TAR             = tar
 
MAKEDEPEND      = $(srcdir)/g++dep
  
######################################################################
 
DEFS            = -D$(PACKAGE)
 
CXXFLAGS        = -Wall 
 

######################################################################
SRCS_CXX	= 	Main.cc \
                Mathematics.cc \
                Physics.cc \
#                Atmosphere.cc \

OBJS_PROG 	= $(patsubst %.cc,%.o,$(SRCS_CXX))

OBJS		= $(patsubst %.cc,%.o,$(SRCS_CXX))

HEADS		= $(patsubst %.cc,%.h,$(SRCS_CXX)) 

DIST_FILE	= CRs.tgz

EXE		= CRs

######################################################################

MAKEDEPOPTS	= -DMAKE_DEPEND

######################################################################
#Build rules

all: $(EXE)

CRs: $(OBJS_PROG) 
	$(RM) -f $@
	$(CXX) $(CXXFLAGS) $(OBJS_PROG)  -o $@ 


%.o:	%.cc
	$(CXX) -c -o $@ $<


clean:
	$(RM) -f $(OBJS) $(EXE)

install:
	$(TAR) zxvf $(DIST_FILE)
#	$(RM) -f $(DIST_FILE)

depend:	$(SRCS_CXX)
	$(MAKEDEPEND) $(MAKEDEPOPTS) $(includedir) $(SRCS_CXX)
# DO NOT DELETE THIS LINE -- g++dep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
