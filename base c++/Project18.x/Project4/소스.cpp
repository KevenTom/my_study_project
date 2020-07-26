//사용자로부터 입력을 받아드릴때 혹은 파일로부터 데이터를 읽어들일때 항상 우리가 의도한대로 입력이 들어온다는 보장이 없죠
//그래서 매번 스트림의 현재 상태가 어떤지, 그리고 입력받은 데이터가 우리가 의도한것과 유호한지(validation) 확인하는 과정이 필요할겁니다. 이 두가지에 대해서 알아봅시다.
#include<iostream>
#include<cctype>
#include<string>
#include<bitset>

using namespace std;

void printStates(const std::ios& stream) { //3 파라미터로 ios를 받습니다. 부모로써 높은 클래스죠 
//ios클래스로는 입출력 작업의 상태를 처리할수 있습니다. 또한 파일, 콘솔 두개다 공통적으로 사용하실수 있습니다.
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl; //good 정상적으로 작동했는지 체크함
	cout << "eof()=" << stream.eof() << endl; //eof 파일을 다 읽었는지 채크함
	cout << "faill()=" << stream.fail() << endl; //fail 실패했는지 체크함
	cout << "bad()=" << stream.bad() << endl; //bad 오류가 발생하는지 체크함
} //또는 ios::rdstate 로 비트플래그로 받아올수 있지만 잘 사용하지는 않는다고 함 http://www.cplusplus.com/reference/ios/ios/rdstate/ 길음 6분부터 ㄱㄱ

void printCharacterClassification(const int& i) {//6 아래의 std::들은 cctype에 들어있습니다. 뭐가뭔지 모른다면 검색 ㄱ
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl; //커서를 갖다대보면 int로 리턴해 줍니다. 그래서 이번에는 bool로 캐스팅해 봤습니다
	cout << "isblank " << bool(std::isblank(i)) << endl; //97을 입력하면 아스키코드로 'a'임 정상적으로 작동함
	cout << "isdigit " << bool(std::isdigit(i)) << endl; //빈칸을 입력해도 blank는 작동하지 않는다. 당연히 cin에서는 띄어쓰기를 구분하는 용도로 사용한다고 저번에 배웠죠
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;
}

bool isAlldigit(const string& str) { //8 보시면 알겠지만 하나하나 검증하는 방식입니다. 끝
	bool ok_flag = true;
	for (auto& e : str)
		if (!isdigit(e)) {
			ok_flag = false;
			break;
		}
	return ok_flag;
}

int main() {
	while (true) {
		int i;
		cin >> i; //1 int 타입이니까 숫자가 들어가야 하는데 문자가 들어올경우 문제가 생기겠죠

		printStates(cin); //2 그래서 스트림이 어떤 상태인지 확인하는 함수를 만들어 봤습니다.
		cout << i << endl;
		printCharacterClassification(i); //5 또는 상태를 확인하는거 외에 내가 원하는 문자인지를 검증하는 방법도 있습니다.

		cin.clear();
		cin.ignore(1024, '\n'); //4 ignore에 인자도 넣을수 있습니다. 읽어들일 문자의 개수, 읽어들이면 종료할 문자
	}


	//7 입력을 받을때 우리가 정말 원하는 형태로 왔는지 확인을 해야할때가 많습니다.
	//지금 가르쳐 드리는거는 한글자한글자 다 비교하는 방식입니다. 다음 강의에 배울 졍규포현식(regular expression)을 사용하면 훨씬 편해집니다.
	//요즘은 정규표현식으로 사용한다고 합니다.
	cout << boolalpha;
	cout << isAlldigit("1234") << endl;
	cout << isAlldigit("a1234") << endl;


	return 0;
}