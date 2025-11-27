#include <stdio.h>
#define MAX 50

int main() {
    int frames, pages;
    int page[MAX], frame[MAX];
    int i, j, k = 0, flag, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < pages; i++) {
        flag = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            frame[k] = page[i];
            k = (k + 1) % frames;
            faults++;
        }

        printf("%d\t", page[i]);
        for (j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}


// output 

// Frames: 3
// Pages: 7
// Reference String: 1 3 0 3 5 6 3

// Page    Frames
// 1       1 -1 -1
// 3       1 3 -1
// 0       1 3 0
// 3       1 3 0
// 5       5 3 0
// 6       5 6 0
// 3       5 6 3

// Total Page Faults = 6
