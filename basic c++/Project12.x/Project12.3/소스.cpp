//�̹����� �������� �����Ҷ� �����ϰ� ����ϴ� override, final, ���� ��ȯ��(covariant)�� �˾ƺ��ô�.
#include <iostream>

using namespace std;

class A
{
public:
	//5 3virtual void print(int x) { cout << "A" << endl; }
	void print() { cout << "A" << endl; }
	virtual A* getThis() { return this; } //5 3covariant�̶� �Ϲ������� ����Ÿ���� �ٸ��� �ȵǴ� �������̵��� �ȵ����� ����Ŭ����. �ڽ�Ŭ���� �̱� ������ �������̵��� �˴ϴ�.
};

class B : public A
{
public:
	//3 3void print(short x) { cout << "B" << endl; } //1 ��������Ʈ���� �Ű������� �ٸ���.
	//3 3void print(short x) override { cout << "B" << endl; } //3 3�̷��� �������̵带 �����ش�. �ڽ�Ŭ�������� �Լ��� �����Ҷ� ����Ŭ������ �ִ� ���������� ������ �������̵� �ϰ� �ʹٸ� 
	//override�� �����ش�. �׷��� �� �Լ��� ������ �������̵� �ؾ��Ѵٰ� �����϶�� ���ظ� �Ѵ�. �׷��� ���� �����Ϸ��� ������ �߻��Ѵ�. (�����Ϸ��� ���� ������ ����شٰ� �����ϸ� ���ϴ�.)
	//4 2void print() final { cout << "B" << endl; //4 2final Ű����� �����ϴ�. �����ָ� �� �Ʒ��Լ����� �������̵��� �Ҽ� ���� �����ش�.
	void print() { cout << "B" << endl; }
	virtual B* getThis() { return this; }
};

class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;

	//5 3A& ref = b;
	//ref.print(1); //2 �Ű������� �ٸ��ϱ� �翬�� B�� �ȳ��´�. �˴ٽ��� �Լ��� �Ķ���Ͱ� �ٸ��� �������̵��� �Ҽ� ����. 
				//�����Ϸ� ��ü�� �׳� �ٸ� �Լ��ΰ����� �Ҽ� ������ ���� �� �Լ��� ������ �������̵� �ؾ��Ѵٰ� �ϸ� ��� �ؾ��ұ�?
	A& ref = b;
	b.getThis()->print();
	ref.getThis()->print();
	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl; //6 ������ ������ �����ϱ� �����ϱ� ������ 7�� ��


	return 0;
}