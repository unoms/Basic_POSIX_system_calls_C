#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	//Create a file where 664 is ownership
	//it's clear that fd = 3 because 0 - is a standard in, 1 - out, 2 -errors
	int fd = creat("file.txt", 0664);

	printf("fd=%d\n", fd);

	//We close the standard output
	close(1);
	
	// dup2 - duplicate a file descriptor
	//So in the place of the standard output, we place the descriptor of the created file
	dup2(fd, 1);

	//Close the created file
	close(fd);

	//So ls -a should be printed in the shell but we have redirected the output to the file.txt
	execl("/bin/ls", "ls", "-a", 0);

	return 0;
}