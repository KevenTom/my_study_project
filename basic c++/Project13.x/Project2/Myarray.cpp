#include "Myarray.h"

template<typename T>
void Myarray<T>::print() { //11 2�� �ű�ϱ� �����߳� ������ �߻��ϴ� ������ Ȯ���ϱ� ���� ���� ������ �˾ƺ��� �ҽ�.cpp ���� (���� �� �ڵ尡 template�� �ƴϾ��ٸ� ���� �����Ѵ�)
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}//12 ���� ������� �� �ڵ带 ������ �Ҷ� char Ÿ������ ������ �ؾ��Ѵٰ� �˷��ִ� ����� �ִ�. �̰� explicit instantiation �̶� �θ��ϴ�.
//�Լ� ���ø��� �Ҷ��� �ڵ����� �ν��Ͻÿ��̼� ������?
//���� �ڵ尡 ������Ͽ� �������� �ڵ����� �ν��Ͻÿ��̼��� ������?
//�̹����� cpp���Ͽ� �ֱ� ������ �����Ϸ��� �˼��ֱ� ����� ������ ��������� �ν��Ͻ�ȭ(explicit instantiation)�� ����� �Ѵ�

//15 2template void Myarray<double>::print();
//template void Myarray<char>::print(); //13 ������ �����ϴ� 

//14 �׷��� cpp�� �Ű��ִ� �Լ��� �������� �Ź� �̷��� ���ֱ�� ���ŷ���

//15 2Ŭ���� ��ü�� �ν��Ͻÿ��̼� ���ִ� ����� �ֽ��ϴ�. ��
template class Myarray<char>;
template class Myarray<double>;