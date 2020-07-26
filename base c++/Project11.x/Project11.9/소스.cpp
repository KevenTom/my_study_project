//한 클래스로부터 상속을 받을 수 있다면 두개 이상의 클래스로부터 상속을 받을수 없을까요?? 이번에는 다중상속에 대해 알아봅시다.
#include<iostream>

using namespace std;

class USBDevice
{
private:
	long m_id;
public:
	USBDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;
public:
	NetworkDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id) :USBDevice(usb_id), NetworkDevice(net_id) {}
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.0222);
	my_device.networking();
	my_device.plugAndPlay(); //1 딱히 설명이 필요 없다. 주의할점이 있는데 중복된 함수가 있을때 문제가 생기는데
	//3 2my_device.getID(); //2 그냥 적으면 어떤getID인지 모르겠다며 빌드가 안된다. 해결법은 간단하다.
	cout << my_device.USBDevice::getID() << endl;
	cout << my_device.NetworkDevice::getID() << endl; //3 2 그냥 앞에 원하는 함수의 클래스를 적어주면 된다. 동영상 마지막에 다이아몬드 다중 상속의 주의점 얘기해줌 끝


	return 0;
}