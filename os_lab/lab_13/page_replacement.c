#include <stdio.h>

int main() {
    // 1. Define Data
    int nf, np;
    int hit = 0, fault = 0;
    int i, j, flag;
    int pos = 0;

    // Accept data from user to make the program dynamic
    printf("Enter number of frames (nf): ");
    scanf("%d", &nf);

    printf("Enter number of pages in reference string (np): ");
    scanf("%d", &np);

    int F[nf];
    int p[np];

    printf("Enter the page reference string (space separated): ");
    for (i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }

    // 2. Frames to -1
    for (i = 0; i < nf; i++) {
        F[i] = -1;
    }

    printf("\nPage\t| Frame Status\t\t| Condition\n");

    // 3. Page hit and fault condition
    for (i = 0; i < np; i++) {
        flag = 0;

        for (j = 0; j < nf; j++) {
            if (F[j] == p[i]) {
                hit++;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            F[pos] = p[i];
            pos++;
            fault++;

            if (pos == nf) {
                pos = 0;
            }
        }

        printf("%d\t| ", p[i]);
        for (j = 0; j < nf; j++) {
            if (F[j] == -1) {
                printf("-1 ");
            } else {
                printf("%d ", F[j]);
            }
        }

        if (flag == 1) {
            printf("\t\t| H\n");
        } else {
            printf("\t\t| F\n");
        }
    }

    // 4. Ratios
    float hit_ratio = (float)hit / np;
    float miss_ratio = (float)fault / np;

    printf("-------------------------------------------------\n");
    printf("Total Hits: %d\n", hit);
    printf("Total Faults: %d\n", fault);
    printf("Hit Ratio: %.2f\n", hit_ratio);
    printf("Miss Ratio: %.2f\n", miss_ratio);

    return 0;
}