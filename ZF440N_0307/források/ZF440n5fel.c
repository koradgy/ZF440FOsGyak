#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

	pid_t pid;
	int visszateres;

	if(( pid = fork() < 0)
	{
		perror("fork hiba");
	}
	
	else if(pid == 0)
	{

	}

	return 0;
}
