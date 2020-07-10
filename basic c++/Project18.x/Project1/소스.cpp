//���ݱ��� iostream���� �Է��� �ޱ⵵ �ϰ� ����� �ϱ⵵ ����
//�̹����� istream�� ���� ���� �˾ƺ��ڽ��ϴ�
//����� �Է��ϰų� ����ϴ� �����͸� ��Ʈ��(stream)�̶� �θ���.
//�׸��� �������ִ� �Ŵ� �̷��� �ְ� �Ƿ��ϸ� ã�ư��� �ڱ⿡ �°� �����ϸ鼭 ����ϴ°� ���� �ڵ��̶�� �Ѵ�.
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main() {
	//1 ���ݱ��� ����ϰ� ����ؿ� �͵��� ���α����� ��� �۵��ϴ��� �˾ƺ��ô�.
	//�⺻������ stream�� ���ۿ� �ӽ������� ����Ǿ� �ִ°� �Ϻ� �������� ����Դϴ�.
	char buf[5];
	cin >> buf;
	cout << buf << endl;
	/*abcdefgh...*/
	//runtime error
	//cin���� �Է¹��� ���۸� buf�� ũ�� �̻��� �ַ��� �ϴϱ� ������ �߻�����

	//iomanop�� ��� ���� ������ ���� ����� �����մϴ�.
	//iomanop�� ���ǵǾ� �ִ� setw �Լ��� 
	//�Է¿��� setw�� �Ű����� ��ŭ�� ���ۿ��� ���� buf1�� �־� �ݴϴ�.
	//��µ� ������ �װ� ���� ���ǿ� �����帮�ڽ��ϴ�.
	char buf1[5];
	cin >> setw(5) >> buf1;
	cout << buf1 << endl;
	/*abcdefgh...*/
	//abcd
	//���� �Է��ص� �Ű�������ŭ �־��ذ��� Ȯ���� �� �ֽ��ϴ�.
	//�׷��� �Ű������� 5�ε� �� 4���� ��µɱ��? 
	//�翬�� �������� ���� �־�� �ϴϱ� �α��� ��ġ�� 5����

	//�׷��� ���ۿ� �ִ� �������� ��� �ɱ��? ��� ���ۿ� �ֽ��ϴ�.
	cin >> setw(5) >> buf1;
	cout << buf1 << endl;
	/*abcdefgh*/
	//abcd
	//efgh
	//���ڸ� ���� �Է��غ��� �ι� �Է����� �ʾƵ� �˾Ƽ� ���ۿ� �����͵��� �����Դ����� Ȯ���� �� �ֽ��ϴ�. 
	//�̷��� ���۷κ��� ���������� �������� ����Դϴ�.


	//2 �ݺ������� ���� �ϳ��ϳ��� ��� �޴� ����� �ֽ��ϴ�.
	char ch;
	while (cin >> ch)
		cout << ch;
	/*Hello word*/
	//Helloword
	//���α׷��� �ϴٺ��� ���⵵ ���Խ�Ű�� �������� �����ϴ�.
	//�츮�� cin���� �Է��Ҷ� ���⿡ ���� ���е���.
	//�׷��� ��ĭ�� �����ؼ� �������� ��� �ؾ� �ұ��

	//cin.get() �� ����Ͻø� �˴ϴ�.
	char ch1;
	while (cin.get(ch1))
		cout << ch1;
	/*Hello word*/
	//Hello word

	//get�� ������ �������ټ� �ֽ��ϴ�.
	//�翬�� �Ѿ�� �������� ���ۿ� �״�� �ֽ��ϴ�.
	char buf2[5];
	cin.get(buf2, 5);
	cout << buf2 << endl;
	/*ABCDEF*/
	//ABCD

	//���������� ���ۿ� �ִ°͵��� get���ε� �����ü� �ֽ��ϴ�.
	//�׸��� gcount ��� �Լ��� �ֽ��ϴ�. �����ϰ� �Է¹����� ����� �о����� ������ִ� �Լ��Դϴ�.
	char buf3[5];
	cin.get(buf3, 5);
	cout << cin.gcount() << " " << buf3 << endl;
	cin.get(buf3, 5);
	cout << cin.gcount() << " " << buf3 << endl;
	/*a bcd fg*/
	//4 a bc
	//4 d fg


	//3 �׸��� getline �Լ���°͵� �ֽ��ϴ�.
	char buf4[5];
	cin.getline(buf4, 5);
	cout << cin.gcount() << " " << buf4 << endl;
	cin.getline(buf4, 5);
	cout << cin.gcount() << " " << buf4 << endl;
	/*abcdefg*/
	//4 abcd
	//0
	//�ణ �ٸ��� �۵����� getline�� ������ �� �о���̰� 5�� ��ŭ �޾Ƶ��̰� ������ ���۸� ������� �̴ϴ�.
	//4���� ���Ϸ� ������ �Է��ϸ� �������� �۵��մϴ�.
	//�׸��� getline�� ī���Ͱ� +1 �϶��� �ִµ� ������ �ٹٲޱ��� ���� �о �׷��ٰ� �մϴ�.


	//4 string�� ����Ͻ� �� �ֽ��ϴ�.
	string buf5;
	getline(cin, buf5); //������ getline�Լ��� string�� �ִ°̴ϴ�.
	cout << cin.gcount() << " " << buf5 << endl;
	//����غ��� gcount�� 0�Դϴ� cin.���� ������ �ƴϱ� 0�� ������ �̴ϴ�.


	//5 ignore�� ���ڸ�ŭ ������ �ݴϴ�.
	char buf6[1024];
	cin.ignore(2);
	cin >> buf6;
	cout << buf6 << endl;
	/*Hello*/
	//llo


	//6 peek�� ���ۿ��� �� �״�� peek ó�� ������ �ʰ� ���⸸ �Ѵٰ� �����Ͻø� �˴ϴ�.
	char buf7[1024];
	cout << (char)cin.peek() << endl;
	cin >> buf7;
	cout << buf7 << endl;
	/*Hello*/
	//H
	//Hello


	//7 unget�� get�� �ݴ���
	//�������� �������� �ٽ� ���ۿ� ���� �ֽ��ϴ�.
	char buf8[1024];
	cin >> buf8;
	cout << buf8 << endl;
	cin.unget();
	cin >> buf8;
	cout << buf8 << endl;
	/*Hello*/
	//Hello
	//o


	//8 putback�� �Ķ���͸� ���ۿ� �־��ִ� ����Դϴ�.
	char buf9[1024];
	cin >> buf9;
	cout << buf9 << endl;
	cin.putback('A');
	cin >> buf9;
	cout << buf9 << endl;
	/*Hello*/
	//Hello
	//A


	//�׸��� ���ݱ��� �Ұ��ص帰 ����� �ܼ��� �ֿܼ����� ����ϴ°� �ƴϰ� 
	//���߿� ������ ������� �Ҷ��� �Ȱ��� ����ϽǼ� �ֽ��ϴ�. ��


	return 0;
}