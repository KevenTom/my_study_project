//가상함수를 이용하는 다형성이 내부적으로 어떻게 작동하는지 이해하려면 동적바인딩 과 정적바인딩을 이해하시면 됩니다.
#include <iostream>

using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}


int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 3 : multiply" << endl;
	cin >> op;

	//static binding(early binding)
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;
	//1 이런식으로 모든 변수명이나 함수명이 깔끔하게 정리되어 있을때 얼리바인딩, 또는 스태틱바인딩 이라고 부릅니다.

	//Dynamic binding(late binding)
	int (*func_ptr)(int, int) = nullptr; //2 설명구간: 이줄은 펑션포인터이고
	switch (op)
	{
	case 0: func_ptr = add; break; //3 스위치에 뭐가 들어오냐에 따라 add가 들어오고 다른게 들어오는 방식
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl; //4 마지막으로 펑션포인터에 할당이 된 함수를 찾아가서 이 실행을 하는,
	//스태틱 바인딩처럼 함수를 직접적으로 하는 방식이 아닌, func_ptr처럼 저장된 주소를 보고 그 주소를 쫒아가서 거기에 있는 함수를 실행시키는 방식이다.
	//이런식으로 작동하는것을 다이나믹 바인딩이라고 부릅니다.

	//5 두 바인딩의 차이점을 알아봅시다.
	//속도는 스태틱바인딩이 빠르겠죠??
	//다이나믹은 주소를 넣어줘야하고 이런 과정을 거쳐야 하니까 느릴수밖에 없다.
	//대신 다이나믹 바인딩은 프로그래밍의 자유도가 훨씬 유연해진다. 주소가지고 할꺼 많잖아
	//게임만들때 동적바인딩(다이나믹 바인딩)을 자주 사용한다. 
	//설명은 안했지만 가상함수는 다이나믹 바인딩처럼 작동하는거 같다.끝


	return 0;
}