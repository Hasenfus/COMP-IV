CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
DEP = Checkers.h
OBJS = main.o Checkers.o

all: Checkers

Checkers: $(OBJS)
	$(CC) -o Checkers $(OBJS) $(LFLAGS)
$(objects): %.o: %.cpp $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@ $(LFLAGS)

lint:
	cpplint.py --filter=-runtime/references,-build/c++11 --root=. *
	

cleanall : cleanobj
	rm Checkers

cleanobj :
	rm *.o