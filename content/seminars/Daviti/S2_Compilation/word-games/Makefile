CC = g++
CFLAGS = -g -Wall

SRCS = word-games.cc
HDRS =
OBJS = word-games.o

EXECUTABLES = word-games

default: $(EXECUTABLES)

word-games : Makefile.dependencies $(OBJS)
	$(CC) -o $@ $(OBJS)


Makefile.dependencies:: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -MM $(SRCS) > Makefile.dependencies
	g++ -g -Wall -MM word-games.cc > Makefile.dependencies

-include Makefile.dependencies

clean:
	\rm -fr a.out $(EXECUTABLES) *.o core Makefile.dependencies
