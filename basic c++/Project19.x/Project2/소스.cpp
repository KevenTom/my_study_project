//함수에서는 기본적으로 리턴값이 하나밖에 안되죠
//여러 서로 다른 타입들을 묶을수 있는 tuple에 알아봅시다.
#include<iostream>
#include<tuple> //2 tuple은 여러개의 데이터의 쌍이라고 생각하면 됩니다.

using namespace std;

int my_func() {//1 리턴값을 여러개를 반환하려면 스트럭쳐나 클래스를 사용하는 방법이 있지만 다른 방법도 있습니다.
	return 1;
}

tuple<int, double> my_funce() { //3 튜플을 사용해서 서로 다른 타입들의 집합을 생성할수 있습니다.
	return tuple<int, double>(123, 456.123);
}

auto my_funce2() { //5 좀더 편리하게 사용하실수 있습니다. auto를 사용하면 좀더 편하고요
	return tuple(345, 567.567); // c++17 부터는 템플릿을 넣어주지 않아도 알아서 작동해줍니다.
}

int main() {
	//4 받을때는 다음처럼 하면 됩니다.
	tuple<int, double> result = my_funce();
	cout << std::get<0>(result) << " " << get<1>(result) << endl;
	//123 456.123
	result = make_tuple(111, 222.222);
	

	auto [a, b] = my_funce2(); //6 마찬가지로 auto를 넣어줄 수도 있고, 값을 변수마다 넣어줄수도 있습니다.
	cout << a << " " << b << endl;
	//345 567.567
	//정상적으로 작동하는것을 알 수 있습니다 끝

	return 0;
}