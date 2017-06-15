#include <iostream>
#include "ALGraph.h"

using namespace std;

void listpath(ALGraph &g,int from ,int to);
void findAndListPath(ALgraph &g,int from,int to,bool* visited,int* visitList);
int main(){
	ALGraph g = makeALGraph();
	int from,to;
	cout<<"input from:";
	cin>>from;
	cout<<"input to:";
	cin>>to;
	listPath(g,from,to);
}

void listpath(ALGraph &g , int from ,int to){
	if(g.vexnum<=0 || from<0||to<0 || from>=g.vexnum|| to>=g.vexnum ||from==to)
		return;
	bool visited[g.vexnum];
	int visitList[g.vexnum];
	for(int i=0;i<g.vexnum;i++){
		visited[i]=false;
		visitList[i] = -1;
	}

	findAndListPath(g,from,to,visited,visitList);
}

void findAndListPath(ALGraph &g ,int from ,int to,bool* visited,int* visitList){
	visit(visitList,from);
	VNode* v = g.vetices[from];
	ArcNode* a = v->first;
	while(a != NULL){
		
	}
}
