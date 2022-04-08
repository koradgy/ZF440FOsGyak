#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  pid_t	pid;
  
	if(argc < 1) {
		perror(" Hibas argumentum! \n");
		exit(1);
	}
  
	pid = atoi(argv[1]); 
	kill(pid, SIGALRM); 
	exit(0);	
}

