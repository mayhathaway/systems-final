all: client.c server.c game.c
	gcc -o client.o client.c
	gcc -o server.o server.c
	gcc -o game.o game.c

run:
	./client.o & ./server.o

clean:
	rm *.o
