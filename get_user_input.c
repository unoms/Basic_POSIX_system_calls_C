#include <unistd.h> //read
#include <stdlib.h> //exit
#include <stdio.h> //memset
#include <cstring> //memset

int main(){
	//How many bytes we'll read
	int k;
	//Buffer for a user input
	char name[256];
	
	//Clean the buffer
	memset(name, 0, 256);
	
	printf("Please, enter your name\n");
	
	//file descriptor, buffer, size
	if(( k = read(0, name, 256)) == -1){
		printf("Cannot read user input\n");
		exit(0);
	}
	
	//Write into the standard out
	write(1, "Your name is ", 13);
	write(1, name, k);

	return 0;
}