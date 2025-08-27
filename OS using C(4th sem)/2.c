#include <stdio.h>
#include <string.h>
#define MAX 200


int isinframes(char frames[], int frameCount, char page) {
for (int i = 0; i < frameCount; i++) {
if (frames[i] == page)
return 1;
}
return 0;
}
void optimalPageReplacement(char referenceString[], int frameSize) {
char frames[MAX];
int refLen = strlen(referenceString);
int pageFaults = 0, pageHits = 0;
int frameCount = 0;

printf("\nStep-by-step Table (Optimal Page Replacement):\n");
printf("------------------------------------------------------------------------------\n");
printf("%-12s %-35s %-18s %-18s\n", "Page", "Frames", "Page Fault", "Page Hit");
printf("------------------------------------------------------------------------------\n");

for (int i = 0; i < refLen; i++) {
char currentPage = referenceString[i];
int found = isinframes(frames, frameCount, currentPage);
if (!found) { 
if (frameCount < frameSize)
{
frames[frameCount++] = currentPage;
}

else {

int farthest = -1;
int indexToReplace = -1;
for (int j = 0; j < frameSize; j++)
{
int k;
for (k = i + 1; k < refLen; k++)
{
if (referenceString[k] == frames[j])
break;
}
if (k > farthest) {
farthest = k;
indexToReplace = j;
}
}
frames[indexToReplace] = currentPage;
}
pageFaults++;
} else {
pageHits++;
}


char frameStr[MAX * 3] = "";
for (int j = 0; j < frameCount; j++)
{
char buf[4];
snprintf(buf, sizeof(buf), "%c ", frames[j]);
strncat(frameStr, buf, sizeof(frameStr) - strlen(frameStr) - 1);
}


printf("%-12c %-35s %-18s %-18s\n",
currentPage,
frameStr,
found ? "No" : "Yes",
found ? "Yes" : "No");
}
printf("------------------------------------------------------------------------------\n");
printf("Total Page Faults = %d\n", pageFaults);
printf("Total Page Hits = %d\n", pageHits);
}
int main() {
int refSize, frameSize;
char referenceString[MAX];
printf("Enter reference string size: ");
scanf("%d", &refSize);
printf("Enter reference string (one character per page): ");
for (int i = 0; i < refSize; i++) {
char page;
scanf(" %c", &page); 
referenceString[i] = page;
}
referenceString[refSize] = '\0'; 
printf("Enter frame size: ");
scanf("%d", &frameSize);
optimalPageReplacement(referenceString, frameSize);
printf("\tCoded by Yunish Udas\n");
return 0;
}