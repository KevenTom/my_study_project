//이번에는 앞에 배운 3가지 관계에 비해서 서로간의 연결 강도가 더 약한 의존관계(Dependencies)에 대해 알아봅시다.

//3 #include<iostream>
//#include<vector>
//#include<algorithm>
//#include<random>
//#include<chrono>
#include "Worker.h"

//3 class Timer
//{
//	using clock_t = std::chrono::high_resolution_clock;
//	using second_t = std::chrono::duration<double, std::ratio<1>>;
//	std::chrono::time_point<clock_t> start_time = clock_t::now();
//public:
//	void elapsed()
//	{
//		std::chrono::time_point<clock_t> end_time = clock_t::now();
//		std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
//	}
//};
//1 타이머 클래스 이 타이머 클래스는 꼭 여기가 아니더라고 다른곳에서 재사용할수 있다.

//3 class Worker //2 타이머 클래스가 언제 시작하고 언제 끝나는지 확실하게 제어하지만 신기한건 타이머 클래스에 대해 워커 클래스가 몰라도 된다.
//{
//public:
//	void doSomething()
//	{
//		Timer timer; // 타이머 시작
//
//		//시간 재는중
//
//		timer.elapsed(); //타이머끝
//	}
//};


int main()
{
	Worker().doSomething();


	return 0;
} //6 다 정리하니까 휑 하는 느낌이 드는데 이렇게 가볍고 깔끔한게 좋은 코드입니다.