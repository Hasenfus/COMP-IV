CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
DEP = EDistance.h
OBJS = main.o EDistance.o

all: EDistance

EDistance: $(OBJS)
	$(CC) -g -o EDistance $(OBJS) $(LFLAGS)
$(objects): %.o: %.cpp $(DEP)
	$(CC) -g -c $(CFLAGS) $< -o $@ $(LFLAGS)

lint:
	cpplint.py --filter=-runtime/references,-build/c++11 --root=. *
	

cleanall : cleanobj
	rm EDistance

cleanobj :
	rm *.o