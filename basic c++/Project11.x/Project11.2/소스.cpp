//�տ��� �������� �Ұ���� �̹����� ��ä���� ��ʷ� �����帮�� ���� é���Դϴ�. �������� �ڵ��Ҽ��� �̷� �����ϴ� ������ ��ġ�鼭 �ͼ������ϴ�.
#include "Student.h"
#include "Teacher.h"

using namespace std;


int main()
{
	Student std("JACK JACK");
	std.setName("JACK JACK2");//9 Student ���� setNane�Լ��� ������ ����Ҽ� ����?? �θ�Ŭ������ �޽��� ���ݾ�!
	cout << std << endl;
	
	Teacher teacher1("Dr. H");
	cout << teacher1.getName() << endl;

	teacher1.doNothing();//13 2
	//14 ���������� ��Ʃ��Ʈ�� ����Ŵ� �޽�, Ƽ�Ŀ��� ����Ҽ� ���°� �翬�� �˾Ƽ� �ۼ� ����, ������ ������ �κ� ������ ����� ��
	return 0;
}