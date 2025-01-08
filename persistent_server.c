#include "pipe_networking.h"

/*static void sighandler(int signo) {
  if (signo == SIGINT) {
  }
  if (signo == SIGPIPE) {
  }
}*/

int main() {
  //signal(SIGINT, sighandler);
  //signal(SIGPIPE, sighandler);

  srand(time(NULL));

  //while (1) {
    printf("1st spot\n");
    int to_client;
    int from_client;

    from_client = server_handshake( &to_client );
    printf("handshake done\n");

    int x = 0;
    char str[16];
    while (1) {
      printf("hi 2nd\n");
      x = (int) rand() % 100 + 1;
      sprintf(str, "%d", x);
      //int errno;
      //errno = write(to_client, str, 16);
      write(to_client, str, 16);
      /*if (errno == -1) {
        printf("errno %d\n", errno);
        printf("%s\n", strerror(errno));
        exit(1);
      }*/
      printf("2nd spot\n");
      sleep(1);
    }
    printf("3rd spot\n");
  //  close(to_client);
  //  close(from_client);
  //}
  printf("4th spot\n");
}
