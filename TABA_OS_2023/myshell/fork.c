#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int glob = 6;

int main() {
	int var = 88; 
	pid_t fork_return;
	
	printf("Hello, my pid is %d\n", getpid());
	printf("before fork\n");

	if((fork_return = fork()) < 0){
		perror("fork error");
		exit(1);
	}
	else if(fork_return == 0) {
		//child
		glob++; var++;
		printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
	}
	else{
		//parent
		wait(NULL); sleep(1);
		printf("parent: I created child with pid=%d\n", fork_return);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	printf("Bye, my pid is %d\n", getpid());
}
