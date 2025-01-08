#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char str[16];
  int num = -2;
  while (1) {
  num = read(from_server, str, 16);
    if (num == -1) {
      int pid = getpid();
      char pp[16];
      sprintf(pp, "%d", pid);
      remove(pp);
      exit(0);
    }
    if (num) {
      printf("%s\n", str);
    }
  }
}
