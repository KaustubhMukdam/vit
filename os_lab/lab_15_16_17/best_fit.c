#include <stdio.h>

int main() {
    int nb, np;
    
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter number of processes: ");
    scanf("%d", &np);
    
    int p[np], b[nb], bn[np], bf[nb], frag[np];
    
    printf("Enter sizes of blocks:\n");
    for(int i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
        bf[i] = 0; 
    }
    
    printf("Enter sizes of processes:\n");
    for(int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
        bn[i] = -1; 
        frag[i] = 0;
    }

    for(int i = 0; i < np; i++) {
        int smallest = 1000;
        
        for(int j = 0; j < nb; j++) {
            if(bf[j] == 0 && b[j] >= p[i]) {
                if(b[j] < smallest) {
                    smallest = b[j];
                    bn[i] = j;
                }
            }
        }
        
        if(bn[i] != -1) {
            bf[bn[i]] = 1;
            frag[i] = smallest - p[i];
        }
    }
    
    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragment\n");
    for(int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i, p[i]);
        if(bn[i] != -1) {
            // We use bn[i] to find the original block size from array b
            printf("B%d\t\t%d\t\t%d\n", bn[i], b[bn[i]], frag[i]);
        } else {
            printf("Not Allocated\t--\t\t--\n");
        }
    }
    return 0;
}