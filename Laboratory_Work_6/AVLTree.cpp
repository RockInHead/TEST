#include"AVLTree.h"

AVLTree::AVLTree() :_size(0), _root(nullptr) {}

AVLNode* AVLTree::GetRoot() {
	return _root;
}

void AVLTree::AddElement(int data) {
	_root = Insert(_root, data);
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

	//????????? ????.
	FixHeight(treeNode);
	FixHeight(current);

	//?????????? ????? ??????.
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