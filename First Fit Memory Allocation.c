#include <stdio.h>

int main() {
    int b, p;
    int block[20], process[20], allocation[20];
    int i, j;

    printf("Enter number of memory blocks (max 20): ");
    scanf("%d", &b);

    printf("Enter size of each block:\n");
    for (i = 0; i < b; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("\nEnter number of processes (max 20): ");
    scanf("%d", &p);

    printf("Enter memory required for each process:\n");
    for (i = 0; i < p; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (i = 0; i < p; i++) {
        for (j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                allocation[i] = j;    
                block[j] -= process[i]; 
                break;           
            }
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for (i = 0; i < p; i++) {
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
// Block 1: 100
// Block 2: 500
// Block 3: 200
// Block 4: 300
// Block 5: 600

// Enter number of processes: 4
// Process 1: 212
// Process 2: 417
// Process 3: 112
// Process 4: 426

// Process Size    Block Allocated
// 1        212    2
// 2        417    5
// 3        112    3
// 4        426    Not Allocated
