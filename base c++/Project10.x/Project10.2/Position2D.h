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
		//m_y = pos_target.m_y; //�̷��� �ϴ°� ���ϴٰ� ������ �� �ִµ� �� ����� 17, 18���� ���� ����̴�. ���������� ����� �� ���� �̷��� ��Ȱ�� ���ִ� ���� ����.
	}

	friend std::ostream& operator << (std::ostream& out, const position2D& pos) //������
	{
		out << pos.m_x << " " << pos.m_y << std::endl;
		return out;
	}
};