//������������Ҷ� �׻� ���������θ� �۾��Ҽ� �ִ°� �ƴϰ���
//�̹� �����ϴ� ������ �߰��� �ʿ��� �κ��� ã�Ƽ� �׺κи� �Ϻ� �����Ҽ��� �����Ű� �� ��ü Ŀ�ٶ� ���Ͽ��� �ʿ��� �κи� �������� �ֽ��ϴ�.
//������ ���� ��ġ �����ϴ� ����� ������ �帮�ڽ��ϴ�.
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	if (true) {
		const string filename = "my_file.txt";

		//make file
		//1 a���� z���� ���Ͽ� �Է����Դϴ�.
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;


		//read the file
		//2 filename�� �дµ� �� ���Ƕ��� �ణ �ٸ��ϴ�.
		ifstream ifs(filename);

		ifs.seekg(5); //seekg�� ó������ 5����Ʈ �̵��϶�´� ���Դϴ�.
		cout << (char)ifs.get() << endl;
		ifs.seekg(5, ios::cur); //cur�� ���� ���� ��ġ���� 5����Ʈ �̵��Ѵٴ� ���Դϴ�.
		cout << (char)ifs.get() << endl;
		cout << (char)ifs.get() << endl; //get�� ��� �����ִϱ� �������� �о��ݴϴ�.
		ifs.seekg(2); //seekg�� �ϴϱ� �ٽ� ó������ �о��ִ°��� �˼� �ֽ��ϴ�.
		cout << (char)ifs.get() << endl;
		ifs.seekg(-5, ios::end); //end�� ������ �̵��Ѵٴ� ���Դϴ�
		cout << (char)ifs.get() << endl;
		ifs.seekg(0, ios::end);
		cout << ifs.tellg() << endl; //tellg�� ������ġ�� �˷��ݴϴ�.
		ifs.seekg(10);
		string str;
		getline(ifs, str); //�̷��� 10����Ʈ �ں��� getline�� ���ְ���
		cout << str << endl;
		//f
		//l
		//m
		//c
		//x
		//28
		//klmnopqrstuvwxyz
		//�����ϸ� �� �۵��ϴ°��� �˼� �ֽ��ϴ�.


		//3�̹����� �б⵵ �ϰ� ���⵵ �ϴ� ����� �˾ƺ��ڽ��ϴ�.
		fstream iofs(filename); //ofstream�� �ƴϰ� ifstream�� �ƴ�, �׳� fstream���� �ʱ�ȭ���ֽø� �˴ϴ�.

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; //�б⵵ �ϰ�
		iofs.seekg(5);
		iofs.put('A');//put���� ���⵵ �մϴ�.
		iofs.seekg(5);
		cout << (char)iofs.get() << endl; //�ٽ� �о�ý��ϴ�.
		//f
		//A
		//�� �۵��մϴ� ��
	}



	return 0;
}