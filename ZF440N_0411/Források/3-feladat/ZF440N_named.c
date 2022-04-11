#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int child;

    mkfifo("DaBaby", S_IRUSR | S_IWUSR);
    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        fd = open("DaBaby", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);
        close(fd);
        unlink("DaBaby");

    } else if(child == 0) {
        int fd = open("DaBaby", O_RDONLY);
        write(fd, "TJ WI2GDP\n", 11);
        close(fd);

    }
    return 0;
}