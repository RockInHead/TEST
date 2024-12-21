#include"AVLTree.h"

AVLTree::AVLTree() :_size(0), _root(nullptr) {}

//Вычисляет текущую высоту дерева.
int AVLTree::CalculateHeight(AVLNode* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = CalculateHeight(node->Left);
	int rightHeight = CalculateHeight(node->Right);
	return std::max(leftHeight, rightHeight) + 1;
}

//Возвращает высоту дерева.
int AVLTree::GetHeight() {
	return CalculateHeight(_root);
}

//Возврщает минимальный элемент дерева.
int AVLTree::FindMin() {
	if (_root == nullptr)
	{
		return 0;
	}
	AVLNode* temp = _root;
	while (temp->Left != nullptr)
	{
		temp = temp->Left;
	}
	return temp->Data;
}

//Возвращает максимальный элемент дерева.
int AVLTree::FindMax() {
	if (_root == nullptr)
	{
		return 0;
	}
	AVLNode* temp = _root;
	while (temp->Right != nullptr)
	{
		temp = temp->Right;
	}
	return temp->Data;
}


AVLNode* AVLTree::GetRoot() {
	return _root;
}

void AVLTree::AddElement(int data) {
	_root = Insert(_root, data);
	_size++;
}

AVLNode* AVLTree::Insert(AVLNode* treeNode, const int data)
{
	if (!treeNode)
	{
		treeNode = new AVLNode;
		treeNode->Data = data;
		return treeNode;
	}

	if (data < treeNode->Data)
	{
		treeNode->Left = Insert(treeNode->Left, data);
	}
	else
	{
		treeNode->Right = Insert(treeNode->Right, data);
	}

	return Balance(treeNode);
}

AVLNode* AVLTree::Balance(AVLNode* treeNode)
{
	FixHeight(treeNode);
	if (GetBalanceFactor(treeNode) == 2)
	{
		if (GetBalanceFactor(treeNode->Right) < 0)
		{
			treeNode->Right = RotateRight(treeNode->Right);
		}
		return RotateLeft(treeNode);
	}

	if (GetBalanceFactor(treeNode) == -2)
	{
		if (GetBalanceFactor(treeNode->Left) > 0)
		{
			treeNode->Left = RotateLeft(treeNode->Left);
		}
		return RotateRight(treeNode);
	}

	return treeNode;
}

void AVLTree::FixHeight(AVLNode* treeNode)
{
	size_t heightLeft = GetHeight(treeNode->Left);
	size_t heightRight = GetHeight(treeNode->Right);
	treeNode->Height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

size_t AVLTree::GetHeight(AVLNode* treeNode)
{
	return treeNode ? treeNode->Height : 0;
}

int AVLTree::GetBalanceFactor(AVLNode* treeNode)
{
	return static_cast<int>(GetHeight(treeNode->Right) - GetHeight(treeNode->Left));
}

AVLNode* AVLTree::RotateLeft(AVLNode* treeNode)
{
	AVLNode* current = treeNode->Right;

	treeNode->Right = current->Left;
	current->Left = treeNode;

	//Îáíîâëÿåì âåñà.
	FixHeight(treeNode);
	FixHeight(current);

	//Âîçâðàùàåì íîâûé êîðåíü.
	return current;
}


AVLNode* AVLTree::RotateRight(AVLNode* treeNode)
{
	AVLNode* current = treeNode->Left;

	treeNode->Left = current->Right;
	current->Right = treeNode;

	FixHeight(treeNode);
	FixHeight(current);

	return current;
}

void AVLTree::DeleteElement(int data) {
	_root = Remove(_root, data);
}

AVLNode* AVLTree::Remove(AVLNode* treeNode, const int key)
{
	if (!treeNode)
	{
		return nullptr;
	}

	if (key < treeNode->Data)
	{
		treeNode->Left = Remove(treeNode->Left, key);
	}
	else if (key > treeNode->Data)
	{
		treeNode->Right = Remove(treeNode->Right, key);
	}
	else //  k == p->key 
	{
		AVLNode* leftPoint = treeNode->Left;
		AVLNode* rightPoint = treeNode->Right;
		delete treeNode;
		if (!rightPoint)
		{
			return leftPoint;
		}

		AVLNode* minimal = FindMinimal(rightPoint);
		minimal->Right = RemoveMinimal(rightPoint);
		minimal->Left = leftPoint;

		return Balance(minimal);
	}

	return Balance(treeNode);
}

AVLNode* AVLTree::FindMinimal(AVLNode* treeNode)
{
	return treeNode->Left ? FindMinimal(treeNode->Left) : treeNode;
}


AVLNode* AVLTree::RemoveMinimal(AVLNode* treeNode)
{
	if (treeNode->Left == nullptr)
	{
		return treeNode->Right;
	}

	treeNode->Left = RemoveMinimal(treeNode->Left);

	return Balance(treeNode);
}

int AVLTree::FindValue(int data) {
	if (_size != 0) {
		AVLNode* foundNode = FindNode(_root, data);
		if (foundNode != nullptr) {
			return foundNode->Data;
		}
		return -1;
	}
}


AVLNode* AVLTree::FindNode(AVLNode* node, const int key){
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Data == key)
	{
		return node;
	}

	if (node->Data > key)
	{
		return FindNode(node->Left, key);
	}

	return FindNode(node->Right, key);
}