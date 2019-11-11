all: main.o
	gcc main.o -o alan

main.o: src/main.c
	gcc -c src/main.c -o main.o

test: all
	./alan test/one.alan