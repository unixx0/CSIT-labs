#include <stdio.h>
#include <stdlib.h> 
int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    char *p = (char*)malloc(n * sizeof(char));
    int *bt = (int*)malloc(n * sizeof(int));
    int *wt = (int*)malloc(n * sizeof(int));
    int *tat = (int*)malloc(n * sizeof(int));
    if (p == NULL || bt == NULL || wt == NULL || tat == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for(i=0; i<n; i++){
        printf("Enter name of process %d: ", i+1);
        scanf(" %c", &p[i]);
    }
    for(i=0; i<n; i++){
        printf("Enter burst time for process %c: ", p[i]);
        scanf("%d", &bt[i]);
    }
    char temp_p;
    int temp_bt;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(bt[j] > bt[j+1]) {
                temp_bt = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp_bt;
                temp_p = p[j];
                p[j] = p[j+1];
                p[j+1] = temp_p;
            }
        }
    }
    wt[0] = 0;
    for(i=1; i<n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i=0; i<n; i++)
        tat[i] = bt[i] + wt[i];
    printf("\n\nGantt Chart:\n");
    printf("+-------");
    for(i=0; i<n; i++)
        printf("----------");
    printf("+\n|");
    for(i=0; i<n; i++)
        printf("    %c    |", p[i]);
    printf("\n+-------");
    for(i=0; i<n; i++)
        printf("----------");
    printf("+\n");
    printf("0       ");
    for(i=0; i<n; i++)
        printf("%-10d", tat[i]);
    printf("\n\n+---------+--------------------+-------------------+\n");
    printf("| Process | Turnaround Time(s) | Waiting Time(s)   |\n");
    printf("+---------+--------------------+-------------------+\n");
    for(i=0; i<n; i++) {
        printf("|    %c    |         %3d        |        %3d        |\n", p[i], tat[i], wt[i]);
    }
    printf("+---------+--------------------+-------------------+\n");
    double totalWT=0, totalTAT=0;
    for(i=0; i<n; i++){
        totalWT+=wt[i];
        totalTAT+=tat[i];
    }
    printf("\nAverage Waiting Time : %.2f seconds\n", totalWT/n);
    printf("Average Turnaround Time: %.2f seconds\n", totalTAT/n);
    free(p);
    free(bt);
    free(wt);
    free(tat);
   printf("\tCoded by Yunish Udas\n");
    return 0;
}
