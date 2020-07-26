//포인터가 가리키고 있는 데이터의 소유권이 한곳에 속할 경우에만 사용할수 있는 스마트포인터, unique_ptr 에 대해 살펴보겠습니다.
//전 강의에 사용한 auto_ptr의 진화한 형태죠
#include<iostream>
#include<memory> //2 unique_ptr은 memory.h에 있습니다.
#include"Resource.h"

using namespace std;

auto dosomething() {
	return std::make_unique<Resource>(5);

	//5 3당연히 함수안에서도 이렇게 해줄수 있죠
	//auto res1 = std::make_unique<Resource>(5);
	//return res1;
	//return std::unique_ptr<Resource>(new Resource(5));
}

//9 3auto dosomething2(unique_ptr<Resource>& res) { //8 2유니크 포인터를 파라미터로 넣고 함수를 보면 유니크포인터의 레퍼런스 &를 받고 있습니다.
//10 4auto dosomething2(unique_ptr<Resource> res) { //9 3그런데 만약 레퍼런스 말고 그냥 벨류로 쓰고 싶을때도 있죠 이렇게 하면 어떻게 될까요
auto dosomething2(Resource* res) {//10 4 이렇게 포인터를 직접 받는 방법도 있습니다.
	res->setAll(10);
}

int main() {
	//1 전에 사용한 예제입니다. 이런 상황에 첫 강의에서 unique_ptr를 사용했죠
	{
		//3 3Resource* res = new Resource(100000000);
		std::unique_ptr<Resource> res(new Resource(100000000)); //3 3이렇게 해주면 되고 delete도 없앴습니다. 실행하면 알아서 소멸자도 해주는 것을 알 수 있습니다.
		//이게 기본적인 유니크ptr의 역할이고요 이제 좀더 자세한 내용을 살펴보겠습니다.

		//early return or throw

		//3 3delete res;
	}
	cout << '\n' << endl;

	//4 이번에는 다른 예시를 봅시다.
	{
		std::unique_ptr<int> upi(new int); //보면 알겠지만 기본 자료형에도 얼마든지 사용할 수 있습니다.

		//5 3std::unique_ptr<Resource> res1(new Resource(5));
		//auto res1 = std::make_unique<Resource>(5); //조금 더 권장하는 방법은 make_unique를 사용하는 방법입니다. 
													//make_unique로 하면 무브시멘틱스를 사용하기 때문에 빠릅니다. 카피를 호출 안합니다.
		auto res1 = dosomething(); //5 3함수를 사용하는 방법도 있습니다.

		res1->setAll(5);
		res1->print();

		unique_ptr<Resource> res2; //6 이번에는 유니크 포인터를 하나 더 만들었습니다.

		//널값인지 아닌지 bool로 캐스팅 해서 출력해 보았습니다.
		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;
		cout << static_cast<bool>(res2) << endl;

		//res2 = res1; //유니크포인터는 복사를 못합니다. 에러가 뜨는것을 확인할 수 있습니다. 
						//첫줄에 말씀드린것처럼 유니크포인터는 소유권이 한곳에 속한 경우에만 작동하게 만들었기 때문에 ㅇㅇ
		res2 = move(res1); //때문에 무브시멘틱스만 사용할 수 있습니다.

		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;
		cout << static_cast<bool>(res2) << endl;
	}
	cout << '\n' << endl;


	//7 다른예제를 봅시다.
	{
		auto res1 = make_unique<Resource>(5);
		(*res1).setAll(1); //이렇게도 쓸수 있음
		(*res1).print();
		
		//이번에는 함수에서 리턴값으로 받는 것이 아닌, 파라미터로 집어 넣는 경우에 알아봅시다.
		//10 4dosomething2(res1); //8 2유니크 포인터를 파라미터로 넣고 함수를 보면 유니크포인터의 레퍼런스 &를 받고 있습니다.
		//9 3당연히 컴파일이 안되죠 왜냐면 유니크 성질 때문에
		//아니면 무브시멘틱스로 주는 방법도 있지만 그러면 데이터가 dosomething에서 소멸하고 res1이 널값이 되서 프린터가 안되죠 
		//물론 리턴으로 다시 받는 방법도 있습니다. 최근에는 이렇게 리턴해서 사용하기도 한답니다.
		dosomething2(res1.get()); //10 4 또는 포인터만 넘겨주고 작업해주는 방법도 있죠. 이렇게 포인터를 쓰기도 하고 위처럼 하기도 한답니다. 위의 방법을 추천하긴 했음
		//get은 유니크 자체가 갖고 있는 걸로 유니크에 데이터에 들어있는 포인터를 가져오는 겁니다.

		(*res1).print();
	}

	//11 마지막 예제입니다.
	//당연히 아래 예제는 하면 안되는 것들입니다.
	//res를 두개 주면 당연히 안되죠, 그리고 넘겨준걸 delete 해주면 당연히 안되죠 끝
	{
		Resource* res = new Resource;
		unique_ptr<Resource> res1(res);
		unique_ptr<Resource> res2(res);

		delete res;
	}


	return 0;
}