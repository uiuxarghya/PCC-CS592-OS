#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pid, status;
	pid = fork();
	if (pid > 0){
		printf("\nPARENT: pid=%d\tppid=%d\n",getpid(),getppid());
		sleep(9);
		wait(&status);
	}
	if (pid==0){
		printf("\nCHILD: pid=%d\tppid=%d\n",getpid(),getppid());
		sleep(5);
		printf("CHILD DIES...");
	}
	return 0;
}
