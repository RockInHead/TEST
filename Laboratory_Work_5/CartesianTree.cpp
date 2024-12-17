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
 CartesianNode* CartesianTree::Merge(CartesianNode* a, CartesianNode* b) {

	if (!a || !b) {
		/*if (a != nullptr) {
			return a;
		}
		else {
			return b;
		}*/
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

	/*if (a== nullptr || b == nullptr)
	{
		return a == nullptr ? b : a;
	}
	if (a->Priority > b->Priority)
	{
		a->Right = Merge(a->Right, b);
		return a;
	}
	b->Left = Merge(a, b->Left);
	return b;*/

}


	

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
void CartesianTree::InitRoot(int key) {
	_root = new CartesianNode(key);
	_size++;
}

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

void CartesianTree::AddElementOptimazed(int key) {
	//if (_root == nullptr)
	//{
	//	_root = new CartesianNode;
	//	_root->Key = key;
	//	_root->Priority = priority;
	//	return;
	//}

	//if (_root->Priority > priority)
	//{
	//	if (key < _root->Key)
	//	{
	//		Insert(_root->Left, key, priority);
	//	}
	//	else
	//	{
	//		Insert(_root->Right, key, priority);
	//	}
	//	return;
	//}

	//CartesianNode* newCartesianNode = new CartesianNode;
	//newCartesianNode->Key = key;
	//newCartesianNode->Priority = priority;
	//Split(_root, key, newCartesianNode->Left, newCartesianNode->Right);
	//_root = newCartesianNode;
}

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