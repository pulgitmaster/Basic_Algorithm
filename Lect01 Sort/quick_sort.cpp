#include <iostream>
#include <cstdio>
#include <time.h>

#define MAX 10000000
#define SIZE 10000

void quickSort(int *, int, int);

int main()
{
	srand(time(NULL));
	int *arr = new int[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % MAX;
	}

	/* quick sort */
	quickSort(arr, 0, SIZE - 1);

	/* print result */
	for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;

	delete[] arr;

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