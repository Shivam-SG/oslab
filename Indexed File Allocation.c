#include <stdio.h>

int main() {
    int n, blocks[50] = {0}, index, count, b;

    printf("Enter total number of blocks: ");
    scanf("%d", &n);

    while (1) {
        int ch;
        printf("\n1.Allocate File (Indexed)\n2.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 2) break;

        printf("Enter index block: ");
        scanf("%d", &index);

        if (blocks[index] == 1) {
            printf("Index block already allocated!\n");
            continue;
        }

        printf("Enter number of blocks needed: ");
        scanf("%d", &count);

        blocks[index] = 1;
        printf("Enter %d block numbers: ", count);

        int ok = 1;
        int temp[20];

        for (int i = 0; i < count; i++) {
            scanf("%d", &temp[i]);
            if (temp[i] >= n || blocks[temp[i]] == 1)
                ok = 0;
        }

        if (!ok) {
            printf("Allocation failed!\n");
            blocks[index] = 0;
        } 
        else {
            for (int i = 0; i < count; i++)
                blocks[temp[i]] = 1;

            printf("File allocated.\nIndex Block -> %d\nBlocks: ", index);
            for (int i = 0; i < count; i++)
                printf("%d ", temp[i]);
            printf("\n");
        }
    }
    return 0;
}


// output 

// Enter total number of blocks: 10

// 1.Allocate File (Indexed)
// 2.Exit
// Choice: 1
// Enter index block: 3
// Enter number of blocks needed: 3
// Enter block numbers: 5 6 7
// File allocated successfully!
// Index Block: 3
// Linked Blocks: 5 6 7 

// Choice: 1
// Enter index block: 3
// Index block already allocated!

// Choice: 2
