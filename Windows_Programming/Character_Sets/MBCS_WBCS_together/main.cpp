#include<iostream>
#include<Windows.h>
#include<tchar.h>

//#define UNICODE	//�ּ�ó�� �ߴµ� �� WBCS�� �۵��ϴ°���?
//#define _UNICODE	//�����Ʃ������� ������Ʈ ������ �⺻������ ���ǵǾ� �ֱ� ����

using namespace std;

int main() {
	TCHAR str[] = _T("test�׽�Ʈ��");
	wcout << "�迭�� ũ�� : " << sizeof(str) << endl;

	return 0;
}