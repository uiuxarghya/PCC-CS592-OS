#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// Define a structure using typedef to hold the data
typedef struct {
    int num;
    char result[10];
} thread_data_t;

// Function to check if a number is prime
void* check_prime(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    int num = data->num;
    bool is_prime = true;

    if (num <= 1) {
        is_prime = false;
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
    }

    // Return the result to the main thread
    if (is_prime) {
        snprintf(data->result, sizeof(data->result), "PRIME");
    } else {
        snprintf(data->result, sizeof(data->result), "NOT PRIME");
    }

    pthread_exit(NULL); // Exit the thread
}

int main() {
    pthread_t tid;
    thread_data_t data;  // Using the typedef struct

    // Input the number
    printf("Enter an integer: ");
    scanf("%d", &data.num);

    // Create a thread to check whether the number is prime
    pthread_create(&tid, NULL, check_prime, &data);

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    // Print the result
    printf("The number %d is %s.\n", data.num, data.result);

    return 0;
}
