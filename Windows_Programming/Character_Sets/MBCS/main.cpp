#include<iostream>

using namespace std;

int main() {
	char str[] = "ABC한글";
	
	int size = sizeof(str);
	int len = strlen(str);

	//ABC(3바이트) + 한글(4바이트) + NULL(1바이트) = 8바이트
	//다양한 바이트 수를 사용한다 -> 이는 MBCS를 기반으로 실행된다는 것을 알 수 있다.
	cout << "배열의 크기 : " << size << endl;

	//ABC(3바이트) + 한글(4바이트) = 7바이트
	//실제로는 5글자 지만 7글자로 인식하고 있다. 이것이 MBCS의 문제점 이다.
	cout << "문자열 길이 : " << len << endl;


	return 0;
}