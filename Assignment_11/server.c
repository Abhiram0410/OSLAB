#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
struct data { char str[100]; int flag; };
int main() {
    key_t key = ftok("abc.txt", 'A');
    int shmid = shmget(key, sizeof(struct data), 0777 | IPC_CREAT);
    struct data *d = (struct data *)shmat(shmid, NULL, 0);
    printf("Enter data: ");
    fgets(d->str, sizeof(d->str), stdin);
    d->flag = 1;
    while (d->flag != -1) { sleep(2); }
    shmdt(d); shmctl(shmid, IPC_RMID, NULL);
    return 0;
}