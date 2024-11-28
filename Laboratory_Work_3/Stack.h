#include"Node.h"
#include <iostream>

class Stack {
private:
	//Размер текущего списка
	int _size;

	//Указатель на последний элемент стэка.
	Node* _top;

	//Создает корневой элемент стэка.
	void InitRoot(int data);
public:
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

