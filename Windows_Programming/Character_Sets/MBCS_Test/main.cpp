#include<iostream>

using namespace std;

int main() {
	char str[] = "ABC�ѱ�";	//�ü������ ���ڿ��� ��� ó���ϰ� ������?
	
	cout << "�迭�� ũ�� : " << sizeof(str) << endl;	//8
	cout << "���ڿ� ���� : " << strlen(str) << endl;	//7

	return 0;
}