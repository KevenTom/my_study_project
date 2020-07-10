//지금까지 살펴본 입출력스트림은 콘솔창에 출력창에 입력받거나 내보넸죠
//이번에는 문자열 흐름의 버퍼 역할을 하는 string stream에 대해 알아보겠습니다.
#include<iostream>
#include<sstream> //1 sstream 인클루드 해줘야 한다.
//sstream이란 string stream의 약자로, 스트림에 들어있는 문자열 객체들을 조작하는데 사용됩니다.
using namespace std;

int main() {
	//2 stringstream으로 만들수 있습니다.
	stringstream os;

	//이렇게 문자를 넣어줄 수 있습니다.
	//참고로 그때까지 사용한 "<<" 이거는 insertion operator 한마디로 집어 넣는거고 >> 이거는 extraction operator 데이터를 뽑아온다고 생각하시면 됩니다.
	os << "Hello world!";
	os.str("Hello world!2"); //이렇게 해줄수도 있습니다.
	string strr;
	strr = os.str(); //strr에 os에 있는것을 통째로 가져온다는 뜻입니다.
	cout << strr << endl;
	//Hello world!2
	// <<는 안에 계속 넣고 넣고 쌓는 방식이고 str은 전체를 바꾼다고 생각하면 됩니다. (참고로 << endl 도 끝내는게 아니라 endl을 넣어줍니다.)

	//int 같은 숫자로도 동일하게 작동합니다.
	int i = 12345;
	double d = 67.89;
	os << i << " " << d;
	int i2;
	double d2;
	os >> i2 >> d2; //앞에서 말한대로 >>로 os에 있는 데이터를 뽑아왔습니다. 
	cout << i2 << " " << d2 << endl;
	//12345 67.89


	//str("") 해주면 빈칸이니까 안에 있는걸 싹 비워줌
	os.str("");

	//위의 코드들을 보면 알겠지만 str에는 파라미터가 없으면 리턴하고 있으면 있는대로 설정한다는 것을 알수 있습니다.
	os.str(""); //파라미터로 초기화(공백이니까 비어버림)
	os.str(); //안에있는걸 통째로 리턴


	//clear는 플래그를 초기화 해줍니다. 그렇담 완벽하게 초기화 하려면 앞에 os.str(""); 를 붙이시면 됩니다.
	os.clear();


	//이런 자잘한 용법을들 보여드리는 이유는 
	//c++의 표쥰적인 구현스타일을 이렇다는 감을 잡아줬으면 좋겠다는 거지만 
	//그렇다고 따라하실 필요는 없다는걸 알려드리기 위함입니다.


	return 0;
}