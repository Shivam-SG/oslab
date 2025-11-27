#include <stdio.h>

int main() {
    int n, r;
    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int finish[10] = {0}, safe[10];

    printf("Enter processes: ");
    scanf("%d", &n);
    printf("Enter resources: ");
    scanf("%d", &r);

    printf("Enter Allocation:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Max:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available:\n");
    for(int j=0;j<r;j++)
        scanf("%d",&avail[j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;
    while(count < n) {
        int found = 0;
        for(int i=0;i<n;i++) {
            if(!finish[i]) {
                int ok = 1;
                for(int j=0;j<r;j++)
                    if(need[i][j] > avail[j]) ok = 0;

                if(ok) {
                    for(int j=0;j<r;j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                    safe[count++] = i;
                    found = 1;
                }
            }
        }
        if(!found) {
            printf("\nUnsafe State! Deadlock Possible!\n");
            return 0;
        }
    }

    printf("\nSafe State!\nSequence: ");
    for(int i=0;i<n;i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return 0;
}


// output 

// Enter processes: 5
// Enter resources: 3
// Enter Allocation:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
// Enter Max:
// 7 5 3
// 3 2 2
// 9 0 2
// 4 2 2
// 5 3 3
// Enter Available:
// 3 3 2

// Safe State!
// Sequence: P1 P3 P4 P0 P2
