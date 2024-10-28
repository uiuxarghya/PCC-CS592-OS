#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *summation() {
  int n, s = 0, x;
  printf("Enter N: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &x);
    s += x;
  }
  printf("Sum: %d\n", s);
}

int main(int argc, char *argv[]) {
  pthread_t thread;
  pthread_create(&thread, NULL, summation, NULL);
  pthread_join(thread, NULL);

  return EXIT_SUCCESS;
}