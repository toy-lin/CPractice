#include <iostream>
#include "ALGraph.h"

using namespace std;

void listpath(ALGraph &g,int from ,int to);
void findAndListPath(ALGraph &g,int from,int to,bool* visited,int* visitList);
void listAdd(int* list,int data);
void listRemoveLast(int* list);
void listPrint(int* list);

int main(){
	ALGraph g = makeALGraph();
	int from,to;
	cout<<"input from:";
	cin>>from;
	cout<<"input to:";
	cin>>to;
	listpath(g,from,to);
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
	if(visited[from])
		return;

	visited[from] = true;
	listAdd(visitList,from);
	VNode* v = &g.vertices[from];
	ArcNode* a = v->first;

	while(a != NULL){
		if(a->adjvex == to){
			listAdd(visitList,to);
			listPrint(visitList);
			listRemoveLast(visitList);
		}else{
			findAndListPath(g,a->adjvex,to,visited,visitList);
		}
		a = a->next;
	}
	visited[from] = false;
	listRemoveLast(visitList);
}

void listAdd(int *visitList,int data){
	for(int i =0 ; i< 100; i++){
		if(visitList[i] == -1){
			visitList[i] = data;
			return;
		}
	}
}

void listRemoveLast(int* visitList){
	for(int i =0 ; i< 100; i++){
		if(visitList[i] ==-1){
			visitList[i-1] = -1;
			return;
		}
	}
}

void listPrint(int* visitList){	
	for(int i =0 ; i< 100; i++){
		if(visitList[i]!=-1){
			cout<< visitList[i] << "->";
		}else{
			break;
		}
	}
	cout << "\n";
}
