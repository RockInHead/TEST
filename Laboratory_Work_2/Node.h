#include <iostream>

//Узел, хранящий значение и указатели на следующий и предыдущй элементы.
struct Node {
public:

	//Хранимые данные. В нашем случае число.
	int Data;

	//Указатель на следуйщий элемент списка.
	struct Node* Next;

	//Указатель на предыдущий элемент списка.
	struct Node* Prev;

	//Конструктор для инициализации узла с входящим значением.
	Node() {
		this->Data = -1;
		this->Next = nullptr;
		this->Prev = nullptr;
	}

	//Конструктор для инициализации узла с входящим значением.
	Node(int Data)
	{
		this->Data = Data;
		this->Next = nullptr;
		this->Prev = nullptr;
	}
};