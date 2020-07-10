//앞에는 문법적인 소개라면 이번에는 구채적인 사례로 보여드리기 위한 챕터입니다. 여러분이 코딩할수록 이런 정리하는 과정을 거치면서 익숙해집니다.
#include "Student.h"
#include "Teacher.h"

using namespace std;


int main()
{
	Student std("JACK JACK");
	std.setName("JACK JACK2");//9 Student 에는 setNane함수가 없지만 사용할수 있지?? 부모클래스인 펄슨에 있잖아!
	cout << std << endl;
	
	Teacher teacher1("Dr. H");
	cout << teacher1.getName() << endl;

	teacher1.doNothing();//13 2
	//14 마지막으로 스튜던트에 만든거는 펄슨, 티쳐에서 사용할수 없는거 당연히 알아서 작성 안함, 동영상 마지막 부분 간단한 요약임 끝
	return 0;
}