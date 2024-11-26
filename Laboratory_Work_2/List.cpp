#include"List.h"
#include <iostream>
#include <chrono>

using namespace std;
//Размер текущего списка
int _size;

//Указатель на начала списка.
Node* _head;

//Указатель на конец списка.
Node* _tail;

//Инициализиурет корень списка.
void List::InitRoot(int data) {
	Node* root = new Node();
	_head = root;
	// выделение памяти под корень списка
	_head->data = data;
	_head->next = nullptr; // указатель на следующий узел
	_head->prev = nullptr; // указатель на предыдущий узел
	_size++;
}
//Конструктор по умолчанию для списка
List::List():_size(0),_head(nullptr),_tail(nullptr) {}

//Функция возвращающая, текущую голову.
int List::GetHead() {
	if (_head != nullptr) {
		return _head->data;
	}
	if (_head == nullptr && _size == 0) {
		return 0;
	}
}
//Функция возвращающая, текущий хвост.
int List::GetTail() {
	if (_tail != nullptr){
		return _tail->data;
     }
	if (_tail == nullptr && _size < 2) {
		return 0;
	}
	
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
		Node* temp = _head;
		do {
			array[index] = temp->data;
			temp = temp->next;
			index++;
		} while (temp != nullptr); // условие окончания обхода
	}
	return array;
	delete[] array;

}
//Функция добавление элемента в конец массива.
void List::AddNodeAtEnd(int data)
{
	//Создаем новый элемент, с значением data
	Node* newNode = new Node(data);

	//Проверяем, создана ли "голова" массива, если нет, создаем.
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
}
//Функция доавбление элемента в начало массива.
void List::AddNodeAtStart(int data) {
	auto start =chrono::high_resolution_clock::now(); // Начало замера
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
	auto end = chrono::high_resolution_clock::now(); // Конец замера
	chrono::duration<double, milli> duration = end - start; // Вычисляем разницу
	cout << "runtime = " << duration.count() << "ms" << endl; // время работы программы  
	system("pause");
}
//Добавляем элемент в список перед определенным элементом
void List::InsertBefore(int data, int indexOfElement) {
	auto start = chrono::high_resolution_clock::now(); // Начало замера
	Node* newNode = new Node(data);
	Node* temp;

	if (indexOfElement <= _size && indexOfElement >= 0) {
		if (_head == nullptr)
		{
			InitRoot(data);
			return;
		}
		if (indexOfElement == 0) {
			AddNodeAtStart(data);
			return;
		}
		if (indexOfElement == _size) {
			AddNodeAtEnd(data);
			return;
		}

		//Анализируем к голове или к хвосту ближе элемент.
		if (indexOfElement < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < indexOfElement-1; i++) {
				temp = temp->next;
			}
		}
		else {
			temp = _tail;
			for (int i = _size; temp != nullptr && i > indexOfElement; i--) {
				temp = temp->prev;
			}
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next != nullptr) {
			temp->next->prev = newNode;
		}
		temp->next = newNode;
		_size++;
	}
	auto end = chrono::high_resolution_clock::now(); // Конец замера
	chrono::duration<double, milli> duration = end - start; // Вычисляем разницу
	cout << "runtime = " << duration.count() << "ms" << endl; // время работы программы  
	system("pause");
}
//Линейный поиск элемента списка.
int List::LinearSearch(int seacrhingElement) {
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		if (temp->data == seacrhingElement) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}
//Добавляем элемент в список после определенного элемента
void List::InsertAfter(int data, int indexOfElement)
{
	if (indexOfElement >= 0) {
		InsertBefore(data, indexOfElement + 1);
	}
}

//Переназначаем голову на следующий элемент списка. Текущую голову удаляем.
void List::DeleteHead() {
	_head = _head->next;
	if (_head != nullptr) {
		_head->prev = nullptr;
	}
	
}
//Переназначаем хвост на предыдущий элемент списка. Текущий хвост удаляем.
void List::DeleteTail() {
	_tail = _tail->prev;
	if (_tail != nullptr) {
		_tail->next = nullptr;
	}
	
}

//Функция удаления элемента по индексу.
void List::DeleteNodeIndex(int deletedIndex) 
{
	//Если "голова" существует.
	if (_head != nullptr && deletedIndex<_size && deletedIndex>=0) {
		//Если один элемент в списке, который является и головой и хвостом.
		if (_size == 1 && _tail!=nullptr) {
			DeleteHead();
			DeleteTail();
			_size--;
			return;
		}
		//Если удаляем голову.
		if (deletedIndex == 0 ) {
			DeleteHead();
			_size--;
			return;
		}
		//Удаляем хвост.
		if (deletedIndex == _size - 1 ) {
			DeleteTail();
			_size--;
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
//Меняет местами два соседних элемента списка.
void List::SwapNodes(Node* firstNode,Node* secondNode) 
{
	Node *prev1, * prev2, * next1, * next2;
	prev1 = firstNode->prev;  // узел предшествующий lst1
	prev2 = secondNode->prev;  // узел предшествующий lst2
	next1 = firstNode->next; // узел следующий за lst1
	next2 = secondNode->next; // узел следующий за lst2
	secondNode->next = firstNode;
	secondNode->prev = prev1;
	firstNode->next = next2;
	firstNode->prev = secondNode;

	if (next2 != nullptr) {
		next2->prev = firstNode;
	}
	if (firstNode != _head) {
		prev1->next = secondNode;
	}
	if (prev1 == nullptr) {
		_head= secondNode;
	}
	if (next2 == nullptr) {
		_tail = firstNode;
	}
	
}
//Сортирует список по возрастанию.
void List::SortList()
{
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		temp = _head;
		for (int j = 0; j < _size; j++) {
			if (temp != nullptr && temp->next!=nullptr) {
				if (temp->data > temp->next->data) {
					SwapNodes(temp, temp->next);
				}
				temp = temp->next;
			}
		}
	}
}


