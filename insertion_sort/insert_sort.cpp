#include <iostream>
#include <time.h>

void insert_sort(int arr[], int n)
{
	int j, key;
	for(int i = 1; i < n; ++i){
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void print(int arr[], int n)
{
	for(int i = 0; i < n; ++i)
		std::cout << arr[i] << std::endl;
}

int main()
{
	clock_t start, end;
	start = clock();
	int arr[] = {11, -21, 0, 42, 2, 5, 64, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	insert_sort(arr, n);
	print(arr, n);
	end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "duration of code " << duration;
	return 0;
}
