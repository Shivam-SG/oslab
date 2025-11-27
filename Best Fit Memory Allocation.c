#include <stdio.h>

int main() {
    int b, p;
    int block[10], process[10], allocation[10];

    printf("Enter number of memory blocks (max 10): ");
    scanf("%d", &b);

    printf("Enter size of each block:\n");
    for (int i = 0; i < b; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("\nEnter number of processes (max 10): ");
    scanf("%d", &p);

    printf("Enter memory required for each process:\n");
    for (int i = 0; i < p; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (int i = 0; i < p; i++) {
        int best_index = -1;

        for (int j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                if (best_index == -1 || block[j] < block[best_index]) {
                    best_index = j;
                }
            }
        }

        if (best_index != -1) {
            allocation[i] = best_index;
            block[best_index] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}


// output 

// Enter number of memory blocks (max 10): 5
// 100 500 200 300 600
// Enter number of processes (max 10): 4
// 212 417 112 426

// Process Size    Block Allocated
// P1     212      B4
// P2     417      B2
// P3     112      B1
// P4     426      B5
