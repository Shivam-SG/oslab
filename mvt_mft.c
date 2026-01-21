#include <stdio.h>

void MVT() {
    int ms, n, i;
    int mp[10];
    int used = 0;

    printf("\n----- MVT (Memory Variable Partition) -----\n");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    printf("Enter Total Memory Size: ");
    scanf("%d", &ms);

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Memory Required for Each Process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nProcess Allocation:\n");
    for (i = 0; i < n; i++) {
        if (used + mp[i] <= ms) {
            printf("Process %d Allocated (%d KB)\n", i + 1, mp[i]);
            used = used + mp[i];
        } else {
            printf("Process %d Not Allocated (Insufficient Memory)\n", i + 1);
        }
    }

    printf("\nTotal Memory Used = %d KB\n", used);
    printf("Total Free Memory (External Fragmentation) = %d KB\n", ms - used);
}

void MFT() {
    int ms, ps, np, i;
    int pro[10];
    int internal = 0;
    int usedPartitions = 0;

    printf("\n----- MFT (Memory Fixed Partition) -----\n");
    printf("Enter Total Memory Size: ");
    scanf("%d", &ms);

    printf("Enter Partition Size: ");
    scanf("%d", &ps);

    int partitions = ms / ps;
    printf("Total Number of Partitions = %d\n", partitions);

    printf("Enter Number of Processes: ");
    scanf("%d", &np);

    printf("Enter Memory Required for Each Process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &pro[i]);
    }

    printf("\nProcess Allocation:\n");
    for (i = 0; i < partitions && i < np; i++) {
        if (pro[i] <= ps) {
            printf("Process %d Allocated (%d KB) → Internal Waste = %d KB\n",
                   i + 1, pro[i], ps - pro[i]);
            internal = internal + (ps - pro[i]);
        } else {
            printf("Process %d Not Allocated (Too Large)\n", i + 1);
        }
        usedPartitions++;
    }

    printf("\nTotal Internal Fragmentation = %d KB\n", internal);
    printf("Total External Fragmentation = %d KB\n", ms - (usedPartitions * ps));
}

int main() {
    int ch;

    while (1) {
        printf("\n====== MEMORY MANAGEMENT ======\n");
        printf("1. MVT (Variable Partitioning)\n");
        printf("2. MFT (Fixed Partitioning)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            MVT();
        else if (ch == 2)
            MFT();
        else if (ch == 3)
            return 0;
        else
            printf("Invalid Input! Try Again.\n");
    }
}


// output

// ====== MEMORY MANAGEMENT ======
// 1. MVT (Variable Partitioning)
// 2. MFT (Fixed Partitioning)
// 3. Exit
// Enter your choice: 1

// ----- MVT (Memory Variable Partition) -----
// Enter Total Memory Size: 500
// Enter Number of Processes: 4
// Enter Memory Required for Each Process:
// Process 1: 100
// Process 2: 250
// Process 3: 200
// Process 4: 100

// Process Allocation:
// Process 1 Allocated (100 KB)
// Process 2 Allocated (250 KB)
// Process 3 Not Allocated (Insufficient Memory)
// Process 4 Allocated (100 KB)

// Total Memory Used = 450 KB
// Total Free Memory (External Fragmentation) = 50 KB


// ====== MEMORY MANAGEMENT ======
// 1. MVT (Variable Partitioning)
// 2. MFT (Fixed Partitioning)
// 3. Exit
// Enter your choice: 2

// ----- MFT (Memory Fixed Partition) -----
// Enter Total Memory Size: 500
// Enter Partition Size: 100
// Total Number of Partitions = 5
// Enter Number of Processes: 4
// Enter Memory Required for Each Process:
// Process 1: 95
// Process 2: 50
// Process 3: 120
// Process 4: 30

// Process Allocation:
// Process 1 Allocated (95 KB) → Internal Waste = 5 KB
// Process 2 Allocated (50 KB) → Internal Waste = 50 KB
// Process 3 Not Allocated (Too Large)
// Process 4 Allocated (30 KB) → Internal Waste = 70 KB

// Total Internal Fragmentation = 125 KB
// Total External Fragmentation = 200 KB
