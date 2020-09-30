#pragma once

typedef int Key;

enum SlotStatus {EMPTY, DELETED, INUSE};

template<typename T>
class Slot
{
public:
	Key key;
	T* val;
	SlotStatus status;
};