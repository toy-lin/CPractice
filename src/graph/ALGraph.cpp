/*
 * ALGraph.cpp
 *
 *  Created on: 2017年6月8日
 *      Author: linkaitao
 */
#include "ALGraph.h"
#include <iostream>
#include <stdlib.h>

ALGraph makeALGraph(){
	ALGraph g;

	VNode v1;
	v1.data = '1';
	v1.first = (ArcNode*)malloc(sizeof(ArcNode));
	v1.first->adjvex = 1;
	v1.first->next = (ArcNode*)malloc(sizeof(ArcNode));;
	v1.first->next->adjvex = 3;
	v1.first->next->next = NULL;

	VNode v2;
	v2.data = '2';
	v2.first = (ArcNode*)malloc(sizeof(ArcNode));
	v2.first->adjvex = 4;
	v2.first->next = NULL;

	VNode v3;
	v3.data = '3';
	v3.first = (ArcNode*)malloc(sizeof(ArcNode));
	v3.first->adjvex = 4;
	v3.first->next = (ArcNode*)malloc(sizeof(ArcNode));
	v3.first->next->adjvex = 6;
	v3.first->next->next = NULL;

	VNode v4;
	v4.data = '4';
	v4.first = (ArcNode*)malloc(sizeof(ArcNode));
	v4.first->adjvex = 1;
	v4.first->next = NULL;

	VNode v5;
	v5.data = '5';
	v5.first = (ArcNode*)malloc(sizeof(ArcNode));
	v5.first->adjvex = 3;
	v5.first->next = NULL;

	VNode v6;
	v6.data = '6';
	v6.first = NULL;

	g.vexnum = 6;
	g.arcnum = 7;
	g.vertices[0] = v1;
	g.vertices[1] = v2;
	g.vertices[2] = v3;
	g.vertices[3] = v4;
	g.vertices[4] = v5;
	g.vertices[5] = v6;

	return g;
}

