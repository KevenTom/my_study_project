#pragma once

#include <iostream>

class position2D
{
private:
	int m_x;
	int m_y;
public:
	position2D(const int& x_in, const int& y_in)
		:m_x(x_in), m_y(y_in)
	{}

	void set(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	void set(const position2D & pos_target)
	{
		set(pos_target.m_x, pos_target.m_y);
		//m_x = pos_target.m_x;
		//m_y = pos_target.m_y; //이렇게 하는게 편하다고 생각할 수 있는데 이 기능은 17, 18번과 같은 기능이다. 같은역할을 만드는 것 보단 이렇게 재활용 해주는 것이 좋다.
	}

	friend std::ostream& operator << (std::ostream& out, const position2D& pos) //가져옴
	{
		out << pos.m_x << " " << pos.m_y << std::endl;
		return out;
	}
};