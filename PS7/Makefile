CC = g++
CFLAGS = -c -Wall -Werror -std=c++14 
LFLAGS = -lboost_regex
DEP = 
OBJS =  stdinboost.o 

all: ps7 

ps7: $(OBJS)
	$(CC) -g -o ps7 $(OBJS) $(LFLAGS)
$(objects): %.o: %.cpp $(DEP)
	$(CC) -g -c $(CFLAGS) $< -o $@ $(LFLAGS)

lint:
	cpplint.py --filter=-runtime/references,-build/c++11 --root=. *
	

cleanall : cleanobj
	rm ps7

cleanobj :
	rm *.o