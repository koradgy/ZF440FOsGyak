#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

#define KEY  1
#define PERM 0666

void main()
{
int	id; 			   
struct msqid_ds buff, *buffp = &buff; 
  if( (id = msgget(KEY, PERM | IPC_CREAT)) < 0) {
		perror(" Nem hozható létre az üzenetsor. \n");
		exit(-1);
	}

	msgctl(id, IPC_STAT, buffp);

	if(buff.msg_qnum > 0) 
	perror(" Nem üres az üzenetsor.     \n");
	else 
	msgctl(id, IPC_RMID, NULL); 
	
}
