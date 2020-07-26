//STL 컨테이너들을 사용할때 여러 도구들이 들어있는 알고리즘(algorithms)을 살펴보겠습니다. 참고로 알고리즘과목에서 알고리즘을 배우지 않고 자료구조에서 배웁니다.
//교수님 말로는 알고리즘보단 유틸리티에 가깝다고 한다.
//당연히 알고리즘안에는 엄청 많은것들이 존재합니다.
//그중 몇가지를 소개해 드리겠습니다.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	//1 저번에 사용한 벡터입니다.
	vector<int> container;
	//3 마찬가지로 list로 바꿀수 있습니다. 대신 list는 자기 클래스에 들어 있기 때문에 예를들어 정렬할꺼면 container.sort(); 이렇게 해줘야 한다. 끝
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto itr1 = min_element(container.begin(), container.end()); //2 min_element로 입력받은 값 중에 가장 작은 값을 받을 수 있습니다.
	cout << itr1[0] << endl;
	auto itr2 = max_element(container.begin(), container.end()); //max는 당연히 아시겠죠?
	cout << itr2[0] << endl;

	itr1 = find(container.begin(), container.end(), 3); //또는 find로 특정한걸 찾을수도 있습니다. 이렇게 하면 itr1이 3의 위치를 가리키게 됩니다.
	container.insert(itr1, 128);

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end()); //이렇게 순서도 바꾸거나

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end()); //정렬할수도 있습니다.

	for (auto& e : container)
		cout << e << " ";
	cout << endl;


	return 0;
}