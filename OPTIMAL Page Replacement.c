#include <stdio.h>
#define MAX 50

int main() {
    int frames, pages, page[MAX], frame[MAX], faults = 0;

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
            if (frame[j] == page[i])
                flag = 1;

        if (!flag) {
            int pos = -1;

            for (int j = 0; j < frames; j++)
                if (frame[j] == -1) pos = j;

            if (pos == -1) {
                int far = -1, idx = 0;
                for (int j = 0; j < frames; j++) {
                    int next = 9999;
                    for (int k = i + 1; k < pages; k++)
                        if (frame[j] == page[k]) { next = k; break; }

                    if (next > far) { far = next; idx = j; }
                }
                pos = idx;
            }
            frame[pos] = page[i];
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
// Pages: 10
// Reference string:
// 7 0 1 2 0 3 0 4 2 3

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
// 3       2 4 3

// Total Page Faults = 6
