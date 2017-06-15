#include <iostream>
#include "ALGraph.h"
using namespace std;

bool dfsfind(ALGraph &g, int from, int to);
bool dfsTraverseAndFind(ALGraph &g,int from ,int to,bool* visited);

int main(){
	ALGraph g = makeALGraph();
	int from;
	int to;
	cout<<"input from:";
	cin>>from;
	cout<<"input to:";
	cin>>to;
	bool result = dfsfind(g,from,to);
	cout<< "exist path from "<<from<<" to "<<to<< ": "<<result;
}

bool dfsfind(ALGraph &g, int from ,int to){
	if(from < 0 || to < 0 ||  from == to)
		return false;
	if (g.vexnum == 0 || g.vexnum <= from || g.vexnum <= to)
		return false;

	bool visited[g.vexnum];
	for(int i =0; i < g.vexnum;i++)
		visited[i] = false;	
	return dfsTraverseAndFind(g,from,to,visited);
}

bool dfsTraverseAndFind(ALGraph &g,int from ,int to,bool* visited){
	VNode *v = &g.vertices[from];
	ArcNode *a = v->first;
	visited[from] = true;
	while(a!=NULL){
		if(to == a->adjvex)
			return true;
		if(!visited[a->adjvex])
			if(dfsTraverseAndFind(g,a->adjvex,to,visited))
				return true;
		a = a->next;
	}
	return false;
}


