/* Fájlnév: msgmegszuntetes.c
   KEY kulcsú létező sort beazonosít. 
   (Készít üzenetsor KEY kulccsal,ha az még nem létezik.)
   Megnézi, üres-e az üzenetsor. Megszünteti, ha üres.
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
	/* Létrehozzuk a sor vagy beazanosítjuk */
	if( (id = msgget(KEY, PERM | IPC_CREAT)) < 0) {
		perror(" Nem hozható létre az üzenetsor. \n");
		exit(-1);
	}
	/* Most megnézzük, üre-e a sor. 
	   Attribútumait a buff struktúrába hozzuk. */
	msgctl(id, IPC_STAT, buffp);
	/* A buff.msg_qnum változóban az üzenetek pillanatnyi száma ... */
	if(buff.msg_qnum > 0) 
	perror(" Nem üres az üzenetsor.     \n");
	else 
	msgctl(id, IPC_RMID, NULL); /* Most töröltem. */
	
}
