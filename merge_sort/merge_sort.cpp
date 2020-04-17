#include <iostream>

void merge(int arr[], int b, int m, int e)
{
	int i, j, k;
	int s1 = m - b + 1;
	int s2 = e - m;
	int left[s1], right[s2];

	for(i = 0; i < s1; ++i){
		left[i] = arr[b + i];
	}
	for(j = 0; j < s2; ++j){
		right[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = b;
	while(i < s1 && j < s2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			++i;
		}else {
			arr[k] = right[j];
			++j;
		}
		++k;
	}
	while(i < s1){
		arr[k] = left[i];
		++i;
		k++;
	}
	while(j < s2){
		arr[k] = right[j];
		++j;
		k++;
	}
}

void merge_sort(int arr[], int b, int e)
{
	if(b < e){
		int m = b + (e - b) / 2;
		merge_sort(arr, b, m);
		merge_sort(arr, m + 1, e);
		merge(arr, b, m, e);
	}
}

void print(int arr[], int size)
{
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " " << std::endl;
	}
	std::cout << std::endl;
}



int main()
{
	int arr[] = {2, 4, 7, 6, 5, 1};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	print(arr, arr_size);
	merge_sort(arr, 0, arr_size - 1);
	print(arr, arr_size);
	return 0;
}
