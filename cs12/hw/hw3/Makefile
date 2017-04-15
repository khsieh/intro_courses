#Makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJECTS = User.o Message.o BBoard.o
SOURCES = User.cpp Message.cpp BBoard.cpp 
HEADERS = User.h Message.h BBoard.h

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

User.o: User.cpp Use.h
	$(COMPILE) $(FLAGS) -c User.cpp
Message.o: Message.cpp Message.h
	$(COMPILE) $(FLAGS) -c Message.cpp
BBoard.o: BBoard.cpp BBoard.h
	$(COMPILE) $(FLAGS) -c BBoard.cpp

clean:
	rm -rf *~ *.o a.out
