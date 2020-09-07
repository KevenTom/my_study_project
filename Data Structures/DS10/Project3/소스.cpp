#include<iostream>
#include<queue>

#define BUCKET_NUM 10

using namespace std;




void radixSort(int* arr, int leg, int maxLen) {
	queue<int> buckets[BUCKET_NUM];
	int unit = 1;

	for (int i = 0; i < maxLen; ++i) {

		for (int ii = 0; ii < leg; ++ii)
			buckets[(arr[ii] / unit) % 10].push(arr[ii]);


		for (int iii = 0, di = 0; iii < 10; ++iii) {
			while (!buckets[iii].empty()) {
				arr[di++] = buckets[iii].front();
				buckets[iii].pop();
			}
		}

		unit *= 10;
	}
}



void radixSort2(int* arr, int leg, int maxLen) {
	if (maxLen == 0)
		return;

	queue<int>* q = new queue<int>[leg];
	int ii = 0;
	int unit;

	if (maxLen == 3)
		unit = 1;
	else if (maxLen == 2)
		unit = 10;
	else
		unit = 100;

	for (int i = 0; i < leg; ++i)
		q[arr[i] / unit % 10].push(arr[i]);

	for (int i = 0; i < leg; ++i)
		if (!q[i].empty() == true) {
			while (!q[i].empty()) {
				arr[ii++] = q[i].front();
				q[i].pop();
			}
		}

	delete[] q;
	radixSort2(arr, leg, --maxLen);
}



int main() {

	int array[]{ 13, 212, 14, 7141, 10987, 6, 15 };


	radixSort(array, sizeof(array) / sizeof(int), 5);


	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
		cout << array[i] << " ";


	return 0;
}