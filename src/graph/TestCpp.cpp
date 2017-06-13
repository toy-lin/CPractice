//============================================================================
// Name        : TestCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AlGraph.h"
using namespace std;

void dfs(ALGraph g);
void dfsTraversal(ALGraph g ,int index,bool* visited);
void visit(VNode v);

int main() {
	ALGraph g = makeALGraph();
	dfs(g);
	return 0;
}

void dfs(ALGraph g){
	if(g.vexnum == 0){
		return;
	}

	bool visited[g.vexnum];
	for(int i = 0; i < g.vexnum;i ++){
		visited[i] = false;
	}
	for(int i = 0 ; i< g.vexnum ;i++)
		dfsTraversal(g,i,visited);
}

void dfsTraversal(ALGraph g ,int index,bool visited[]){
//	cout<< "index:"<<index<<"\n";
	if(visited[index]){
		return;
	}
	visited[index] = true;
	visit(g.vertices[index]);
	ArcNode* a = g.vertices[index].first;
	while(a){
		dfsTraversal(g,a->adjvex,visited);
		a = a->next;
	}
}

void visit(VNode v){
	cout << v.data << "->";
}

bool doesPathExist(ALGraph g,int i,int j){
	return false;
}

