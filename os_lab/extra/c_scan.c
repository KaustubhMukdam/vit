#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    int n, initial, disk_size, total_head_movement = 0;
    int i, index;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int RQ[n + 2]; 
    printf("Enter the Request Queue:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    printf("Enter the total disk size: ");
    scanf("%d", &disk_size);

    RQ[n] = 0;
    RQ[n + 1] = disk_size - 1;
    n = n + 2;
    sort(RQ, n);

    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    printf("\nMovement Trace:\n");

    for (i = index; i < n; i++) {
        total_head_movement += abs(RQ[i] - initial);
        printf("Head moved from %d to %d (Movement: %d)\n", initial, RQ[i], abs(RQ[i] - initial));
        initial = RQ[i];
    }

    total_head_movement += abs(disk_size - 1 - 0);
    printf("Head JUMPS from %d to 0 (Movement: %d)\n", disk_size - 1, disk_size - 1);
    initial = 0;

    for (i = 0; i < index; i++) {
        total_head_movement += abs(RQ[i] - initial);
        printf("Head moved from %d to %d (Movement: %d)\n", initial, RQ[i], abs(RQ[i] - initial));
        initial = RQ[i];
    }

    // 6. Display Result
    printf("\nTotal Head Movement: %d\n", total_head_movement);

    return 0;
}