#pragma once

typedef int Key;

//enum SlotStatus {EMPTY, DELETED, INUSE}; //���� ��巹�� ����� ������ ���¸� �� �ʿ䰡 ����.

template<typename T>
class Slot
{
public:
	Key key;
	T* val;
	//SlotStatus status;
};