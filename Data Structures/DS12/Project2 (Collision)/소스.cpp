#include <iostream>
#include"Person.h"
#include"Table.h"

using namespace std;

int MyHashFunc(Key k) { //사용할 1차 해쉬 함수
	return k % 15;
}
int MyhashFunc2(Key k) { //사용할 2차 해쉬 함수
	return 1 + (k % 7);
}

int main(){
	Table<Person> myTbl(MyHashFunc, MyhashFunc2);
	Person* np;

	np = new Person(3, (char*)"Lee", (char*)"Seoul"); //데이터 추가
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(18, (char*)"KIM", (char*)"Jeju");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(33, (char*)"HAN", (char*)"Kangwon");
	myTbl.TBLInsert(np->GetSSN(), np);


	np = myTbl.TBLSearch(3); //데이터 탐색
	if (np != NULL)
		np->ShowPerInfo();

	np = myTbl.TBLSearch(18);
	if (np != NULL)
		np->ShowPerInfo();

	np = myTbl.TBLSearch(33);
	if (np != NULL)
		np->ShowPerInfo();


	np = myTbl.TBLDelete(3); //데이터 삭제
	if (np != NULL)
		delete np;

	np = myTbl.TBLDelete(18);
	if (np != NULL)
		delete np;

	np = myTbl.TBLDelete(33);
	if (np != NULL)
		delete np;


	return 0;
}