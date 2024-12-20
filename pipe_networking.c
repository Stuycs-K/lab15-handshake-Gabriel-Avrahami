#include "pipe_networking.h"
//UPSTREAM = to the server / from the client
//DOWNSTREAM = to the client / from the server
/*=========================
  server_setup

  creates the WKP and opens it, waiting for a connection.
  removes the WKP once a connection has been made

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_setup() {
  char * wkp = "./toServer";
  mkfifo(wkp, 0666);
  printf("1.1\n");
  int from_client = open(wkp, O_RDONLY);
  printf("1.2\n");
  remove(wkp);
  printf("1.3\n");
  return from_client;
}

/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe (Client's private pipe).

  returns the file descriptor for the upstream pipe (see server setup).
  =========================*/
int server_handshake(int *to_client) {
  printf("1\n");
  int from_client = server_setup();
  printf("2\n");
  char buffer[16];
  while (! read(from_client, buffer, 16)) {
  }
  *to_client = open(buffer, O_WRONLY);
  srand(time(NULL));
  int x = (int) rand();
  char randint[4];
  sprintf(randint, "%d", x);
  write(*to_client, randint, 4);
  char randIntPlusOne[4];
  while (! read(from_client, randIntPlusOne, 4)) {
  }
  int xPlusOne = atoi(randIntPlusOne);
  if (xPlusOne == x+1) {
    printf("YAY\n");
  }
  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  printf("client 1\n");
  int p = getpid();
  printf("client 2\n");
  char pp[4];
  sprintf(pp, "./%d", p);
  printf("client 3\n");
  mkfifo(pp, 0666);
  printf("client 4\n");
  *to_server = open("./toServer", O_WRONLY);
  printf("client 5\n");
  write(*to_server, pp, strlen(pp));
  int from_server = open(pp, O_RDONLY);
  char buffer[16];
  while (! read(from_server, buffer, 16)) {
  }
  int rando = atoi(buffer);
  rando++;
  char randoPlusOne[4];
  sprintf(randoPlusOne, "%d", rando);
  write(*to_server, randoPlusOne, 4);
  return from_server;
}


/*=========================
  server_connect
  args: int from_client

  handles the subserver portion of the 3 way handshake

  returns the file descriptor for the downstream pipe.
  =========================*/
int server_connect(int from_client) {
  int to_client  = 0;
  return to_client;
}
