#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    int n, head, size, rq[MAX], total = 0, pos = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &rq[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (rq[i] > rq[j]) {
                int t = rq[i]; rq[i] = rq[j]; rq[j] = t;
            }

    while (pos < n && rq[pos] < head) pos++;

    printf("\nC-SCAN Order: %d", head);

    for (int i = pos; i < n; i++) {
        total += abs(head - rq[i]);
        head = rq[i];
        printf(" -> %d", head);
    }

    total += abs((size - 1) - head);
    printf(" -> %d", size - 1);
    total += (size - 1); 
    head = 0;
    printf(" -> %d", head);

    for (int i = 0; i < pos; i++) {
        total += abs(head - rq[i]);
        head = rq[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d\n", total);
    return 0;
}


// output 

// Enter number of requests: 7
// Enter request sequence:
// 176 79 34 60 92 11 41
// Enter head position: 50
// Enter disk size: 200

// C-SCAN Order: 50 -> 60 -> 79 -> 92 -> 176 -> 199 -> 0 -> 11 -> 34 -> 41

// Total Head Movement = 389
