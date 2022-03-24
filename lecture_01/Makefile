# You need to have cudd installed.
# Set CUDD_HOME to the root of your CUDD installation.

CC = g++

CUDD_HOME = /home/lcapogrosso/Libraries/cudd-3.0.0
CUDD_LIBS = -L$(CUDD_HOME)/lib
CUDD_INCLUDE = -I$(CUDD_HOME)/include	\
			   -I$(CUDD_HOME)/cudd		\
			   -I$(CUDD_HOME)/objdir	\

LIBS = -lcudd

all: cudd_not cudd_and cudd_nand cudd_or cudd_nor cudd_xor cudd_xnor \
	 half_adder var_order

cudd_not: cudd_not.o
	$(CC) -g cudd_not.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_not.o: cudd_not.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_not.cpp -o $@

cudd_and: cudd_and.o
	$(CC) -g cudd_and.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_and.o: cudd_and.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_and.cpp -o $@

cudd_nand: cudd_nand.o
	$(CC) -g cudd_nand.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_nand.o: cudd_nand.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_nand.cpp -o $@

cudd_or: cudd_or.o
	$(CC) -g cudd_or.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_or.o: cudd_or.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_or.cpp -o $@

cudd_nor: cudd_nor.o
	$(CC) -g cudd_nor.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_nor.o: cudd_nor.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_nor.cpp -o $@

cudd_xor: cudd_xor.o
	$(CC) -g cudd_xor.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_xor.o: cudd_xor.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_xor.cpp -o $@

cudd_xnor: cudd_xnor.o
	$(CC) -g cudd_xnor.o -o $@ $(CUDD_LIBS) $(LIBS)
cudd_xnor.o: cudd_xnor.cpp
	$(CC) -c -g $(CUDD_INCLUDE) cudd_xnor.cpp -o $@

half_adder: half_adder.o
	$(CC) -g half_adder.o -o $@ $(CUDD_LIBS) $(LIBS)
half_adder.o: half_adder.cpp
	$(CC) -c -g $(CUDD_INCLUDE) half_adder.cpp -o $@

var_order: var_order.o
	$(CC) -g var_order.o -o $@ $(CUDD_LIBS) $(LIBS)
var_order.o: var_order.cpp
	$(CC) -c -g $(CUDD_INCLUDE) var_order.cpp -o $@

clean:
	rm -f *.o
	rm -f cudd_not cudd_and cudd_nand cudd_or cudd_nor cudd_xor cudd_xnor \
		  half_adder var_order
	rm -f *.dot
