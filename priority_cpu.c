#include <stdio.h>

struct Process {
    int pid;
    int burst;
    int priority;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[50];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].burst);

        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &p[i].priority);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting = 0;
    p[0].turnaround = p[0].burst;

    for (int i = 1; i < n; i++) {
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    printf("\n\nPriority Scheduling Result:\n");
    printf("PID\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid, p[i].burst, p[i].priority,
               p[i].waiting, p[i].turnaround);
    }

    return 0;
}

// output

// Enter number of processes: 4

// Enter burst time for P1: 5
// Enter priority for P1: 2

// Enter burst time for P2: 3
// Enter priority for P2: 1

// Enter burst time for P3: 8
// Enter priority for P3: 4

// Enter burst time for P4: 6
// Enter priority for P4: 3


// Priority Scheduling Result:
// PID     Burst   Priority        Waiting Turnaround
// 2       3       1               0       3
// 1       5       2               3       8
// 4       6       3               8       14
// 3       8       4               14      22
