//STL에는 다양한 컨테이너들이 정의되어있습니다. 이 다양한 정이의 컨테이너들을 공통적인 방법으로 접근할수 있는 반복자(iterators)라는 것이 정의되어 있습니다.
//반복자를 처음보면 생소하실수 있습니다.
//http://tcpschool.com/cpp/cpp_iterator_intro 정의가 궁금하면 이거 보셈
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>

using namespace std;

int main() {
	//1 기본적인 백터입니다.
	vector<int> container;
	for (int i = 5; i < 15; ++i)
		container.push_back(i);

	vector<int>::const_iterator itr; //2 이렇게 반복자 자체를 변수로 만듭니다. 그냥 iterator도 있습니다. const는 말 그대로 const인 거겠죠
	//그러니까 백터 인트타입에 해당하는 인터레이터타입의 itr을 만드는 겁니다.
	itr = container.begin(); //itr을 초기화를 할때 begin을 가져옵니다.
	while (itr != container.end()) { //컨테이너의 앤드가 아닐때까지 반복하겠죠
		cout << *itr << " ";
		++itr;
	}
	cout << endl;
	//이터레이터는 다른 컨테이너에서도 일관되게 사용할수 있다는 장점이 있습니다.
	//그런데 아 뭔가 itr 만들고 길고 번거롭죠
	//전 강의에 사용한 범위 for문을 사용하거나
	for (auto itr2 = container.begin(); itr2 != container.end(); ++itr2)
		cout << *itr2 << " ";
	cout << endl;
	//이렇게 사용하셔도 됩니다.

	//3 리스트를 사용하고싶다면 어떻게 하면 되죠?
	list<int> container2; //4 이렇게 list로만 바꿔주면 간단하게 해결됩니다.
	for (auto itr2 = container2.begin(); itr2 != container2.end(); ++itr2)
		cout << *itr2 << " ";
	cout << endl;
	//당연히 내부적으로 저장방식이나 순서는 당연히 다릅니다.
	// set, map 또한 사용하실 수 있습니다. 끝
	

	return 0;
}