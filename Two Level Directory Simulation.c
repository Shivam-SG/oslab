#include <stdio.h>
#include <string.h>

#define MAX 10

struct User {
    char dname[20];
    char files[10][20];
    int fcount;
};

int main() {
    int n, ch;
    struct User u[MAX];

    printf("Enter number of users: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter directory name for user %d: ", i + 1);
        scanf("%s", u[i].dname);
        u[i].fcount = 0;
    }

    while (1) {
        printf("\n1.Create File\n2.Search File\n3.Display Files\n4.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 4) break;

        char d[20], f[20];
        int found = -1;

        printf("Enter directory name: ");
        scanf("%s", d);

        for (int i = 0; i < n; i++)
            if (strcmp(d, u[i].dname) == 0) found = i;

        if (found == -1) {
            printf("Directory not found!\n");
            continue;
        }

        if (ch == 1) {
            printf("Enter file name: ");
            scanf("%s", f);
            strcpy(u[found].files[u[found].fcount++], f);
            printf("File created.\n");
        }
        else if (ch == 2) {
            printf("Enter file name: ");
            scanf("%s", f);
            int ok = 0;
            for (int i = 0; i < u[found].fcount; i++)
                if (strcmp(f, u[found].files[i]) == 0) ok = 1;
            if (ok) printf("File found.\n");
            else printf("File not found!\n");
        }
        else if (ch == 3) {
            printf("Files in %s:\n", u[found].dname);
            for (int i = 0; i < u[found].fcount; i++)
                printf("%s\n", u[found].files[i]);
        }
    }
    return 0;
}


// output 

// Enter number of users: 2
// Enter directory name for user 1: user1
// Enter directory name for user 2: user2

// 1.Create File
// 2.Search File
// 3.Display Files
// 4.Exit
// Choice: 1
// Enter directory name: user1
// Enter file name: a.txt
// File created.

// Choice: 1
// Enter directory name: user2
// Enter file name: b.txt
// File created.

// Choice: 3
// Enter directory name: user1
// Files in user1:
// a.txt

// Choice: 2
// Enter directory name: user2
// Enter file name: c.txt
// File not found!

// Choice: 4
