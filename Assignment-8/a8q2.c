#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *summation(void *arg)
{
  int n = *(int *)arg, s = 0, x;
  for (int i = 0; i < n; i++)
  {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &x);
    s += x;
  }
  int *result = malloc(sizeof(int));
  *result = s;
  return result;
}

int main(int argc, char *argv[])
{
  int n;
  printf("Enter N: ");
  scanf("%d", &n);

  pthread_t thread;
  pthread_create(&thread, NULL, summation, &n);

  int *result;
  pthread_join(thread, (void **)&result);
  printf("Sum: %d\n", *result);

  free(result);

  return EXIT_SUCCESS;
}