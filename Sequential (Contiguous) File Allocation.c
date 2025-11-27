#include <stdio.h>

int main() {
    int n, blocks[50] = {0};

    printf("Enter total number of blocks: ");
    scanf("%d", &n);

    while (1) {
        int ch, start, len;
        printf("\n1.Allocate File\n2.Display Blocks\n3.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 3) break;

        if (ch == 1) {
            printf("Enter starting block and length: ");
            scanf("%d %d", &start, &len);

            int ok = 1;
            for (int i = start; i < start + len; i++)
                if (i >= n || blocks[i] == 1) ok = 0;

            if (!ok)
                printf("Cannot allocate! Blocks not free.\n");
            else {
                for (int i = start; i < start + len; i++)
                    blocks[i] = 1;
                printf("File allocated successfully.\n");
            }
        }

        else if (ch == 2) {
            printf("Block Status:\n");
            for (int i = 0; i < n; i++)
                printf("%d ", blocks[i]);
            printf("\n(1 = allocated, 0 = free)\n");
        }

        else
            printf("Invalid Choice!\n");
    }

    return 0;
}

// output 

// Enter total number of blocks: 10

// 1.Allocate File
// 2.Display Blocks
// 3.Exit
// Choice: 1
// Enter starting block and length: 2 4
// File allocated successfully.

// Choice: 2
// Block Status:
// 0 0 1 1 1 1 0 0 0 0
// (1 = allocated, 0 = free)

// Choice: 1
// Enter starting block and length: 5 6
// Cannot allocate! Blocks not free.

// Choice: 3
