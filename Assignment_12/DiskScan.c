#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_REQUESTS 100
void scan(int requests[], int n, int initial_head, int max_track) {
    int total_seek_time = 0;
    int current_head = initial_head;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
    total_seek_time += abs(current_head - max_track);
    current_head = max_track;
    printf("Move to right end: %d (Seek Time: %d)\n", max_track, abs(initial_head - max_track));
    for (int i = 0; i < n; i++) {
        if (requests[i] >= initial_head) {
            total_seek_time += abs(current_head - requests[i]);
            current_head = requests[i];
            printf("Move to: %d (Seek Time: %d)\n", current_head, abs(current_head - requests[i]));
        }
    }
    total_seek_time += abs(current_head - 0);
    current_head = 0;
    printf("Move to left end: 0 (Seek Time: %d)\n", abs(current_head));
    for (int i = n - 1; i >= 0; i--) {
        if (requests[i] < initial_head) {
            total_seek_time += abs(current_head - requests[i]);
            current_head = requests[i];
            printf("Move to: %d (Seek Time: %d)\n", current_head, abs(current_head - requests[i]));
        }
    }
    printf("Total Seek Time: %d\n", total_seek_time);
}
int main() {
    int n, initial_head, max_track;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;
    }
    int requests[MAX_REQUESTS];
    printf("Enter initial head position: ");
    scanf("%d", &initial_head);
    printf("Enter maximum track position: ");
    scanf("%d", &max_track);
    printf("Enter track positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        if (requests[i] < 0 || requests[i] > max_track) {
            printf("Invalid request position.\n");
            return 1;
        }
    }
    scan(requests, n, initial_head, max_track);
    return 0;
}