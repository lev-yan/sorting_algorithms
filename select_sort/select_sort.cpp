#include <iostream>


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void select_sort(int arr[], int n)
{
	int i, j, prev_ind;
	for(i = 0; i < n - 1; i++){
		prev_ind = i;
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[prev_ind]){
				prev_ind = j;
				swap(&arr[prev_ind], &arr[i]);
			}
		}

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
	int arr[] = {3, 5, 2, 2, 1, 7, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	select_sort(arr, size);
	print(arr, size);
	return 0;
}
