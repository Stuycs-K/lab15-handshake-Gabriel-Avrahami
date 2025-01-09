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
  signal(SIGINT, sighandler);
  signal(SIGPIPE, sighandler);
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char pid[32] = "my pid is";
  strcat(pid, atoi(getpid()));
  write(to_server, pid, strlen(pid);
    
  char str[16];
  read(from_server, str, 16);
  printf("Returned: %s\n", str);
  sleep(1);
}
