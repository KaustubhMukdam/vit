#include <stdio.h>
#include <stdbool.h>

// 1. Declare Structure [cite: 82]
struct Process {
    int pid;  // [cite: 84]
    int at;   // [cite: 85]
    int bt;   // [cite: 86]
    int tat;  // [cite: 87]
    int wt;   // [cite: 88]
    int rbt;  // Added: Required to store the original burst time for WT calculation
};

int main() {
    int n, tq;
    
    // 2. Declare variables [cite: 89]
    int y = 0; // count of no of process completed on CPU 
    int x = 0; // current execution time of processes on CPU [cite: 93]
    int i = 0; // index variables to keep track of process 

    // 3. Accept n, tq, pid, at, bt [cite: 95]
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    struct Process p[n];

    for(int j = 0; j < n; j++) {
        printf("Enter AT and BT for Process %d: ", j + 1);
        scanf("%d %d", &p[j].at, &p[j].bt);
        p[j].pid = j + 1;
        
        // 4. Copy p[i].bt = p[i].rbt [cite: 97]
        // The PDF implies 'rbt' is the backup of the original burst time.
        p[j].rbt = p[j].bt; 
    }

    // 5. while(true) [cite: 101]
    while(true) {
        
        // check if p[i].bt > 0 [cite: 102]
        if (p[i].bt > 0) {
            
            // check if p[i].bt > tq [cite: 104]
            if (p[i].bt > tq) {
                x = x + tq;             // [cite: 105]
                p[i].bt = p[i].bt - tq; // [cite: 106]
            } 
            else {                      // [cite: 107]
                x = x + p[i].bt;        // [cite: 108]
                p[i].bt = 0;            // [cite: 109]
                
                // Calculate TAT. Corrected from the PDF's p[i].tat = x 
                p[i].tat = x - p[i].at; 
                
                // p[i].wt = p[i].tat - p[i].rbt 
                p[i].wt = p[i].tat - p[i].rbt; 
                
                // add 1 into y [cite: 114]
                y++;                    
            }
        }

        // compare y with n [cite: 114]
        if (y == n) {                   // [cite: 115]
            break;                      // [cite: 116]
        }

        // Corrected Loop cycle logic. PDF incorrectly used 'y == n-1' 
        if (i == n - 1) {               
            i = 0;                      // 
        } 
        else {                          // [cite: 119]
            i++;                        // [cite: 120]
        }
    }

    // 6. Display result in table format [cite: 123]
    printf("\nProcess\t AT\t BT\t TAT\t WT\n");
    for(int j = 0; j < n; j++) {
        // Displaying 'rbt' as the Burst Time since 'bt' was reduced to 0 during execution
        printf("P%d\t %d\t %d\t %d\t %d\n", p[j].pid, p[j].at, p[j].rbt, p[j].tat, p[j].wt);
    }

    return 0;
}