#include "pipe_networking.h"

static void sighandler(int signo) {
  if (signo == SIGPIPE) {
    int pid = getpid();
    char pp[16];
    sprintf(pp, "%d", pid);
    remove(pp);
    exit(0);
  }
}

int main() {
  signal(SIGPIPE, sighandler);

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char str[16];
  while (1) {
    if (read(from_server, str, 16)) {
      printf("%s\n", str);
    }
    write(to_server, "", 1);
  }
}
