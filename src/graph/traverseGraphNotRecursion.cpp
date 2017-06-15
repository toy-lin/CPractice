#include "AlGraph.h"
#include "../linearlist/Stack.h"
#include <iostream>
using namespace std;

void traverse(ALGraph &g);
void visit(VNode *vp);

int main(){
	ALGraph g = makeALGraph();
	traverse(g);
	return 0;
}

void traverse(ALGraph &g){
	if(g.vexnum <= 0)
		return;
	Stack s;
	initStack(s);
	bool visited[g.vexnum];
	for(int i= 0; i< g.vexnum;i++)
		visited[i] =false;

	for(int i= 0 ;i < g.vexnum ;i++){
		if(visited[i])continue;
		VNode* vp = &g.vertices[i];
		int index = i;
		while(vp!=NULL||!isStackEmpty(s)){
			if(vp == NULL){
				pop(s,index);
				vp = &g.vertices[index];
			}
			if(visited[index]){
				vp = NULL;
				continue;
			}
			visit(vp);
			visited[index] = true;
			
			ArcNode* ap = vp->first;
			if(ap !=NULL){
				vp = &g.vertices[ap->adjvex];
				index = ap->adjvex;
			
				ap = ap->next;
				while(ap!=NULL){
					if(!visited[ap->adjvex])
						push(s,ap->adjvex);
					ap = ap->next;
				}
			}
		}
	}
}

void visit(VNode *vp){
	cout<< vp->data <<'\n';
}
