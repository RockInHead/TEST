#include"BinaryTree.h"
#include <iostream>

using namespace std;

//Констурктор по умолчанию.
BinaryTree::BinaryTree() :_size(0),_root(nullptr){}

//Вычисляет текущую высоту дерева.
int BinaryTree::CalculateHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = CalculateHeight(node->Left);
	int rightHeight = CalculateHeight(node->Right);
	return std::max(leftHeight, rightHeight) + 1;
}

//Возвращает высоту дерева.
int BinaryTree::GetHeight() {
	return CalculateHeight(_root);
}

//Возврщает количество элементов в дереве.
int BinaryTree::GetSize() {
	return _size;
}

//Возвращает текущий корень дерева.
Node* BinaryTree::GetRoot() {
	return _root;
}

//Инициализиурет корень дерева.
void BinaryTree::InitRoot(int data) {
	_root = new Node(data);
	_size++;
}

//Функция вставки элемента дерева.
void BinaryTree::Insert(Node*& node, int data) {
	if (node == nullptr)
	{
		node = new Node(data);
		return;
	}

	if (node->Data > data)
	{
		Insert(node->Left, data);
		return;
	}
	else {
		Insert(node->Right, data);
		return;
	}
}

//Добавление элемента в дерево.
void BinaryTree::AddElement(int data) {
	if (_size == 0) {
		InitRoot(data);
		return;
	}
	Insert(_root,data);
	_size++;
}

//Удаляет элемент дерева.
void BinaryTree::DeleteNode(Node*& node, int data) {
	// Если дерево пусто
	if (node == nullptr) {
		return;
	}

	// Ищем узел, который нужно удалить
	if (data < node->Data) {
		DeleteNode(node->Left, data);
	}
	else if (data > node->Data) {
		DeleteNode(node->Right, data);
	}
	else {
		// Узел с единственным значением найден
		if (node->Left == nullptr) {
			Node* temp = node->Right;
			delete node;
			node = temp; 
			_size--;
		}
		else if (node->Right == nullptr) {
			Node* temp = node->Left;
			delete node;
			node = temp; 
			_size--;
		}
		else {
			// Узел с двумя дочерними узлами
			Node* temp = node->Right;
			while (temp && temp->Left != nullptr) {
				temp = temp->Left;
			}
			node->Data = temp->Data;
			DeleteNode(node->Right, temp->Data);
		}
	}
}

//Удаление элемента по значению.
void BinaryTree::DeleteElement(int data) {
	if (_size != 0) {
		DeleteNode(_root, data);
		
	}
}

//Возврщает минимальный элемент дерева.
int BinaryTree::FindMin() {
	if (_root == nullptr)
	{
		return 0;
	}
	Node* temp = _root;
	while (temp->Left != nullptr)
	{
		temp = temp->Left;
	}
	return temp->Data;
}

//Возвращает максимальный элемент дерева.
int BinaryTree::FindMax() {
	if (_root == nullptr)
	{
		return 0;
	}
	Node* temp = _root;
	while (temp->Right != nullptr)
	{
		temp = temp->Right;
	}
	return temp->Data;
}