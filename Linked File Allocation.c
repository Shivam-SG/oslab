#include <stdio.h>

int main() {
    int n, blocks[50] = {0};
    int start, next, len;

    printf("Enter total number of blocks: ");
    scanf("%d", &n);

    while (1) {
        int ch;
        printf("\n1.Allocate File (Linked)\n2.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 2) break;

        printf("Enter starting block: ");
        scanf("%d", &start);

        if (blocks[start] == 1) {
            printf("Starting block already allocated!\n");
            continue;
        }

        printf("Enter number of blocks needed: ");
        scanf("%d", &len);

        int ok = 1, temp[20];

        printf("Enter next %d linked blocks: ", len);
        for (int i = 0; i < len; i++) {
            scanf("%d", &temp[i]);
            if (temp[i] >= n || blocks[temp[i]] == 1)
                ok = 0;
        }

        if (!ok) {
            printf("Allocation failed!\n");
        } else {
            blocks[start] = 1;
            for (int i = 0; i < len; i++)
                blocks[temp[i]] = 1;

            printf("File allocated through linked blocks:\n");
            printf("%d -> ", start);
            for (int i = 0; i < len; i++)
                printf("%d ", temp[i]);
            printf("\n");
        }
    }
    return 0;
}


// output 

// Enter total number of blocks: 10

// 1.Allocate File (Linked)
// 2.Exit
// Choice: 1
// Enter starting block: 2
// Enter number of blocks needed: 3
// Enter next 3 linked blocks: 5 6 7
// File allocated as linked blocks:
// 2 -> 5 6 7 

// Choice: 1
// Enter starting block: 5
// Starting block already allocated!

// Choice: 2
