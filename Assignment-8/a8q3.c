#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define MAX_RANGE 100

// Function to check if a number is prime
bool is_prime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

// Thread function to compute prime numbers in the given range
void* compute_primes(void* arg) {
  int* data = (int*)arg;
  int start = data[0];
  int end = data[1];
  int thread_id = data[2];

  for (int i = start; i <= end; i++) {
    if (is_prime(i)) {
      printf("From thread %d: %d\n", thread_id, i);
    }
  }

  free(arg);  // Free allocated memory for the argument array
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int range_per_thread = MAX_RANGE / NUM_THREADS;

  // Create threads and assign range for each thread
  for (int i = 0; i < NUM_THREADS; i++) {
    int* data = (int*)malloc(3 * sizeof(int));  // Allocate memory for start, end, and thread_id

    data[0] = i * range_per_thread + 1;    // Start of the range
    data[1] = (i + 1) * range_per_thread;  // End of the range
    data[2] = i + 1;                       // Thread ID

    if (i == NUM_THREADS - 1) {
      data[1] = MAX_RANGE;  // Ensure the last thread covers till 100
    }

    pthread_create(&threads[i], NULL, compute_primes, (void*)data);
  }

  // Wait for all threads to finish
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
