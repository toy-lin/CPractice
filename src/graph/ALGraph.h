/*
 * ALGraph.h
 *
 *  Created on: 2017年6月8日
 *      Author: linkaitao
 */

#ifndef ALGRAPH_H_
#define ALGRAPH_H_

#define MaxVertexNum 100
#define VertexType char

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode{
	VertexType data;
	ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

ALGraph makeALGraph();

#endif /* ALGRAPH_H_ */
