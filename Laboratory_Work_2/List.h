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

	//Инициализиурет корень списка.
	void InitRoot(int Data);

	//Переназначаем голову на следующий элемент списка. Текущую голову удаляем.
	void DeleteHead();

	//Переназначаем хвост на предыдущий элемент списка. Текущий хвост удаляем.
	void DeleteTail();

	//Меняет местами два соседних элемента списка.
	void SwapNodes(Node* firstNode, Node* secondNode);

public:
	//Конструктор по умолчанию для списка
	List();

	//Функция возвращающая, текущую голову.
	int GetHead();

	//Функция возвращающая, текущий хвост.
	int GetTail();

	//Возвращает размер текущего списка.
	int GetSize();

	//Возвращает текущий список
	int* GetList();

	//Функция добавление элемента в конец массива.
	void AddNodeAtEnd(int Data);

	//Функция доавбление элемента в начало массива.
	void AddNodeAtStart(int Data);

	//Функция удаления элемента по индексу.
	void DeleteNodeIndex(int Data);

	//Добавляем элемент в список перед определенным элементом
	void InsertBefore(int Data, int indexOfElement);

	//Добавляем элемент в список после определенного элемента
	void InsertAfter(int Data, int indexOfElement);

	// Функция линейного поиска элемента в списке
	int LinearSearch(int seacrhingElement);

	//Сортирует список по возрастанию.
	void SortList();

};
