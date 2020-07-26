//�Լ��� �Լ��� ȣ���ϰ� �� �Լ��� �ٽ� �ٸ� �Լ��� ȣ���Ѵٸ� ���ÿ� ȣ�ⱸ���� �������� �׿���������
//���࿡ ���� �������� �ִ� �Լ��� ���ܸ� �����ٸ� ������ �ǰ��� ���鼭 ��� ���ܸ� ������ ã�Ե˴ϴ�.
//���⼭�� ����ó���� ���� �ǰ���(stack unwinding)�� ���� �˾ƺ��ô�.
#include<iostream>

using namespace std;

//10 2void last() throw(int) { //10 2�̷� ������ �����Ѵ�. exception specifier �̶�� �θ��µ� �Լ� �ڿ� hrow(int) �ٿ��ָ� intŸ���� ���ܸ� ���ο� �Ҽ��� �ִٶ�� �ǹ̰� �Ǵµ� �� exception specifier�� ���� ������� �ʴ´�. ��� int�� �ƴ϶� ���������� �� ... ���� �ٲ۴ٰ� �Ѵ� �׳� �˾Ƶζ� �Ѵ� �ٵ� �ʿ�����
void last() {
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw - 1; //4 throw �� �ϸ� �����ڵ���� �������� �ʰ� �ٷ� ����������.

	cout << "End last" << endl;
}

void third() {
	cout << "third" << endl;

	last(); //5 �״��� third�� �͵� endthird�� ȣ������ �ʴ´�. �� �������� ��� ���󰣴�.

	cout << "End third" << endl;
}

void second() {
	cout << "second" << endl;

	try {
		third();
	}
	catch (double) {//6 ĳġ�� �������� �Ұ��ϰ� double�̴ϱ� ����.
		cerr << "second caught int exception" << endl;
	}

	cout << "End second" << endl;
}

void first() {
	cout << "first" << endl;
	
	try {
		second();
	}
	catch (int) { //3 throw ���ڸ��� �ٷ� first catch�� ����Դ�. ��� �� ������?
		cerr << "first caught int exception" << endl;
	}//7 �� �����ϰ� ���ٰ� �´� catch�� �����ϱ� �� �������� �����ϴ� ���� �� �� �ִ�.

	cout << "End first" << endl;
}

int main() {
	cout << "start" << endl;

	try { //2 ����׷� �� ����
		first();
	}
	catch (int) {
		cerr << "main caught int exception" << endl;
	}

	//1 cerr�� �����Ҽ� �ִµ� ���ƿ�(cout), ������(cerr), ���α�(clog) 3������ �ִµ� 3������ ���̴�
	//��ɻ� ���̴� ���� �α׸� ������ִ� "ä��"�� 3������ �ִ�. ������ �Ƽŵ� �˴ϴ�.
	//������� ���������ٰ� ������ ����Ѵٴ��� ���� ������ �����
	//cout ���� ��쿡�� ����� ���ۿ� ��Ƴ��� �ٷιٷ� ���Ҷ��� �ְŵ�� �׷��� endl; �� �ٿ��ָ� �÷����� �ٷ� �ϰ� �ٹٲ޵� ���ִ� �ΰ��� ����� ���ÿ� �������ݴϴ�.
	//cerr ���� ��쿡�� �������. �׷��� endl; ��� �ٷ� ����� �Ѵٰ� �մϴ�. �׳� �׷��� �ִ������� �˾Ƶ� �ȴ�.

	//8 �ٵ� ���� �ƿ� �ϴ� ĳġ�� ���ϴ� ��쿡�� ��� �ɱ�? �翬�� ��Ÿ�ӿ����� ���. �Ǵٸ� ������� ��� ��� ĸ�ĸ� ����� �ȴ�. ������ ���� ���� ����
	catch (...) { //9 ellipses(...)�� �־��ָ� �Ÿ���̵� �� �޾��ش� ��� �ǹ̰� �ȴ�.
		cerr << "ellipses exception" << endl;
	}

	cout << "end main" << endl;



	return 0;
}