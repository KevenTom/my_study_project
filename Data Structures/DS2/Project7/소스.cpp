#include<iostream>
#include"InfixToPostfix.h"

using namespace std;

int main()
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	cout << exp1 << endl;
	cout << exp2 << endl;
	cout << exp3 << endl;

	cout << EvalRPNExp(exp1) << endl;
	cout << EvalRPNExp(exp2) << endl;
	cout << EvalRPNExp(exp3) << endl;

	return 0;
}