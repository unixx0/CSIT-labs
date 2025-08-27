#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    char p[n];
    int bt[n], wt[n], tat[n];

    for(i=0;i<n;i++){
        printf("Enter name of process %d: ", i+1);
        scanf(" %c", &p[i]);
    }
    for(i=0;i<n;i++){
        printf("Enter burst time for process %c: ", p[i]);
        scanf("%d", &bt[i]);
    }

    wt[0]=0;
    for(i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(i=0;i<n;i++)
        tat[i]=bt[i]+wt[i];

    // Gantt Chart
    printf("\n\nGantt Chart:\n");
    printf("+-------");
    for(i=0;i<n;i++)
        printf("----------");
    printf("+\n|");

    for(i=0;i<n;i++)
        printf("    %c    |", p[i]);

    printf("\n+-------");
    for(i=0;i<n;i++)
        printf("----------");
    printf("+\n");

    printf("0       ");
    for(i=0;i<n;i++)
        printf("%-10d", tat[i]);

    // Process Table
    printf("\n\n+---------+--------------------+-------------------+\n");
    printf("| Process | Turnaround Time(s) | Waiting Time(s)   |\n");
    printf("+---------+--------------------+-------------------+\n");
    for(i=0;i<n;i++) {
        printf("|    %c    |         %3d        |        %3d        |\n", p[i], tat[i], wt[i]);
    }
    printf("+---------+--------------------+-------------------+\n");

    // Averages
    double totalWT=0, totalTAT=0;
    for(i=0;i<n;i++){
        totalWT+=wt[i];
        totalTAT+=tat[i];
    }
    printf("\nAverage Waiting Time : %.2f seconds\n", totalWT/n);
    printf("Average Turnaround Time: %.2f seconds\n", totalTAT/n);
  printf("\tCoded by Yunish Udas\n");

    return 0;
}