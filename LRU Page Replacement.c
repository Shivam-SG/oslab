#include <stdio.h>
#define MAX 50

int main() {
    int frames, pages;
    int page[MAX], frame[MAX], used[MAX];
    int faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < pages; i++) {
        int flag = 0;

        for (int j = 0; j < frames; j++)
            if (frame[j] == page[i]) {
                flag = 1;
                used[j] = i;
            }

        if (!flag) {
            int pos = 0;

            for (int j = 0; j < frames; j++)
                if (frame[j] == -1) { pos = j; break; }

            if (frame[pos] != -1) {
                int min = used[0];
                for (int j = 1; j < frames; j++)
                    if (used[j] < min) {
                        min = used[j];
                        pos = j;
                    }
            }

            frame[pos] = page[i];
            used[pos] = i;
            faults++;
        }

        printf("%d\t", page[i]);
        for (int j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}


// output 

// Frames: 3
// Pages: 9
// Reference: 7 0 1 2 0 3 0 4 2

// Page    Frames
// 7       7 -1 -1
// 0       7 0 -1
// 1       7 0 1
// 2       2 0 1
// 0       2 0 1
// 3       2 0 3
// 0       2 0 3
// 4       2 4 3
// 2       2 4 3

// Total Page Faults = 7
