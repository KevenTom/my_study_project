//유니크포인터와 달리 소유권을 여러곳에 공유할 수 있는 std::shared_ptr에 대해서 알아봅시다.
#include<iostream>
#include"Resource.h"

using namespace std;

int main() {
	Resource* res = new Resource(3);
	res->setAll(1);

	std::shared_ptr<Resource> ptr1(res);
	//1 auto ptr1 = make_shared<Resource>(3);
	//ptr1->setAll(1);
	//사용법은 유니크포인터와 마찬가가지로 똑같습니다.
	//쉐어드포인터의 특징이 뭐냐면 자기가 가리키고 있는 주소의 포인터가 몇군데에서 공유(shared)하고 있는지를 셉니다.

	ptr1->print();

	{
		//2 ptr2에 ptr1을 넣었습니다. 유니크포인터와 달리 잘 작동하는것을 알 수 있습니다.
		shared_ptr<Resource> ptr2(ptr1);
		//shared_ptr<Resource> ptr2(res);
		//auto ptr2 = ptr1;
		//4 문제가 될수있는 사항을 말씀드리겠습니다.
		//ptr2에 ptr1이 아니라 res를 넣으면 어떻게 될까요? ptr2과 ptr1이 독립됩니다. 즉, 저대로 실행하면 res의 delete가 두번 이뤄지겠죠? 이렇게 하시면 안됩니다.
		//그래서 위처럼 	Resource* res = new Resource(3); 이렇게 딴대서 메모리 할당받고 그걸 포인터로 넣는 간접적인 방식으로는 사용하지는 않고 
		//위에서 auto ptr1 = make_shared<Resource>(3); 처럼 make_shared를 사용하여 직접적으로 사용하는 방식으로 하는것이 좋습니다.
		//그리고 auto ptr2 = ptr1; 이것도 간편하고 좋습니다.
		//유니크포인터보다 자유롭죠? 둘중 원하는걸 자유롭게 사용하시면 됩니다. 끝

		ptr2->setAll(3);
		ptr2->print();
		cout << "goig out of the block" << endl;
	}

	ptr1->print(); //3 ptr1의 소유권이 그대로 있다는 것을 알 수 있습니다.
	//그리고 소멸자가 호출이 안되죠 소유권을 공유하는 거라 생각하면 됩니다. 막 소유권 여러개 만드는게 아니라 공유가 몇개인지 기록해서 소멸해주는 방식입니다.
	cout << "goig out of the block" << endl;


	return 0;
}