//STL �����̳ʵ��� ����Ҷ� ���� �������� ����ִ� �˰���(algorithms)�� ���캸�ڽ��ϴ�. ����� �˰�����񿡼� �˰����� ����� �ʰ� �ڷᱸ������ ���ϴ�.
//������ ���δ� �˰��򺸴� ��ƿ��Ƽ�� �����ٰ� �Ѵ�.
//�翬�� �˰���ȿ��� ��û �����͵��� �����մϴ�.
//���� ����� �Ұ��� �帮�ڽ��ϴ�.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	//1 ������ ����� �����Դϴ�.
	vector<int> container;
	//3 ���������� list�� �ٲܼ� �ֽ��ϴ�. ��� list�� �ڱ� Ŭ������ ��� �ֱ� ������ ������� �����Ҳ��� container.sort(); �̷��� ����� �Ѵ�. ��
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto itr1 = min_element(container.begin(), container.end()); //2 min_element�� �Է¹��� �� �߿� ���� ���� ���� ���� �� �ֽ��ϴ�.
	cout << itr1[0] << endl;
	auto itr2 = max_element(container.begin(), container.end()); //max�� �翬�� �ƽð���?
	cout << itr2[0] << endl;

	itr1 = find(container.begin(), container.end(), 3); //�Ǵ� find�� Ư���Ѱ� ã������ �ֽ��ϴ�. �̷��� �ϸ� itr1�� 3�� ��ġ�� ����Ű�� �˴ϴ�.
	container.insert(itr1, 128);

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end()); //�̷��� ������ �ٲٰų�

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end()); //�����Ҽ��� �ֽ��ϴ�.

	for (auto& e : container)
		cout << e << " ";
	cout << endl;


	return 0;
}