#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int pid;
	pid = fork();
	if (pid > 0){
		printf("\nPARENT: pid=%d\tppid=%d\n",getpid(),getppid());
		sleep(5);
		printf("PARENT DIES");
	}
	if (pid==0){
		printf("\nCHILD: pid=%d\tppid=%d\n",getpid(),getppid());
		sleep(9);
	}
	return 0;
}
