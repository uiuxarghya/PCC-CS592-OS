#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<unistd.h>

sem_t mutex;

void *tf1(void *arg) {
	while(1) {
		sem_wait(&mutex);
		printf("ba");
		sem_post(&mutex);
		usleep(5000);
	}
	pthread_exit(NULL);
}

void *tf2(void *arg) {

	while(1) {
		sem_wait(&mutex);
		printf("ab");
		sem_post(&mutex);
		usleep(5000);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	sem_init(&mutex,0,1);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, tf1, NULL);
	pthread_create(&thread2, NULL, tf2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	sem_destroy(&mutex);
}
