//1 ���� ���迡���� Ŭ������ ����������� ������ �� �ְ� �ִ� ���¿��� �̹����� �װͺ��� ���ݴ� �������� ������ ����(association) ���� ������ �񱳸� �ϸ鼭 ������ �帮�ڽ��ϴ�
#include "Lecture.h"




int main()
{

	Teacher teacher1("Prof Hong");
	Teacher teacher2("prof good");

	Student std1("Jack Jack", 0);//15 �� �ּҸ� �����ٰ� ����ϱ� ������ �����л�, ���������͸� ����ϱ� ������ lec1, lce2���� �Ȱ��� ������ ���� Ȯ���� �� �ִ�.
								//���� ���� ������� ����ߴٸ� ������ ��Ʃ��Ʈ���� ���ε��� �޸𸮰� �ٸ��� ������ �˻��ϴ� ������ �ڵ��� �ؾ��ϱ� ������ ������.
	Student std2("Dash", 1);
	Student std3("Violet", 2);
	//16 ��� ���� ���� �Լ��� �������� ���� ���� ��������̱� ������ �����Լ��� ������ ��� �������. 
	//���� �ٸ��������� ��� ����ϰ� �ʹٸ� �̰� �����Ҵ����� ����ϱ⵵ �մϴ�. Student std1 = new Studnet("Jack Jack", 0); �翬�� delete�� �ؾ��Ѵ�.
	//17 ���������� ������ ������ �κ� ����

	//8 Lecture lec1("Introduction to Computer Programming");
	//lec1.assignTeacher(Teacher("Prof Hong"));
	//lec1.registerStudent(Student("Jack Jack", 0)); //7 �˰����� lec2�� JACK JACK�� ���� �����Ͱ� �ƴϴ�.
	//lec1.registerStudent(Student("Dash", 1));
	//lec1.registerStudent(Student("Violet", 2));

	//Lecture lec2("computational Thinking");
	//lec2.assignTeacher(Teacher("prof good"));
	//lec2.registerStudent(Student("Jack Jack", 0)); //7 �˰����� lec1�� JACK JACK�� ���� �����Ͱ� �ƴϴ�.


	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);
	lec1.registerStudent(&std3);

	Lecture lec2("computational Thinking");
	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(&std1); //9 �����غ��� ������ �ȿö��



	//6 �����غ��� �۵��� ������ ���� �л��� lec1, lec2 ������ �ٸ���. �ٸ� �����͸� ���ϱ�, �ذ��ϱ� ���� �̹����� ���� ����� �ٲ㺸��.
	{
		std::cout << lec1 << std::endl;
		std::cout << lec2 << std::endl;

		lec2.study();

		std::cout << lec1 << std::endl;
		std::cout << lec2 << std::endl;
	}
	return 0;
}