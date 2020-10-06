#pragma once
#include<iostream>
#include"LinkedList.h"

enum Vertex{A, B, C, D, E, F, G, H, I, J}; //정점의 이름을 상수화


template<typename T>
class Graph
{
private:
	int numV; //정점의 수
	int numE; //간선의 수
	LinkedList<T>* adjList; //간선의 정보
public:
	Graph(int nv); //그래프 생성자

	void GraphDestory(); //그래프 리소스 삭제
	void Addedge(int fromV, int toV); //간선 추가
	void ShowGraphEdgeInfo(); //간선의 정보 출력
};



template<typename T>
inline Graph<T>::Graph(int nv) :adjList(new LinkedList<T> [nv]), numV(nv), numE(0) {} //리스트 생성, 정점, 간선 설정

template<typename T>
inline void Graph<T>::GraphDestory() {
	if (adjList != NULL)
		delete[] adjList; //데이터 할당 해제
}

template<typename T>
inline void Graph<T>::Addedge(int fromV, int toV) {
	adjList[fromV].LInsert(toV); //정점 fromV에 정점 toV 연결

	adjList[toV].LInsert(fromV); //정점 toV에 정점 fromV 연결

	++numE;
}

template<typename T>
inline void Graph<T>::ShowGraphEdgeInfo() {
	T data;

	for (int i = 0; i < numV; ++i) {
		std::cout << static_cast<char>(i + 65) << "와 연결된 정점 : ";

		if (adjList[i].LFirest(&data)) {
			std::cout << static_cast<char>(data + 65) << " ";

			while(adjList[i].LNext(&data))
				std::cout << static_cast<char>(data + 65) << " ";
		}

		std::cout << std::endl;
	}
}
