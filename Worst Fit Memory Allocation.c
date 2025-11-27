#include <stdio.h>

int main() {
    int b, p;
    int block[20], process[20];
    int allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &b);

    printf("Enter size of each block:\n");
    for (int i = 0; i < b; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &p);

    printf("Enter memory required for each process:\n");
    for (int i = 0; i < p; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (int i = 0; i < p; i++) {
        int max_index = -1;

        for (int j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                if (max_index == -1 || block[j] > block[max_index]) {
                    max_index = j;
                }
            }
        }

        if (max_index != -1) {
            allocation[i] = max_index;
            block[max_index] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

// output

// Enter number of memory blocks: 5
// Enter size of each block:
// Block 1: 100
// Block 2: 500
// Block 3: 200
// Block 4: 300
// Block 5: 600

// Enter number of processes: 4
// Enter memory required for each process:
// Process 1: 212
// Process 2: 417
// Process 3: 112
// Process 4: 426

// Process Size  Block Allocated
// 1       212   5
// 2       417   2
// 3       112   4
// 4       426   Not Allocated
