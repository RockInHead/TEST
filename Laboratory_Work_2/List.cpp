#include"List.h"
#include <iostream>
using namespace std;
//Размер текущего списка
int _size;
//Указатель на начала списка.
Node* _head;
//Указатель на конец списка.
Node* _tail;
void List::InitRoot(int data) {
	Node* root = new Node();
	_head = root;
	// выделение памяти под корень списка

	_head->data = data;
	_head->next = nullptr; // указатель на следующий узел
	_head->prev = nullptr; // указатель на предыдущий узел

}
List::List():_size(0),_head(nullptr),_tail(nullptr) {

}
void List::GetList() {
	Node* p = _head;
	do {
		cout << p->data << endl; // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != nullptr); // условие окончания обхода
}
void List::AddNodeAtEnd(int data)
{
	Node* newNode = new Node(data);

	if (_head == nullptr) 
	{
		InitRoot(data);
		return;
	}
	
		Node* temp = _head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;

	
}




