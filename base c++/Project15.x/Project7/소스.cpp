//shard포인터를 사용할떄 발생할수 있는 순환의존성 문제와 해결하기 위한 weak_ptr을 알아보겠습니다.
#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Person {
	string m_name;
	//3 2shared_ptr<Person> m_partner;
	weak_ptr<Person> m_partner;
public:
	Person(const string& name)
		:m_name(name) {
		cout << m_name << " created\n";
	}

	~Person() {
		cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(shared_ptr<Person>& p1, shared_ptr<Person>& p2) {
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		cout << p1->m_name << " is partnerd with " << p2->m_name << '\n';
		return true;
	}

	const shared_ptr<Person> getPartner() const {
		return m_partner.lock(); //4 2 커서를 갖다대면 lock함수를 호출 하면 쉐얼드포인터로 리턴해줍니다. 즉 쉐얼드포인터로 바꿔서 써야 합니다.
	}

	const string& getName() const {
		return m_name;
	}
};

int main() {
	auto lucy = make_shared<Person>("Lucy");
	auto ricky = make_shared<Person>("Ricky");
	//1 우리가 스마트포인터를 사용하는 기본적인 이유는 신경안쓰고 메모리좀 잘 지워달라는 목적이죠
	//일단 문제없이 잘 실행된다는것을 알 수 있습니다.

	partnerUp(lucy, ricky);
	//2 파트너업을 하면 파트너가 생성은 되는데 소멸자가 안되고 메모리릭이 일어난걸 알 수 있습니다.
	//원인을 보면 Person 자체가 쉐얼드입니다. 즉, Person을 지우려고 할때 m_partner를 같이 지우려고 하겠죠 근데 이때 카운터가 되어버립니다.
	
	//3 2이때 weak_ptr을 사용하시면 됩니다.
	//실행하면 정상작도아는 것을 알 수 있습니다.
	//4 2그러면 shared 쓰지말고 weak만 쓰면 되지 않냐, weak의 내용물을 사용하실때 lock을 해줘야 합니다.
	//그래서 weak 포인터는 직접 사용할수 없고 lock해서 쉐얼드포인터로 만들어서 그 쉐얼드포인터로 뭔가를 할수 있는 구조입니다.
	//바꿔말하면 순환의존성을 깨기 위해서 이렇게 구조가 만들어져 있는 겁니다.

	cout << lucy->getPartner()->getName() << endl;
	//5 이처럼 사용하셔야 합니다. 끝

	return 0;
}