#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, initial, total_head_movement = 0;
    int i, j, count = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int RQ[n], visited[n]; 
    printf("Enter the Request Queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
        visited[i] = 0;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    printf("\nMovement Trace:\n");

    while(count < n) {
        int min_distance = INT_MAX;
        int index = -1;

        for(i = 0; i < n; i++) {
            if(visited[i] == 0) {
                int distance = abs(RQ[i] - initial);
                if(distance < min_distance) {
                    min_distance = distance;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        total_head_movement += min_distance;
        
        printf("Head moved from %d to %d (Movement: %d)\n", initial, RQ[index], min_distance);

        initial = RQ[index];
        count++;
    }

    printf("\nTotal Head Movement: %d\n", total_head_movement);

    return 0;
}