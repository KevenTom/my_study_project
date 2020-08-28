#include<iostream>
#include"PriorityQueue.h"

using namespace std;

template<typename T>
int DataPriorityComp(T d1, T d2) {
	return strlen(d2) - strlen(d1);
}

int main() {
	PriorityQueue<char*> pq(DataPriorityComp);

	pq.PEnqueue((char*)"A");
	pq.PEnqueue((char*)"ABC");
	pq.PEnqueue((char*)"EOHE");
	cout << pq.PDequeue() << endl;

	pq.PEnqueue((char*)"D");
	pq.PEnqueue((char*)"AHF");
	pq.PEnqueue((char*)"JKSSSRG");
	cout << pq.PDequeue() << endl;

	while (!pq.PQIsEmoty())
		cout << pq.HDelete() << endl;


	return 0;
}