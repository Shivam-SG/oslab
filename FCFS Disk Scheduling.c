#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    int n, head, req[MAX], total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of Movement: %d", head);

    for (int i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", total);
    return 0;
}


// output 

// Enter number of disk requests: 5
// Enter disk request sequence:
// 82 170 43 140 24
// Enter initial head position: 50

// Order of Movement: 50 -> 82 -> 170 -> 43 -> 140 -> 24

// Total Head Movement = 407 cylinders
