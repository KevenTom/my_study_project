#include<iostream>

using namespace std;

int main() {
	char str[] = "ABC�ѱ�";
	
	int size = sizeof(str);
	int len = strlen(str);

	//ABC(3����Ʈ) + �ѱ�(4����Ʈ) + NULL(1����Ʈ) = 8����Ʈ
	//�پ��� ����Ʈ ���� ����Ѵ� -> �̴� MBCS�� ������� ����ȴٴ� ���� �� �� �ִ�.
	cout << "�迭�� ũ�� : " << size << endl;

	//ABC(3����Ʈ) + �ѱ�(4����Ʈ) = 7����Ʈ
	//�����δ� 5���� ���� 7���ڷ� �ν��ϰ� �ִ�. �̰��� MBCS�� ������ �̴�.
	cout << "���ڿ� ���� : " << len << endl;


	return 0;
}