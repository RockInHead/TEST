#include"Node.h"
#include <iostream>
class List {
private:
	//Размер текущего списка
	int _size;
	//Указатель на начала списка.
	Node* _head;
	//Указатель на конец списка.
	Node* _tail;

	void InitRoot(int data);
public:
	List();
	void GetList();
	void AddNodeAtEnd(int data);
};
