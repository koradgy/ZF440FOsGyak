#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fp;
    fp = fopen("korad.txt","w");
    fprintf(fp,"Kórád György, Programtervező Informatukus, ZF440N");
    fclose(fp);
    
    return 0;
}