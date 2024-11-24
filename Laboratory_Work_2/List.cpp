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
	_size++;
}
List::List():_size(0),_head(nullptr),_tail(nullptr) {

}
//Возвращает размер текущего списка.
int List::GetSize() {

	return _size;
}
int* List::GetList() {
	int sizeOfArray = GetSize();
	int* array= new int[sizeOfArray];
	int index = 0;
	if (_head != nullptr) {
		Node* p = _head;
		do {
			/*cout << p->data << endl; */
			array[index] = p->data;
			p = p->next;
			index++;
		} while (p != nullptr); // условие окончания обхода
		
	}
	return array;
	//Node* p = _head;
	//do {
	//	cout << p->data << endl; // вывод значения элемента p
	//	p = p->next; // переход к следующему узлу
	//} while (p != nullptr); // условие окончания обхода
}
//Функция добавление элемента в конец массива.
void List::AddNodeAtEnd(int data)
{
	//Создаем новый элемент, с значением data
	Node* newNode = new Node(data);

	//Проверяем, создана ли "голова" массива, если нет, создаем
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
	_size++;
	/*_tail = newNode;*/
}
void List::AddNodeAtStart(int data) {
	Node* newNode = new Node(data);
	//Проверяем, создана ли "голова" массива, если нет, создаем
	if (_head == nullptr)
	{
		InitRoot(data);
		return;
	}

	newNode->next = _head;
	_head->prev = newNode;
	_head = newNode;
	_size++;
}
void List::DeleteNodeIndex(int deletedIndex) {

}


