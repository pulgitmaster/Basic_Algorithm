#include <iostream>
#include <cstdio>
#include <time.h>

#define MAX 10000000
#define SIZE 10000

int main()
{
	srand(time(NULL));
	int *arr = new int[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % MAX;
	}

	/* bubble sort */
	int * temp = new int;
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (arr[i] > arr[j]) {
				*temp = arr[i];
				arr[i] = arr[j];
				arr[j] = *temp;
			}
		}
	}

	/* print result */
	for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;

	delete temp;
	delete[] arr;

    return 0;
}

