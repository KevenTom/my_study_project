//move semantics가 구체적으로 어떻게 작동하고 어떻게 구현이 되고 어떻게 이득을 줄 수 있는지 이동 생성자(move constructors)와 이동 대입(move assignmenet)에 대해 알아봅시다.
#include<iostream>
#include"Timer.h"
#include"Resource.h" //1 전강의에 사용한 코드를 헤더파일로 추가하고 약간 변경사항이 있습니다.
#include"Autoptr.h"

using namespace std;

Autoptr<Resource> generateResource() {
	Autoptr<Resource> res(new Resource(10000000));
	return res;
}

int main() {
	streambuf* orig_buf = cout.rdbuf();

	//6 자 이제 한번 실행해 봅시다.
	//7 복잡하지만 디버그로 어떻게 진행하는지 확인해 보는게 좋음
	//8 참고로 프로그램의 시간을 재는데 이게 로그가 출력될때 시간도 포함이 되는거라서 이번에는 로그출력을 버퍼와 끊어보겠습니다.
	//cout.rdbuf(NULL);
	//안끊었을때 : 0.14047, 버퍼 끊었을때 : 0.125919 이처럼 차이는 미묘하지만 나중에 시간재거나 하실때 화면의 로그나 파일출력 이런거는 시간이 오래 걸리기 때문에 끄고 하시는게 좋습니다.
	//10				   버퍼 끊었을때 : 0.0237393 엄청나게 차이가 나죠
	//이처럼 deep copy로 인한 시간 차이가 많이 난다는걸 알 수 있습니다.
	//디버그로 찍어봐서 전과 차이점을 로그를 확인해 보면 deep copy를 하지 않았다는걸 알 수 있습니다. 그러니까 훨씬 빠를수밖에 없습니다.

	Timer timer;

	{
		Autoptr<Resource> main_res;
		main_res = generateResource(); //12 즉, generateResource란 함수가 리턴해서 받은것은 R벨류죠 
		//그러니까 전처럼 deep copy를 하지 않고, R벨류로 받아서 포인터를 그냥 shallow copy, 얕은복사를 해주는 거지만! 문맥상으로는 얕은복사 이지만! 
		//"의미상으로는 move assignment를" 해준다고 표현하는게 맞겠죠?
		cout << "123test" << endl; //xx 디버그확인용도임, 보면 generateResource에서 리턴받은 "res를" 먼저 delete 하고 그 후에 스코프 넘어가면 main_res 함
	}


	cout.rdbuf(orig_buf);
	timer.elapsed();

	return 0;
}