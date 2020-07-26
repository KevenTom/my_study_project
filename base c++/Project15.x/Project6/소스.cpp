//����ũ�����Ϳ� �޸� �������� �������� ������ �� �ִ� std::shared_ptr�� ���ؼ� �˾ƺ��ô�.
#include<iostream>
#include"Resource.h"

using namespace std;

int main() {
	Resource* res = new Resource(3);
	res->setAll(1);

	std::shared_ptr<Resource> ptr1(res);
	//1 auto ptr1 = make_shared<Resource>(3);
	//ptr1->setAll(1);
	//������ ����ũ�����Ϳ� ������������ �Ȱ����ϴ�.
	//������������� Ư¡�� ���ĸ� �ڱⰡ ����Ű�� �ִ� �ּ��� �����Ͱ� ������� ����(shared)�ϰ� �ִ����� ���ϴ�.

	ptr1->print();

	{
		//2 ptr2�� ptr1�� �־����ϴ�. ����ũ�����Ϳ� �޸� �� �۵��ϴ°��� �� �� �ֽ��ϴ�.
		shared_ptr<Resource> ptr2(ptr1);
		//shared_ptr<Resource> ptr2(res);
		//auto ptr2 = ptr1;
		//4 ������ �ɼ��ִ� ������ �����帮�ڽ��ϴ�.
		//ptr2�� ptr1�� �ƴ϶� res�� ������ ��� �ɱ��? ptr2�� ptr1�� �����˴ϴ�. ��, ����� �����ϸ� res�� delete�� �ι� �̷�������? �̷��� �Ͻø� �ȵ˴ϴ�.
		//�׷��� ��ó�� 	Resource* res = new Resource(3); �̷��� ���뼭 �޸� �Ҵ�ް� �װ� �����ͷ� �ִ� �������� ������δ� ��������� �ʰ� 
		//������ auto ptr1 = make_shared<Resource>(3); ó�� make_shared�� ����Ͽ� ���������� ����ϴ� ������� �ϴ°��� �����ϴ�.
		//�׸��� auto ptr2 = ptr1; �̰͵� �����ϰ� �����ϴ�.
		//����ũ�����ͺ��� ��������? ���� ���ϴ°� �����Ӱ� ����Ͻø� �˴ϴ�. ��

		ptr2->setAll(3);
		ptr2->print();
		cout << "goig out of the block" << endl;
	}

	ptr1->print(); //3 ptr1�� �������� �״�� �ִٴ� ���� �� �� �ֽ��ϴ�.
	//�׸��� �Ҹ��ڰ� ȣ���� �ȵ��� �������� �����ϴ� �Ŷ� �����ϸ� �˴ϴ�. �� ������ ������ ����°� �ƴ϶� ������ ����� ����ؼ� �Ҹ����ִ� ����Դϴ�.
	cout << "goig out of the block" << endl;


	return 0;
}