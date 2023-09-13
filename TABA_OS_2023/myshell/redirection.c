#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64

int main(int argc, char *argv[]){
	int fd1, fd2, read_size, write_size;
	char buf[MAX_BUF];

	if (argc != 4){
		printf("Usage: %s input_file_name \">\" output_file_name\n", argv[0]);
		exit(-1);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[3], O_RDWR | O_CREAT, 0641);

	dup2(fd2, STDOUT_FILENO);
	close(fd2);

	while(1){
		read_size = read(fd1, buf, MAX_BUF);
		if (read_size == 0)
			break;
		write_size = write(STDOUT_FILENO, buf, read_size);
	}
	close(fd1);
}

