#include <stdio.h>

// 3. How to group the information of Process? Ans: Use Structure
struct process_struct {
    int pid;
    int at;
    int bt; // Added: Was missing from the PDF struct snippet
    int ct;
    int tat;
    int wt;
    int rt;
    int start_time; 
};

int main() {
    int n;
    float sum_tat = 0, sum_wt = 0;
    
    // 1. Input: No. of total processes
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    
    struct process_struct ps[n];
    
    // 4. Accept pid, at, bt from user
    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        // Corrected syntax from the PDF to successfully capture AT and BT
        scanf("%d %d", &ps[i].at, &ps[i].bt);
        ps[i].pid = i + 1;
    }
    
    // 5. Calculate start_time, CT, TAT, WT of each process
    for(int i = 0; i < n; i++) {
        
        // Calculate start_time based on conditions provided in the PDF table
        if(i == 0) {
            ps[i].start_time = ps[i].at;
        } else {
            if(ps[i-1].ct < ps[i].at) {
                ps[i].start_time = ps[i].at;
            } else {
                // This covers both == and > conditions mathematically 
                ps[i].start_time = ps[i-1].ct; 
            }
        }
        
        // Calculations using the formulas from the PDF
        ps[i].ct = ps[i].start_time + ps[i].bt;
        ps[i].tat = ps[i].ct - ps[i].at;
        ps[i].wt = ps[i].tat - ps[i].bt;
        
        // Calculating Response Time (Start Time - Arrival Time)
        ps[i].rt = ps[i].start_time - ps[i].at; 
        
        // Add to sums for averages
        sum_tat += ps[i].tat;
        sum_wt += ps[i].wt;
    }
    
    // 6. Calculate ATAT and AWT
    float atat = sum_tat / n;
    float awt = sum_wt / n;
    
    // Calculate Throughput: Total processes / Total time taken
    float throughput = (float)n / (ps[n-1].ct - ps[0].start_time);
    
    // 7. Print data in table format
    printf("\nProcess\t AT\t BT\t CT\t TAT\t WT\t RT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\t %d\n", 
               ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }
    
    printf("\nAverage Turn Around Time (ATAT): %.2f\n", atat);
    printf("Average Waiting Time (AWT): %.2f\n", awt);
    printf("Throughput: %.2f processes/unit time\n", throughput);
    
    return 0;
}