#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    int n, rq[MAX], head, size, dir;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &rq[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Direction (1=right, 0=left): ");
    scanf("%d", &dir);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (rq[i] > rq[j]) {
                int t = rq[i]; rq[i] = rq[j]; rq[j] = t;
            }

    int total = 0, pos = 0;
    while (pos < n && rq[pos] < head) pos++;

    printf("\nSCAN Order: %d", head);

    if (dir == 1) { 
        for (int i = pos; i < n; i++)
            total += abs(head - (head = rq[i])), printf(" -> %d", head);

        total += abs((size - 1) - head);
        head = size - 1;
        printf(" -> %d", head);

        for (int i = pos - 1; i >= 0; i--)
            total += abs(head - (head = rq[i])), printf(" -> %d", head);
    } 
    else { 
        for (int i = pos - 1; i >= 0; i--)
            total += abs(head - (head = rq[i])), printf(" -> %d", head);

        total += abs(head - 0);
        head = 0;
        printf(" -> %d", head);

        for (int i = pos; i < n; i++)
            total += abs(head - (head = rq[i])), printf(" -> %d", head);
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
// Direction (1=right, 0=left): 1

// SCAN Order: 50 -> 60 -> 79 -> 92 -> 176 -> 199 -> 41 -> 34 -> 11

// Total Head Movement = 387
