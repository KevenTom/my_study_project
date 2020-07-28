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
	int expLen = strlen(exp); // strlen ���ڿ� ���� ���ϱ� (�� NULL�� �������� ����)
	char* ConvExp = new char[expLen + 1]{ 0 };

	int idx = 0;
	char popOp;



	for (int i = 0; i < expLen; ++i) // ���ڿ� ó������ ������
	{
		if (isdigit(exp[i])) // exp[i]�� ������ ��� �ٷ� ����
		{
			ConvExp[idx++] = exp[i];
		}
		else // ���ڰ� �ƴ� ���
		{
			switch (exp[i])
			{
			case '(':
				stack.SPush(exp[i]); // ���ÿ� '(' �� ����
				break;

			case')':
				while (true) // ')' �� ������ ���ÿ� �ִ°� �� ����
				{
					popOp = stack.SPop();
					if (popOp == '(')
						break;
					ConvExp[idx++] = popOp;
				}
				break;

			case '+': case '-': case '*': case '/':
				while(!stack.SIsEmpty() && WhoPrecOp(stack.SPeek(), exp[i]) >= 0) //������� �����鼭 ù��° ���ÿ� exp[i]���� ũ�ٸ�
					ConvExp[idx++] = stack.SPop(); // ���ÿ� �ִ� �����ڸ� ���� ����
				stack.SPush(exp[i]); // �����ڸ� ���ÿ� ����
				break;

			}
		}
	}

	while (!stack.SIsEmpty()) // ������ ������� ������
		ConvExp[idx++] = stack.SPop(); // �����ڸ� ������

	strcpy_s(exp, expLen + 1, ConvExp); // exp���ٰ� ConvExp�� �����ϰ�
	delete[] ConvExp; // ConvExp �Ҹ�
}

int EvalRPNExp(char arr[])
{
	LStack stack;
	int op1, op2, expLen = strlen(arr);

	for (int i = 0; i < expLen; ++i)
	{
		if (isdigit(arr[i])) // exp[i]�� ������ ��� ���ÿ� ����
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