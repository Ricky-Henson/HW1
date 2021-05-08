#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myHeader.h"

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void MergeNum(int number[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = number[l + i];
    for (j = 0; j < n2; j++)
        R[j] = number[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            number[k] = L[i];
            i++;
        }
        else {
            number[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        number[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        number[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void MergeSortNum(int number[], int l, int r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        MergeSortNum(number, l, m);
        MergeSortNum(number, m + 1, r);
 
        MergeNum(number, l, m, r);
    }
}

void MergeStr(char *str[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    char *left[n1], *right[n2];

    int z;
    for(z=0; z<n1; z++){
        left[z] = (char *) malloc (100);
        right[z] = (char *) malloc (100);
    }

    for(i=0; i<n1; i++){
        strcpy(left[i], str[l+i]);
    }
    for(j=0; j<n2; j++){
        strcpy(right[j], str[m+1+j]);
    }

    i=0; j=0; k=l;
    while(i<n1 && j<n2){
        if((strcmp(left[i], right[j])) <= 0){
            strcpy(str[k], left[i]);
            i++;
        }
        else{
            strcpy(str[k], right[j]);
            j++;
        }
        k++;
    }

    while(i<n1){
        strcpy(str[k], left[i]);
        i++;
        k++;
    }
    while(j<n2){
        strcpy(str[k], right[j]);
        j++;
        k++;
    }
}

void MergeSortStr(char *str[], int l, int r){
    if(l<r){
        int m = l + (r-l) / 2;

        MergeSortStr(str, l, m);
        MergeSortStr(str, m+1, r);
        MergeStr(str, l, m, r);
    }
}
