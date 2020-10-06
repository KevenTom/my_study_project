#pragma once
#include<iostream>
#include"LinkedList.h"
#include"ArrayBaseStack.h"

enum Vertex{A, B, C, D, E, F, G, H, I, J}; //������ �̸��� ���ȭ

template<typename T>
bool WhoIsPrecede(T data1, T data2); //��ũ����Ʈ ���� �Լ�

template<typename T>
class Graph
{
private:
	int numV; //������ ��
	int numE; //������ ��
	LinkedList<T>* adjList; //������ ����
	bool* visitInfo; //Ž���� ������ ����

	bool VisitVertex(T visitV);
public:
	Graph(int nv); //�׷��� ������

	void GraphDestory(); //�׷��� ���ҽ� ����
	void Addedge(T fromV, T toV); //���� �߰�
	void ShowGraphEdgeInfo(); //������ ���� ���

	void DFShowGraphVertex(T startV); //DFS Ž��
};





template<typename T>
inline Graph<T>::Graph(int nv) :adjList(new LinkedList<T>[nv]), visitInfo(new bool[numV] {}), numV(nv), numE(0) { //����Ʈ ����, ����, ���� ����
	for (int i = 0; i < nv; ++i)
		adjList[i].SetSortRule(WhoIsPrecede);
}

template<typename T>
inline void Graph<T>::GraphDestory() { //������ �Ҵ� ����
	if (adjList != NULL)
		delete[] adjList;
	if (visitInfo != NULL)
		delete[] visitInfo;
}

template<typename T>
inline void Graph<T>::Addedge(T fromV, T toV) {
	adjList[fromV].SInsert(toV); //���� fromV�� ���� toV ����
	adjList[toV].SInsert(fromV); //���� toV�� ���� fromV ����

	++numE;
}

template<typename T>
inline void Graph<T>::ShowGraphEdgeInfo() {
	T data;

	for (int i = 0; i < numV; ++i) {
		std::cout << static_cast<char>(i + 65) << "�� ����� ���� : ";

		if (adjList[i].LFirest(&data)) {
			std::cout << static_cast<char>(data + 65) << " ";

			while(adjList[i].LNext(&data))
				std::cout << static_cast<char>(data + 65) << " ";
		}

		std::cout << std::endl;
	}
}

template<typename T>
inline bool Graph<T>::VisitVertex(T visitV) {
	if (visitInfo[visitV] == false) {
		visitInfo[visitV] = true;
		std::cout << static_cast<char>(visitV + 65) << " ";
		return true;
	}
	else
		return false;
}

template<typename T>
inline void Graph<T>::DFShowGraphVertex(T startV) {
	T visitV = startV;
	T nextV = startV;
	ArrayBaseStack<int> Stack;

	Stack.SPush(startV);

	while (!Stack.SIsEmpty()) {
		visitV = nextV;
		VisitVertex(nextV);


		if (adjList[visitV].LFirest(&nextV) && visitInfo[nextV] == true)
			while (adjList[visitV].LNext(&nextV) && visitInfo[nextV] == true);

		if (visitInfo[nextV] == true) {
			nextV = static_cast<T>(Stack.SPop());
		}
		else {
			Stack.SPush(visitV);
		}
	}

	for (int i = 0; i < numV; ++i)
		visitInfo[i] = false;
	std::cout << std::endl;
}

template<typename T>
bool WhoIsPrecede(T data1, T data2) {
	if (data1 > data2)
		return false;
	else
		return true;
}