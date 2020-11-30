#include<iostream>

using namespace std;

int wmain(int argc, wchar_t* argv[]) {
	//wmain 함수는 전달되는 문자열을 WBCS 기반으로 만들어 줍니다.
	//당연히 인자 또한 wchar_t 자료형으로 받아야 합니다.

	wcout.imbue(std::locale(""));	//wcout 로케일을 시스템 로케일로 설정해 줍니다.
	wcout << L"Hello, 안녕, 人事, おはよう" << endl;	//wcout은 WBCS 기반으로 사용함

	for (int i = 0; i < argc; ++i)
		wcout << "argv[" << i << "] = " << argv[i] << endl;


	return 0;
}