#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void myhandler(int sig) {
  signal(SIGINT, SIG_DFL);
  printf("Program was interrupted by signal %d\n", sig);
  return;
}

int main() {
  signal(SIGINT, myhandler);
  while (1) {
    printf("Hello I am first program\n");
    sleep(1);
  }
  return 0;
}