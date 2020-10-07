#pragma once

#define STACK_lEN 100
#define NULL 0

template<typename T>
class ArrayBaseStack
{
private:
	T stackArr[STACK_lEN];
	int topIndex;
public:
	ArrayBaseStack(); //�ʱ�ȭ ������
	bool SIsEmpty(); //���� ������� Ȯ��, ����ִٸ� true, �ƴϸ� false

	void SPush(T data); //���ÿ� data ����
	T SPop(); //���ÿ��� ������ ��ȯ
	T SPeek(); //���ÿ��� �ֱ� ������ ��ȯ
};



template<typename T>
inline ArrayBaseStack<T>::ArrayBaseStack() :topIndex(-1) {}

template<typename T>
inline bool ArrayBaseStack<T>::SIsEmpty() {
	if (topIndex == -1)
		return true;
	else
		return false;
}

template<typename T>
inline void ArrayBaseStack<T>::SPush(T data) {
	stackArr[++topIndex] = data;
}

template<typename T>
inline T ArrayBaseStack<T>::SPop() {
	if (SIsEmpty())
		return NULL;

	return stackArr[topIndex--];
}

template<typename T>
inline T ArrayBaseStack<T>::SPeek() {
	if (SIsEmpty())
		return NULL;

	return stackArr[topIndex];
}
