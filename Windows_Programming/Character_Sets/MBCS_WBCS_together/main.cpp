#include<iostream>
#include<Windows.h>
#include<tchar.h>

//#define UNICODE	//주석처리 했는데 왜 WBCS로 작동하는거지?
//#define _UNICODE	//비쥬얼스튜디오에서 프로젝트 생성시 기본적으로 정의되어 있기 때문

using namespace std;

int main() {
	TCHAR str[] = _T("test테스트중");
	wcout << "배열의 크기 : " << sizeof(str) << endl;

	return 0;
}