//지금까지 c++ 공부하면서 많은 예제를 만들어 왔습니다.
//더 나아가서 실무에서 다양한 프로젝트를 할때 "어? 전에 만들었던거 같은데 또 만드네" 라고 생각하실때가 많습니다.
//c++에서는 당연히 사용 가능한 여러가지 라이브러리들이 있는데
//그중 표준 템플릿 라이브러리(standard template libraries) 줄여서 STL와 컨테이너에 대해 소개해 드리겠습니다.
#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

void sequence_containers() {//참고로 미리 말씀드리면 사용하는 컨테이너 이름하고 헤더의 이름이 대부분 같습니다.
	//vector
	//첫번쨰로 우리가 가장 많이 사용해온 백터입니다.
	{
		vector<int> vec; //#include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);
		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	//deque
	//덱은 앞,뒤 하는거 알지?
	{
		deque<int> deq; //#include <deque>
		for (int i = 0; i < 10; ++i) {
			deq.push_back(i);
			deq.push_front(i);
		}
		for (auto& e : deq)
			cout << e << " ";
		cout << endl;
	}

}//associative_containers로 넘어가기전에 메뉴얼 보는법 먼저 알려드리겠습니다.
//https://en.cppreference.com/w/cpp/header 가시면 찾기로 백터를 클릭하면 조금 정신 없죠 뭐 일단 보면 초기화리스트 사용할수 있고 백터있고 오퍼레이터도 되어있고 
//사이즈도 있고 여러가지 있습니다. 그냥 천천히 보라고 한다 ㅋㅋ 궁금한 문법은 구글검색해서 보면 됨


void associative_containers() {
	//set
	//말 그대로 집합입니다.
	//특징은 원소가 중복이 되지를 않습니다.
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("Word");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}
	//multiset : duplication is allowed
	//멀티셋은 그냥 셋과 같은데 디플리케이션(중복)이 가능합니다.
	//근데 출력을 보면 순서가 다르죠 이는 set 성질 자체가 원소가 삽입되면 자동으로 정렬하기 때문입니다.
	{
		std::multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("Word");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}

	//map : key/value
	//맵이 유용하게 쓰입니다. 특히 웹프로그래밍 시작하면 json 이라는걸 배우거든요 json 구조가 이렇게 생겼습니다.
	//맵이란 맵핑 대응한다는 뜻입니다.
	{
		map<char, int> map;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50; //c를 위로 옮겨도 정렬된 순서로 출력합니다.

		cout << map['a'] << endl;
		map['a'] = 100;
		cout << map['a'] << endl;

		for (auto& e : map)
			cout << e.first << " " << e.second << " "; //first가 key고 second가 벨류입니다.
		cout << endl;
	}

	//multimap : duplication key
	{
		multimap<char, int> map;
		map.insert(pair('a', 10)); //c++14 에서는 pair<char, int>('a', 10) 이렇게 해줘야함 지금 c++17로 바꿔서 가능
		map.insert(pair('b', 10));
		map.insert(pair('c', 10));
		map.insert(pair('a', 100));

		cout << map.count('a') << endl; //count하면 해당하는 키의 원소가 몇개인지 알려줍니다.

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}
}

void container_adapters() {
	//stack
	{
		stack<int> stack;
		stack.push(1);		//push와 emplace의 차이는 push는 복사해서 넣는 겁니다.
		stack.emplace(2);	//emplace는 새로운 객체를 만들어서 집어 넣습니다.
		stack.emplace(3);
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
	}

	//queue
	{
		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.emplace(3);
		cout << queue.front() << " " << queue.back() << endl;
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl;
	}

	//Priority queue
	//얘는 큐인데 sort를 해줍니다.
	//사용자 정의 타입을 넣으면 크기를 비교 연산자를 오버로딩 해주셔야 합니다.
	{
		cout << "Priority queue" << endl;
		priority_queue<int> queue;

		for (const int n : {1, 8, 5, 7, 2, 3, 0, 9, 6, 4})
			queue.push(n);

		for (int i = 0; i < 10; ++i) {
			cout << queue.top() << endl;
			queue.pop();
		}
	}
}

int main() {
	//1 먼저 STL에 대해 말씀해 드리겠습니다.
	//위키같은곳에 검색하면 바로 볼 수 있습니다.(https://en.wikipedia.org/wiki/Standard_Template_Library)
	//여러가지가 있지만 교수님은 그중 펑션스는 잘 다루지 않는다고는 합니다.
	//STL와 c++ 스탠다드 라이브러리는 간단하게 얘기하면 c++ 스탠다드 라이브러리안에 STL이 있다고 생각하시면 됩니다.
	//보면 스탠다드 템플릿 라이브러리에는 크게 Containers, Iterators, Algorithms, Functions 이렇게 구분되어 있고 나머지는 거의다 스탠다드 라이브러리라고 생각하시면 됩니다.
	//예를들어 std::쓰레드 같은 경우에는 STL에 포함되지 않겠죠 하지만 사용할때는 쓸때는 그냥 갖다쓰면 되는 겁니다.
	//https://en.cppreference.com/w/cpp/header 보면 알겠지만 엄청 많다. 이걸 하나하나 다 알기에는 효율적이지 않기 때문에
	//간단하게 중요한거 몇몇개만 소개해 드리고 레퍼런스메뉴얼 보는 방법정도만 설명해 드리고 이후에 여러분들이 필요힐때 그때그때 찾아가시면서 프로그래밍하시면서 발전해나가시면 됩니다.
	
	//여기에서는 컨테이너에 대해 알아보겠습니다.
	//컨테이너는 크게 3가지라 나뉩니다.
	sequence_containers();
	associative_containers();
	container_adapters();
	//함수 정의로 이동해서 시퀀스 컨테이너부터 차근차근 보시면 됩니다.


	return 0;
}
