#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20];
    int i, j;
    float avwt = 0, avtat = 0;

    printf("Enter total number of processes (max 20): ");
    scanf("%d", &n);

    printf("\nEnter burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    avwt /= n;
    avtat /= n;

    printf("\nAverage Waiting Time: %.2f", avwt);
    printf("\nAverage Turnaround Time: %.2f\n", avtat);

    return 0;
}

// output 

// Enter total number of processes (max 20): 4
// Enter burst time of each process:
// P[1]: 5
// P[2]: 3
// P[3]: 8
// P[4]: 6


// Process Burst Time      Waiting Time   Turnaround Time
// P[1]        5               0               5
// P[2]        3               5               8
// P[3]        8               8               16
// P[4]        6               16              22

// Average Waiting Time: 7.25
// Average Turnaround Time: 12.75
