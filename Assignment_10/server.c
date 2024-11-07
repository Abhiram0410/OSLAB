#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    const char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char str1[80];
    while (1) {
        int fd = open(myfifo, O_RDONLY);
        read(fd, str1, sizeof(str1));
        printf("User1: %s\n", str1);
        close(fd);
    }
    return 0;
}