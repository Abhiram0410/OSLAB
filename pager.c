#include <stdio.h>
int n, nf, in[100], p[50], pgfaultcnt = 0;
void getData() {
    printf("\nEnter length of page reference sequence: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    printf("Enter number of frames: ");
    scanf("%d", &nf);
}
void initialize() {
    pgfaultcnt = 0;
    for (int i = 0; i < nf; i++) p[i] = 9999;
}
int isHit(int data) {
    for (int j = 0; j < nf; j++)
        if (p[j] == data) return 1;
    return 0;
}
void dispPages() {
    for (int k = 0; k < nf; k++)
        if (p[k] != 9999) printf(" %d", p[k]);
}
void optimal() {
    initialize();
    for (int i = 0; i < n; i++) {
        printf("\nFor %d :", in[i]);
        if (!isHit(in[i])) {
            int repindex = -1, max = -1;
            for (int j = 0; j < nf; j++) {
                int k;
                for (k = i; k < n; k++)
                    if (p[j] == in[k]) break;
                if (k > max) max = k, repindex = j;
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            dispPages();
        } else {
            printf(" No page fault");
        }
    }
    printf("\nTotal page faults: %d", pgfaultcnt);
}
int main() {
    int choice;
    while (1) {
        printf("\n1.Enter data\n2.Optimal\n3.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) getData();
        else if (choice == 2) optimal();
        else break;
    }
    return 0;
}