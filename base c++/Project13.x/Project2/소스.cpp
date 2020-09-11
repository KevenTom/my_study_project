//함수 템플릿에서 템플릿을 사용하면 편하다라는걸 알수 있었습니다.
//이번에는 클래스를 템플릿 하는 방법에 대해 알아봅시다.
#include<iostream>
#include"Myarray.h" //1 헤더파일에 어레이 클레스를 만듬

using namespace std;


int main() {
	//5 2Myarray my_array(10); //4 어? 오류가 뜨네?
							//오류를 읽어보면 매개변수에 들어갈 인자가 설정이 안됬다고한다.

	Myarray<char> my_array(10); //5 2이렇게 설정해주면 된다.

	//11 2위를 보면 컴파일러가 "myarray라는 클래스를 char 라는 데이터타입에 대해서 인스턴시에이션을 해야하는 거구나" 라는 것까지는 알수 있다.
	//그런데 myarray.h 에서 void print(); 의 바디를 컴파일을 할때는 myarray.cpp 에서 컴파일을 하잖아요
	//그런데 메인에서는 "Myarray.h"만 인클루드 하기 때문에 myarry.cpp 에 char 타입으로 해야한다는 내용은 몰라요
	//그렇다면 메인에 #include"Myarray.cpp"를 인클루드 하면 해결할수 있겠죠?? 해결할 수 있지만 이러면 나중에 걷잡을수 없을 정도로 문제가 생기기 때문에 절떄 이런 방법은 X

	//인터넷에서 본 정리 : https://m.blog.naver.com/PostView.nhn?blogId=swkang7229&logNo=220160000206&proxyReferer=https:%2F%2Fwww.google.com%2F

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print(); //2 문제없이 출력하는것을 확인할 수 있습니다.

	return 0;
}