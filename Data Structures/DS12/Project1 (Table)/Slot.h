#pragma once
#include"Person.h"

typedef int Key;

enum SlotStatus {EMPTY, DELETED, INUSE}; //������ ������ ���� (����, ����ȹٰ� ������ ����� ����, ����)

template<typename T>
class Slot //�����͸� �����ϱ� ���� ����
{
public:
	Key key; //Ű
	T* val; //������ ������
	SlotStatus status; //������ ����
};