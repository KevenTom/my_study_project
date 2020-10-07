#pragma once
#include<iostream>
#include"LinkedList.h"
#include"CircularQueue.h"
#include"ArrayBaseStack.h"

enum Vertex{A, B, C, D, E, F, G, H, I, J}; //������ �̸��� ���ȭ

template<typename T>
bool WhoIsPrecede(T data1, T data2) { //����� ���� �Լ�
	if (data1 < data2)
		return false;
	else
		return true;
}

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
	void BFShowGraphVertex(T starV); //BFS Ž��
};





template<typename T>
inline Graph<T>::Graph(int nv) :adjList(new LinkedList<T>[nv]), visitInfo(new bool[numV] {}), numV(nv), numE(0) { //����Ʈ ����, ����, ���� ����
	for (int i = 0; i < nv; ++i)
		adjList[i].SetSortRule(WhoIsPrecede);
}

template<typename T>
inline void Graph<T>::GraphDestory() { //������ �Ҵ� ����
	if (adjList != nullptr)
		delete[] adjList;
	if (visitInfo != nullptr)
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
	ArrayBaseStack<int> Stack;
	T visitV = startV;
	T nextV = startV;

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
inline void Graph<T>::BFShowGraphVertex(T startV) {
	CircularQueue<int> queue;
	T visitV = startV;
	T nextV = startV;

	VisitVertex(visitV);

	while (adjList[visitV].LFirest(&nextV)) {
		if (VisitVertex(nextV) == true)
			queue.Enqueue(nextV);

		while (adjList[visitV].LNext(&nextV))
			if (VisitVertex(nextV) == true)
				queue.Enqueue(nextV);

		if (queue.QIsEmpty())
			break;
		else
			visitV = static_cast<T>(queue.Dequeue());
	}

	for (int i = 0; i < numV; ++i)
		visitInfo[i] = false;
	std::cout << std::endl;
}