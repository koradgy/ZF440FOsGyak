#include <stdio.h>
#include <sys/types.h> //pid_t
#include <signal.h> //signal()
#include <unistd.h>

void signalHandler(int);

int main(){
	pid_t pid = getpid();
	unsigned int sec = 3;
	printf("PID: %d\n", (int)pid);
	printf("Signal kezelo atvetele: %d\n", signal(SIGTERM, signalHandler));
    
	while(1){
		printf("varakozas..\n");
		sleep(3);
	}
	return 0;
}

void signalHandler(int sig){
	printf("Az integer erteke: %d\n", sig);
	return;
}
