//�̹����� �ƿ�ǲ��Ƽ��(ostream)���� ����Ҷ� �ɼ��� ���ݴ� ���ϰ� �����ϴ� ����� ���ؼ� ������ �帮�ڽ��ϴ�.
//�翬�� ��û ���Ƽ� ���δ� �����ص帮�� ���ϰ� �Ϻκи� �����ص帮�ڽ��ϴ�.
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	//iostream�� �ֻ��� Ŭ���� ios_base ���� ����� ������ �ٲܼ� �ֽ��ϴ�.
	//�������ַ� �����帮�ڽ��ϴ�.

	//1 setf �Լ��� ��Ʈ���� ������ �ٲܼ� �ֽ��ϴ�.
	cout.setf(ios::showpos); //�̹����� �ѹ� +��ȣ�� ����ϴ� showpos�� �غ��ڽ��ϴ�. 
	cout << 108 << endl;
	//+108

	cout.unsetf(ios::showpos); //unsetf�� ���ټ� �ִ� 
	cout << 109 << endl;
	//109

	cout.setf(ios::hex); //16������ ������ټ� �ֽ��ϴ�.
	cout.unsetf(ios::dec); //��� 10������ ������� 16������ ����մϴ�
	cout.setf(ios::uppercase); //�̷��� �ϸ� �빮�ڷ� ������ش�
	cout << 108 << endl;
	//6C

	cout.setf(ios::hex, ios::basefield); //���ڰ� 2���� ��� basefield�� ������ �ʱ�ȭ �ϰ� hex�� �������ִ� ����Դϴ�.
	//���� ó���ϴ� ����� 1���� ������ ó���� �� �����Ƿ� ���������� ���� ó������ �����ϴ� basefield�� �ʱ�ȭ�ϰ� hex �÷��׸� �����Ų ���Դϴ�.
	cout << 108 << endl;
	//6c

	cout << std::hex; //�̷��� ����Ҽ��� �ֽ��ϴ�.
	cout << 108 << endl;
	//6c

	cout << true << false << endl;
	cout << std::boolalpha; //bool���� ������ٶ� 1, 0�� true, false�� ������ش�
	cout << true << false << endl;
	//10
	//truefalse

	//����Ҷ� float�� �⺻���� ������ݴϴ�.
	cout << std::defaultfloat;

	//setprecision�� ����Ҷ� �Ҽ����� ������ �ݴϴ�.
	cout << std::setprecision(5) << 123.456 << endl;
	//123.46 (�� 6����? �ݿø� �ؼ� �׷����ϴ�)

	//fixed�� ���ָ� setprecision�� ����ŭ �Ҽ����� �������ݴϴ�
	cout << fixed;
	cout << std::setprecision(5) << 123.456 << endl;
	//123.45600

	//scientific�� ����ǥ�������� ������ݴϴ�.
	cout << scientific; 
	cout << std::setprecision(5) << 123.456 << endl;
	//1.23456e+02

	//showpoint�� �Ҽ����� ������ ���ݴϴ�.
	cout << showpoint;
	cout << std::setprecision(3) << 123.456 << endl;
	//123.
	
	//�տ��� ��� setw�Լ� ���� ��¿��� ����ϽǼ� �ֽ��ϴ�.
	cout << setw(10) << -1234 << endl; 	//�Ű����� ��ŭ ���� �������ݴϴ�.
	cout << setw(10) << std::left << -1234 << endl; //�������� �������ְ� �Ű����� ��ŭ ���� �������ݴϴ�.
	cout << setw(10) << std::right << -1234 << endl;//���������� �������ְ� �Ű����� ��ŭ ���� �������ݴϴ�.
	cout << setw(10) << std::internal << -1234 << endl;//��ȣ�� ���ʿ�, ���ڴ� �����ʿ� �������ְ� �Ű����� ��ŭ ���� �������ݴϴ�.
	//     -1234
	//-1234     
	//     -1234
	//-     1234

	//fill�� ��ĭ�� �Ű������� �ٲ��ݴϴ�.
	cout.fill('*');
	cout << setw(10) << -1234 << endl;
	//*****-1234


	//��

	return 0;
}