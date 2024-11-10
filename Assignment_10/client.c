#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";
    char buffer1[100];
    int d1, d2, i = 0, cc = 0, ln = 0, wc = 0;
    d1 = open(fifo1, O_RDONLY);
    read(d1, buffer1, sizeof(buffer1));
    while (buffer1[i] != '#' && buffer1[i] != '\0') {
    // Check for line breaks and word boundaries accurately
    if (buffer1[i] == ' ' || buffer1[i] == '\n') {
        if (buffer1[i] == '\n') {
            ln++;      // Count lines on each newline
        }
        if (i > 0 && buffer1[i-1] != ' ' && buffer1[i-1] != '\n') {
            wc++;      // Count words when a space or newline follows a non-space character
        }
    } else {
        cc++;          // Count characters excluding spaces and newlines
        }
    i++;
    }

    // Final check for the last word if input doesn’t end with a space or newline
    if (i > 0 && buffer1[i-1] != ' ' && buffer1[i-1] != '\n') {
        wc++;
    }

    FILE *fp = fopen("Rajnandini.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(fp, "\nLine count = %d", ln);
    fprintf(fp, "\nWord count = %d", wc);
    fprintf(fp, "\nCharacter count = %d", cc);
    fclose(fp);
    mkfifo(fifo2, 0666);
    d2 = open(fifo2, O_WRONLY);
    write(d2, "Rajnandini.txt", 14);
    close(d2);
    return 0;
}
