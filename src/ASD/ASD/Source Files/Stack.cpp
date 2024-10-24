#include <iostream>
#include "Stack.h"

using namespace std;

void Initialize(Stack* stack, int size) 
{
	stack->BufferSize = size;
	stack->Buffer = new int[size];
	stack->Top = -1;
}

void Push(Stack* stack, int data)
{
	if (stack->Top < stack->BufferSize - 1)
	{
		stack->Buffer[++stack->Top] = data;
	}
	else 
	{
		return;
	}
}

int Pop(Stack* stack)
{
	if (!IsEmpty(stack))
	{
		return stack->Buffer[stack->Top--];
	}
	else
	{
		return -1;
	}
}

bool IsEmpty(Stack* stack)
{
	return stack->Top == -1;
}

void Delete(Stack* stack)
{
	delete[] stack->Buffer;
	stack->Buffer = nullptr;
	stack->Top = -1;
	stack->BufferSize = 0;
}