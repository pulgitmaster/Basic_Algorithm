#include <iostream>
#include <cstdio>
#include <time.h>
#include <ctime>

#define MAX 10000000
#define SIZE 100000

void quickSort(int *, int, int);

int main()
{
	srand(time(NULL));
	int *arr = new int[SIZE];
	int *arr2 = new int[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % MAX;
		arr2[i] = arr[i];	// copy arr data to arr2
	}

	/* bubble sort */
	int * temp = new int;
	time_t bubble_begin = clock();
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (arr[i] > arr[j]) {
				*temp = arr[i];
				arr[i] = arr[j];
				arr[j] = *temp;
			}
		}
	}
	time_t bubble_end = clock();
	double bubble_elapsed = ((double)bubble_end - (double)bubble_begin) / CLOCKS_PER_SEC;

	/* quick sort */
	time_t quick_begin = clock();
	quickSort(arr2, 0, SIZE - 1);
	time_t quick_end = clock();
	double quick_elapsed = ((double)quick_end - (double)quick_begin) / CLOCKS_PER_SEC;

	/* print result */
	std::cout << "BubbleSort elapsed time : " << bubble_elapsed << "sec" << std::endl;
	std::cout << "QuickSort elapsed time : " << quick_elapsed << "sec" << std::endl;

	delete temp;
	delete[] arr, arr2;

	return 0;
}

void quickSort(int *arr, int left, int right) {
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2];
	int temp;

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}