//shard�����͸� ����ҋ� �߻��Ҽ� �ִ� ��ȯ������ ������ �ذ��ϱ� ���� weak_ptr�� �˾ƺ��ڽ��ϴ�.
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
		return m_partner.lock(); //4 2 Ŀ���� ���ٴ�� lock�Լ��� ȣ�� �ϸ� ����������ͷ� �������ݴϴ�. �� ����������ͷ� �ٲ㼭 ��� �մϴ�.
	}

	const string& getName() const {
		return m_name;
	}
};

int main() {
	auto lucy = make_shared<Person>("Lucy");
	auto ricky = make_shared<Person>("Ricky");
	//1 �츮�� ����Ʈ�����͸� ����ϴ� �⺻���� ������ �Ű�Ⱦ��� �޸��� �� �����޶�� ��������
	//�ϴ� �������� �� ����ȴٴ°��� �� �� �ֽ��ϴ�.

	partnerUp(lucy, ricky);
	//2 ��Ʈ�ʾ��� �ϸ� ��Ʈ�ʰ� ������ �Ǵµ� �Ҹ��ڰ� �ȵǰ� �޸𸮸��� �Ͼ�� �� �� �ֽ��ϴ�.
	//������ ���� Person ��ü�� ������Դϴ�. ��, Person�� ������� �Ҷ� m_partner�� ���� ������� �ϰ��� �ٵ� �̶� ī���Ͱ� �Ǿ�����ϴ�.
	
	//3 2�̶� weak_ptr�� ����Ͻø� �˴ϴ�.
	//�����ϸ� �����۵��ƴ� ���� �� �� �ֽ��ϴ�.
	//4 2�׷��� shared �������� weak�� ���� ���� �ʳ�, weak�� ���빰�� ����ϽǶ� lock�� ����� �մϴ�.
	//�׷��� weak �����ʹ� ���� ����Ҽ� ���� lock�ؼ� ����������ͷ� ���� �� ����������ͷ� ������ �Ҽ� �ִ� �����Դϴ�.
	//�ٲ㸻�ϸ� ��ȯ�������� ���� ���ؼ� �̷��� ������ ������� �ִ� �̴ϴ�.

	cout << lucy->getPartner()->getName() << endl;
	//5 ��ó�� ����ϼž� �մϴ�. ��

	return 0;
}