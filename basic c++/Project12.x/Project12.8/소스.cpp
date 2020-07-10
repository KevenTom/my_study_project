//���߻�ӿ� ���� �����Ҷ� ���̾Ƹ�� ����� ������ �ִٶ�°��� ������ �����, �̹����� ���̾Ƹ������ �������� ���� �ڼ��� �˾ƺ���
//���̾Ƹ�幮���� �ذ��Ҷ� ����ϴ� ���� �⺻ Ŭ����(virtual base class)�� ���� �˾ƺ��ô�
#include <iostream>

using namespace std;

//�� �׸��� �տ� ���߻���� ����Ҷ� �����帰 �׸��ε� ���ʰ��� ����� ������ ������ �׸�ó�� ���̾Ƹ�� ���°� �ȴٰ� ����� ����
//������ �޸� ������ �������� A�� �ΰ��� ����� ������ �߻��մϴ�.
//������ � ���α׷��� ���鶧�� �̷��� ����� ���� �ǵ� �Ҽ��� �ֽ��ϴ�.
//�ϴ� ������ ��ܷ� ġ�� A�� �ΰ��� ����°� ���� ���̾Ƹ��ó�� �����Ϸ��� �ϸ� ��� �ؾ� �ұ��?
//�����Լ��� �̿��ؼ� ����⺻Ŭ������ ����� �˴ϴ�.

class PoweredDevice {
public:
	int m_i;

	PoweredDevice(int power) {
		cout << "PoweredDevice : " << power << endl;
	}
};
class Scanner : public PoweredDevice {
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power) {
		cout << "Scanner : " << scanner << endl;
	}
};
class Printer : public PoweredDevice {
public:
	Printer(int Printer, int power)
		:PoweredDevice(power) {
		cout << "Printer : " << Printer << endl;
	}
};
class Copier : public Scanner, public Printer {
public:
	Copier(int Scanner, int Printer, int power)
		:Scanner(Scanner, power), Printer(Printer, power) {}
};
int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;


    return 0;
}