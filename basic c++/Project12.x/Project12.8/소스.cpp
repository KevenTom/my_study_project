//다중상속에 대해 공부할때 다이아몬드 상속은 문제가 있다라는것을 말씀해 드렸죠, 이번에는 다이아몬드상속의 문제점을 좀더 자세히 알아보고
//다이아몬드문제를 해결할때 사용하는 가상 기본 클래스(virtual base class)에 대해 알아봅시다
#include <iostream>

using namespace std;

//이 그림은 앞에 다중상속을 사용할때 보여드린 그림인데 왼쪽같은 상속을 가질때 오른쪽 그림처럼 다이아몬드 형태가 된다고 상상을 되죠
//상상과는 달리 실제로 내부적는 A가 두개가 생기는 문제가 발생합니다.
//하지만 어떤 프로그램을 만들때는 이렇게 만드는 것을 의도 할수도 있습니다.
//일단 지금은 논외로 치고 A를 두개로 만드는것 말고 다이아몬드처럼 구현하려고 하면 어떻게 해야 할까요?
//가상함수를 이용해서 가상기본클래스를 만들면 됩니다.

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