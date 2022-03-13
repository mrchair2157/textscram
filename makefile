flags = -Wall -Wextra -Werror -pedantic
cc = clang
main: main.c main.h
	$(cc) -c -o main.o main.c $(flags)
	$(cc) -c -o secondary.o secondary.c $(flags)
	$(cc) -o textscram secondary.o main.o $(flags) 
	rm *.o

maintt:
	$(cc) -c -o main.o main.c $(flags) -g -v
	$(cc) -c -o secondary.o secondary.c $(flags) -g -v
	$(cc) -o textscramtest secondary.o main.o $(flags) -g -v
	rm *.o
install: main
	mv textscram /usr/bin
