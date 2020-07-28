#include<iostream>
#include"ArrayBaseStack.h"

using namespace std;

int main()
{
	Stack stack;
	Data data;

	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);

	data = SPeek(&stack);
	cout << data << endl;

	data = SPop(&stack);
	cout << data << endl;
	data = SPeek(&stack);
	cout << data << endl;

	SPop(&stack);
	data = SPeek(&stack);
	cout << data << endl;

	SPop(&stack);
	data = SPeek(&stack);
	cout << data << endl;

	SPop(&stack);
	data = SPeek(&stack);
	cout << data << endl;

	SPop(&stack);
	data = SPeek(&stack);
	cout << data << endl;

	SPop(&stack);
	data = SPeek(&stack);
	cout << data << endl;

	return 0;
}