#pragma once
//#include <iostream> Position2D가 iostream 인클루드 해주니까 해줄 필요 없음
#include <string>
#include "Position2D.h"
//헤더이름을 클래스 이름과 똑같이 하는게 좋다고 했죠??

using namespace std;

class Monster
{
private:
	string m_name; //이름
	//int m_x; //좌표
	//int m_y; //Position2D로 가져감
	position2D m_location; //더 좋은건 몬스터2d 클래스를 재활용 할 수 있다. 주의해야할 점은 포지션2d라는 클래스를 다른 클래스를 만들때 사용한다는 개념하고 여기있는것처럼 포지션2d의 인스턴스를 여기에 사용한다는
	//개념하고는 다른 개념이다.


	//이처럼 몬스터가 다른 클래스의 포지션을 사용하는것을 컴포지션(구성 관계)라고 부릅니다. 이 로케이션이 몬스터의 부분이다, 일부분이다 라고 부릅니다.
	//로케이션을 몬스터 소환할때 작동하게 할 수도 있고 따로 사용할 수도 있습니다.
	//그럼 언제 이처럼 좌표를 쪼개서 클래스를 만든것처럼 구성관계를 만들때가 좋을까? 답은 그냥 숙련이다. 많이할수록 느끼지만 가급적 빨리 분리하는것이 좋다.
	//마지막으로 동영상 끝부분 다시 보셈

public:
	//Monster(const string name_in, const int& x_in, const int& y_in)
	//	: m_name(name_in), m_x(x_in), m_y(y_in)
	//{}

	Monster(const string name_in, const position2D& pos_in)
		: m_name(name_in), m_location(pos_in)
	{}

	//void moveTo(const int& x_target, const int& y_target)
	//{
	//	m_x = x_target;
	//	m_y = y_target;
	//}

	void moveTo(const position2D& pos_target)
	{
		m_location.set(pos_target);
	}

	//friend ostream& operator << (ostream& out, const Monster& monster) //포지션2d로 가져가자!
	//{
	//	out << monster.m_name << " " << monster.m_x << " " << monster.m_y << endl;
	//	return out;

	friend ostream& operator << (ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << monster.m_location << endl;
		return out;

	} //지금 보면 m_x, m_y는 항상 묶어 다녀요, 그리고 물리엔진이나 게임엔진같은 경우에는 얘네가 더 많은 기능을 할꺼라는걸 알 수 있어요
		//그러면 m_x, m_y를 따로 묶어서 클래스를 만들면 어떨까??
};