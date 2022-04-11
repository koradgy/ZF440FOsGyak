/* Fájlnév: msgletrehozas.c
   Készít üzenetsor KEY kulccsal,ha az még nem létezik.
   KEY kulcsú létező sort beazonosít. 
   Megnézi, üres-e az üzenetsor. Kiírja az üzeneteket, ha nem üres.
   Készítő: dr. Vadász Dénes
   Dátum: 2006. január
*/   

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY  1
#define PERM 0666

main(void)
{
int	id; 			      /* Üzenetsor belső leírója */
struct msqid_ds buff, *buffp = &buff; /* Attribútumok puffere */
struct {long	mtype;		      /* Az üzenet típusa */
	char	mtext[80];	      /* Az üzenet teste */
       }  uzenet; 		      /* Üzenet struktúra változó */
int 	msgsize = 32;		      /* Csonkolási méret */
int 	select = 0;		      /* Üzenet típus választó */

	/* Létrehozzuk a sort vagy beazanosítjuk */
	if( (id = msgget(KEY, PERM | IPC_CREAT)) < 0) {
		perror(" Nem hozható létre az üzenetsor. \n");
		exit(-1);
	}
	/* lekérdezzük az üzenetek pillanatnyi számát */
	msgctl(id, IPC_STAT, buffp);
	/* A buff.msg_qnum változóban az üzenetek pillanatnyi száma ... */
	while(buff.msg_qnum)  {
	   msgrcv(id, (struct msgbuf *) &uzenet, msgsize, select, IPC_NOWAIT);
	   puts(uzenet.mtext);
 	   msgctl(id, IPC_STAT, buffp);
	}	
		
}
