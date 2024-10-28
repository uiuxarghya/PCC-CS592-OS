#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Invalid number of inputs\n");
    return EXIT_FAILURE;
  }

  int p[2];

  if (pipe(p) != 0) {
    fprintf(stderr, "Pipe failure\n");
    return EXIT_FAILURE;
  }

  int child = fork();

  if (child == -1) {
    fprintf(stderr, "Fork failed\n");
    return EXIT_FAILURE;
  }

  else if (child == 0) {
    close(p[0]);

    printf("%d: Reached child\n", (int)getpid());
    printf("%d: Child writing to pipe: %s\n", (int)getpid(), argv[1]);
    write(p[1], argv[1], strlen(argv[1]));

    close(p[1]);
  }

  else {
    close(p[1]);

    printf("%d: Parent\n", getpid());

    char message[100];
    int n = read(p[0], message, sizeof(message) - 1);
    message[n] = '\0';

    close(p[0]);

    printf("%d: Parent read from pipe: %s\n", (int)getpid(), message);
  }

  int corpse;
  int status;
  while ((corpse = wait(&status)) > 0)
    printf("%d: Child PID %d exited with status 0x%.4x\n", (int)getpid(), corpse, status);

  return EXIT_SUCCESS;
}
