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
//Функция удаления головы.
int List::GetHead() {
	if (_head != nullptr) {
		return _head->data;
	}
	return 0;
}
//Функция удаления хвоста.
int List::GetTail() {
	if (_tail != nullptr){
		return _tail->data;
}
	return 0;
}

//Возвращает размер текущего списка.
int List::GetSize() {

	return _size;
}
//Возвращает текущий список
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
	delete[] array;

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

	if ( _size > 1)
	{
		_tail = newNode;
	}
	

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
	if (_size == 2) {
		_tail = _head->next;
	}
}
//Переназначаем голову на следующий элемент списка. Текущую голову удаляем.
void List::DeleteHead() {
	_head = _head->next;
	if (_head != nullptr) {
		_head->prev = nullptr;
	}
	_size--;
}
//Переназначаем хвост на предыдущий элемент списка. Текущий хвост удаляем.
void List::DeleteTail() {
	_tail = _tail->prev;
	if (_tail != nullptr) {
		_tail->next = nullptr;
	}
	_size--;
}

//Функция удаления элемента по индексу.
void List::DeleteNodeIndex(int deletedIndex) 
{
	//Если "голова" существует.
	if (_head != nullptr && deletedIndex<_size && deletedIndex>=0) {
		//Если удаляем голову.
		if (deletedIndex == 0) {
			DeleteHead();
			return;
		}
		//Удаляем хвост.
		if (deletedIndex == _size - 1) {
			DeleteTail();
			return;
		}
		Node* temp;
		//Анализируем к голове или к хвосту ближе элемент.
		if (deletedIndex < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < deletedIndex; i++) {
				temp = temp->next;
			}
		}
		else  {
			temp = _tail;
			for (int i = _size-1; temp != nullptr && i > deletedIndex; i--) {
				temp = temp->prev;
			}
		}
		//Удаляем элемент.
		if (temp != nullptr) {
			if (temp->next != nullptr) {
				temp->next->prev = temp->prev;
			}
			else if (temp->next == nullptr) {
				_tail = temp->prev;
			}
			if (temp->prev != nullptr) {
				temp->prev->next = temp->next;
			}
			delete temp;
			_size--;
		}
	}
}


