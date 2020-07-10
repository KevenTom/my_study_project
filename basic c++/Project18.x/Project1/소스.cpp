//지금까지 iostream으로 입력을 받기도 하고 출력을 하기도 했죠
//이번에는 istream에 대해 좀더 알아보겠습니다
//참고로 입력하거나 출력하는 데이터를 스트림(stream)이라 부른다.
//그리고 강의해주는 거는 이런게 있고 피료하면 찾아가고 자기에 맞게 변형하면서 사용하는게 좋은 코딩이라고 한다.
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main() {
	//1 지금까지 평범하게 사용해온 것들을 내부구조가 어떻게 작동하는지 알아봅시다.
	//기본적으로 stream은 버퍼에 임시적으로 저장되어 있는걸 일부 꺼내오는 방식입니다.
	char buf[5];
	cin >> buf;
	cout << buf << endl;
	/*abcdefgh...*/
	//runtime error
	//cin으로 입력받은 버퍼를 buf의 크기 이상을 주려고 하니까 오류가 발생하죠

	//iomanop는 출력 포맷 조작을 위한 기능을 제공합니다.
	//iomanop에 정의되어 있는 setw 함수는 
	//입력에서 setw는 매개변수 만큼만 버퍼에서 빼고 buf1에 넣어 줍니다.
	//출력도 있지만 그건 다음 강의에 말씀드리겠습니다.
	char buf1[5];
	cin >> setw(5) >> buf1;
	cout << buf1 << endl;
	/*abcdefgh...*/
	//abcd
	//많이 입력해도 매개변수만큼 넣어준것을 확인할 수 있습니다.
	//그런데 매개변수는 5인데 왜 4개만 출력될까요? 
	//당연히 마지막에 널이 있어야 하니까 널까지 합치면 5개죠

	//그러면 버퍼에 있는 나머지는 어떻게 될까요? 계속 버퍼에 있습니다.
	cin >> setw(5) >> buf1;
	cout << buf1 << endl;
	/*abcdefgh*/
	//abcd
	//efgh
	//글자를 많이 입력해보면 두번 입력하지 않아도 알아서 버퍼에 남은것들을 가져왔던것을 확인할 수 있습니다. 
	//이렇듯 버퍼로부터 순차적으로 가져오는 방식입니다.


	//2 반복문으로 글자 하나하나를 계속 받는 방법도 있습니다.
	char ch;
	while (cin >> ch)
		cout << ch;
	/*Hello word*/
	//Helloword
	//프로그래밍 하다보면 띄어쓰기도 포함시키고 싶을때가 많습니다.
	//우리가 cin으로 입력할때 띄어쓰기에 따라 구분되죠.
	//그러면 빈칸도 포함해서 받으려면 어떻게 해야 할까요

	//cin.get() 을 사용하시면 됩니다.
	char ch1;
	while (cin.get(ch1))
		cout << ch1;
	/*Hello word*/
	//Hello word

	//get도 범위를 지정해줄수 있습니다.
	//당연히 넘어가서 남은것은 버퍼에 그대로 있습니다.
	char buf2[5];
	cin.get(buf2, 5);
	cout << buf2 << endl;
	/*ABCDEF*/
	//ABCD

	//마찬가지로 버퍼에 있는것들을 get으로도 가져올수 있습니다.
	//그리고 gcount 라는 함수가 있습니다. 간단하게 입력받을때 몇글자 읽었는지 출력해주는 함수입니다.
	char buf3[5];
	cin.get(buf3, 5);
	cout << cin.gcount() << " " << buf3 << endl;
	cin.get(buf3, 5);
	cout << cin.gcount() << " " << buf3 << endl;
	/*a bcd fg*/
	//4 a bc
	//4 d fg


	//3 그리고 getline 함수라는것도 있습니다.
	char buf4[5];
	cin.getline(buf4, 5);
	cout << cin.gcount() << " " << buf4 << endl;
	cin.getline(buf4, 5);
	cout << cin.gcount() << " " << buf4 << endl;
	/*abcdefg*/
	//4 abcd
	//0
	//약간 다르게 작동하죠 getline은 한줄을 다 읽어들이고 5개 만큼 받아들이고 나머지 버퍼를 비워버린 겁니다.
	//4글자 이하로 두줄을 입력하면 정상으로 작동합니다.
	//그리고 getline은 카운터가 +1 일때가 있는데 이유는 줄바꿈까지 같이 읽어서 그런다고 합니다.


	//4 string도 사용하실 수 있습니다.
	string buf5;
	getline(cin, buf5); //여기의 getline함수는 string에 있는겁니다.
	cout << cin.gcount() << " " << buf5 << endl;
	//출력해보면 gcount가 0입니다 cin.으로 읽은게 아니까 0이 나오는 겁니다.


	//5 ignore는 숫자만큼 무시해 줍니다.
	char buf6[1024];
	cin.ignore(2);
	cin >> buf6;
	cout << buf6 << endl;
	/*Hello*/
	//llo


	//6 peek은 버퍼에서 말 그대로 peek 처럼 꺼내지 않고 보기만 한다고 생각하시면 됩니다.
	char buf7[1024];
	cout << (char)cin.peek() << endl;
	cin >> buf7;
	cout << buf7 << endl;
	/*Hello*/
	//H
	//Hello


	//7 unget은 get의 반대죠
	//마지막에 읽은것을 다시 버퍼에 도로 넣습니다.
	char buf8[1024];
	cin >> buf8;
	cout << buf8 << endl;
	cin.unget();
	cin >> buf8;
	cout << buf8 << endl;
	/*Hello*/
	//Hello
	//o


	//8 putback은 파라미터를 버퍼에 넣어주는 기능입니다.
	char buf9[1024];
	cin >> buf9;
	cout << buf9 << endl;
	cin.putback('A');
	cin >> buf9;
	cout << buf9 << endl;
	/*Hello*/
	//Hello
	//A


	//그리고 지금까지 소개해드린 기능은 단순히 콘솔에서만 사용하는게 아니고 
	//나중에 파일을 입출력을 할때도 똑같이 사용하실수 있습니다. 끝


	return 0;
}