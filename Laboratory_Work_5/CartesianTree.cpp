#include"CartesianTree.h"

CartesianTree::CartesianTree() : _size(0), _root(nullptr) {}

//Возврщает количество элементов в дереве.
int CartesianTree::GetSize() {
	return _size;
}

//Возвращает текущий корень дерева.
CartesianNode* CartesianTree::GetRoot() {
	return _root;
}

//Сливает 2 деерва в 1.
CartesianNode* CartesianTree::Merge(CartesianNode* a, CartesianNode* b) {

	if (!a || !b) {
		return a ? a : b;
	}
	if (a->Priority > b->Priority) {
		a->Right = Merge(a->Right, b);
		return a;
	}
	else {
		b->Left = Merge(a, b->Left);
		return b;
	}

}

//Деление дерева по ключу.
void CartesianTree::Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b) {
	if (!node)
	{
		a = b = nullptr;
		return;
	}
	if (node->Key < key)
	{
		Split(node->Right, key, node->Right, b);
		a = node;
	}
	else
	{
		Split(node->Left, key, a, node->Left);
		b = node;
	}

}

//Инициализиурет корень дерева.
void CartesianTree::InitRoot(int key) {
	_root = new CartesianNode(key);
	_size++;
}

//Добавление элемента в дерево.
void CartesianTree::AddElementNotOptimazed(int key) {
	if (_size != 0) {
		CartesianNode* less;
		CartesianNode* greater;
		Split(_root, key, less, greater);
		less = Merge(less,new CartesianNode(key));
		_root = Merge(less, greater);
		_size++;
	}
	else {
		InitRoot(key);
	}	
}

//Функция вставки элемента дерева.
void CartesianTree::Insert(CartesianNode*& node, int key, int priority) {
	if (node == nullptr)
	{
		node = new CartesianNode;
		node->Key = key;
		node->Priority = priority;
		return;
	}

	if (node->Priority > priority)
	{
		if (key < node->Key)
		{
			Insert(node->Left, key, priority);
		}
		else
		{
			Insert(node->Right, key, priority);
		}
		return;
	}

	CartesianNode* newCartesianNode = new CartesianNode(key);
	newCartesianNode->Priority = priority;
	Split(node, key, newCartesianNode->Left, newCartesianNode->Right);
	node = newCartesianNode;
}

//Добавление элемента в дерево.
void CartesianTree::AddElementOptimazed(int key) {
	if (_size != 0) {
		int start = 0;
		int end = 20;

		Insert(_root, key, rand() % (end - start + 1) + start);
		_size++;
	}
	else {
		InitRoot(key);
	}
}

//Удаление элемента по значению.
void CartesianTree::DeleteElementNotOptimazed(int key) {
	if (_size != 0) {
		CartesianNode* less;
		CartesianNode* equal;
		CartesianNode* greater;
		Split(_root, key, less, greater);
		Split(greater, key + 1, equal, greater);
		if (equal != nullptr) {
			equal = Merge(equal->Left, equal->Right);
			_root = Merge(less, greater);
			_root = Merge(_root, equal);
			_size--;
		}
	}
	 
}
//Удаляет элемент по ключу.
void CartesianTree::Remove(CartesianNode*& node, int key) {
	if (node == nullptr)
	{
		return;
	}

	if (key < node->Key)
	{
		Remove(node->Left, key);
	}
	else if (key > node->Key)
	{
		Remove(node->Right, key);
	}
	else
	{
		CartesianNode* current = node;
		node = Merge(node->Left, node->Right);
		delete current;
		_size--;
	}
}

//Удаление элемента по значению.
void CartesianTree::DeleteElementOptimazed(int key) {
	if (_size != 0) {
		Remove(_root,key);
	}
}

//Удаляет все ветви у node.
void CartesianTree::FreeTree(CartesianNode*& node)
{
	if (node == nullptr)
	{
		return;
	}
	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
	node = nullptr;
}

//Удаляет все элементы дерева.
void CartesianTree::ClearTree() {
	if (_size != 0) {
		FreeTree(_root);
		_size = 0;
	}
}