#pragma once

typedef int Key;

enum SlotStatus {EMPTY, DELETED, INUSE}; //열거형 슬롯의 상태 (없음, 저장된바가 있으나 비워진 상태, 있음) (지금은 필요없고 충돌해결을 위해 필요함)

template<typename T>
class Slot //데이터를 저장하기 위한 슬롯
{
public:
	Key key; //키
	T* val; //저장할 데이터
	SlotStatus status; //슬롯의 상태
};