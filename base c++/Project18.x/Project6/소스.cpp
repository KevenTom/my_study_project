//���ݱ����� �ܼ� ��������� �����Ǿ� �־���
//�ǹ������� ������ ��� �ٷ������ �� �߿��մϴ�.
//���⼭�� �⺻���� ���� ����¿� ���ؼ� �˾ƺ��ڽ��ϴ�.
#include<iostream>
#include<fstream> //���Ͻ�Ʈ��
#include<string>
#include<cstdlib>
#include<sstream>

using namespace std;

int main() {
	//writing
	if (false) {
		//1 ofstream�� ����ϴ�. �̶� my_firest_file ������ ������� �ڱⰡ ����� �ݴϴ�. ������ ������ ���ϴ�.
		ofstream ofs("my_firest_file.dat"); //9 ("my_firest_file.dat", ios::app) append�� �ٿ��ټ� �ִµ� �̷��� ���Ͽ� ��� �̾ �����Ѵٴ� ���Դϴ�. �̿� ���������� �ֽ��ϴ�. ��
		//ofs.open("my_firest_file.dat"); �ƴϸ� �̷��� ������ open �Ҽ��� �ֽ��ϴ�.
		
		if (!ofs) { //2 ���� ������ ���� �����ٸ� ������ exit�� ���ݴϴ�.
			cerr << "Couldn't open file" << endl;
			exit(1); //��ó�� ����������� ����ó������� ����Ǵ� ������ ���ؼ� ���ݴ� �����ϰ� �غ��� �ʿ䰡 �ֽ��ϴ�.
		}

		//3 ���Ͻ�Ʈ�� ���� ��Ʈ���̱� ������ ���ݱ��� ��Ʈ���� ����ؿԴ� ��� �״�� ����ϽǼ� �ֽ��ϴ�.
		ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;



		//ofs.close(); //���� �ڵ��� �ϸ� �������ȿ��� �ڵ��� �ϱ� ������ �������� ����� ofs�� ������ϴ�. ���� �̷��� ���� �ݾ��ټ��� �ֽ��ϴ�. ���� �����ʿ�� ������
	}

	//reading
	if (false) {
		//4 �׷��� �о�� ����� �˾ƺ��ô�.
		ifstream ifs("my_firest_file.dat");

		if (!ifs) {
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		while (ifs) {
			string str;
			getline(ifs, str);

			cout << str << endl;
		}
	}//ũ�� ���̳����� �ʽ��ϴ�.



	//5 �̹����� ���̳ʸ��� �����ϴ� ����� �����帮�ڽ��ϴ�.
	//�ƽ�Ű�������� �����͸� ���� �����ϴ� ����� �ִµ� ��û �����ϴ�. ������� �ε��� �ƽ�Ű�������� �ϸ� �Ϸ簡 �ɸ������� �����ٰ� �Ѵ�.
	//�׷��� �ǹ������� ���̳ʸ��� �����ϴ� ��찡 �����ϴ�.
	if (true) {
		ofstream ofs("my_firest_file.dat");

		if (!ofs) { 
			cerr << "Couldn't open file" << endl;
			exit(1); 
		}

		//6 ���̳ʸ��� �����Ҷ��¿� �� �����Ͱ� ���������� �˼� ����� �������� ������ �Ǿ��ִٰ� ���ø� �˴ϴ�.
		//�׷��� ������Ͱ� �󸶸�ŭ ��� ������ ������ �̸� ������ؼ� �츮�� �˰��־�� �մϴ�. �׷��ϱ� �����ϴ»���� �д»���� ����� �ϰ� �־�� �մϴ�.
		const unsigned num_data = 10; //����ε� int�� �����Ͱ� ����� ���� �ϳ��� �����Ѵٰ� ����߽��ϴ�.
		ofs.write((char*)&num_data, sizeof(num_data)); //����ε�int�� num_data�� �����͸� char�����ͷ� ĳ�����ؼ� write�Լ��� �Ķ���Ϳ� �־��ְ� �ֽ��ϴ�. 
		//num_data�� 10 �̶�� ���ڸ� ��� �����ϱ� �����Ʈ int��ŭ ����Ʈ�� �����ؾߵǰ���

		for (int i = 0; i < num_data; ++i) //���⿡���� �׿� �°� 10���� �����͸� �����ϰ� �ֽ��ϴ�. 
			ofs.write((char*)&i, sizeof(i));
	}

	if (true) {
		ifstream ifs("my_firest_file.dat");

		if (!ifs) {
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		//7 ���̳ʸ��� �д� ����Դϴ�.
		unsigned num_data = 0; 
		ifs.read((char*)&num_data, sizeof(num_data)); //�����Ʈ int�� ����Ǿ� �����ϱ� �װ� ���� �о�鿩�� �����Ͱ� ��ִ��� Ȯ���� �ϰ�

		for (unsigned i = 0; i < num_data; ++i) { //�о�帮�� ����Դϴ�.
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}
	}
	//8 �����ϸ� �� ������ ������ ����� �̻��ϰ� �Ǿ��ֽ��ϴ�. ���̳ʸ��� �������α׷����� ������ �����ϴ�.  


	return 0;
}