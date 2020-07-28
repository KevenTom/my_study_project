#include<iostream>
#include<cstring>
#include"ClassStack.h"

using namespace std;


int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	LStack stack;
	int expLen = strlen(exp); // strlen 문자열 길이 구하기 (끝 NULL은 포함하지 않음)
	char* ConvExp = new char[expLen + 1]{ 0 };

	int idx = 0;
	char popOp;



	for (int i = 0; i < expLen; ++i) // 문자열 처음부터 끝까지
	{
		if (isdigit(exp[i])) // exp[i]가 숫자일 경우 바로 저장
		{
			ConvExp[idx++] = exp[i];
		}
		else // 숫자가 아닐 경우
		{
			switch (exp[i])
			{
			case '(':
				stack.SPush(exp[i]); // 스택에 '(' 를 저장
				break;

			case')':
				while (true) // ')' 을 만나면 스택에 있는걸 다 꺼냄
				{
					popOp = stack.SPop();
					if (popOp == '(')
						break;
					ConvExp[idx++] = popOp;
				}
				break;

			case '+': case '-': case '*': case '/':
				while(!stack.SIsEmpty() && WhoPrecOp(stack.SPeek(), exp[i]) >= 0) //비어있지 않으면서 첫번째 스택에 exp[i]보다 크다면
					ConvExp[idx++] = stack.SPop(); // 스택에 있는 연산자를 빼서 넣음
				stack.SPush(exp[i]); // 연산자를 스택에 넣음
				break;

			}
		}
	}

	while (!stack.SIsEmpty()) // 스택이 비어있지 않으면
		ConvExp[idx++] = stack.SPop(); // 연산자를 빼낸다

	strcpy_s(exp, expLen + 1, ConvExp); // exp에다가 ConvExp를 복사하고
	delete[] ConvExp; // ConvExp 소멸
}

int EvalRPNExp(char arr[])
{
	LStack stack;
	int op1, op2, expLen = strlen(arr);

	for (int i = 0; i < expLen; ++i)
	{
		if (isdigit(arr[i])) // exp[i]가 숫자일 경우 스택에 저장
		{
			stack.SPush(arr[i] - '0');
		}
		else
		{
			op2 = stack.SPop();
			op1 = stack.SPop();
			switch (arr[i])
			{
			case'+':
				stack.SPush(op1 + op2);
				break;
			case'-':
				stack.SPush(op1 - op2);
				break;
			case'*':
				stack.SPush(op1 * op2);
				break;
			case'/':
				stack.SPush(op1 / op2);
				break;
			}
		}
	}

	return stack.SPop();
}