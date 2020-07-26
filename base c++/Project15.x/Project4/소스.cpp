//지금까지 강의에서 무브시멘틱스가 어떻게 작동하는지, 어떤 장점이 있는지 알아봤습니다. 주기적으로 무브시멘틱스를 사용하다보면 컴파일러의 해주는 결정이 아니라
//프로그래머 스스로 무브시멘틱스를 사용할지말지 결정을 하고싶을때가 있는데 이럴때 사용하는 std::move 함수에 대해 알아봅시다.
#include<iostream>
#include<vector>
#include"Autoptr.h"
#include"Resource.h"

using namespace std;

template<class T>
void MySwap(T& a, T& b) { //5 그런데 보면 카피컨스트럭터, 카피어사이먼트로 하니까 과정이 느리고 복잡한걸 알 수 있습니다.
	//6 2T tmp = a;
	//a = b;
	//b = tmp;

	//6 2 이번에는 무브시멘틱스를 이용하도록 해보겠습니다. 실행하면 빠르고 깔끔하게 진행됬다는 것을 알 수 있습니다.
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main() {
	//1 예제를 실행해 보면 당연히 L벨류니까 카피컨스트럭터가 실행되는것을 확인할 수 있습니다.
	{
		Autoptr<Resource> res1(new Resource(10000000));

		cout << res1.m_ptr << endl;

		//3 2Autoptr<Resource> res2 = res1; //2 만약 여기에서 카피컨스트럭터 말고 무브시멘틱스를 실행하고 싶다면 어떻게 해야할까요?
		Autoptr<Resource> res2 = std::move(res1); //3 2이렇게 std::move를 넣어주시면 됩니다. move 함수는 복잡한건 아니고 들어온걸 R벨류로 리턴을 해줍니다.
		//실행해보면 무브컨스트럭터가 실행된걸 확인할 수 있습니다.

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}
	cout << '\n' << endl;

	//4 이번에는 다른 예제입니다. Myswap으로 res1, res2를 바꿔서 출력해주는 코드입니다.
	{
		Autoptr<Resource> res1(new Resource(3));
		res1->setAll(3);

		Autoptr<Resource> res2(new Resource(5));
		res2->setAll(5);


		res1->print();
		res2->print();

		MySwap(res1, res2);

		res1->print();
		res2->print();
	}
	//7 주의하실점이 있는데 첫번째 예제에서는 res1이 res2에게 다 넘겨줬죠 그 후에 res1를 재활용 할지 말지는 프로그래머에게 달려있다는걸 숙지하는게 좋습니다.
	//즉, 한마디로 move 모르고 자주 사용하면 해깔려서 실수할 수도 있습니다.
	cout << '\n' << endl;


	//8 그리고 무브 시멘틱스가 std라이브러리 안에는 거의다 구현이 되어 있기 때문에 std::move를 사용하실 수 있습니다.
	{
		vector<string> v;
		string str = "Hello";

		v.push_back(str); //여길 커서로 갖다 대면 &가 하나 있다. 즉 str를 L벨류로 받아들인다. 즉 카피 시멘틱스를 사용하는 것을 알 수 있습니다.

		cout << str << endl;
		cout << v[0] << endl;

		v.push_back(move(str)); //커서를 갖다 대면 &&가 두개 있다. 즉 R벨류로 받아들인다. 즉 vector에 이미 무브시멘틱스가 구현되어 있다는 것을 알 수 있습니다.

		cout << str << endl; //출력을 보면 빈칸이 있는데 이건 str에 있던게 없어졌으니까 빈칸만 추력된겁니다.
		cout << v[0] << " " << v[1] << endl;
	}
	// 이를통해 vector에는 R벨류 레퍼런스에 대해서 푸시백이 별도로 구현되어 있다는 것을 알수 있습니다. 
	// 뭐 묵시적으로 컴파일된게 아니라 vector 만든 사람이 "R벨류는 이렇게 작동하게 만들자" 하고 만든겁니다. 끝

	return 0;
}