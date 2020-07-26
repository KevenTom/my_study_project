#pragma once
//#include <iostream> Position2D�� iostream ��Ŭ��� ���ִϱ� ���� �ʿ� ����
#include <string>
#include "Position2D.h"
//����̸��� Ŭ���� �̸��� �Ȱ��� �ϴ°� ���ٰ� ����??

using namespace std;

class Monster
{
private:
	string m_name; //�̸�
	//int m_x; //��ǥ
	//int m_y; //Position2D�� ������
	position2D m_location; //�� ������ ����2d Ŭ������ ��Ȱ�� �� �� �ִ�. �����ؾ��� ���� ������2d��� Ŭ������ �ٸ� Ŭ������ ���鶧 ����Ѵٴ� �����ϰ� �����ִ°�ó�� ������2d�� �ν��Ͻ��� ���⿡ ����Ѵٴ�
	//�����ϰ�� �ٸ� �����̴�.


	//��ó�� ���Ͱ� �ٸ� Ŭ������ �������� ����ϴ°��� ��������(���� ����)��� �θ��ϴ�. �� �����̼��� ������ �κ��̴�, �Ϻκ��̴� ��� �θ��ϴ�.
	//�����̼��� ���� ��ȯ�Ҷ� �۵��ϰ� �� ���� �ְ� ���� ����� ���� �ֽ��ϴ�.
	//�׷� ���� ��ó�� ��ǥ�� �ɰ��� Ŭ������ �����ó�� �������踦 ���鶧�� ������? ���� �׳� �����̴�. �����Ҽ��� �������� ������ ���� �и��ϴ°��� ����.
	//���������� ������ ���κ� �ٽ� ����

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

	//friend ostream& operator << (ostream& out, const Monster& monster) //������2d�� ��������!
	//{
	//	out << monster.m_name << " " << monster.m_x << " " << monster.m_y << endl;
	//	return out;

	friend ostream& operator << (ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << monster.m_location << endl;
		return out;

	} //���� ���� m_x, m_y�� �׻� ���� �ٳ��, �׸��� ���������̳� ���ӿ������� ��쿡�� ��װ� �� ���� ����� �Ҳ���°� �� �� �־��
		//�׷��� m_x, m_y�� ���� ��� Ŭ������ ����� ���??
};