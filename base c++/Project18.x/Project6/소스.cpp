//지금까지는 콘솔 입출력으로 구성되어 있었죠
//실무에서는 파일을 어떻게 다루는지가 더 중요합니다.
//여기서는 기본적인 파일 입출력에 대해서 알아보겠습니다.
#include<iostream>
#include<fstream> //파일스트림
#include<string>
#include<cstdlib>
#include<sstream>

using namespace std;

int main() {
	//writing
	if (false) {
		//1 ofstream을 만듭니다. 이때 my_firest_file 파일이 없을경우 자기가 만들어 줍니다. 파일이 있으면 엽니다.
		ofstream ofs("my_firest_file.dat"); //9 ("my_firest_file.dat", ios::app) append를 붙여줄수 있는데 이러면 파일에 계속 이어서 직업한다는 것입니다. 이외 여러가지가 있습니다. 끝
		//ofs.open("my_firest_file.dat"); 아니면 이렇게 별도로 open 할수도 있습니다.
		
		if (!ofs) { //2 만약 파일을 열수 없었다면 오류와 exit를 해줍니다.
			cerr << "Couldn't open file" << endl;
			exit(1); //이처럼 파일입출력은 예외처리라던지 예상되는 오류에 대해서 조금더 신중하게 준비할 필요가 있습니다.
		}

		//3 파일스트림 역시 스트림이기 때문에 지금까지 스트림을 사용해왔던 방식 그대로 사용하실수 있습니다.
		ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;



		//ofs.close(); //보통 코딩을 하면 스코프안에서 코딩을 하기 때문에 스코프를 벗어나면 ofs가 사라집니다. 물론 이렇게 직접 닫아줄수도 있습니다. 굳이 쓰실필요는 없지만
	}

	//reading
	if (false) {
		//4 그러면 읽어보는 방법도 알아봅시다.
		ifstream ifs("my_firest_file.dat");

		if (!ifs) {
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		while (ifs) {
			string str;
			getline(ifs, str);

			cout << str << endl;
		}
	}//크게 차이나지는 않습니다.



	//5 이번에는 바이너리로 저장하는 방법을 말씀드리겠습니다.
	//아스키포맷으로 데이터를 전부 저장하는 방법이 있는데 엄청 느립니다. 만약게임 로딩을 아스키포맷으로 하면 하루가 걸릴정도로 느린다고 한다.
	//그래서 실무에서는 바이너리로 저장하는 경우가 많습니다.
	if (true) {
		ofstream ofs("my_firest_file.dat");

		if (!ofs) { 
			cerr << "Couldn't open file" << endl;
			exit(1); 
		}

		//6 바이너리로 저장할때는요 이 데이터가 어디까지인지 알수 없어요 이진수로 저장이 되어있다고 보시면 됩니다.
		//그래서 어떤데이터가 얼마만큼 몇개가 저장이 될지를 미리 약속을해서 우리가 알고있어야 합니다. 그러니까 저장하는사람과 읽는사람이 약속을 하고 있어야 합니다.
		const unsigned num_data = 10; //언사인드 int로 데이터가 몇개인지 숫자 하나를 저장한다고 약속했습니다.
		ofs.write((char*)&num_data, sizeof(num_data)); //언사인드int인 num_data의 포인터를 char포인터로 캐스팅해서 write함수의 파라미터에 넣어주고 있습니다. 
		//num_data가 10 이라는 숫자를 담고 있으니까 언사인트 int만큼 바이트를 저장해야되겠죠

		for (int i = 0; i < num_data; ++i) //여기에서는 그에 맞게 10개의 데이터를 저장하고 있습니다. 
			ofs.write((char*)&i, sizeof(i));
	}

	if (true) {
		ifstream ifs("my_firest_file.dat");

		if (!ifs) {
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		//7 바이너리를 읽는 방법입니다.
		unsigned num_data = 0; 
		ifs.read((char*)&num_data, sizeof(num_data)); //언사인트 int가 저장되어 있으니까 그걸 먼저 읽어들여서 데이터가 몇개있는지 확인을 하고

		for (unsigned i = 0; i < num_data; ++i) { //읽어드리는 방식입니다.
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}
	}
	//8 실행하면 잘 나오고 파일을 열어보면 이상하게 되어있습니다. 바이너리라서 문서프로그램으로 읽을수 없습니다.  


	return 0;
}