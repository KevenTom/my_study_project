//���ݱ����� ���������� ����� ����� �����Ҷ� �ڽ�Ŭ�������� �ڱ⿡�� ������ �Լ��� �������̵� �ϴ� �������� ������ �����
//�̹����� ���踦 �ϴ� �������� ���̽�Ŭ������ ���鶧 �ڽ�Ŭ�������� �̷��̷��� ���� �ݵ�� �ؾ��Ѵٴ� ������ �ɾ�δ� ����� ������ �帮�ڽ��ϴ�
//�̹����� "���� ���� �Լ�"(�ٵ� ���� ������ �ڽ�Ŭ�������� �ݵ�� �������̵��� ����߸� �Ѵ�),
//���� ���� �Լ��� ������ �� Ŭ������ "�߻� �⺻ Ŭ����",
//���� ���� �Լ��θ� �̷���� Ŭ������ "�������̽� Ŭ����", �̷��� 3������ ������ �帮�ڽ��ϴ�.
#include<iostream>
#include<string>
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
	//1 2virtual void speak() const
	//{
	//	cout << m_name << " ??? " << endl;
	//}
	virtual void speak() const = 0; //1 2ù ���ǿ� ����� Ŭ���� �Դϴ�. �ִϸ�Ŭ�������� ����ũ�ҋ� ??? �ߴ°� �̻��ϴϱ� ����� �ٵ� ���� �� �ִ�.
	//�̷��� �ٵ� ���� ����� ����̰� �ڿ� =0 �̷��� �Ǿ��ִ� �Լ��� pure virtual function(���� ���� �Լ�) ��� �θ���.

	//3 ��, �θ�Ŭ�������� �����Ҷ� "���� �𸣰ڴ�", ���� �𸣰����� �ڽ�Ŭ���������� �ݵ�� speak�� �����ض� ��� �ǹ̸� ������.
	//���ݱ����� ������� ����Ҷ� �Ϲ����� �͵��� �θ� Ŭ������ ��Ƴ��� ��Ȱ�� �Ҽ� �ִٸ� �ϰ�, �Ǵ� �ڽ�Ŭ������ Ưȭ�� ���� ���� ��쿡�� �������̵��� �ϴ� �������� ������ �����
	//���⼭�� ������ ���ݴ� �޶����Ŵ�. �ִϸ�Ŭ������ �����Ҷ� �ڽ�Ŭ������ ������ ǻ����������� ������ �Ѵ�. ��� �������� �ٲ�Ŵ�.
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

class Cow : public Animal //4 �ѹ� ǻ����������� speak�� ���� �ڽ� Ŭ���� Cow �� ����� �ô�.
{
public:
	Cow(string name)
		:Animal(name)
	{}
};


//-----------------�������̽� Ŭ������ �����ϱ� ���� Ŭ����-----------------------
class IErrorLog //7 �������̽�Ŭ������ �̸� �տ� �빮�� I�� �ٿ��ִ°� �����̴�.
	//���ο� ����ִ� �Լ����� ��� ���� ���� �Լ��θ� �̷���� Ŭ������ �������̽� Ŭ������� �θ���.
	//�ڱⰡ �� ������ �ƹ��͵� ���Ǹ� ���� �ʾұ� ������ ��� ������ �ؾ��Ѵٸ� ������ �ִ� ������ �ȴ�.
	//�������̽�Ŭ������ �Ѹ���� �ܺο��� ����Ҷ� �̷��̷��� ��ɵ��� �����Ŵ� ��� ������ �Ҽ� �ִ� �߰�� ������ ���ش�.
	//�׷��ϱ� �������̽� Ŭ������ ��� ���� Ŭ������ ǻ����������� ���� �ȴٸ� �˰� �ִ�.
{
public:
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog(){}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log) //8 �Ű������� �������̽� Ŭ������ �޳�? �ٵ� �������̽� Ŭ������ �ν��Ͻ��� ����� ���� Ŭ���� ���뵵 �ϳ��� ���µ�
								//�׷��ϱ� �������̽� Ŭ������ ��� ���� Ŭ������ ǻ����������� ���� �ȴٸ� �˰� �ִ�. 
{
	log.reportError("Runtime error!!"); //9 �����ε� ǻ��������Ǹ� ������ �ִ�.
}

int main()
{
	Animal ani("H1"); //2 ���������Լ��� �ִ� ���¿��� �ִϸ�Ŭ������ ȣ���� ���Ҵ�.
					//����������� �ʴ´�. ǻ����������� �ϳ��� ���ִ� Ŭ������ abstract class(�߻� �⺻ Ŭ����)�� ��ü�� ����� ����.
	Cow cow("hello"); //5 �ȸ���� ����. ������ ���� ǻ����������� speak�Լ��� ���ٰ� �Ѵ�.
					//�Ѹ���� ǻ����������� Ŭ������ �����Ҷ� ��ӱ�����ü�� �Ѳ����� �����Ҽ� �ֵ��� �����ִ� ����̶�� �����ϸ� �ȴ�.





	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log); //10 �Ű������� IErrorLog�� ������ �μ��� FileErrorLog�� �ټ� �ִ�. ����� �޴� ������ �Ǿ������ϱ�
							//�����غ��� �־��� ��� ������شٴ°��� �� �� �ִ�. ���� ������ ����̴� �������. ��
	doSomething(console_log);


	return 0;
}