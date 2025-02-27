all: clientcompile forking
client: clients
	@./clients

server: servers
	@./servers

clientcompile: basic_client.o pipe_networking.o
	@gcc -o clients basic_client.o pipe_networking.o

serverrun: basicserver
	@./basicserver

servercompile: basic_server.o pipe_networking.o
	@gcc -o basicserver basic_server.o pipe_networking.o

basic_client.o: basic_client.c pipe_networking.h
	@gcc -c basic_client.c -Wall

basic_server.o: basic_server.c pipe_networking.h
	@gcc -c basic_server.c -Wall

persistent: persistent_server.o pipe_networking.o
	@gcc -o persistent persistent_server.o pipe_networking.o

persistent_server.o: persistent_server.c pipe_networking.h
	@gcc -c persistent_server.c -Wall

forking: forking_server.o pipe_networking.o
	@gcc -o servers forking_server.o pipe_networking.o

forking_server.o: forking_server.c pipe_networking.h
	@gcc -c forking_server.c -Wall

pipe_networking.o: pipe_networking.c pipe_networking.h
	@gcc -c pipe_networking.c -Wall

clean:
	rm *.o
	rm *~
