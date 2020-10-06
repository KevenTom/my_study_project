#include<iostream>
#include"Graph.h"

using namespace std;

int main() {
	Graph<int> graph(5);

	graph.Addedge(A, B);
	graph.Addedge(A, D);
	graph.Addedge(B, C);
	graph.Addedge(C, D);
	graph.Addedge(D, E);
	graph.Addedge(E, A);

	graph.ShowGraphEdgeInfo();


	return 0;
}