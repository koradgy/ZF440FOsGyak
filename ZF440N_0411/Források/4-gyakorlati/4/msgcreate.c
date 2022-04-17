#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY  1
#define PERM 0666

void main()
{
int	id; 			      
struct msqid_ds buff, *buffp = &buff;
struct {long	mtype;		  
	char	mtext[80];	      
       }  uzenet; 		    
int 	msgsize = 32;		    
int 	select = 0;		      

	if( (id = msgget(KEY, PERM | IPC_CREAT)) < 0) {
		perror(" Nem hozható létre az üzenetsor. \n");
		exit(-1);
	}
	msgctl(id, IPC_STAT, buffp);
		while(buff.msg_qnum)  {
	   msgrcv(id, (struct msgbuf *) &uzenet, msgsize, select, IPC_NOWAIT);
	   puts(uzenet.mtext);
 	   msgctl(id, IPC_STAT, buffp);
	}	
		
}
