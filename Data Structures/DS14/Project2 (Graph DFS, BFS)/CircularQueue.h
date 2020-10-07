#pragma once

#define QUE_LEN 100
#define NULL 0

template<typename T>
class CircularQueue
{
private:
	int front;
	int rear;
	T queArr[QUE_LEN];

	int NextPosIdx(int pos);
public:
	CircularQueue();
	bool QIsEmpty();

	void Enqueue(T data);
	T Dequeue();
	T QPeek();
};

template<typename T>
inline int CircularQueue<T>::NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

template<typename T>
inline CircularQueue<T>::CircularQueue() :front(0), rear(0) {}

template<typename T>
inline bool CircularQueue<T>::QIsEmpty() {
	if (front == rear)
		return true;
	else
		return false;
}

template<typename T>
inline void CircularQueue<T>::Enqueue(T data) {
	if (NextPosIdx(rear) == front)
		return;

	rear = NextPosIdx(rear);
	queArr[rear] = data;
}

template<typename T>
inline T CircularQueue<T>::Dequeue() {
	if (QIsEmpty())
		return NULL;

	front = NextPosIdx(front);
	return queArr[front];
}

template<typename T>
inline T CircularQueue<T>::QPeek() {
	if (QIsEmpty())
		return NULL;

	return queArr[NextPosIdx(front)];
}
