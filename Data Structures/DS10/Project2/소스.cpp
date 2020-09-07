#include <iostream>

using namespace std;

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void partition(int arr[], int left, int right) {
	if (left > right)
		return;

	int pivot = left;
	int low = pivot + 1;
	int high = right;

	while (low <= high) {
		while (arr[low] <= arr[pivot] && low <= right)
			++low;
		while (arr[high] >= arr[pivot] && high >= (left + 1))
			--high;

		if (low <= high) {
			Swap(arr, low, high);
			++low;
			--high;
		}
	}

	Swap(arr, pivot, high);

	partition(arr, left, high - 1);
	partition(arr, high + 1, right);
}

int main() {
	int array[] = { 8, 2, 3, 7, 1, 5, 4, 6 };

	cout << sizeof(array) / sizeof(int) - 1 << endl;

	partition(array, 0, sizeof(array) / sizeof(int) - 1);

	for (int i = 0; i <= sizeof(array) / sizeof(int) - 1; ++i)
		cout << array[i] << " ";


	return 0;
}