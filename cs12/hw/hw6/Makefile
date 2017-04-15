#Bboard makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = bboard.o message.o user.o reply.o topic.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

bboard.o: bboard.cpp bboard.h message.h reply.h topic.h user.h
	$(COMPILE) $(FLAGS) -c bboard.cpp

message.o: message.cpp message.h
	$(COMPILE) $(FLAGS) -c message.cpp

reply.o: reply.cpp reply.h message.h
	$(COMPILE) $(FLAGS) -c reply.cpp

topic.o: topic.cpp topic.h message.h
	$(COMPILE) $(FLAGS) -c topic.cpp
	
user.o: user.cpp user.h
	$(COMPILE) $(FLAGS) -c user.cpp
	
clean:
	rm -rf *~ *.o a.out
