#include <stdio.h>

int main() {
    int n, r;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int req[10], finish[10] = {0}, safe[10];

    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter Max Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(int j=0;j<r;j++)
        scanf("%d",&avail[j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int p;
    printf("\nEnter process requesting resources: ");
    scanf("%d",&p);

    printf("Enter request for each resource:\n");
    for(int j=0;j<r;j++)
        scanf("%d",&req[j]);

    for(int j=0;j<r;j++)
        if(req[j] > need[p][j] || req[j] > avail[j]) {
            printf("\nRequest CANNOT be granted!\n");
            return 0;
        }

    for(int j=0;j<r;j++) {
        avail[j] -= req[j];
        alloc[p][j] += req[j];
        need[p][j] -= req[j];
    }

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
            printf("\nUnsafe State! Request Denied.\n");
            return 0;
        }
    }

    printf("\nRequest Granted!\nSafe Sequence: ");
    for(int i=0;i<n;i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return 0;
}


// output 

// Enter number of processes: 5
// Enter number of resources: 3

// Enter Allocation Matrix:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// Enter Max Matrix:
// 7 5 3
// 3 2 2
// 9 0 2
// 4 2 2
// 5 3 3

// Enter Available Resources:
// 3 3 2

// Enter process requesting resources: 1
// Enter request for each resource:
// 1 0 2


// Request Granted!
// Safe Sequence: P1 P3 P4 P0 P2
