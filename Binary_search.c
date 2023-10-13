#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char word[100];  
} WordEntry;
 
// An iterative binary search function.
int binarySearch(WordEntry arr[], int low, int high, char x[])
{
     while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(arr[mid].word, x);
        if (cmp == 0) {
            return mid; // Word found
        } else if (cmp < 0) {
            low= mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Word not found
 
    // If we reach here, then element was not present
   // return -1;
}


int main()
{
    WordEntry list[500];
    FILE  *f;
    FILE *output;
    char line[100];
    int frequency[100];
    char word[50];
    int capacity= 10;
    int count = 0;
    char inputfile[50];

    printf("Enter the input file name:");
    gets(inputfile);
    f = fopen(inputfile, "r");
    if(f == NULL)
        return 1;
    
     // Prompt user for a word to search
    char searchWord[100];
    printf("Enter a word to search: ");
    scanf("%s", searchWord);

    while(fgets(line, 1000, f)){
        sscanf( line, "%s", word);  
        strcpy(list[count].word, word);
        count++;
    }

    int result = binarySearch(list,0, count-1,searchWord);

    if (result != -1) {
        printf("'%s' found in the file at index '%d'\n", searchWord,result+1);
    } else {
        printf("'%s' not found in the file. \n", searchWord);
    }


    return 0;

}