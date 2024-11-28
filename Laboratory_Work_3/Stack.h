#include"Node.h"
#include <iostream>

class Stack {
private:
	//Размер текущего стэка.
	int _size;

	//Указатель на голову стэка.
	Node* _head;

	//Указатель на последний элемент стэка.
	Node* _top;

	//Создает корневой элемент стэка.
	void InitRoot(int data);
public:
	// Возвращает последний элемент стэка.
	int GetTop();

	// Возвращает текущий размер стэка.
	int GetSize();

	//Возвращает текущий стэк.
	int* GetStack();

	//Конструктор по умолчанию.
	Stack();

	//Добавить элемент в конец стэка.
	void Push(int data);

	//Удалить последний элемент стэка.
	void Pop();

	//Очистить весь стэк.
	void ClearStack();


};

