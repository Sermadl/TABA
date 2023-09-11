#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64
char fname[]="newfileadv.txt";
char dummy[]="TABA OS 2023 Seeun Kim\n";

int main(int argc, char *argv[]){
	int fd, read_size, write_size=0;
	char buf[MAX_BUF];

	fd = open(fname, O_RDWR | O_CREAT | O_EXCL, 0777);
	write_size = write(fd, dummy, sizeof(dummy));
	if(write_size<0){
		printf("Can't open %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	printf("write to file %s write size %d\n", fname, write_size);
	close(fd);

	fd = open(fname, O_RDONLY);
	read_size = read(fd, buf, MAX_BUF);
	printf("read_size = %d\n", read_size);
	write_size = write(STDOUT_FILENO, buf, read_size);

	close(fd);
}
