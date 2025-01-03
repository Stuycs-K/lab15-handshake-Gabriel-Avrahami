#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char str[16];
  while (1) {
    if (read(from_server, str, 16)) {
      printf("%s\n", str);
    }
  }
}
