CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lboost_unit_test_framework
DEP = RandWriter.h
OBJS = RandWriter.o TextWriter.o 

all: TextWriter test

TextWriter: $(OBJS)
	$(CC) -g -o TextWriter $(OBJS) $(LFLAGS)
$(objects): %.o: %.cpp $(DEP)
	$(CC) -g -c $(CFLAGS) $< -o $@ $(LFLAGS)

test: test.o $(DEP)
	$(CC) -g -o test test.o RandWriter.o $(LFLAGS)
test.o:test.cpp
	$(CC) -g -c $(CFLAGS) test.cpp $(LFLAGS)


lint:
	cpplint.py --filter=-runtime/references,-build/c++11 --root=. *
	

cleanall : cleanobj
	rm TextWriter

cleanobj :
	rm *.o