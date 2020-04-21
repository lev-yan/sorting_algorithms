#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for(int j = low; j <= high; j++){
		if(arr[j] < pivot){
		i++;
		swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}
 
void quick_sort(int arr[], int low, int high)
{
	if(low < high){
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
	
}

void print(int arr[], int size)
{
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	int arr[] = {9, 3, 5, 2, 84, 43, 25};
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	quick_sort(arr, 0, size - 1);
	print(arr, size);
	return 0;
}
