#pragma once

typedef int Data;

class Deque
{
private:
	class Node
	{
	public: //외부에서는 접근을 못하나 클래스 안에서는 public 이기 때문에 객체생성후에는 자유롭게 사용 가능하다. private 이였다면 마찬가지로 Node 안에 접근함수를 만들어 줘야 한다.
		int data;
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

