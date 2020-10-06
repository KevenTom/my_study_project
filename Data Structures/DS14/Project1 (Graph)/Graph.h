#pragma once
#include<iostream>
#include"LinkedList.h"

enum Vertex{A, B, C, D, E, F, G, H, I, J}; //������ �̸��� ���ȭ


template<typename T>
class Graph
{
private:
	int numV; //������ ��
	int numE; //������ ��
	LinkedList<T>* adjList; //������ ����
public:
	Graph(int nv); //�׷��� ������

	void GraphDestory(); //�׷��� ���ҽ� ����
	void Addedge(int fromV, int toV); //���� �߰�
	void ShowGraphEdgeInfo(); //������ ���� ���
};



template<typename T>
inline Graph<T>::Graph(int nv) :adjList(new LinkedList<T> [nv]), numV(nv), numE(0) {} //����Ʈ ����, ����, ���� ����

template<typename T>
inline void Graph<T>::GraphDestory() {
	if (adjList != NULL)
		delete[] adjList; //������ �Ҵ� ����
}

template<typename T>
inline void Graph<T>::Addedge(int fromV, int toV) {
	adjList[fromV].LInsert(toV); //���� fromV�� ���� toV ����

	adjList[toV].LInsert(fromV); //���� toV�� ���� fromV ����

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
