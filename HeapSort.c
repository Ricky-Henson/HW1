#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myHeader.c"

// assignment
void swapNum(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyNum(int number[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && number[left] > number[largest])
        largest = left;
  
    if (right < n && number[right] > number[largest])
        largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&number[i], &number[largest]);
        heapify(number, n, largest);
    }
}
  
// Main function to do heap sort
void HeapSortNum(int number[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(number, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(&number[0], &number[i]);
  
      // Heapify root element to get highest element at root again
        heapify(number, i, 0);
    }
}

void swapStr(char **str1, char **str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void heapifyStr(char *str[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left<n && (strcmp(str[left], str[largest]) > 0))
        largest = left;
    if(right<n && (strcmp(str[right], str[largest]) > 0))
        largest = right;

    if(largest != i){
        swapStr(&str[i], &str[largest]);
        heapifyStr(str, n, largest);
    }
}

void HeapSortStr(char *str[], int n){
    int i;
    for(i = n / 2 - 1; i>=0; i--)
        heapifyStr(str, n, i);
    for(i = n - 1; i>=0; i--){
        swapStr(&str[0], &str[i]);
        heapifyStr(str, i, 0);
    }
}