#include <iostream>
#include <stdarg.h>

using namespace std;


int TestFunction(int args, ...) {
	va_list num;			//�μ��� ������ ������
	va_start(num, args);	//va_list���� ���ڵ� �ּҸ� �˷��ֱ� ����

	int result = 0;

	for (int i = 0; i < args; ++i) {
		result += va_arg(num, int);	//�������� ���� ��ȯ�ϰ� ���� �ּҷ� �̵�������
	}

	va_end(num);			//va_list���� �����ٰ� �˸�
	return result;
}

int main() {
	cout << TestFunction(6, 1, 2, 3, 4, 5, 6) << endl;

	return 0;
}