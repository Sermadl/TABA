#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 5
char fname[]="alphabet.txt";

int main() {
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	fd = open(fname, O_RDONLY);
	if(fd<0){
		printf("Can't open %sfile with errno %d\n", fname, errno);
		exit(-1);
	}
	read_size = read(fd, buf, MAX_BUF);
	if(read_size<0){
		printf("Can't read from file %s, size= %d\n", fname, read_size);
	}
	write_size = write(STDOUT_FILENO, buf, MAX_BUF);	
	close(fd);
}
