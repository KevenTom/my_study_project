#pragma once

typedef int Key;

enum SlotStatus {EMPTY, DELETED, INUSE}; //������ ������ ���� (����, ����ȹٰ� ������ ����� ����, ����) (������ �ʿ���� �浹�ذ��� ���� �ʿ���)

template<typename T>
class Slot //�����͸� �����ϱ� ���� ����
{
public:
	Key key; //Ű
	T* val; //������ ������
	SlotStatus status; //������ ����
};