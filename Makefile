default: all

all: server client

server: server.o
	gcc -g -o server server.o

client: client.o
	gcc -g -o client client.o

clean:
	$(RM) *.o server client