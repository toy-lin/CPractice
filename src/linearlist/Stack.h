#ifndef _STACK_H_
#define _STSCK_H_

#define MAX_STACK_SIZE 50
typedef int ElemType;

typedef struct{
	ElemType data[MAX_STACK_SIZE];
	int top;
}Stack;

bool initStack(Stack &s);
bool isStackEmpty(Stack &s);
bool push(Stack &s,ElemType e);
bool pop(Stack &s,ElemType &e);
bool clearStack(Stack &s);

#endif //_STACK_H_
