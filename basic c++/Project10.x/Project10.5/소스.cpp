//�̹����� �տ� ��� 3���� ���迡 ���ؼ� ���ΰ��� ���� ������ �� ���� ��������(Dependencies)�� ���� �˾ƺ��ô�.

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
//1 Ÿ�̸� Ŭ���� �� Ÿ�̸� Ŭ������ �� ���Ⱑ �ƴϴ���� �ٸ������� �����Ҽ� �ִ�.

//3 class Worker //2 Ÿ�̸� Ŭ������ ���� �����ϰ� ���� �������� Ȯ���ϰ� ���������� �ű��Ѱ� Ÿ�̸� Ŭ������ ���� ��Ŀ Ŭ������ ���� �ȴ�.
//{
//public:
//	void doSomething()
//	{
//		Timer timer; // Ÿ�̸� ����
//
//		//�ð� �����
//
//		timer.elapsed(); //Ÿ�̸ӳ�
//	}
//};


int main()
{
	Worker().doSomething();


	return 0;
} //6 �� �����ϴϱ� �� �ϴ� ������ ��µ� �̷��� ������ ����Ѱ� ���� �ڵ��Դϴ�.