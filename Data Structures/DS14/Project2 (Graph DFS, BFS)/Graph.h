#pragma once
#include<iostream>
#include"LinkedList.h"
#include"CircularQueue.h"
#include"ArrayBaseStack.h"

enum Vertex{A, B, C, D, E, F, G, H, I, J}; //정점의 이름을 상수화

template<typename T>
bool WhoIsPrecede(T data1, T data2) { //사용할 정렬 함수
	if (data1 < data2)
		return false;
	else
		return true;
}

template<typename T>
class Graph
{
private:
	int numV; //정점의 수
	int numE; //간선의 수
	LinkedList<T>* adjList; //간선의 정보
	bool* visitInfo; //탐색된 정점의 정보

	bool VisitVertex(T visitV);
public:
	Graph(int nv); //그래프 생성자

	void GraphDestory(); //그래프 리소스 삭제
	void Addedge(T fromV, T toV); //간선 추가
	void ShowGraphEdgeInfo(); //간선의 정보 출력

	void DFShowGraphVertex(T startV); //DFS 탐색
	void BFShowGraphVertex(T starV); //BFS 탐색
};





template<typename T>
inline Graph<T>::Graph(int nv) :adjList(new LinkedList<T>[nv]), visitInfo(new bool[numV] {}), numV(nv), numE(0) { //리스트 생성, 정점, 간선 설정
	for (int i = 0; i < nv; ++i)
		adjList[i].SetSortRule(WhoIsPrecede);
}

template<typename T>
inline void Graph<T>::GraphDestory() { //데이터 할당 해제
	if (adjList != nullptr)
		delete[] adjList;
	if (visitInfo != nullptr)
		delete[] visitInfo;
}

template<typename T>
inline void Graph<T>::Addedge(T fromV, T toV) {
	adjList[fromV].SInsert(toV); //정점 fromV에 정점 toV 연결
	adjList[toV].SInsert(fromV); //정점 toV에 정점 fromV 연결

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