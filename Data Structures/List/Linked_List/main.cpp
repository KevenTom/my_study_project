#include<iostream>

using namespace std;

struct Range {
	int min;
	int max;
};

int RangeCheck(Range* pr, int pos) {
	if (pr->min <= pos && pos <= pr->max)
		return pr->max - pos;
	else
		return -1;
}


int main() {
	Range ran;
	ran.max = 5;
	ran.min = 1;

	cout << RangeCheck(&ran, 3) << endl;


	return 0;
}