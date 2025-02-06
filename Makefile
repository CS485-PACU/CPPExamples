#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)

# https://lists.gnu.org/archive/html/help-make/2008-04/msg00052.html
SUBCLEAN = $(addsuffix .clean,$(SUBDIRS))
        
clean: $(SUBCLEAN)
        
.PHONY: $(SUBDIRS) $(SUBCLEAN)


$(SUBDIRS):
	cd $@; make

$(SUBCLEAN): %.clean:
	cd $*; make clean