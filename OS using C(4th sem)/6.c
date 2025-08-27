#include <stdio.h>
#include <stdbool.h>

#define MAX_GANTT_SLICES 100 // Maximum number of time slices for the Gantt chart

int main() {
    int n, time_quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    // Arrays to store process details
    int pid[n];
    int burst_time[n];
    int remaining_bt[n];
    int waiting_time[n];
    int turnaround_time[n];

    // Gantt chart storage
    int gantt_p[MAX_GANTT_SLICES];
    int gantt_time[MAX_GANTT_SLICES];
    int gantt_index = 0;

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter burst time for process %d: ", pid[i]);
        scanf("%d", &burst_time[i]);
        remaining_bt[i] = burst_time[i]; // Initialize remaining time
    }

    int current_time = 0;
    int completed_processes = 0;

    // --- RR ALGORITHM CORE LOGIC ---
    while (completed_processes < n) {
        bool process_executed_in_cycle = false;

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                process_executed_in_cycle = true;

                if (remaining_bt[i] <= time_quantum) {
                    current_time += remaining_bt[i];
                    remaining_bt[i] = 0;

                    turnaround_time[i] = current_time;
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                    
                    completed_processes++;
                } else {
                    current_time += time_quantum;
                    remaining_bt[i] -= time_quantum;
                }
                
                // Record this execution slice for the Gantt chart
                gantt_p[gantt_index] = pid[i];
                gantt_time[gantt_index] = current_time;
                gantt_index++;
            }
        }

        if (!process_executed_in_cycle) {
            break;
        }
    }

    // --- PRINTING GANTT CHART ---
    printf("\n\nGantt Chart:\n");
    // Print top border
    for (int i = 0; i < gantt_index; i++) {
        printf("+----P%d----", gantt_p[i]);
    }
    printf("+\n|");

    // Print process execution intervals
    for (int i = 0; i < gantt_index; i++) {
        printf("           |");
    }
    printf("\n");

    // Print bottom border
    for (int i = 0; i < gantt_index; i++) {
        printf("+-----------");
    }
    printf("+\n");

    // Print timeline
    printf("0");
    for (int i = 0; i < gantt_index; i++) {
        printf("          %2d", gantt_time[i]);
    }
    printf("\n");


    // --- PRINTING PROCESS TABLE ---
    printf("\n\n+---------+-------------+--------------------+-------------------+\n");
    printf("| Process | Burst Time  | Turnaround Time(s) | Waiting Time(s)   |\n");
    printf("+---------+-------------+--------------------+-------------------+\n");

    for(int i = 0; i < n; i++) {
        printf("|    P%d    |     %3d     |         %3d        |        %3d        |\n", pid[i], burst_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("+---------+-------------+--------------------+-------------------+\n");

    // --- PRINTING AVERAGES ---
    double total_wt = 0, total_tat = 0;
    for(int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time   : %.2f seconds\n", total_wt / n);
    printf("Average Turnaround Time: %.2f seconds\n", total_tat / n);
    printf("\tCoded by Yunish Udas\n");

    return 0;
}