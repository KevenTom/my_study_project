#include <iostream>
#include"Table.h"

using namespace std;

int MyHashFunc(Key k) {
	return k % 100;
}

int main(){
	Table<Person> myTbl(MyHashFunc);
	Person* np;

	np = new Person(20120003, (char*)"Lee", (char*)"Seoul");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20120012, (char*)"KIM", (char*)"Jeju");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20170049, (char*)"HAN", (char*)"Kangwon");
	myTbl.TBLInsert(np->GetSSN(), np);


	np = myTbl.TBLSearch(2012003);
	if (np != NULL)
		np->ShowPerInfo();

	np = myTbl.TBLSearch(2012012);
	if (np != NULL)
		np->ShowPerInfo();

	np = myTbl.TBLSearch(20170049);
	if (np != NULL)
		np->ShowPerInfo();


	np = myTbl.TBLDelete(2012003);
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