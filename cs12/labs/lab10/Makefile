#Music_collection makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = music.o tune.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

music.o: music.cpp music.h tune.h
	$(COMPILE) $(FLAGS) -c music.cpp

tune.o: tune.cpp tune.h
	$(COMPILE) $(FLAGS) -c tune.cpp

clean:
	rm -rf *~ *.o a.out
