//move semantics�� ��ü������ ��� �۵��ϰ� ��� ������ �ǰ� ��� �̵��� �� �� �ִ��� �̵� ������(move constructors)�� �̵� ����(move assignmenet)�� ���� �˾ƺ��ô�.
#include<iostream>
#include"Timer.h"
#include"Resource.h" //1 �����ǿ� ����� �ڵ带 ������Ϸ� �߰��ϰ� �ణ ��������� �ֽ��ϴ�.
#include"Autoptr.h"

using namespace std;

Autoptr<Resource> generateResource() {
	Autoptr<Resource> res(new Resource(10000000));
	return res;
}

int main() {
	streambuf* orig_buf = cout.rdbuf();

	//6 �� ���� �ѹ� ������ ���ô�.
	//7 ���������� ����׷� ��� �����ϴ��� Ȯ���� ���°� ����
	//8 ����� ���α׷��� �ð��� ��µ� �̰� �αװ� ��µɶ� �ð��� ������ �Ǵ°Ŷ� �̹����� �α������ ���ۿ� ����ڽ��ϴ�.
	//cout.rdbuf(NULL);
	//�Ȳ������� : 0.14047, ���� �������� : 0.125919 ��ó�� ���̴� �̹������� ���߿� �ð���ų� �ϽǶ� ȭ���� �α׳� ������� �̷��Ŵ� �ð��� ���� �ɸ��� ������ ���� �Ͻô°� �����ϴ�.
	//10				   ���� �������� : 0.0237393 ��û���� ���̰� ����
	//��ó�� deep copy�� ���� �ð� ���̰� ���� ���ٴ°� �� �� �ֽ��ϴ�.
	//����׷� ������ ���� �������� �α׸� Ȯ���� ���� deep copy�� ���� �ʾҴٴ°� �� �� �ֽ��ϴ�. �׷��ϱ� �ξ� �������ۿ� �����ϴ�.

	Timer timer;

	{
		Autoptr<Resource> main_res;
		main_res = generateResource(); //12 ��, generateResource�� �Լ��� �����ؼ� �������� R������ 
		//�׷��ϱ� ��ó�� deep copy�� ���� �ʰ�, R������ �޾Ƽ� �����͸� �׳� shallow copy, �������縦 ���ִ� ������! ���ƻ����δ� �������� ������! 
		//"�ǹ̻����δ� move assignment��" ���شٰ� ǥ���ϴ°� �°���?
		cout << "123test" << endl; //xx �����Ȯ�ο뵵��, ���� generateResource���� ���Ϲ��� "res��" ���� delete �ϰ� �� �Ŀ� ������ �Ѿ�� main_res ��
	}


	cout.rdbuf(orig_buf);
	timer.elapsed();

	return 0;
}