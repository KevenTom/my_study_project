#include<iostream>
#include"Stack.h"

using namespace std;

int main() {
	Stack<int> stack;

	stack.SPush(1);
	stack.SPush(2);
	stack.SPush(3);
	stack.SPush(4);
	stack.SPush(5);

	while (!stack.SIsEmpty()) {
		cout << stack.SPeek() << " ";
		stack.SPop();
	}



	return 0;
}