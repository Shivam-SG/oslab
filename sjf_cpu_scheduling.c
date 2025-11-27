#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int wt;
    int tat;
};

int main() {
    int n;
    float avwt = 0, avtat = 0;

    printf("Enter total number of processes (max 20): ");
    scanf("%d", &n);

    struct Process p[20];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time for P[%d]: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].bt > p[j].bt) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;
    for(int i = 1; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        avwt += p[i].wt;
        avtat += p[i].tat;
        printf("P[%d]\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    avwt /= n;
    avtat /= n;

    printf("\nAverage Waiting Time: %.2f", avwt);
    printf("\nAverage Turnaround Time: %.2f\n\n", avtat);

    return 0;
}


// output

// Enter total number of processes: 4
// Burst Time:
// P1: 6
// P2: 8
// P3: 7
// P4: 3

// Process Burst Time  Waiting Time  Turnaround Time
// P4      3           0             3
// P1      6           3             9
// P3      7           9             16
// P2      8           16            24

// Average Waiting Time: 7.00
// Average Turnaround Time: 13.00
