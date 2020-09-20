//객체들의 여러 관계 중에서 가장 먼저 구성 관계(Composition)에 대해 알아봅시다.
//#include <iostream> iostream을 인클라우드 할 필요가 없다 -> Monster.h에서 이미 iostream을 이미 인클루드 했으니까
#include "Monster.h"


int main()
{
	//Monster mon1("sanson", 0, 0);
	Monster mon1("sanson", position2D(0, 0));
	//mon1.m_location;이 몬스터의 이름을 사용할 수도 없고 알 필요도 없다 m_location에는 오직 그 역할만 하는 것만 들어 있습니다. 나중에 위치 더하기 뺴기같은걸 몬스터클래스에 넣으면 복잡해지겠죠
	//하지만 포지션2d에 역할을 분리해서 정리한다면 정리해서 사용하기 편하고 나중에 다른 유닛에게도 사용할 수 있습니다.

	while (1)
	{
		//event
		//mon1.moveTo(1, 1); 
		mon1.moveTo(position2D(1, 1));
		cout << mon1 << endl;
	}


	return 0;
}