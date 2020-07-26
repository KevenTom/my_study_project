//���ݱ��� c++ �����ϸ鼭 ���� ������ ����� �Խ��ϴ�.
//�� ���ư��� �ǹ����� �پ��� ������Ʈ�� �Ҷ� "��? ���� ��������� ������ �� �����" ��� �����ϽǶ��� �����ϴ�.
//c++������ �翬�� ��� ������ �������� ���̺귯������ �ִµ�
//���� ǥ�� ���ø� ���̺귯��(standard template libraries) �ٿ��� STL�� �����̳ʿ� ���� �Ұ��� �帮�ڽ��ϴ�.
#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

void sequence_containers() {//����� �̸� �����帮�� ����ϴ� �����̳� �̸��ϰ� ����� �̸��� ��κ� �����ϴ�.
	//vector
	//ù������ �츮�� ���� ���� ����ؿ� �����Դϴ�.
	{
		vector<int> vec; //#include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);
		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	//deque
	//���� ��,�� �ϴ°� ����?
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

}//associative_containers�� �Ѿ������ �޴��� ���¹� ���� �˷��帮�ڽ��ϴ�.
//https://en.cppreference.com/w/cpp/header ���ø� ã��� ���͸� Ŭ���ϸ� ���� ���� ���� �� �ϴ� ���� �ʱ�ȭ����Ʈ ����Ҽ� �ְ� �����ְ� ���۷����͵� �Ǿ��ְ� 
//����� �ְ� �������� �ֽ��ϴ�. �׳� õõ�� ����� �Ѵ� ���� �ñ��� ������ ���۰˻��ؼ� ���� ��


void associative_containers() {
	//set
	//�� �״�� �����Դϴ�.
	//Ư¡�� ���Ұ� �ߺ��� ������ �ʽ��ϴ�.
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
	//��Ƽ���� �׳� �°� ������ ���ø����̼�(�ߺ�)�� �����մϴ�.
	//�ٵ� ����� ���� ������ �ٸ��� �̴� set ���� ��ü�� ���Ұ� ���ԵǸ� �ڵ����� �����ϱ� �����Դϴ�.
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
	//���� �����ϰ� ���Դϴ�. Ư�� �����α׷��� �����ϸ� json �̶�°� ���ŵ�� json ������ �̷��� ������ϴ�.
	//���̶� ���� �����Ѵٴ� ���Դϴ�.
	{
		map<char, int> map;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50; //c�� ���� �Űܵ� ���ĵ� ������ ����մϴ�.

		cout << map['a'] << endl;
		map['a'] = 100;
		cout << map['a'] << endl;

		for (auto& e : map)
			cout << e.first << " " << e.second << " "; //first�� key�� second�� �����Դϴ�.
		cout << endl;
	}

	//multimap : duplication key
	{
		multimap<char, int> map;
		map.insert(pair('a', 10)); //c++14 ������ pair<char, int>('a', 10) �̷��� ������� ���� c++17�� �ٲ㼭 ����
		map.insert(pair('b', 10));
		map.insert(pair('c', 10));
		map.insert(pair('a', 100));

		cout << map.count('a') << endl; //count�ϸ� �ش��ϴ� Ű�� ���Ұ� ����� �˷��ݴϴ�.

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}
}

void container_adapters() {
	//stack
	{
		stack<int> stack;
		stack.push(1);		//push�� emplace�� ���̴� push�� �����ؼ� �ִ� �̴ϴ�.
		stack.emplace(2);	//emplace�� ���ο� ��ü�� ���� ���� �ֽ��ϴ�.
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
	//��� ť�ε� sort�� ���ݴϴ�.
	//����� ���� Ÿ���� ������ ũ�⸦ �� �����ڸ� �����ε� ���ּž� �մϴ�.
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
	//1 ���� STL�� ���� ������ �帮�ڽ��ϴ�.
	//��Ű�������� �˻��ϸ� �ٷ� �� �� �ֽ��ϴ�.(https://en.wikipedia.org/wiki/Standard_Template_Library)
	//���������� ������ �������� ���� ��ǽ��� �� �ٷ��� �ʴ´ٰ�� �մϴ�.
	//STL�� c++ ���Ĵٵ� ���̺귯���� �����ϰ� ����ϸ� c++ ���Ĵٵ� ���̺귯���ȿ� STL�� �ִٰ� �����Ͻø� �˴ϴ�.
	//���� ���Ĵٵ� ���ø� ���̺귯������ ũ�� Containers, Iterators, Algorithms, Functions �̷��� ���еǾ� �ְ� �������� ���Ǵ� ���Ĵٵ� ���̺귯����� �����Ͻø� �˴ϴ�.
	//������� std::������ ���� ��쿡�� STL�� ���Ե��� �ʰ��� ������ ����Ҷ��� ������ �׳� ���پ��� �Ǵ� �̴ϴ�.
	//https://en.cppreference.com/w/cpp/header ���� �˰����� ��û ����. �̰� �ϳ��ϳ� �� �˱⿡�� ȿ�������� �ʱ� ������
	//�����ϰ� �߿��Ѱ� ���� �Ұ��� �帮�� ���۷����޴��� ���� ��������� ������ �帮�� ���Ŀ� �����е��� �ʿ����� �׶��׶� ã�ư��ø鼭 ���α׷����Ͻø鼭 �����س����ø� �˴ϴ�.
	
	//���⿡���� �����̳ʿ� ���� �˾ƺ��ڽ��ϴ�.
	//�����̳ʴ� ũ�� 3������ �����ϴ�.
	sequence_containers();
	associative_containers();
	container_adapters();
	//�Լ� ���Ƿ� �̵��ؼ� ������ �����̳ʺ��� �������� ���ø� �˴ϴ�.


	return 0;
}
