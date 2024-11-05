#ifndef STACK_H
#define STACK_H

//! \brief ��������� �����.
struct Stack
{
	int* Buffer;		//!< ��������� �� ������ ������.
	int BufferSize;		//!< ������������ ������ �����.
	int Top;			//!< ������ ������� �����.
};

//! \brief �������������� ����.
//! \param stack ��������� �� ��������� Stack.
//! \param size ������ �����.
void Initialize(Stack* stack, int size);

//! \brief ��������� ������� � ����.
//! \param stack ��������� �� ��������� Stack.
//! \param data ����������� �������.
void Push(Stack* stack, int data);

//! \brief ��������� ������� �� �����.
//! \param stack ��������� �� ��������� Stack.
//! \return ����������� �������.
int Pop(Stack* stack);

//! \brief ���������, ���� �� ����.
//! \param stack ��������� �� ��������� Stack.
//! \return true, ���� ���� ����, ����� false.
bool IsEmpty(const Stack* stack);

//! \brief ������� ���� � ����������� ������.
//! \param stack ��������� �� ��������� Stack.
void Delete(Stack* stack);

//! \brief �������� ������ �����.
//! \param stack ��������� �� ��������� Stack.
//! \param newSize ����� ������ �����.
void Resize(Stack* stack, int newSize);

#endif