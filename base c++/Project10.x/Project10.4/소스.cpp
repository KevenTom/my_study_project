//�տ��� ��� ���������̳� ��׸����̼��� ������ Ȯ���� �ְ� �ǰ� �ٸ����� ��ǰ, ��Ʈ���� ������ �ΰ� �˴ϴ�. �̹����� ������� Ȯ���� �ְ��ǰ� ������ ��Ȯ���� ���� ���, �Ѵ� �ְ��ɼ��ְ� �ΰ� �ɼ��ִ�
//���ް���(Association)�� ���� �˾ƺ��ô�.
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
//3 ���� �߻� : ���漱���� doctor�� m_name�� �ִ��� ������ �� ->�Ʒ��� ����

int main() {
	Patient* p1 = new Patient("JACK JACK");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	p1->addDoctor(d1);
	d1->addPatient(p1); //2 p1�� d1�� ������ d1�� p1�� ������. ��ȣ���̴�

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


	//5 ���� : Ŭ���� patient, docotr�� ���� ���ް����̴�. �׷��� ���� ������ ����ν� ���� �ִ�.
	//���������� ������ �κ� Ȯ��


	return 0;
}