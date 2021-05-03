#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myHeader.h"

// #define Total 1000000

void GenerateNumbers(){
    int number[Total];
    FILE *fp;

    fp = fopen("dataset1.txt", "w+");
    int i;
	for(i=0; i<Total; i++){
        number[i] = rand();
        fprintf(fp, "%d\n", number[i]);
    }
    fclose(fp);
}

void GenerateStrings(){
    char string[Total];
    char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int poolLen = strlen(pool);
    int index = 0;
    FILE *fp;

    fp = fopen("dataset2.txt", "w+");
    int i, j;
	for(i=0; i<Total; i++){
        for(j=0; j<sent; j++){
            // index = (double)rand() /RAND_MAX *52;
            index = rand() % poolLen;
            string[j] = pool[index];
            fprintf(fp, "%c", string[j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
