//����Ǳ����� �����غ����� �θ�Ŭ�������ٴ� �ڽ�Ŭ������ �� ���� ������ ������ ���� ��찡 ������ �ڽ�Ŭ�������� �θ�Ŭ������ �Ϲ����� ��캸�ٴ�
//�� ��ü�ϰ� �����Ǳ� ������ �߰����� ������ �Լ��� ������ ���� �� �ֽ��ϴ�.�� �Լ� �����ε��� �Ǿ������� ����
//�ٵ� ���࿡ ���� ���� �θ��� ��ü���ٰ� ���� ū �ڽ� ��ü�� ������ �����ϸ� ��� �ɱ��?
//�׷��� �θ��� ��ü�� ���� �� �ִ� ������ ���� ������ �ڽ�Ŭ�������� �ִ� �������� ��� �߷��� ���������
//�̷��� ���� ��ü�߸�(object slicing) �̶� �θ��ϴ�.
//�������� �����Ҷ� �ʺ����α׷��ӵ��� �Ǽ��� ��ü�߸������� ����� ���� ��찡 �ֽ��ϴ�.
//�̷����� �����Ҽ� �ִ� reference_wrapper �� ���ؼ��� �˾ƺ��ô�.
#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "i'm Base" << endl;
	}
};

class Derived : public Base {
public:
	int m_j = 1;

	virtual void print() override {
		cout << "i'm derived" << endl;
	}
};

void dosomething(Base& b) {
	b.print();
}

int main() {
	Derived d;
	vector<std::reference_wrapper<Base>> my_vec;

	my_vec.push_back(d);
	my_vec[0].get().print();

	return 0;
}