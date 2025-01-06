#include "pipe_networking.h"

int main() {
  srand(time(NULL));

  while (1) {
    int to_client = (int*) (malloc(sizeof(int)));
    int from_client = (int*) (malloc(sizeof(int)));

    from_client = server_handshake( &to_client );

    int x = 0;
    char str[16];
    while (1) {
      x = (int) rand() % 100;
      sprintf(str, "%d", x);
      write(to_client, str, 16);
      sleep(1);
    }

    free(to_client);
    free(from_client);
  }
}
