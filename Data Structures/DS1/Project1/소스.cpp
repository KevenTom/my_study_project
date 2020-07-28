//반복문 이진탐색알고리즘
#include<iostream>
using namespace std;

int search(int arr[], int length, int search)
{
	int first = 0;
	int last = length - 1;
	int mid;
	int opcount = 0;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (arr[mid] > search)
		{
			last = mid - 1;
		}
		else if (arr[mid] < search)
		{
			first = mid + 1;
		}
		else
		{
			return mid;
		}
		opcount += 1;
	}
	cout << "비교 연산 횟수" << opcount << endl;
	return -1;
}

int main()
{
	int arr[8]{};
	int idx;

	idx = search(arr, sizeof(arr) / sizeof(int), 3);

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