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
	ArrayBaseStack(); //초기화 생성자
	bool SIsEmpty(); //스택 비었는지 확인, 비어있다면 true, 아니면 false

	void SPush(T data); //스택에 data 저장
	T SPop(); //스택에서 삭제후 반환
	T SPeek(); //스택에서 최근 데이터 반환
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
