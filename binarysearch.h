#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

typedef struct
{
    char word[100];
    int freq;
} WordEntry;
 
int binarySearch(WordEntry arr[], int low, int high, char x[]);

#endif