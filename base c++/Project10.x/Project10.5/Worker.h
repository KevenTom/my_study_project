#pragma once
//6 #include "Timer.h" //4 인클루드했으니까 워커가 타이머에 대해 정보를 알고 있다.

class Worker  //5 Worker.cpp 파일을 만들고 거기에 dosomething의 정의를 해 놨다. 이러면 "Timer.h"를 인클루드 할 필요가 있을까? 답은 필요없다. Worker.cpp 파일에만 있으면 된다.
{				//이렇게 선언할대는 가벼운관계가 되어 버린다. 작동해보면 문제 없다.
				//여기서 중요한건 이 의존관계는 클래스레벨에서는 몰라도 상관 없다. 구현하는 단계에서 필요하다.
public:
	void doSomething(); //7 이렇게 되어 있다고 하면 뭔가 의존관계를 이용해서 갖다 썻나보다 추측했다고 생각하면 됩니다. 이 패턴이 가장 많이 볼 패턴입니다. 마찬가지로 동영상 마지막 부분
	//5 {
	//	Timer timer; // 타이머 시작

	//	//시간 재는중

	//	timer.elapsed(); //타이머끝
	//}
};