#include"Storage.h"

using namespace std;

int main() {
	//4 이번에는 멤버펑션을 specialization 하는 예제를 보여드릴께요
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}