#include <stdio.h>
#include <string.h>
#define MAX 200

void lruPageReplacement(char referenceString[], int frameSize) {
char frames[MAX];
int lastUsed[MAX];
int pageFaults = 0, pageHits = 0;
int frameCount = 0;
int refLen = strlen(referenceString);
printf("\nStep-by-step Table (LRU Page Replacement):\n");
printf("-------------------------------------------------------------------------------\n");

printf("%-8s %-20s %-12s %-8s\n",
"Page",
"Frames",
"Page Fault",
"Hit");
printf("-------------------------------------------------------------------------------\n");
for (int i = 0; i < refLen; i++)
{
char page = referenceString[i];
int found = 0;

for (int j = 0; j < frameCount; j++) {
if (frames[j] == page) {
found = 1;
lastUsed[j] = i;
break;
}
}

if (!found) { 
if (frameCount < frameSize) {
frames[frameCount] = page;
lastUsed[frameCount] = i;
frameCount++;
} else {

int lruIndex = 0;
for (int j = 1; j < frameSize; j++) {
if (lastUsed[j] < lastUsed[lruIndex]) {
lruIndex = j;
}
}
frames[lruIndex] = page;
lastUsed[lruIndex] = i;
}
pageFaults++;
} else {
pageHits++;
}

printf("%-8c ", page);

char frameBuf[64] = {0};
char *ptr = frameBuf;

for (int j = 0; j < frameCount; j++) {
ptr += sprintf(ptr, "%c ", frames[j]);
}
printf("%-20s %-12s %-8s\n",
frameBuf,
found ? "No" : "Yes",
found ? "Yes" : "No");
}
printf("-------------------------------------------------------------------------------\n");
printf("Total Page Faults = %d\n", pageFaults);
printf("Total Page Hits = %d\n", pageHits);
}
int main() {
int refSize, frameSize;
char referenceString[MAX];
printf("Enter reference string size: ");
scanf("%d", &refSize);
printf("Enter reference string (length should be %d): ", refSize);
for (int i = 0; i < refSize; i++) {
scanf(" %c", &referenceString[i]); 
referenceString[refSize] = '\0'; 
printf("Enter frame size: ");
scanf("%d", &frameSize);
if ((int)strlen(referenceString) != refSize) {
printf("Error: reference string size does not match input length!\n");
return 1;
}
lruPageReplacement(referenceString, frameSize);
printf("\tCoded by Yunish Udas\n");
return 0;
}