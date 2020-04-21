#include <iostream>
#include <vector>
#include <algorithm>

void count_sort(std::vector <int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;
	std::vector <int> count(range), output(arr.size());
	for(int i = 0; i < arr.size(); ++i){
		count[arr[i] - min]++;
	}
	for(int i = 1; i < count.size(); ++i){
		count[i] += count[i - 1];
	}
	for(int i = arr.size() - 1; i >= 0; --i){
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	for(int i = 0; i < arr.size(); ++i){
		arr[i] = output[i];
	}
}


void print(std::vector <int>& arr)
{
	for(int i = 0; i < arr.size(); i++){
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr = {-5, -10, 0,  5, 3, 10, 6, -1};
	print(arr);
	count_sort(arr);
	print(arr);
	return 0;
}
