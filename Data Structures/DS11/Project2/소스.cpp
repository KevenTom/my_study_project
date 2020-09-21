#include"BinartSerachTree.h"
#include<iostream>

using namespace std;



void ShowData(int data) {
	cout << data << " ";
}


int main() {
	BinartSerachTree<int> asd;

	asd.MakeSearchTree(5, &asd);
	asd.MakeSearchTree(8, &asd);
	asd.MakeSearchTree(1, &asd);
	asd.MakeSearchTree(6, &asd);
	asd.MakeSearchTree(4, &asd);
	asd.MakeSearchTree(9, &asd);
	asd.MakeSearchTree(3, &asd);
	asd.MakeSearchTree(2, &asd);
	asd.MakeSearchTree(7, &asd);



	InroderTraverse(&asd, ShowData);
	cout << endl;

	asd.DeleteSearchTree(5);
	InroderTraverse(&asd, ShowData);
	cout << endl;

	asd.DeleteSearchTree(3);
	InroderTraverse(&asd, ShowData);
	cout << endl;

	asd.DeleteSearchTree(8);
	InroderTraverse(&asd, ShowData);
	cout << endl;

	asd.DeleteSearchTree(1);
	InroderTraverse(&asd, ShowData);
	cout << endl;

	asd.DeleteSearchTree(6);
	InroderTraverse(&asd, ShowData);
	cout << endl;


	return 0;
}