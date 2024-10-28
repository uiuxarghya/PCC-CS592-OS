#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {

  char *fifo1 = "./myfifo1";
  char *fifo2 = "./myfifo2";

  char s1[100], s2[100], result[10];
  int fd1, fd2;

  if ((fd1 = open(fifo1, O_RDONLY)) == -1) {
    perror("FAILED TO OPEN FIFO\n");
    exit(EXIT_FAILURE);
  }

  if ((fd2 = open(fifo2, O_WRONLY)) == -1) {
    perror("FAILED TO OPEN FIFO\n");
    exit(EXIT_FAILURE);
  }

  read(fd1, s1, sizeof(s1));
  read(fd1, s2, sizeof(s2));

  if (strcmp(s1, s2) == 0) {
    strcpy(result, "SAME");
  } else {
    strcpy(result, "NOT SAME");
  }

  printf("Compared\n");

  write(fd2, result, strlen(result));

  close(fd1);
  close(fd2);

  return EXIT_SUCCESS;

}
