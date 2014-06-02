default: all

all: server client

server.o: server.c bib.h
	gcc -c server.c -g
client.o: client.c bib.h
	gcc -c client.c -g

server: server.o
	gcc -o server server.o -g

client: client.o
	gcc -o client client.o -g

clean:
	$(RM) *.o server client
