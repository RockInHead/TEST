#include"CartesianTree.h"

CartesianTree::CartesianTree() : _size(0), _root(nullptr) {}

CartesianNode* CartesianTree::Merge(CartesianNode* a, CartesianNode* b) {
	if (a== nullptr || b == nullptr)
	{
		return a == nullptr ? b : a;
	}
	if (a->Priority > b->Priority)
	{
		a->Right = Merge(a->Right, b);
		return a;
	}
	b->Left = Merge(a, b->Left);
	return b;
}

void  CartesianTree::Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b) {
	if (node == nullptr)
	{
		a = b = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, b);
		a = node;
	}
	else if (node->Key <= key)
	{
		Split(node->Left, key, a, node->Left);
		b = node;
	}

}