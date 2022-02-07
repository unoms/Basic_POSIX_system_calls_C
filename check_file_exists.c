#include <unistd.h> //read
#include <stdlib.h> //exit
#include <stdio.h> //memset
#include <cstring> //memset
#include <sys/wait.h> 

int main(){
	int s;
	int p[2];
	
	printf("Please, enter a name of the file to check if it exists in the current directory\n");
	
	//Open pipe
	pipe(p);
	
	if( fork() == 0){//Child process
		//we aren't going to read from the pipe so we close that
		close(p[0]);
		
		//Buffer for a user input
		char name[50];
		
		//Clean the buffer
		memset(name, 0, 50);
		//file descriptor, buffer, size
		scanf("%s", name);
		
		//Check if there's a file with the entered name with system call access
		if(!access(name, F_OK)){
			write(p[1], name, 50);
			write(p[1], " file exists", 11);
		}else{
			write(p[1], name, 50);
			write(p[1], " file doesn't exist", 18);
		}
		_exit(0);
	}else{//parent process
		//Wait for the end of the child process
		wait(&s);
		//Buffer for a user input
		char name[256];
		
		//Clean the buffer
		memset(name, 0, 256);
		
		read(p[0], name, 256);
		write(1, name, 256);
		
	}
	
	return 0;
}