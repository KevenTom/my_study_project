#include<iostream>
#include"ClassStack.h"

using namespace std;

int main()
{
	LStack stack;

	stack.SPush(1)->SPush(2)->SPush(3)->SPush(4)->SPush(5);

	cout << stack.SPeek() << endl;


	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPeek() << endl;


	return 0;
}