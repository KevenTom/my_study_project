#include<iostream>

using namespace std;

int main() {
	wchar_t str[] = L"ABC";	//wchar_t �ڷ����� 2����Ʈ �޸� ������ �Ҵ��Ѵ�.(char�� 1����Ʈ)

	cout << "�迭�� ���� : " << sizeof(str) << endl;
	cout << "���ڿ��� ���� : " << wcslen(str) << endl;	//strlen�� SBCS ����̱� ������ WBCS ����� wcslen�� ����ؾ� ��

	return 0;
}