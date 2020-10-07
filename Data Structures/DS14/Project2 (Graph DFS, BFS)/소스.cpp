#include<iostream>
#include"Graph.h"

using namespace std;

int main() {

	Graph<Vertex> graph(7);

	graph.Addedge(A, B);
	graph.Addedge(A, D);
	graph.Addedge(B, C);
	graph.Addedge(D, C);
	graph.Addedge(D, E);
	graph.Addedge(E, F);
	graph.Addedge(E, G);


	graph.ShowGraphEdgeInfo();

	graph.DFShowGraphVertex(A);
	graph.DFShowGraphVertex(C);
	graph.DFShowGraphVertex(E);
	graph.DFShowGraphVertex(G);
	cout << endl;


	graph.BFShowGraphVertex(A);
	graph.BFShowGraphVertex(C);
	graph.BFShowGraphVertex(E);
	graph.BFShowGraphVertex(G);


	graph.GraphDestory();

	return 0;
}