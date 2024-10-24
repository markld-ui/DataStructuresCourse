#ifndef STACK_H
#define STACK_H

struct Stack
{
	int* Buffer;
	int BufferSize;
	int Top;
};

void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsEmpty(Stack* stack);
void Delete(Stack* stack);
void Initialize(Stack* stack, int size);

#endif