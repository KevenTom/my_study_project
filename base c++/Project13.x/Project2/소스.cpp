//�Լ� ���ø����� ���ø��� ����ϸ� ���ϴٶ�°� �˼� �־����ϴ�.
//�̹����� Ŭ������ ���ø� �ϴ� ����� ���� �˾ƺ��ô�.
#include<iostream>
#include"Myarray.h" //1 ������Ͽ� ��� Ŭ������ ����

using namespace std;


int main() {
	//5 2Myarray my_array(10); //4 ��? ������ �߳�?
							//������ �о�� �Ű������� �� ���ڰ� ������ �ȉ�ٰ��Ѵ�.

	Myarray<char> my_array(10); //5 2�̷��� �������ָ� �ȴ�.

	//11 2���� ���� �����Ϸ��� "myarray��� Ŭ������ char ��� ������Ÿ�Կ� ���ؼ� �ν��Ͻÿ��̼��� �ؾ��ϴ� �ű���" ��� �ͱ����� �˼� �ִ�.
	//�׷��� myarray.h ���� void print(); �� �ٵ� �������� �Ҷ��� myarray.cpp ���� �������� ���ݾƿ�
	//�׷��� ���ο����� "Myarray.h"�� ��Ŭ��� �ϱ� ������ myarry.cpp �� char Ÿ������ �ؾ��Ѵٴ� ������ �����
	//�׷��ٸ� ���ο� #include"Myarray.cpp"�� ��Ŭ��� �ϸ� �ذ��Ҽ� �ְ���?? �ذ��� �� ������ �̷��� ���߿� �������� ���� ������ ������ ����� ������ ���� �̷� ����� X

	//���ͳݿ��� �� ���� : https://m.blog.naver.com/PostView.nhn?blogId=swkang7229&logNo=220160000206&proxyReferer=https:%2F%2Fwww.google.com%2F

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print(); //2 �������� ����ϴ°��� Ȯ���� �� �ֽ��ϴ�.

	return 0;
}