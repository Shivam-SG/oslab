#include <stdio.h>

int main() {
    int n, tq;
    int at[10], bt[10], rt[10];
    int t = 0, remain, flag = 0;
    int wt = 0, tat = 0;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    remain = n;

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\t| Turnaround Time | Waiting Time\n");

    int i = 0;
    while (remain != 0) {

        if (rt[i] > 0 && at[i] <= t) {
            if (rt[i] <= tq) {
                t += rt[i];
                rt[i] = 0;
                flag = 1;
            } else {
                rt[i] -= tq;
                t += tq;
            }

            if (rt[i] == 0 && flag == 1) {
                remain--;
                int turnaround = t - at[i];
                int waiting = turnaround - bt[i];

                printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, turnaround, waiting);

                wt += waiting;
                tat += turnaround;

                flag = 0;
            }
        }

        int next = (i + 1) % n;

        while (at[next] > t && next != i)
            next = (next + 1) % n;

        i = next;
    }

    printf("\nAverage Waiting Time = %.2f", wt * 1.0 / n);
    printf("\nAverage Turnaround Time = %.2f\n", tat * 1.0 / n);

    return 0;
}


// output

// Enter Total Number of Processes: 3
// Enter Arrival Time and Burst Time for Process 1: 0 5
// Enter Arrival Time and Burst Time for Process 2: 1 3
// Enter Arrival Time and Burst Time for Process 3: 2 8
// Enter Time Quantum: 2


// Process | Turnaround Time | Waiting Time
// P[1]    |       10        |      5
// P[2]    |       6         |      3
// P[3]    |       17        |      9

// Average Waiting Time = 5.67
// Average Turnaround Time = 11.00
