#include <iostream>

using namespace std;

template<typename T>
int ISearch(T& arr, int target) {
	int first = 0;
	int last = sizeof(arr) / sizeof(int) - 1;
	int mid;

	while (arr[first] < target && arr[last] > target) {
		mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

		if (arr[mid] == target)
			return mid;

		if (arr[mid] > target)
			last = mid - 1;
		else
			first = mid + 1;
	}

	return -1;
}



int main() {
	int arr[]{ 1, 3, 5, 7, 9 };

	cout << ISearch(arr, 7) << endl;


	return 0;
}