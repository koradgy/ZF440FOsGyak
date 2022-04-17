#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int child;

    mkfifo("Korad Gyorgy", S_IRUSR | S_IWUSR);
    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        fd = open("Korad Gyorgy", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);
        close(fd);
        unlink("Korad Gyorgy");

    } else if(child == 0) {
        int fd = open("Korad Gyorgy", O_RDONLY);
        write(fd, "KGY ZF440N\n", 12);
        close(fd);
    }
    return 0;
}