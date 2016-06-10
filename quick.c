#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int pos1, int pos2) {
	int temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

int split(int arr[], int lower, int upper) {
	int middle = (upper + lower) / 2;
	int pivot = arr[middle];
	swap(arr, lower, middle);
	int left = lower +1;
	int right = upper;
	while (left <= right) {
		while(arr[left] <= pivot) {
			left++;
		}

		while(arr[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(arr, left, right);
		}
	}

	swap(arr, right, lower);

	return right;
}


void quick_sort(int arr[], int lower, int upper) {
	if (upper > lower) {
		int index = split(arr, lower, upper); 
		quick_sort(arr, lower, index - 1);
		quick_sort(arr, index + 1, upper);
	}
}

void print(int arr[], int size) {
	for(int i=0;i<size;i++) {
		printf(" %d", arr[i]);
	}
}


int main() {
	const int size = 1000;
	int arr[size];
	for (int i=0;i<size;i++) {
		arr[i] = rand() % (size * 1000);
	}
	quick_sort(arr, 0 ,size-1);
	print(arr, size);
	return 0;
} 