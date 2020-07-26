//STL���� �پ��� �����̳ʵ��� ���ǵǾ��ֽ��ϴ�. �� �پ��� ������ �����̳ʵ��� �������� ������� �����Ҽ� �ִ� �ݺ���(iterators)��� ���� ���ǵǾ� �ֽ��ϴ�.
//�ݺ��ڸ� ó������ �����ϽǼ� �ֽ��ϴ�.
//http://tcpschool.com/cpp/cpp_iterator_intro ���ǰ� �ñ��ϸ� �̰� ����
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>

using namespace std;

int main() {
	//1 �⺻���� �����Դϴ�.
	vector<int> container;
	for (int i = 5; i < 15; ++i)
		container.push_back(i);

	vector<int>::const_iterator itr; //2 �̷��� �ݺ��� ��ü�� ������ ����ϴ�. �׳� iterator�� �ֽ��ϴ�. const�� �� �״�� const�� �Ű���
	//�׷��ϱ� ���� ��ƮŸ�Կ� �ش��ϴ� ���ͷ�����Ÿ���� itr�� ����� �̴ϴ�.
	itr = container.begin(); //itr�� �ʱ�ȭ�� �Ҷ� begin�� �����ɴϴ�.
	while (itr != container.end()) { //�����̳��� �ص尡 �ƴҶ����� �ݺ��ϰ���
		cout << *itr << " ";
		++itr;
	}
	cout << endl;
	//���ͷ����ʹ� �ٸ� �����̳ʿ����� �ϰ��ǰ� ����Ҽ� �ִٴ� ������ �ֽ��ϴ�.
	//�׷��� �� ���� itr ����� ��� ���ŷ���
	//�� ���ǿ� ����� ���� for���� ����ϰų�
	for (auto itr2 = container.begin(); itr2 != container.end(); ++itr2)
		cout << *itr2 << " ";
	cout << endl;
	//�̷��� ����ϼŵ� �˴ϴ�.

	//3 ����Ʈ�� ����ϰ�ʹٸ� ��� �ϸ� ����?
	list<int> container2; //4 �̷��� list�θ� �ٲ��ָ� �����ϰ� �ذ�˴ϴ�.
	for (auto itr2 = container2.begin(); itr2 != container2.end(); ++itr2)
		cout << *itr2 << " ";
	cout << endl;
	//�翬�� ���������� �������̳� ������ �翬�� �ٸ��ϴ�.
	// set, map ���� ����Ͻ� �� �ֽ��ϴ�. ��
	

	return 0;
}