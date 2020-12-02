#include <iostream>
#include <stdarg.h>

using namespace std;


int TestFunction(int args, ...) {
	va_list num;			//인수를 저장할 포인터
	va_start(num, args);	//va_list에게 인자들 주소를 알려주기 위함

	int result = 0;

	for (int i = 0; i < args; ++i) {
		result += va_arg(num, int);	//포인터의 값을 반환하고 다음 주소로 이동시켜줌
	}

	va_end(num);			//va_list에게 끝났다고 알림
	return result;
}

int main() {
	cout << TestFunction(6, 1, 2, 3, 4, 5, 6) << endl;

	return 0;
}