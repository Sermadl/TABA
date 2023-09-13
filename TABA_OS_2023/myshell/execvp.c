#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	pid_t fork_return, d_pid;
	int exit_status = -1;
	if ((fork_return = fork()) == -1){
		perror("fork error");
		exit(1);
	}
	else if(fork_return == 0){
		//child
		char *args[] = {"./hello", NULL};
		execvp(args[0], args);
		printf("Child..I'm here\n");
		//if execvp succeeds, printf() is not performed
		exit(1);

	}
	else{
		//parent
		d_pid = wait(&exit_status);
		printf("Parent..I'm here\n");
		printf("exit status of task %d is %d\n", d_pid, exit_status);
	}
}
