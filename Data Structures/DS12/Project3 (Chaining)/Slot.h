#pragma once

typedef int Key;

//enum SlotStatus {EMPTY, DELETED, INUSE}; //닫힌 어드레싱 방법은 슬롯의 상태를 알 필요가 없다.

template<typename T>
class Slot
{
public:
	Key key;
	T* val;
	//SlotStatus status;
};