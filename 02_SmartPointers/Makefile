#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

compiler=clang++-16
#compiler=g++

# clang
# https://clang.llvm.org/cxx_status.html
# clang 16 still uses c++2b to represent c++23
CPP_VERSION=c++2b
CFLAGS=-fstandalone-debug -g -Wall

# g++ (Linux)
# Version 10 or later
# CPP_VERSION=c++20
# Version 9 or earlier (Codespaces)
# Enable C++23 support
# CPP_VERSION=c++2b

TARGETS=bin/mainShared bin/mainUnique

all: bin ${TARGETS}


bin:
	mkdir -p bin

bin/Example.o: src/Example.cpp include/Example.h
	${compiler} -std=${CPP_VERSION} ${CFLAGS} -c -o $@  $<

bin/mainShared.o: src/mainShared.cpp include/Example.h
	${compiler} -std=${CPP_VERSION} ${CFLAGS} -c -o $@  $<

bin/mainUnique.o: src/mainUnique.cpp include/Example.h
	${compiler} -std=${CPP_VERSION} ${CFLAGS} -c -o $@  $<

bin/mainShared: bin bin/mainShared.o bin/Example.o
	${compiler} -std=${CPP_VERSION} ${CFLAGS} -o $@  bin/mainShared.o bin/Example.o

bin/mainUnique: bin bin/mainUnique.o bin/Example.o
	${compiler} -std=${CPP_VERSION} ${CFLAGS} -o $@  bin/mainUnique.o bin/Example.o

valgrindShared: bin/mainShared
	valgrind ${VALGRIND_FLAGS} bin/mainShared

valgrindUnique: bin/mainUnique
	valgrind ${VALGRIND_FLAGS} bin/mainUnique

printAll:
	enscript ${ENSCRIPT_FLAGS} src/*.cpp include/*.h | ps2pdf - bin/src.pdf

	
clean:
	rm -rf ${TARGETS} bin/*.o bin/*.pdf