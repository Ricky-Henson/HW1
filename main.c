#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include "myHeader.h"

int number[Total];
char *str[Total];

int main(){
    int i;
    char temp[2048];
    for(i=0; i<Total; i++){
        number[i] = 0;
    }
    FILE *fp;
    
    GenerateNumbers();
    fp = fopen("dataset1.txt", "r");
    i=0;
    while(fgets(temp, 2048, fp)){
        number[i] = atoi(temp);
        i++;
    }
    fclose(fp);
//     GenerateStrings();
//     fp = fopen("dataset2.txt", "r");
//     i=0;
//     while(fgets(temp, 2048, fp)){
//         str[i] = strdup(temp);
//     i++;
//     }
//     fclose(fp);
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
