//�̹����� ��Ӱ� �����͸� ������� �ڽ� Ŭ������ ��ü�� �θ� Ŭ������ �����͸� ����Ѵٸ� ��� �ɱ�?
//������ ������ �����߿� �� ������ �� �߿������� "������"�� ������ �ֱ� �����Դϴ�. �ѹ� �˾ƺ��ô�.
#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string m_name;
public:
	Animal(string name)
		:m_name(name)
	{}
	string getname() { return m_name; }
	//5 2void speak() const
	virtual void speak() const //5 2�տ� virtual Ű���带 �ٿ�����
	{
		cout << m_name << " ??? " << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

int main()
{
	Animal animall("my animal");
	Cat catt("my cat");
	Dog dogg("my dog");

	animall.speak();
	catt.speak();
	dogg.speak();

	Animal* ptr_animal1 = &catt; //1 �θ�Ŭ������ �����Ϳ� �ڽ� Ŭ������ �ּҸ� �־��
	Animal* ptr_animal2 = &dogg;

	ptr_animal1->speak();
	ptr_animal2->speak(); //2 Ĺ�ϰ� �����ε� ����ǥ�� ������?? �ڽ�Ŭ������ �θ�Ŭ������ �����͸� ĳ���� ��Ű�� ȣ���ϸ� �ڱⰡ �θ�Ŭ�������� �˰� �۵��Ѵ�.
						//�����ǰ� �������ǰ�?? Ȯ���غ���
	cout << endl;


	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; ++i)
		cats[i].speak();
	for (int i = 0; i < 2; ++i)
		dogs[i].speak();
	
	//3 ���� �������� ���� ���ڿ� ������ �������ٸ� �翬�� for���� �׿����� �������ϰ� ����ϰ���?
	//Ȥ�� �̷��� �ִϸ�Ŭ������ ����� �ȰŴϱ� �ִϸ�Ŭ������ ��� Ȱ���ϸ� ������ ������?? �� ������ ó��

	Animal* my_animals3[] = { &cats[0], &cats[1], &cats[2], &cats[3],&cats[4],
		&dogs[0],&dogs[1]
	};

	for (int i = 0; i < 7; ++i)
		my_animals3[i]->speak(); //4 �� �ѹ��� ����ϱ�� ������ ���� ???�� �߳�
	//6 �̹����� ���� �ڽ� Ŭ������ ��ó�� ���´�.
	//�տ� ����� Ű���常 �־����� ���ε� �����ʹ� �θ�Ŭ�����ε� �ڽ�Ŭ�����ΰ�ó�� �ൿ�Ѵ�. ���� �����ϴٰ� �� �� �ִ�.
	//�̷��� ������ "������" �̶�� �Ѵ�. ��

	return 0;
}