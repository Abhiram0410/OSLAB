#include <stdio.h>
void findTimes(int n, int at[], int bt[], int quantum) {
    int wt[n], tat[n], rem_bt[n], t = 0, total_wt = 0, total_tat = 0;
    int completed = 0;  // To track completed processes
    for (int i = 0; i < n; i++) 
        rem_bt[i] = bt[i];  // Initialize remaining burst times
    while (completed < n) {  // Loop until all processes are done
        int executed = 0;  // Track if any process was executed in this cycle
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {  // Process is ready to run
                int slice = rem_bt[i];
                if (slice > quantum) {
                    slice = quantum;
                }
                t += slice;  // Advance time
                rem_bt[i] -= slice;  // Decrease remaining burst time
                executed = 1;
                if (rem_bt[i] == 0) {  // Process has finished
                    completed++;
                    wt[i] = t - bt[i] - at[i];  // Calculate waiting time
                }
            }
        }
        if (!executed)  // If no process was executed, advance time
            t++;
    }
    printf("PN\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Calculate turnaround time
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("Avg WT = %.2f\n", (float)total_wt / n);
    printf("Avg TAT = %.2f\n", (float)total_tat / n);
}
int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    findTimes(n, at, bt, quantum);
    return 0;
}