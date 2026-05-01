#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1) Define Data
    int n, initial;
    int total_head_movement = 0;
    int i;
    int seektime = 0; 

    printf("Enter the number of requests in the queue (n): ");
    scanf("%d", &n);

    int RQ[n];
    printf("Enter the Request Queue (track numbers):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    printf("\nMovement Trace:\n");
    for(i = 0; i < n; i++) {
        int movement = abs(RQ[i] - initial);
        total_head_movement += movement;
        
        printf("Head moved from %d to %d (Movement: %d)\n", initial, RQ[i], movement);
        
        initial = RQ[i];
    }

    seektime = total_head_movement;
    
    printf("\nTotal Head Movement: %d", total_head_movement);
    printf("\nTotal Seek Time    : %d", seektime);

    return 0;
}