//�����Լ��� �̿��ϴ� �������� ���������� ��� �۵��ϴ��� �����Ϸ��� �������ε� �� �������ε��� �����Ͻø� �˴ϴ�.
#include <iostream>

using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}


int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 3 : multiply" << endl;
	cin >> op;

	//static binding(early binding)
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;
	//1 �̷������� ��� �������̳� �Լ����� ����ϰ� �����Ǿ� ������ �󸮹��ε�, �Ǵ� ����ƽ���ε� �̶�� �θ��ϴ�.

	//Dynamic binding(late binding)
	int (*func_ptr)(int, int) = nullptr; //2 ������: ������ ����������̰�
	switch (op)
	{
	case 0: func_ptr = add; break; //3 ����ġ�� ���� �����Ŀ� ���� add�� ������ �ٸ��� ������ ���
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl; //4 ���������� ��������Ϳ� �Ҵ��� �� �Լ��� ã�ư��� �� ������ �ϴ�,
	//����ƽ ���ε�ó�� �Լ��� ���������� �ϴ� ����� �ƴ�, func_ptró�� ����� �ּҸ� ���� �� �ּҸ� �i�ư��� �ű⿡ �ִ� �Լ��� �����Ű�� ����̴�.
	//�̷������� �۵��ϴ°��� ���̳��� ���ε��̶�� �θ��ϴ�.

	//5 �� ���ε��� �������� �˾ƺ��ô�.
	//�ӵ��� ����ƽ���ε��� ��������??
	//���̳����� �ּҸ� �־�����ϰ� �̷� ������ ���ľ� �ϴϱ� �������ۿ� ����.
	//��� ���̳��� ���ε��� ���α׷����� �������� �ξ� ����������. �ּҰ����� �Ҳ� ���ݾ�
	//���Ӹ��鶧 �������ε�(���̳��� ���ε�)�� ���� ����Ѵ�. 
	//������ �������� �����Լ��� ���̳��� ���ε�ó�� �۵��ϴ°� ����.��


	return 0;
}