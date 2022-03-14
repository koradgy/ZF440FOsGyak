#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int pid;
	int stat;

	if((pid = fork()) < 0)
	{
		printf("fork hiba!\n");
		exit(7);
	}

	else if(pid == 0)
	{
		abort();
	}
	if(wait(&stat)!=pid)
	{
		printf("wait hiba!\n");
	}
	if(WIFEXITED(stat))
	{
		printf("siker");
	}
	return 0;
}
