#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	fork();
	char *args[]={"./child.o",NULL};
	execvp(args[0],args);
	printf("pisi kaka\n");
	return 0;
}
