#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include "myHeader.h"

int number[Total];
char *str[Total];

int main(){
    int i;
    for(i=0; i<Total; i++){
        number[i] = 0;
    }
    GenerateNumbers();
//     GenerateStrings();

    struct timeval start;
    struct timeval end;
    unsigned long diff;

    gettimeofday(&start, NULL);
    QuickSortNum(number, 0, Total);
//     QuickSortStr(str, 0, Total);
//     MergeSortNum(number, 0, Total);
//     MergeSortStr(str, 0, Total);
//     HeapSortNum(number, Total);
//     HeapSortStr(str, Total);
    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("\nSorting performance %ld us (equal %f sec)", diff, diff/1000000.0);

    return 0;
}
