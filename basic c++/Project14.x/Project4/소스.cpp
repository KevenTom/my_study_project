//�� ���ǿ��� ����Ŭ������ ����� ����� ���� ������ ��Ƚ��ϴ�.
//�̹����� ���Ĵٵ� ���̺귯���� ���ԵǾ��ִ� std::exception Ŭ������ ���� ������ �帮�ڽ��ϴ�.
//std::exception�� ���� �پ��� ��쿡 ���ؼ� �̹� ���� �����Ǿ��ֱ� ������ �츮�� �ϳ��ϳ� ����Ŭ������ �����ʿ� ���� ���ݴϴ�.
#include<iostream>
#include<exception>//1 ���ø� exception�� ��Ŭ��� ���ּž� ����Ͻ� �� �ֽ��ϴ�.
#include<cstring>

using namespace std;

class CustomException : public exception {//6 �̹����� exceptionŬ������ ��ӹ޾Ƽ� ���ο� Ŭ������ ����� �ý��ϴ�.
public:
	const char* what() const noexcept override {//7 ��� �ٸ� exceptionŬ����ó�� �۵��ϰ� �Ϸ��� �ٸ� Ŭ������ó�� what() �Լ��� �������̵� ����� �մϴ�. (noexcept�� noexcept�پ��ִ� �ٵ� �ȿ����� ���ܸ� ������ �ʰڴ� ��� ����, c++11���ʹ� noexcept�� �ٿ���� �Ѵٰ� ��)
		return "custom exception";
	}
};

int main() {
	try {
		//7 3string s;
		//s.resize(-1); //2 �ǵ������� ������ �����׽��ϴ�. ����� ���� ǥ�ض��̺귯������ �̻��Ѱ� �����ϸ� ���ο��� exception�� ���ο� �ϰ� �Ǿ� �ֽ��ϴ�.

		//5 �������� ���� Ŭ������ ����鼭 std::exception �� ����ϰ� �������� �ְ���? �Ʒ�ó�� �ϸ� �˴ϴ�.
		//7 3throw runtime_error("bad");
		
		throw CustomException(); //7 3 �۵��ǳ� �ѹ� ���ܸ� �������ô�. �� �۵��ϳ׿� ��
	}
	catch (exception & exception) {//3 ����� exception�� �θ�Ŭ������.
		cout << typeid(exception).name() << endl; //4 typeid�� name�� ���� �ڽ�Ŭ������ length_error Ŭ������ ����Դٴ°��� Ȯ���� �� �ֽ��ϴ�.
												//�ƴϸ� ���۷��� �޴��󿡼� ã�ƺ��� �� �� �ִ�. http://www.cplusplus.com/reference/string/string/resize/
		cerr << exception.what() << endl; //3 �ٵ� �� ������ ��ٰ� �ߴ°ɱ�? ����ε忡�� -1�ϸ� 9999999... �Ǽ� �׷�
	}


	return 0;
}