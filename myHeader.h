#ifndef HEADER_FILE
#define HEADER_FILE

#define Total 1000000
#define sent 100

void GenerateNumbers();
void GenerateStrings();

void QuickSortNum(int *number, int first, int last);
void QuickSortStr(char *str[], int first, int last);

void MergeSortNum(int *number, int first, int last);
void MergeSortStr(char *str[], int first, int last);

void HeapSortNum(int *number, int total);
void HeapSortNum(char *str[], int total);

#endif
