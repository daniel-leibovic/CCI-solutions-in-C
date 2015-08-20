CC		= gcc
CFLAGS	= -g3 -std=c99 -pedantic -Wall
RM 		= rm -f

default: all

all: 1.3

testOrderedSet: 1.3.c
	${CC} ${CFLAGS} -o $@ $^

clean:
	$(RM) orderedSet *.o