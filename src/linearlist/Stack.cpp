#include <iostream>
#include "Stack.h"

bool initStack(Stack &s){
	s.top = -1;
	return true;
}

bool isStackEmpty(Stack &s){
	return s.top<=-1;
}

bool push(Stack &s,ElemType e){
	if(s.top >= MAX_STACK_SIZE)
		return false;
	s.data[++s.top] = e;
	return true;
}

bool pop(Stack &s, ElemType &e){
	if(s.top < 0)
		return false;
	e = s.data[s.top--];
	return true;
}

bool clearStack(Stack &s){
	s.top = -1;
	return true;
}




