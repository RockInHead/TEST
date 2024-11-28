#ifndef NODE_H
#define NODE_H

#include <iostream>
class Node {
public:
	//Хранимые данные. В нашем случае число.
	int data;
	//Указатель на следуйщий элемент списка.
	Node* next;

	//Конструктор для инициализации узла с входящим значением.
	Node(int data);
	//Конструктор по умолчанию
	Node();

}; 
#endif
