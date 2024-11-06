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

bool IsEmpty(const Stack* stack)
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

void Resize(Stack* stack, int newSize)
{
	if (newSize <= 0)
	{
		throw std::invalid_argument("–азмер стека должен быть положительным.");
	}

	int* newBuffer = new int[newSize];
	std::memcpy(newBuffer, stack->Buffer, stack->BufferSize * sizeof(int));
	delete[] stack->Buffer;
	stack->Buffer = newBuffer;
	stack->BufferSize = newSize;
}