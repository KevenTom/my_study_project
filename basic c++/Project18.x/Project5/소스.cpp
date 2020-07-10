//어떤 문자열이 우리가 원하는 형식에 맞춰져 있는지, 아니면 안맞춰져 있는지 판별하는것은 중요한 문제겠죠
//예를들면 사용자로부터 입력받은 문자열 데이터가 이메일주소를 의미하는건지 아닌지 이메일을 표현할수 있는 최소한의 조건을 만촉시키고 있는건지 아닌지 판별하는거, 혹은 파일로 읽은 문자열 데이터가 우편인지, 전화번호인지
//앞 강의에서 입력이 유효한지 검사하는 방법을 말씀드렸는데요 사실 이걸 일일히 하나하나 구현하는것은 그렇게 간단한일은 아닙니다.
//여기서는 이런 경우에 편하게 사용할 수 있는 정규 표현식(regular expressions)을 소개해 드리겠습니다.
#include<iostream>
#include<regex>

using namespace std;

int main() {
	//1 정규식은 웹 프로그래밍에서 좀더 민감하고 많이 사용합니다. 이메일이 맞는지 암호가 맞는지
	//2 c++에서는 regex가 있습니다. 복잡해 보일수 있지만 이해하시면 어렵지않게 사용하실수 있습니다.
	regex re("\\d"); //3 백슬레쉬 하나는 뒤에 있는 백슬레쉬가 진짜 백슬레쉬라는 뜻이고 \d 는 우리가 \n 처럼 작동한다. \d는 숫자냐? 라는 판별하는 의미를 뜻합니다. 
	
	//6 그러면 여러글자를 입력받으려면 어떻게 해야할까 //d+ 해주면 된다. +를 붙이면 한개 이상의 글자다 라는 의미다.
	//백슬레쉬가 거슬리다면 regex re("[ab]+"); 이렇게 해주면 된다. 괄호 안에 있는게 조건이다.
	//몇개를 정해놓고 받고 싶다면? ("[[:digit:]]{3}") /d를 3개를 딱 맞춰야 한다는 겁니다.
	//("[A-Z]+") 이건 어떤 의미일까요 알파펫 A부터 Z까지 이고 갯수는 상관없다.
	//("[A-Z]{1, 5}") 이건 최소하나 최소 5개
	//("([0-9]{1})([-]?)([0-9]{1, 4})") 이건 0부터 9까지 수를 하나만 받겠다. -가 있어도 되고 없어도 된다. 0부터 9까지 1개이상 4개이하면 ok다
	/*0*/
	//No Match
	/*0-0*/
	//Match
	/*1-1234*/
	//Match
	/*13456*/
	//Match
	/*1-34567*/
	//No Match
	//더 알고싶으면 여러분이 검색하면서 조건을 만들면서 나아가시면 됩니다. 끝 http://www.cplusplus.com/reference/regex/ECMAScript/

	string str;
	while (true) {
		getline(cin, str);
		if (regex_match(str, re)) //4 전 강의에서는 if문으로 막 조건 만들고 힘들었죠, regex_match를 넣어주면 위에 설정한 규칙에 맞는지 안맞는지 판단해 줍니다. 간단해지죠
			cout << "Match" << endl; //즉, 정규식에서는 내가 원하는 규칙을 어떻게 표현하는지가 관건입니다.
		else
			cout << "No match" << endl;

		//print matches
		auto begin = std::sregex_iterator(str.begin(), str.end(), re); //5 regex_iterator는 문자열에서 정규 표현식으로 매칭된 문자열들을 주르륵 뽑아낼 수 있는 반복자 입니다.
		auto end = sregex_iterator(); //sregex_iterator 는 regex_iterator 중에서 string 을 사용하는 반복자 입니다
		for (auto itr = begin; itr != end; ++itr) { //++ 연산자로 증감 될 때마다 regex_search 를 통해 조건에 맞는 문자열을 검색합니다.
			smatch match = *itr; //smatch는 string 형태로 돌려줍니다.
			cout << match.str() << " ";
		}
		cout << endl;
		/*2*/ //정상적으로 매치가 됩니다.
		//Match
		//2
		/*123*/ //여러개를 입력해서 매치가 안되는 겁니다.
		//No Match
		//1 2 3 
	}

	return 0;
}