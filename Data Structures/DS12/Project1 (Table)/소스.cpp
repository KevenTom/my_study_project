#include <iostream>
#include"Person.h"
#include"Table.h"

using namespace std;

int MyHashFunc(Key k) { //사용할 해쉬 함수
	return k % 100;
}

int main(){
	Table<Person> myTbl(MyHashFunc); //테이블 생성
	Person* np;

	np = new Person(20120003, (char*)"Lee", (char*)"Seoul"); //데이터 추가
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20120012, (char*)"KIM", (char*)"Jeju");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20170049, (char*)"HAN", (char*)"Kangwon");
	myTbl.TBLInsert(np->GetSSN(), np);


	np = myTbl.TBLSearch(2012003); //데이터 탐색
	if (np != NULL)
		np->ShowPerInfo();

	np = myTbl.TBLSearch(2012012);
	if (np != NULL)
		np->ShowPerInfo();

	np = myTbl.TBLSearch(20170049);
	if (np != NULL)
		np->ShowPerInfo();


	np = myTbl.TBLDelete(2012003); //데이터 삭제
	if (np != NULL)
		delete np;

	np = myTbl.TBLDelete(2012012);
	if (np != NULL)
		delete np;

	np = myTbl.TBLDelete(20170049);
	if (np != NULL)
		delete np;


	return 0;
}