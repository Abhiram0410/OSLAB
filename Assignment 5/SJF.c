#include <stdio.h>
int main() {
    int n, i, j, time = 0, completed = 0, min_index;
    int arrival_time[100], burst_time[100], remaining_time[100];
    int waiting_time[100], turnaround_time[100];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i]; // Initialize remaining burst time for each process
    }
    int completed_processes = 0;
    int min_remaining_time;
    int process_in_execution = -1;
    while (completed_processes < n) {
        min_remaining_time = __INT_MAX__;
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0 && remaining_time[i] < min_remaining_time) {
                min_remaining_time = remaining_time[i];
                process_in_execution = i;
            }
        }
        if (process_in_execution == -1) {
            time++;
            continue;
        }
        remaining_time[process_in_execution]--;
        time++; 
        if (remaining_time[process_in_execution] == 0) {
            completed_processes++;
            turnaround_time[process_in_execution] = time - arrival_time[process_in_execution];
            waiting_time[process_in_execution] = turnaround_time[process_in_execution] - burst_time[process_in_execution];
            avg_wt += waiting_time[process_in_execution];
            avg_tat += turnaround_time[process_in_execution];
        }
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("P\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);
    return 0;
}