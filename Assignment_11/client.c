#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
struct Data {
    char str[100];
    int flag; // 0: ready to write, 1: data available, 2: client reading
};
int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(struct Data), 0666 | IPC_CREAT);
    struct Data* data = (struct Data*)shmat(shmid, (void*)0, 0);
    while (1) {
        while (data->flag != 1) {
            printf("Client waiting...\n");
            sleep(1); // Wait for the server to write
        }
        data->flag = 2; // Indicate that client is reading
        printf("Client: Data read from memory: %s\n", data->str);
        data->flag = 0; // Reset the flag to allow the server to write again
        if (strcmp(data->str, "exit") == 0) break;
    }
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
