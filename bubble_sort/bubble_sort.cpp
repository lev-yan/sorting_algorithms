#include <iostream>
#include <time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int size)
{
	int i, j;
	bool swapped;
	for(i = 0; i < size - 1; i++){
		swapped = false;
		for(j = 0; j < size - i -1; j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if(swapped == false){
			break;
		}
	}
}
void print(int arr[], int size)
{
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << std::endl;
	}
}
int main()
{
	int arr[] = {2, 5, 6, 2, 4, 1, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	time_t start, end;
	start = clock();
	bubble_sort(arr, size);
	end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "duration of code " << std::endl;
	print(arr, size);
	return 0;
}
