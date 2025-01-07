#include"List.h"
#include <iostream>
using namespace std;

//Инициализиурет корень списка.
void List::InitRoot(int Data) {
	Node* root = new Node();
	_head = root;
	
	_head->Data = Data;
	_head->Next = nullptr; 
	_head->Prev = nullptr; 
	_size++;
}

//Конструктор по умолчанию для списка
List::List():_size(0),_head(nullptr),_tail(nullptr) {}

//Функция возвращающая, текущую голову.
int List::GetHead() {
	if (_head != nullptr) {
		return _head->Data;
	}
	if (_head == nullptr && _size == 0) {
		return 0;
	}
}

//Функция возвращающая, текущий хвост.
int List::GetTail() {
	if (_tail != nullptr){
		return _tail->Data;
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
			array[index] = temp->Data;
			temp = temp->Next;
			index++;
		} while (temp != nullptr); 
	}
	return array;
}

//Функция добавление элемента в конец массива.
void List::AddNodeAtEnd(int Data)
{
	//Создаем новый элемент, с значением data
	Node* newNode = new Node(Data);

	//Проверяем, создана ли "голова" массива, если нет, создаем.
	if (_head == nullptr) 
	{
		InitRoot(Data);
		return;
	}
	
	Node* temp = _head;
	while (temp->Next != nullptr) {
		temp = temp->Next;
	}

	temp->Next = newNode;
	newNode->Prev = temp;
	_size++;

	if ( _size > 1)
	{
		_tail = newNode;
	}
}

//Функция доавбление элемента в начало массива.
void List::AddNodeAtStart(int Data) {
	Node* newNode = new Node(Data);
	//Проверяем, создана ли "голова" массива, если нет, создаем
	if (_head == nullptr)
	{
		InitRoot(Data);
		return;
	}

	newNode->Next = _head;
	_head->Prev = newNode;
	_head = newNode;
	_size++;
	if (_size == 2) {
		_tail = _head->Next;
	}
}

//Добавляем элемент в список перед определенным элементом
void List::InsertBefore(int Data, int indexOfElement) {
	Node* newNode = new Node(Data);
	Node* temp;

	if (indexOfElement <= _size && indexOfElement >= 0) {
		if (_head == nullptr)
		{
			InitRoot(Data);
			return;
		}
		if (indexOfElement == 0) {
			AddNodeAtStart(Data);
			return;
		}
		if (indexOfElement == _size) {
			AddNodeAtEnd(Data);
			return;
		}

		//Анализируем к голове или к хвосту ближе элемент.
		if (indexOfElement < _size / 2) {
			temp = _head;
			for (int i = 0; temp != nullptr && i < indexOfElement-1; i++) {
				temp = temp->Next;
			}
		}
		else {
			temp = _tail;
			for (int i = _size; temp != nullptr && i > indexOfElement; i--) {
				temp = temp->Prev;
			}
		}
		newNode->Next = temp->Next;
		newNode->Prev = temp;
		if (temp->Next != nullptr) {
			temp->Next->Prev = newNode;
		}
		temp->Next = newNode;
		_size++;
	}
}

//Линейный поиск элемента списка.
int List::LinearSearch(int seacrhingElement) {
	Node* temp = _head;
	for (int i = 0; i < _size; i++) {
		if (temp->Data == seacrhingElement) {
			return i;
		}
		temp = temp->Next;
	}
	return -1;
}

//Добавляем элемент в список после определенного элемента
void List::InsertAfter(int Data, int indexOfElement)
{
	if (indexOfElement >= 0) {
		InsertBefore(Data, indexOfElement + 1);
	}
}

//Переназначаем голову на следующий элемент списка. Текущую голову удаляем.
void List::DeleteHead() {
	_head = _head->Next;
	if (_head != nullptr) {
		_head->Prev = nullptr;
	}
	
}

//Переназначаем хвост на предыдущий элемент списка. Текущий хвост удаляем.
void List::DeleteTail() {
	_tail = _tail->Prev;
	if (_tail != nullptr) {
		_tail->Next = nullptr;
	}
	
}

//Функция удаления элемента по индексу.
void List::DeleteNodeIndex(int deletedIndex) 
{
	//Если "голова" существует.
	if (_head != nullptr && deletedIndex < _size && deletedIndex >= 0) 
	{
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
				temp = temp->Next;
			}
		}
		else  {
			temp = _tail;
			for (int i = _size-1; temp != nullptr && i > deletedIndex; i--) {
				temp = temp->Prev;
			}
		}
		//Удаляем элемент.
		if (temp != nullptr) {
			if (temp->Next != nullptr) {
				temp->Next->Prev = temp->Prev;
			}
			else if (temp->Next == nullptr) {
				_tail = temp->Prev;
			}
			if (temp->Prev != nullptr) {
				temp->Prev->Next = temp->Next;
			}
			delete temp;
			_size--;
		}
	}
}

//Меняет местами два соседних элемента списка.
void List::SwapNodes(Node* firstNode,Node* secondNode) 
{
	Node* prev1;
	Node* prev2;
	Node* next1;
    Node* next2;

	prev1 = firstNode->Prev;  
	prev2 = secondNode->Prev;  
	next1 = firstNode->Next; 
	next2 = secondNode->Next; 
	secondNode->Next = firstNode;
	secondNode->Prev = prev1;
	firstNode->Next = next2;
	firstNode->Prev = secondNode;

	if (next2 != nullptr) {
		next2->Prev = firstNode;
	}
	if (firstNode != _head) {
		prev1->Next = secondNode;
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
			if (temp != nullptr && temp->Next!=nullptr) {
				if (temp->Data > temp->Next->Data) {
					SwapNodes(temp, temp->Next);
				}
				temp = temp->Next;
			}
		}
	}
}


