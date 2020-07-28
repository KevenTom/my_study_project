#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int*> s;

	while (false) {
		int* a = new int(1);
		s.push(a);
		int* ab = s.top();
		s.pop();
		delete ab;
	}


	return 0;
}