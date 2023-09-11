#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64
char fname[]="newfile.txt";
char dummy_data[]="HOME.\n";

int main() {
	int fd, read_size, write_size,new_offset;
	char buf[MAX_BUF];
	
	fd = open(fname, O_RDWR | O_CREAT | O_EXCL, 0664);
	if(fd<0){
		printf("Can't open %sfile with errno %d\n", fname, errno);
		exit(-1);
	}
	
	write_size = write(fd, dummy_data, sizeof(dummy_data));
	close(fd);

	fd=open(fname, O_RDONLY);
	new_offset = lseek(fd, 3, SEEK_SET);
	read_size=read(fd, buf, MAX_BUF);
	printf("read_size = %d\n", read_size);
	write_size = write(STDOUT_FILENO, buf, read_size);

	close(fd);
}
