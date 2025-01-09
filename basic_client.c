#include "pipe_networking.h"

  int pid = getpid();
  char pp[16];
  sprintf(pp, "%d", pid);
  remove(pp);

int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char pid[32] = "my pid is";
  strcat(pid, atoi(getpid()));
  if (write(to_server, pid, strlen(pid)) == -1) {
    
  char str[16];
  read(from_server, str, 16);
  printf("Returned: %s\n", str);
  sleep(1);
}
