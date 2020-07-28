//재귀 이진탐색알고리즘
#include<iostream>
using namespace std;

int searchfunct(int arr[], int first, int last, int search)
{
	int mid = (first + last) / 2;

	if (first > last)
	{
		return -1;
	}
	else if (arr[mid] > search)
	{
		return searchfunct(arr, first, mid - 1, search);
	}
	else if (arr[mid] < search)
	{
		return searchfunct(arr, mid + 1, last, search);
	}
	else
	{
		return mid;
	}
}


int main()
{
	int arr[]{ 1, 3, 5, 7, 9, 10, 13, 25, 76, 103 };
	int idx;

	idx = searchfunct(arr, 0, sizeof(arr) / sizeof(int) - 1, 26);

	if (idx == -1)
	{
		cout << "탐색 실패" << endl;
	}
	else
	{
		cout << "탐색 성공 : " << idx << endl;
	}

	return 0;
}