//�ݺ��� ����Ž���˰���
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
	cout << "�� ���� Ƚ��" << opcount << endl;
	return -1;
}

int main()
{
	int arr[8]{};
	int idx;

	idx = search(arr, sizeof(arr) / sizeof(int), 3);

	if (idx == -1)
	{
		cout << "Ž�� ����" << endl;
	}
	else
	{
		cout << "Ž�� ���� : " << idx << endl;
	}

	return 0;
}