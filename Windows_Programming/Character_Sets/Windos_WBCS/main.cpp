#include<iostream>

using namespace std;

int wmain(int argc, wchar_t* argv[]) {
	//wmain �Լ��� ���޵Ǵ� ���ڿ��� WBCS ������� ����� �ݴϴ�.
	//�翬�� ���� ���� wchar_t �ڷ������� �޾ƾ� �մϴ�.

	wcout.imbue(std::locale(""));	//wcout �������� �ý��� �����Ϸ� ������ �ݴϴ�.
	wcout << L"Hello, �ȳ�, ����, ���Ϫ誦" << endl;	//wcout�� WBCS ������� �����

	for (int i = 0; i < argc; ++i)
		wcout << "argv[" << i << "] = " << argv[i] << endl;


	return 0;
}