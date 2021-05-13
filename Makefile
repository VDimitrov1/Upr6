.DEFAULT_TARGET:=Upr6
.PHONY: all clean
CC= gcc

$? #Special command for exiting if error found

all: clean Upr6 main.o

Upr6: main.o
	${CC} main.o -o $@

main.o:
	${CC} -O1 -Wall -Wextra -c main.c -o $@

clean:
	rm -f main.o
