CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lboost_unit_test_framework
DEP = FibLFSR.h
OBJS = FibLFSR.o test.o

all:ps1a

ps1a: $(OBJS)
	$(CC) -o ps1a $(OBJS) $(LFLAGS)
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) FibLFSR.cpp 
test.o: test.cpp FibLFSR.h
	$(CC) $(CFLAGS) test.cpp $(LFLAGS)

clean : 
	rm ps1a *.o
