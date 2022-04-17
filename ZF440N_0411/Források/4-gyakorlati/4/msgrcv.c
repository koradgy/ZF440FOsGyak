#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

#define KEY  1
#define PERM 0666

void main()
{
int	id; 			
struct  {long     mtype;	
	 char     mtext[80];	
	} uzenet; 		
int	msgsize;


	if( (id = msgget(KEY, PERM | IPC_CREAT)) < 0) {
		perror(" Nem hozható létre az üzenetsor. \n");
		exit(-1);
	}
	puts(" Kérek egy sort >"); 
	gets(uzenet.mtext); 	
	uzenet.mtype = 1;	
	msgsize = strlen(uzenet.mtext) + 1;

	msgsnd(id, (struct msgbuf *) &uzenet, msgsize, PERM);
	
}
