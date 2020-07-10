//1 구성 관계에서는 클래스가 멤버변수들의 모든것을 꽉 주고 있는 형태였죠 이번에는 그것보다 조금더 느슨해진 관계인 집합(association) 관계 구성과 비교를 하면서 설명해 드리겠습니다
#include "Lecture.h"




int main()
{

	Teacher teacher1("Prof Hong");
	Teacher teacher2("prof good");

	Student std1("Jack Jack", 0);//15 이 주소를 가져다가 사용하기 때문에 같은학생, 같은데이터를 사용하기 때문에 lec1, lce2에서 똑같이 증가한 것을 확인할 수 있다.
								//구성 관계 방식으로 사용했다면 각각의 스튜던트들이 따로따로 메모리가 다르기 때문에 검사하는 복잡한 코딩을 해야하기 때문에 귀찮다.
	Student std2("Dash", 1);
	Student std3("Violet", 2);
	//16 모두 각각 메인 함수의 스코프에 속한 로컬 베리어블이기 때문에 메인함수가 끝나면 모두 살아진다. 
	//만약 다른곳에서도 계속 사용하고 싶다면 이걸 동적할당으로 사용하기도 합니다. Student std1 = new Studnet("Jack Jack", 0); 당연히 delete도 해야한다.
	//17 마찬가지로 동영상 마지막 부분 보기

	//8 Lecture lec1("Introduction to Computer Programming");
	//lec1.assignTeacher(Teacher("Prof Hong"));
	//lec1.registerStudent(Student("Jack Jack", 0)); //7 알겠지만 lec2의 JACK JACK과 같은 데이터가 아니다.
	//lec1.registerStudent(Student("Dash", 1));
	//lec1.registerStudent(Student("Violet", 2));

	//Lecture lec2("computational Thinking");
	//lec2.assignTeacher(Teacher("prof good"));
	//lec2.registerStudent(Student("Jack Jack", 0)); //7 알겠지만 lec1의 JACK JACK과 같은 데이터가 아니다.


	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);
	lec1.registerStudent(&std3);

	Lecture lec2("computational Thinking");
	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(&std1); //9 실행해봐도 여전히 안올라옴



	//6 실행해보면 작동은 하지만 같은 학생의 lec1, lec2 지능이 다르다. 다른 데이터를 쓰니까, 해결하기 위해 이번에는 집합 관계로 바꿔보자.
	{
		std::cout << lec1 << std::endl;
		std::cout << lec2 << std::endl;

		lec2.study();

		std::cout << lec1 << std::endl;
		std::cout << lec2 << std::endl;
	}
	return 0;
}