#pragma once

typedef int Data;

class Deque
{
private:
	class Node
	{
	public:
		Data data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;

public:
	Deque();

	bool DQIsEmpty();

	void DQAddFirst(Data data);
	void DQAddLast(Data data);

	Data DQRemoveFirst();
	Data DQRemoveLast();

	Data DQGetFrist();
	Data DQGetLast();
};

