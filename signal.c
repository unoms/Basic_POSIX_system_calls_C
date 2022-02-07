#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>  //write

void handleCtrlC(int signal_number);

int main(){
	sigset_t mask;
	//Clean the memory for the mask
	sigemptyset(&mask);
	
	//Now, we get the signal mask for the current process
	sigprocmask( 0, 0, &mask );
	
	//Add SIGINT
	sigaddset( &mask, SIGINT );
	
	// Register signal handler
	signal( 2, handleCtrlC);// = signal(SIGINT, handleCtrlC)

	int i = 1000000;

	while(true){
		if(i == 0) break;
		printf("%d\n", i);
		i--;
	}

	printf("END");
	return 0;

}

void handleCtrlC(int signal_number){
	if(signal_number == SIGINT){
		write(1, "The process was stopped: ", 23);
		system("date");
		_exit(0);	
	}
}