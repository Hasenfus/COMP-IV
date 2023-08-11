CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
DEP = Sokaban.h
OBJS = main.o Sokaban.o

all: Sokaban

Sokaban: $(OBJS)
	$(CC) -o KSGuitarSim $(OBJS) $(LFLAGS)
$(objects): %.o: %.cpp $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@ $(LFLAGS)

lint:
	cpplint.py --filter=-runtime/references,-build/c++11 --root=. *
	

cleanall : cleanobj
	rm KSGuitarSim

cleanobj :
	rm *.o