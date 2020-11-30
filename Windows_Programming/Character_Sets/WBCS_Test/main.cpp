#include<iostream>

using namespace std;

int main() {
	wchar_t str[] = L"ABC";	//wchar_t 자료형은 2바이트 메모리 공간을 할당한다.(char는 1바이트)

	cout << "배열의 길이 : " << sizeof(str) << endl;
	cout << "문자열의 길이 : " << wcslen(str) << endl;	//strlen는 SBCS 기반이기 때문에 WBCS 기반인 wcslen를 사용해야 함

	return 0;
}