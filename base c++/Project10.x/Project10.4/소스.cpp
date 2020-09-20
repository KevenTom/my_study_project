//앞에서 배운 컴포지션이나 어그리게이션은 한쪽이 확실히 주가 되고 다른쪽이 부품, 파트같은 역할을 두게 됩니다. 이번에는 어느쪽이 확실히 주가되고 부인지 명확한지 않은 경우, 둘다 주가될수있고 부가 될수있는
//제휴관계(Association)에 대해 알아봅시다.
#include"Doctor.h"
#include"Patient.h"

using namespace std;


void Patient::meetDoctors() {
	for (auto& ele : m_doctors) {
		std::cout << "Meet doctor : " << ele->m_name << std::endl;
	}
}

void Doctor::meetPatients() {
	for (auto& ele : m_patients) {
		std::cout << "Meet patient : " << ele->m_name << std::endl;
	}
}
//3 오류 발생 : 전방선언한 doctor가 m_name이 있는지 없는지 모름 ->아래로 빼자

int main() {
	Patient* p1 = new Patient("JACK JACK");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	p1->addDoctor(d1);
	d1->addPatient(p1); //2 p1이 d1를 만나고 d1도 p1을 만난다. 상호적이다

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);


	//patients meet doctors
	p1->meetDoctors();

	//doctors meet patients
	d1->meetPatients();


	//delets
	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;


	//5 정리 : 클래스 patient, docotr는 서로 제휴관계이다. 그러면 서로 상대방을 멤버로써 갖고 있다.
	//마찬가지로 마지막 부분 확인


	return 0;
}