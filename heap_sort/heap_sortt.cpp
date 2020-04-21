#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int size, int i)
{
	int parent = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < size && arr[l] > arr[parent]){
		parent = l;
	}
	if(r < size && arr[r] > arr[parent]){
		parent = r;
	}
	if(parent != i){
		std::swap(arr[i], arr[parent]);
		heapify(arr, size, parent);
	}
}

void heap_sort(int arr[], int size)
{
	for(int i = size / 2 - 1; i >= 0; i--){
		heapify(arr, size, i);
	}
	for(int i = size - 1; i > 0; i--){
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
void print(int arr[], int size)
{
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}
int main()
{
	int arr[] = {1, 6, 3, 7, 2, 8, 9, 4};
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	heap_sort(arr, size);
	print(arr, size);
	return 0;
}

