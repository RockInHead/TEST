#include <iostream>
struct Node {
public:
	//Хранимые данные. В нашем случае число.
	int Data;
	//Указатель на следуйщий элемент списка.
	struct Node* Next;
	//Указатель на предыдущий элемент списка.
	struct Node* Prev;
	//Конструктор для инициализации узла с входящим значением.
	Node(int Data);

	Node();

};