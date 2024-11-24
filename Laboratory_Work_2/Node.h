#include <iostream>
class Node {
public:
	//Хранимые данные. В нашем случае число.
	int data;
	//Указатель на следуйщий элемент списка.
	struct Node* next;
	//Указатель на предыдущий элемент списка.
	struct Node* prev;
	//Конструктор для инициализации узла с входящим значением.
	Node(int data);

	Node();

};