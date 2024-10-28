#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main (int argc, char *argv[]) {

  char *fifo1 = "./myfifo1";
  char *fifo2 = "./myfifo2";

  unlink(fifo1);
  unlink(fifo2);

  if (mkfifo(fifo1, 0666) != 0) {
	perror("FAILED TO CREATE PIPE\n");
	exit(EXIT_FAILURE);
  }

  if (mkfifo(fifo2, 0666) != 0) {
	perror("FAILED TO CREATE PIPE\n");
	exit(EXIT_FAILURE);
  }

  char s1[100], s2[100], result[10];
  int fd1, fd2;

  if (( fd1 = open(fifo1, O_WRONLY)) == -1) {
    perror("ERROR OPENING FIFO\n");
    exit(EXIT_FAILURE);
  }

  if (( fd2 = open(fifo2, O_RDONLY)) == -1) {
    perror("ERROR OPENING FIFO\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter string 1: ");
  scanf("%s", s1);

  printf("Enter string 2: ");
  scanf("%s", s2);

  write(fd1, s1, strlen(s1)+1);
  write(fd1, s2, strlen(s2)+1);

  read(fd2, result, sizeof(result));

  printf("Result: %s\n", result);

  close(fd1);
  close(fd2);

  return EXIT_SUCCESS;

}
