#include<iostream>

using namespace std;

int main() {
	char str[] = "ABC한글";	//운영체제에서 문자열을 어떻게 처리하고 있을까?
	
	cout << "배열의 크기 : " << sizeof(str) << endl;	//8
	cout << "문자열 길이 : " << strlen(str) << endl;	//7

	return 0;
}