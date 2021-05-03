all: main.o myHeader.o QuickSort.o MergeSort.o Heapsort.o
	gcc main.o myHeader.o QuickSort.o MergeSort.o HeapSort.o -o all

main.o: main.c
	gcc -c main.c

myHeader.o: myHeader.c
	gcc -c myHeader.c

QuickSort.o: QuickSort.c
	gcc -c QuickSort.c

MergeSort.o: MergeSort.c
	gcc -c MergeSort.c

HeapSort.o: HeapSort.c
	gcc -c HeapSort.c

clean:
	rm *.o all