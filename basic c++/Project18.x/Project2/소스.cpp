//이번에는 아우풋스티림(ostream)으로 출력할때 옵션을 조금더 상세하게 조절하는 방법에 대해서 설명해 드리겠습니다.
//당연히 엄청 많아서 전부는 설명해드리지 못하고 일부분만 설명해드리겠습니다.
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	//iostream의 최상의 클래스 ios_base 에는 입출력 형식을 바꿀수 있습니다.
	//숫자위주로 말씀드리겠습니다.

	//1 setf 함수로 스트림의 설정을 바꿀수 있습니다.
	cout.setf(ios::showpos); //이번에는 한번 +기호를 출력하는 showpos를 해보겠습니다. 
	cout << 108 << endl;
	//+108

	cout.unsetf(ios::showpos); //unsetf로 없앨수 있다 
	cout << 109 << endl;
	//109

	cout.setf(ios::hex); //16진수로 출력해줄수 있습니다.
	cout.unsetf(ios::dec); //대신 10진수를 꺼줘야지 16진수로 출력합니다
	cout.setf(ios::uppercase); //이렇게 하면 대문자로 출력해준다
	cout << 108 << endl;
	//6C

	cout.setf(ios::hex, ios::basefield); //인자가 2개일 경우 basefield의 내용을 초기화 하고 hex를 적용해주는 방식입니다.
	//수를 처리하는 방식은 1가지 진수만 처리할 수 있으므로 몇진법으로 수를 처리할지 보관하는 basefield를 초기화하고 hex 플래그를 적용시킨 것입니다.
	cout << 108 << endl;
	//6c

	cout << std::hex; //이렇게 사용할수도 있습니다.
	cout << 108 << endl;
	//6c

	cout << true << false << endl;
	cout << std::boolalpha; //bool값을 출력해줄때 1, 0을 true, false로 출력해준다
	cout << true << false << endl;
	//10
	//truefalse

	//출력할때 float를 기본으로 출력해줍니다.
	cout << std::defaultfloat;

	//setprecision는 출력할때 소수점을 조절해 줍니다.
	cout << std::setprecision(5) << 123.456 << endl;
	//123.46 (왜 6이지? 반올림 해서 그렇습니다)

	//fixed를 해주면 setprecision의 수만큼 소수점을 고정해줍니다
	cout << fixed;
	cout << std::setprecision(5) << 123.456 << endl;
	//123.45600

	//scientific는 지수표현식으로 출력해줍니다.
	cout << scientific; 
	cout << std::setprecision(5) << 123.456 << endl;
	//1.23456e+02

	//showpoint는 소수점이 나오게 해줍니다.
	cout << showpoint;
	cout << std::setprecision(3) << 123.456 << endl;
	//123.
	
	//앞에서 배운 setw함수 또한 출력에서 사용하실수 있습니다.
	cout << setw(10) << -1234 << endl; 	//매개변수 만큼 폭을 정렬해줍니다.
	cout << setw(10) << std::left << -1234 << endl; //왼쪽으로 정렬해주고 매개변수 만큼 폭을 정렬해줍니다.
	cout << setw(10) << std::right << -1234 << endl;//오른쪽으로 정렬해주고 매개변수 만큼 폭을 정렬해줍니다.
	cout << setw(10) << std::internal << -1234 << endl;//부호는 왼쪽에, 숫자는 오른쪽에 정렬해주고 매개변수 만큼 폭을 정렬해줍니다.
	//     -1234
	//-1234     
	//     -1234
	//-     1234

	//fill은 빈칸을 매개변수로 바꿔줍니다.
	cout.fill('*');
	cout << setw(10) << -1234 << endl;
	//*****-1234


	//끝

	return 0;
}