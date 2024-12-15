#include"BinaryTree.h"
#include <iostream>
//#include <chrono>

using namespace std;

//Констурктор по умолчанию.
BinaryTree::BinaryTree() :_size(0),_root(nullptr){}

int BinaryTree::CalculateHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = CalculateHeight(node->Left);
	int rightHeight = CalculateHeight(node->Right);
	return std::max(leftHeight, rightHeight) + 1;
}
int BinaryTree::GetHeight() {
	return CalculateHeight(_root);
	/*int leftHeight = GetHeight(_root->Left);
	int rightHeight = GetHeight(_root->Right);
	return std::max(leftHeight, rightHeight) + 1;*/
}
int BinaryTree::GetSize() {
	return _size;
}

Node* BinaryTree::GetBinaryTree() {
	return _root;
	/*Node** tree = new Node*[_size];
	if (_size != 0) {
		Node* parent = _root;
		for (int i = 0; i < _size; i++) {
			tree[i] = parent;
			tree[i+1]= parent
		}
	}*/
}


void BinaryTree::InitRoot(int data) {
	_root = new Node(data);
	_size++;
}

void BinaryTree::Insert(Node*& node, int data) {
	if (node == nullptr)
	{
		node = new Node(data);
		/*node->Data = value;*/
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

void BinaryTree::AddElement(int data) {
	if (_size == 0) {
		InitRoot(data);
		return;
	}
	Insert(_root,data);
	_size++;

}
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
		// Узел с одним дочерним элементом или без дочерних узлов
		if (node->Left == nullptr) {
			Node* temp = node->Right;
			delete node;
			node = temp; // Обновляем указатель на корень
			_size--;
		}
		else if (node->Right == nullptr) {
			Node* temp = node->Left;
			delete node;
			node = temp; // Обновляем указатель на корень
			_size--;
		}
		else {
			// Узел с двумя дочерними узлами: получить порядок преемственности
			Node* temp = node->Right;
			while (temp && temp->Left != nullptr) {
				temp = temp->Left;
			}

			// Поменять значение с правым дочерним элементом
			node->Data = temp->Data;

			// Удалить правый дочерний элемент
			DeleteNode(node->Right, temp->Data);
		}
	}
}
void BinaryTree::DeleteElement(int data) {
	if (_size != 0) {
		DeleteNode(_root, data);
		
	}
}