#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node {
public:
	//Хранимые данные. В нашем случае число.
	int Data;

	//Указатель на следуйщий элемент списка.
	Node* Next;

	//Конструктор для инициализации узла с входящим значением.
	Node(int data);

	//Конструктор по умолчанию
	Node();

}; 
#endif
