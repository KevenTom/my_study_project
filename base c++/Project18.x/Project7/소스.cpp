//파일입출력을할때 항상 순차적으로만 작업할수 있는건 아니겠죠
//이미 존재하는 파일의 중간에 필요한 부분을 찾아서 그부분만 일부 수정할수도 있을거고 또 전체 커다란 파일에서 필요한 부분만 읽을수도 있습니다.
//파일의 임의 위치 접근하는 방법을 설명해 드리겠습니다.
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	if (true) {
		const string filename = "my_file.txt";

		//make file
		//1 a부터 z까지 파일에 입력중입니다.
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;


		//read the file
		//2 filename을 읽는데 전 강의랑은 약간 다릅니다.
		ifstream ifs(filename);

		ifs.seekg(5); //seekg은 처음에서 5바이트 이동하라는는 뜻입니다.
		cout << (char)ifs.get() << endl;
		ifs.seekg(5, ios::cur); //cur은 현재 읽은 위치에서 5바이트 이동한다는 뜻입니다.
		cout << (char)ifs.get() << endl;
		cout << (char)ifs.get() << endl; //get을 계속 적어주니까 연속으로 읽어줍니다.
		ifs.seekg(2); //seekg을 하니까 다시 처음부터 읽어주는것을 알수 있습니다.
		cout << (char)ifs.get() << endl;
		ifs.seekg(-5, ios::end); //end는 끝으로 이동한다는 뜻입니다
		cout << (char)ifs.get() << endl;
		ifs.seekg(0, ios::end);
		cout << ifs.tellg() << endl; //tellg는 현재위치를 알려줍니다.
		ifs.seekg(10);
		string str;
		getline(ifs, str); //이러면 10바이트 뒤부터 getline을 해주겠죠
		cout << str << endl;
		//f
		//l
		//m
		//c
		//x
		//28
		//klmnopqrstuvwxyz
		//실행하면 잘 작동하는것을 알수 있습니다.


		//3이번에는 읽기도 하고 쓰기도 하는 방법을 알아보겠습니다.
		fstream iofs(filename); //ofstream도 아니고 ifstream도 아닌, 그냥 fstream으로 초기화해주시면 됩니다.

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; //읽기도 하고
		iofs.seekg(5);
		iofs.put('A');//put으로 쓰기도 합니다.
		iofs.seekg(5);
		cout << (char)iofs.get() << endl; //다시 읽어봤습니다.
		//f
		//A
		//잘 작동합니다 끝
	}



	return 0;
}