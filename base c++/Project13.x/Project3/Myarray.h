#pragma once
#include<cassert>
#include<iostream>

template<typename T, unsigned int T_SIZE> //2 전 강의의 m_length를 대신 unsugned int T_SIZE 를 추가하였습니다.
class Myarray							//이러면 T_SIZE가 컴파일 단계에서 T_SIZE가 알려져있어야 합니다.
{
	T* m_data; //4 사실 T m_data[T_SIZE] 해줄수는 있지만 아시다시피 스택으로 작동하고 많은 수는 만들 수 없기 때문에 동적할당을 사용해 본겁니다. 간단하면 이렇게 사용해도 됨
public:
	Myarray()
		:m_data(new T[T_SIZE])
	{}

	~Myarray() {
		delete[] m_data;
		m_data = nullptr;
	}

	T& operator[](int index) {
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength() {
		return T_SIZE;
	}

	void print() {//5 앞에서 이 함수를 .cpp 에 넣어서 익스플릿 인스턴시에이션 해야하는걸 아시죠? 근데 저 T_SIZE는 언사인드 int중에서 어떠한 숫자도 들어올수 있게
		for (int i = 0; i < T_SIZE; ++i)//해줘야 하잖아요 그렇단 얘기는 만약 익스플릿인스턴시에이션한다면 모든 언사인트 int숫자를 해줘야 합니다. 불가능하죠
			std::cout << m_data[i] << " ";//그래서 논타입파라미터를 사용할때는 그냥 해더에 정의하고 사용해야 한다 ㅎㅎ
		std::cout << std::endl;
	}
};