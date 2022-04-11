/* Fájlnév: msgkuldes.c
   Készít üzenetsor KEY kulccsal,ha az még nem létezik.
   KEY kulcsú létező sort beazonosít. 
   A szabványos bemenetrol beolvasott sort az üzenetsorba teszi
   1-es típusú üzenetként. 
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
int	id; 			/* Üzenetsor belső leírója */
struct  {long     mtype;	/* Az üzenet típusa */
	 char     mtext[80];	/* Az üzenet teste */
	} uzenet; 		/* Az uzenet struktúraváltozó */
int	msgsize;		/* Az üzenet mérethez */ 

	/* Létrehozzuk a sor vagy beazanosítjuk */
	if( (id = msgget(KEY, PERM | IPC_CREAT)) < 0) {
		perror(" Nem hozható létre az üzenetsor. \n");
		exit(-1);
	}
	puts(" Kérek egy sort >"); 
	gets(uzenet.mtext); 	/* Bemenetről egy sort olvasunk */
	uzenet.mtype = 1;	/* Legyen ez a típus */
	msgsize = strlen(uzenet.mtext) + 1; /* Az üzenetméret */
	/* Elküldjük az üzenetet */ 
	msgsnd(id, (struct msgbuf *) &uzenet, msgsize, PERM);
	
}
