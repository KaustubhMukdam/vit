#include <stdio.h>

int main() {
    // 1. Define Data
    int np, nr;
    
    printf("Enter the number of processes (np): ");
    scanf("%d", &np);
    
    printf("Enter the number of resources (nr): ");
    scanf("%d", &nr);
    
    int allocation[np][nr], max[np][nr], need[np][nr];
    int available[nr], safeseq[np];
    int finish[np];
    int i, j, k = 0, flag;

    for(i = 0; i < np; i++) {
        finish[i] = 0;
    }
    
    // 2. Accept data from user
    printf("\nEnter the Allocation Matrix:\n");
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    
    printf("\nEnter the Max Matrix:\n");
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("\nEnter the Available Resources:\n");
    for(j = 0; j < nr; j++) {
        scanf("%d", &available[j]);
    }
    
    // 3. Need Matrix Calculation: need[i][j] = max[i][j] - allocation[i][j]
    printf("\nCalculating Need Matrix...\n");
    for(i = 0; i < np; i++) {
        for(j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    // 4. Check Deadlock / Find Safe Sequence
    for(i = 0; i < np; i++) {
        flag = 0;
        
        if(finish[i] == 0) {
            for(j = 0; j < nr; j++) {
                if(need[i][j] > available[j]) {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0) {
                finish[i] = 1;
                safeseq[k] = i;
                k++;
                
                for(j = 0; j < nr; j++) {
                    available[j] += allocation[i][j];
                }
                
                i = -1; 
            }
        }
    }
    
    // 5. Check status of deadlock
    int isSafe = 1;
    for(i = 0; i < np; i++) {
        if(finish[i] == 0) {
            isSafe = 0;
            break;
        }
    }
    
    if(isSafe == 1) {
        printf("\nSystem is in a SAFE STATE.\nSafe Sequence is: ");
        for(i = 0; i < np; i++) {
            printf("P%d ", safeseq[i]);
            if(i != np - 1) printf("-> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is in a DEADLOCK STATE. Safe sequence not possible.\n");
    }
    
    return 0;
}