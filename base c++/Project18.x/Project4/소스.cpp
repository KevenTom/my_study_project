//����ڷκ��� �Է��� �޾Ƶ帱�� Ȥ�� ���Ϸκ��� �����͸� �о���϶� �׻� �츮�� �ǵ��Ѵ�� �Է��� ���´ٴ� ������ ����
//�׷��� �Ź� ��Ʈ���� ���� ���°� ���, �׸��� �Է¹��� �����Ͱ� �츮�� �ǵ��ѰͰ� ��ȣ����(validation) Ȯ���ϴ� ������ �ʿ��Ұ̴ϴ�. �� �ΰ����� ���ؼ� �˾ƺ��ô�.
#include<iostream>
#include<cctype>
#include<string>
#include<bitset>

using namespace std;

void printStates(const std::ios& stream) { //3 �Ķ���ͷ� ios�� �޽��ϴ�. �θ�ν� ���� Ŭ������ 
//iosŬ�����δ� ����� �۾��� ���¸� ó���Ҽ� �ֽ��ϴ�. ���� ����, �ܼ� �ΰ��� ���������� ����ϽǼ� �ֽ��ϴ�.
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl; //good ���������� �۵��ߴ��� üũ��
	cout << "eof()=" << stream.eof() << endl; //eof ������ �� �о����� äũ��
	cout << "faill()=" << stream.fail() << endl; //fail �����ߴ��� üũ��
	cout << "bad()=" << stream.bad() << endl; //bad ������ �߻��ϴ��� üũ��
} //�Ǵ� ios::rdstate �� ��Ʈ�÷��׷� �޾ƿü� ������ �� ��������� �ʴ´ٰ� �� http://www.cplusplus.com/reference/ios/ios/rdstate/ ���� 6�к��� ����

void printCharacterClassification(const int& i) {//6 �Ʒ��� std::���� cctype�� ����ֽ��ϴ�. �������� �𸥴ٸ� �˻� ��
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl; //Ŀ���� ���ٴ뺸�� int�� ������ �ݴϴ�. �׷��� �̹����� bool�� ĳ������ �ý��ϴ�
	cout << "isblank " << bool(std::isblank(i)) << endl; //97�� �Է��ϸ� �ƽ�Ű�ڵ�� 'a'�� ���������� �۵���
	cout << "isdigit " << bool(std::isdigit(i)) << endl; //��ĭ�� �Է��ص� blank�� �۵����� �ʴ´�. �翬�� cin������ ���⸦ �����ϴ� �뵵�� ����Ѵٰ� ������ �����
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;
}

bool isAlldigit(const string& str) { //8 ���ø� �˰����� �ϳ��ϳ� �����ϴ� ����Դϴ�. ��
	bool ok_flag = true;
	for (auto& e : str)
		if (!isdigit(e)) {
			ok_flag = false;
			break;
		}
	return ok_flag;
}

int main() {
	while (true) {
		int i;
		cin >> i; //1 int Ÿ���̴ϱ� ���ڰ� ���� �ϴµ� ���ڰ� ���ð�� ������ �������

		printStates(cin); //2 �׷��� ��Ʈ���� � �������� Ȯ���ϴ� �Լ��� ����� �ý��ϴ�.
		cout << i << endl;
		printCharacterClassification(i); //5 �Ǵ� ���¸� Ȯ���ϴ°� �ܿ� ���� ���ϴ� ���������� �����ϴ� ����� �ֽ��ϴ�.

		cin.clear();
		cin.ignore(1024, '\n'); //4 ignore�� ���ڵ� ������ �ֽ��ϴ�. �о���� ������ ����, �о���̸� ������ ����
	}


	//7 �Է��� ������ �츮�� ���� ���ϴ� ���·� �Դ��� Ȯ���� �ؾ��Ҷ��� �����ϴ�.
	//���� ������ �帮�°Ŵ� �ѱ����ѱ��� �� ���ϴ� ����Դϴ�. ���� ���ǿ� ��� ����������(regular expression)�� ����ϸ� �ξ� �������ϴ�.
	//������ ����ǥ�������� ����Ѵٰ� �մϴ�.
	cout << boolalpha;
	cout << isAlldigit("1234") << endl;
	cout << isAlldigit("a1234") << endl;


	return 0;
}