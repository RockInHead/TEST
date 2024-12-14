#include"BinaryTree.h"
#include <iostream>
//#include <chrono>

using namespace std;

//Констурктор по умолчанию.
BinaryTree::BinaryTree() :_size(0),_root(nullptr){}

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

void BinaryTree::Insert(Node* node, int data) {
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
	Insert(_root,data);
	_size++;
	//if (_size == 0) {
	//	InitRoot(data);
	//	return;
	//}
	//Node* newNode =new Node(data);

	//if (_root->Data > newNode->Data)
	//{
	//	Insert(_root->Rigth, newNode->Data);
	//	/*return AddElement(data);*/
	//}
	//else
	//{
	//	Insert(_root->Left, newNode->Data);
	//	/*return AddElement(data);*/
	//}
}
