#include <stdio.h>
#include <string.h>

struct Directory {
    char dname[20];
    char fname[20][20];
    int fcount;
};

int main() {
    struct Directory dir;
    int ch;

    dir.fcount = 0;
    printf("Enter directory name: ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n1.Create File\n2.Delete File\n3.Search File\n4.Display\n5.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 5) break;

        char name[20], found = 0;
        printf("Enter file name: ");
        scanf("%s", name);

        if (ch == 1) { 
            for (int i = 0; i < dir.fcount; i++)
                if (!strcmp(name, dir.fname[i])) found = 1;
            if (found) printf("File already exists!\n");
            else {
                strcpy(dir.fname[dir.fcount++], name);
                printf("File created.\n");
            }
        }
        else if (ch == 2) { 
            for (int i = 0; i < dir.fcount; i++)
                if (!strcmp(name, dir.fname[i])) {
                    found = 1;
                    for (int j = i; j < dir.fcount - 1; j++)
                        strcpy(dir.fname[j], dir.fname[j+1]);
                    dir.fcount--;
                    printf("File deleted.\n");
                    break;
                }
            if (!found) printf("File not found!\n");
        }
        else if (ch == 3) { 
            for (int i = 0; i < dir.fcount; i++)
                if (!strcmp(name, dir.fname[i])) found = 1;
            if (found) printf("File found.\n");
            else printf("File not found!\n");
        }
        else if (ch == 4) {  
            printf("\nDirectory: %s\nFiles:\n", dir.dname);
            if (dir.fcount == 0) printf("No Files.\n");
            else for (int i = 0; i < dir.fcount; i++)
                printf("%s\n", dir.fname[i]);
        }
        else
            printf("Invalid Choice!\n");
    }
    return 0;
}


// output 

// Enter directory name: mydir

// 1.Create File
// 2.Delete File
// 3.Search File
// 4.Display
// 5.Exit
// Choice: 1
// Enter file name: a.txt
// File created.

// Choice: 1
// Enter file name: b.txt
// File created.

// Choice: 4
// Enter file name: ignored
// Directory: mydir
// Files:
// a.txt
// b.txt

// Choice: 3
// Enter file name: a.txt
// File found.

// Choice: 2
// Enter file name: b.txt
// File deleted.

// Choice: 4
// Enter file name: ignored
// Directory: mydir
// Files:
// a.txt

// Choice: 5
