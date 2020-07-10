//�����Ͱ� ����Ű�� �ִ� �������� �������� �Ѱ��� ���� ��쿡�� ����Ҽ� �ִ� ����Ʈ������, unique_ptr �� ���� ���캸�ڽ��ϴ�.
//�� ���ǿ� ����� auto_ptr�� ��ȭ�� ������
#include<iostream>
#include<memory> //2 unique_ptr�� memory.h�� �ֽ��ϴ�.
#include"Resource.h"

using namespace std;

auto dosomething() {
	return std::make_unique<Resource>(5);

	//5 3�翬�� �Լ��ȿ����� �̷��� ���ټ� ����
	//auto res1 = std::make_unique<Resource>(5);
	//return res1;
	//return std::unique_ptr<Resource>(new Resource(5));
}

//9 3auto dosomething2(unique_ptr<Resource>& res) { //8 2����ũ �����͸� �Ķ���ͷ� �ְ� �Լ��� ���� ����ũ�������� ���۷��� &�� �ް� �ֽ��ϴ�.
//10 4auto dosomething2(unique_ptr<Resource> res) { //9 3�׷��� ���� ���۷��� ���� �׳� ������ ���� �������� ���� �̷��� �ϸ� ��� �ɱ��
auto dosomething2(Resource* res) {//10 4 �̷��� �����͸� ���� �޴� ����� �ֽ��ϴ�.
	res->setAll(10);
}

int main() {
	//1 ���� ����� �����Դϴ�. �̷� ��Ȳ�� ù ���ǿ��� unique_ptr�� �������
	{
		//3 3Resource* res = new Resource(100000000);
		std::unique_ptr<Resource> res(new Resource(100000000)); //3 3�̷��� ���ָ� �ǰ� delete�� ���ݽ��ϴ�. �����ϸ� �˾Ƽ� �Ҹ��ڵ� ���ִ� ���� �� �� �ֽ��ϴ�.
		//�̰� �⺻���� ����ũptr�� �����̰�� ���� ���� �ڼ��� ������ ���캸�ڽ��ϴ�.

		//early return or throw

		//3 3delete res;
	}
	cout << '\n' << endl;

	//4 �̹����� �ٸ� ���ø� ���ô�.
	{
		std::unique_ptr<int> upi(new int); //���� �˰����� �⺻ �ڷ������� �󸶵��� ����� �� �ֽ��ϴ�.

		//5 3std::unique_ptr<Resource> res1(new Resource(5));
		//auto res1 = std::make_unique<Resource>(5); //���� �� �����ϴ� ����� make_unique�� ����ϴ� ����Դϴ�. 
													//make_unique�� �ϸ� ����ø�ƽ���� ����ϱ� ������ �����ϴ�. ī�Ǹ� ȣ�� ���մϴ�.
		auto res1 = dosomething(); //5 3�Լ��� ����ϴ� ����� �ֽ��ϴ�.

		res1->setAll(5);
		res1->print();

		unique_ptr<Resource> res2; //6 �̹����� ����ũ �����͸� �ϳ� �� ��������ϴ�.

		//�ΰ����� �ƴ��� bool�� ĳ���� �ؼ� ����� ���ҽ��ϴ�.
		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;
		cout << static_cast<bool>(res2) << endl;

		//res2 = res1; //����ũ�����ʹ� ���縦 ���մϴ�. ������ �ߴ°��� Ȯ���� �� �ֽ��ϴ�. 
						//ù�ٿ� �����帰��ó�� ����ũ�����ʹ� �������� �Ѱ��� ���� ��쿡�� �۵��ϰ� ������� ������ ����
		res2 = move(res1); //������ ����ø�ƽ���� ����� �� �ֽ��ϴ�.

		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;
		cout << static_cast<bool>(res2) << endl;
	}
	cout << '\n' << endl;


	//7 �ٸ������� ���ô�.
	{
		auto res1 = make_unique<Resource>(5);
		(*res1).setAll(1); //�̷��Ե� ���� ����
		(*res1).print();
		
		//�̹����� �Լ����� ���ϰ����� �޴� ���� �ƴ�, �Ķ���ͷ� ���� �ִ� ��쿡 �˾ƺ��ô�.
		//10 4dosomething2(res1); //8 2����ũ �����͸� �Ķ���ͷ� �ְ� �Լ��� ���� ����ũ�������� ���۷��� &�� �ް� �ֽ��ϴ�.
		//9 3�翬�� �������� �ȵ��� �ֳĸ� ����ũ ���� ������
		//�ƴϸ� ����ø�ƽ���� �ִ� ����� ������ �׷��� �����Ͱ� dosomething���� �Ҹ��ϰ� res1�� �ΰ��� �Ǽ� �����Ͱ� �ȵ��� 
		//���� �������� �ٽ� �޴� ����� �ֽ��ϴ�. �ֱٿ��� �̷��� �����ؼ� ����ϱ⵵ �Ѵ�ϴ�.
		dosomething2(res1.get()); //10 4 �Ǵ� �����͸� �Ѱ��ְ� �۾����ִ� ����� ����. �̷��� �����͸� ���⵵ �ϰ� ��ó�� �ϱ⵵ �Ѵ�ϴ�. ���� ����� ��õ�ϱ� ����
		//get�� ����ũ ��ü�� ���� �ִ� �ɷ� ����ũ�� �����Ϳ� ����ִ� �����͸� �������� �̴ϴ�.

		(*res1).print();
	}

	//11 ������ �����Դϴ�.
	//�翬�� �Ʒ� ������ �ϸ� �ȵǴ� �͵��Դϴ�.
	//res�� �ΰ� �ָ� �翬�� �ȵ���, �׸��� �Ѱ��ذ� delete ���ָ� �翬�� �ȵ��� ��
	{
		Resource* res = new Resource;
		unique_ptr<Resource> res1(res);
		unique_ptr<Resource> res2(res);

		delete res;
	}


	return 0;
}