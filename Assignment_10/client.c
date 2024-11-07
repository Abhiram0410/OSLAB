#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    const char *myfifo = "/tmp/myfifo";
    char str2[80];
    while (1) {
        int fd = open(myfifo, O_WRONLY);
        fgets(str2, sizeof(str2), stdin);
        write(fd, str2, strlen(str2) + 1);
        close(fd);
    }
    return 0;
}