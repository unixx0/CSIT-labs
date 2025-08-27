#include <stdio.h>
#include <string.h>
#define MAX 200

void fifo(char referenceString[], int frameSize)
{
char frames[MAX];
char queue[MAX]; 
int front = 0, rear = 0;
int pageFaults = 0, pageHits = 0;
int frameCount = 0;
int refLen = strlen(referenceString);
printf("\nStep-by-step Table (FIFO Page Replacement):\n");
printf("---------------------------------------------------------------\n");
printf("%-10s| %-30s| %-12s| %-12s\n", "Page", "Frames", "Page Fault", "Page Hit");
printf("---------------------------------------------------------------\n");
for (int i = 0; i < refLen; i++)
{
char page = referenceString[i];
int found = 0;

for (int j = 0; j < frameCount; j++)
{
if (frames[j] == page)
{
found = 1;
break;
}
}

if (!found) 
{
if (frameCount < frameSize)
{
frames[frameCount++] = page;
queue[rear++] = page;
}
else
{
char oldPage = queue[front++];
for (int j = 0; j < frameCount; j++)
{
if (frames[j] == oldPage)
{
frames[j] = page;
break;
}
}
queue[rear++] = page;
}
pageFaults++;
}
else
{
pageHits++;
}

printf("%-10c| %-30s| %-12s| %-12s\n", page, "", found ? "No" : "Yes", found ? "Yes"
: "No");

for (int j = 0; j < frameCount; j++)
{
printf("%c ", frames[j]);
}
printf("\n");
}

printf("---------------------------------------------------------------\n");
printf("Total Page Faults = %d\n", pageFaults);
printf("Total Page Hits = %d\n", pageHits);
}

int main()
{
int refSize, frameSize;
char referenceString[MAX];
printf("Enter reference string size: ");
scanf("%d", &refSize);
printf("Enter reference string: ");
for (int i = 0; i < refSize; i++)
{
char page;
scanf(" %c", &page); 
referenceString[i] = page;
}
referenceString[refSize] = '\0'; 
printf("Enter frame size: ");
scanf("%d", &frameSize);
fifo(referenceString, frameSize);
printf("\tCoded by Yunish Udas\n");
return 0;
}