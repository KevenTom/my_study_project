//��ü���� ���� ���� �߿��� ���� ���� ���� ����(Composition)�� ���� �˾ƺ��ô�.
//#include <iostream> iostream�� ��Ŭ���� �� �ʿ䰡 ���� -> Monster.h���� �̹� iostream�� �̹� ��Ŭ��� �����ϱ�
#include "Monster.h"


int main()
{
	//Monster mon1("sanson", 0, 0);
	Monster mon1("sanson", position2D(0, 0));
	//mon1.m_location;�� ������ �̸��� ����� ���� ���� �� �ʿ䵵 ���� m_location���� ���� �� ���Ҹ� �ϴ� �͸� ��� �ֽ��ϴ�. ���߿� ��ġ ���ϱ� ���ⰰ���� ����Ŭ������ ������ ������������
	//������ ������2d�� ������ �и��ؼ� �����Ѵٸ� �����ؼ� ����ϱ� ���ϰ� ���߿� �ٸ� ���ֿ��Ե� ����� �� �ֽ��ϴ�.

	while (1)
	{
		//event
		//mon1.moveTo(1, 1); 
		mon1.moveTo(position2D(1, 1));
		cout << mon1 << endl;
	}


	return 0;
}