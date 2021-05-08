#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myHeader.h"

void QuickSortNum(int *number,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      QuickSortNum(number,first,j-1);
      QuickSortNum(number,j+1,last);

   }
}

void QuickSortStr(char *str[], int first, int last){
   int i, j, pivot;
   char *temp;

   if(first<last){
      pivot = first;
      i = first;
      j = last;

      while(i<j){
         while((strcmp(str[i], str[pivot]) <= 0) && i<last)
            i++;
         while((strcmp(str[j], str[pivot]) > 0))
            j--;
         if(i<j){
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
         }
      }
      temp = str[pivot];
      str[pivot] = str[j];
      str[j] = temp;
      QuickSortStr(str, first, j-1);
      QuickSortStr(str, j+1, last);
   }
}
