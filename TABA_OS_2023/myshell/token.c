#include <stdio.h>
#include <string.h>

int main(void){
	char *token;
	char string[] = "a string, of, ,tokens\0,after null terminator";

	token = strtok(string, ", \n");
	do{
		printf("token:%s\n", token);
	}
	while (token = strtok(NULL, ", \n"));

	return 0;
}
