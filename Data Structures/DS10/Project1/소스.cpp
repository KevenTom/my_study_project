#include <iostream>

using namespace std;

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = new int[right + 1];
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		++sIdx;
	}

	if (fIdx > mid) {
		for (int i = rIdx; i <= right; ++i, ++sIdx)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (int i = fIdx; i <= mid; ++i, ++sIdx)
			sortArr[sIdx] = arr[i];
	}

	for (int i = left; i <= right; ++i)
		arr[i] = sortArr[i];

	delete[] sortArr;
}

void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}

}


int main() {
	int array[] = { 8, 2, 3, 7, 1, 5, 4, 6 };


	MergeSort(array, 0, sizeof(array) / sizeof(int) - 1);


	for (int i = 0; i < sizeof(array) / sizeof(int) - 1; ++i)
		cout << array[i] << endl;

	return 0;
}