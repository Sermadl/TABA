#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
int main(int argc, char *argv[]){
	DIR *dir = NULL;
	struct dirent* dentry = NULL;
	char *dir_name=".";	

	if(argc == 1){
		dir = opendir(dir_name);	
	}
	else if(argc == 2){
		dir_name = argv[1];
		dir = opendir(dir_name);
	}
	else {printf("argc %d: We only accept 1 or 2 args for now\n", argc);
		exit(-1);}
	
	while((dentry = readdir(dir)) != NULL){
		printf("%s \n", dentry->d_name);
	}
	closedir(dir);
}
