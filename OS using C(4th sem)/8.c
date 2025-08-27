#include <stdio.h>

void printFreeBlocks(int blocks[], int n) {
    printf("\nCurrent free memory blocks:\n");
    for(int i=0; i<n; i++)
        printf("Block %d: %d\n", i+1, blocks[i]);
}

int main() {
    int n;
    printf("Enter number of free memory blocks: ");
    scanf("%d", &n);
    int blocks[n];
    printf("Enter sizes of each free memory block:\n");
    for(int i=0; i<n; i++) {
        printf("Size of block %d: ", i+1);
        scanf("%d", &blocks[i]);
    }
    while(1) {
        int reqSize;
        printf("\nEnter size of memory to allocate (Enter 0 or negative to exit): ");
        scanf("%d", &reqSize);
        if(reqSize <= 0) {
            printf("Exiting allocation process.\n");
            break;
        }
        printf("\nFinding worst fit size %d...\n", reqSize);
        int worstIndex = -1;
        for(int i=0; i<n; i++) {
            printf("Checking block %d with size %d... ", i+1, blocks[i]);
            if(blocks[i] >= reqSize) {
                if(worstIndex == -1 || blocks[i] > blocks[worstIndex]) {
                    worstIndex = i;
                    printf("This is the worst fit so far.\n");
                } else
                    printf("But not better than current worst fit block %d.\n", worstIndex+1);
            } else
                printf("Not enough space for allocation.\n");
        }
        if(worstIndex != -1) {
            printf("\nWorst fit found: Block %d with size %d.\n", worstIndex+1, blocks[worstIndex]);
            blocks[worstIndex] -= reqSize;
            printf("Allocating %d units of memory.\n", reqSize);
            printf("Remaining free space in block %d: %d\n", worstIndex+1, blocks[worstIndex]);
        } else {
            printf("\nNo block large enough for requested size %d.\n", reqSize);
            printf("Cannot allocate requested memory, insufficient space.\n");
        }
        printFreeBlocks(blocks, n);
    }
    printf("\tCoded by Yunish Udas\n");
    return 0;
}
