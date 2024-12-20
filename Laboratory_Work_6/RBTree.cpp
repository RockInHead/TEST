#include"RBTree.h"

RBNode* RBTree::GetRoot() {
	return _root;
}

RBTree::RBTree() :_size(0), _root(nullptr) {}

Color RBTree::GetColor(RBNode* node)
{
	if (node == nullptr)
	{
		return Color::Black;
	}
	return node->Color;
}

void RBTree::SetColor(RBNode*& node, const Color color)
{
	if (node == nullptr)
	{
		return;
	}
	node->Color = color;
}

void RBTree::AddElement(int data) {
	InsertValue(_root, data);
}
void RBTree::InsertValue(RBNode*& root, const int value) {
	RBNode* node = new RBNode(value);
	/*node->Data = value;*/
	root = InsertNode(root, node);
	FixInsertRBTree(node);
}

RBNode* RBTree::InsertNode(RBNode*& root, RBNode*& node)
{
	if (root == nullptr)
	{
		return node;
	}

	if (node->Data < root->Data)
	{
		root->Left = InsertNode(root->Left, node);
		root->Left->Parent = root;
	}
	else
	{
		root->Right = InsertNode(root->Right, node);
		root->Right->Parent = root;
	}

	return root;
}

void RBTree::FixInsertRBTree( RBNode*& node)
{
	RBNode* parent = nullptr;
	RBNode* grandParent = nullptr;
	while (node != _root && GetColor(node) == Color::Red && GetColor(node->Parent) == Color::Red)
	{
		parent = node->Parent;
		grandParent = parent->Parent;
		if (parent == grandParent->Left)
		{
			RBNode* uncle = grandParent->Right;
			if (GetColor(uncle) == Color::Red)
			{
				SetColor(uncle, Color::Black);
				SetColor(parent, Color::Black);
				SetColor(grandParent, Color::Red);
				node = grandParent;
			}
			else
			{
				if (node == parent->Right)
				{
					RotateLeft(_root, parent);
					node = parent;
					parent = node->Parent;
				}
				RotateRight(_root, grandParent);
				const Color color = grandParent->Color;
				grandParent->Color = parent->Color;
				parent->Color = color;
				node = parent;
			}
		}
		else
		{
			RBNode* uncle = grandParent->Left;
			if (GetColor(uncle) == Color::Red)
			{
				SetColor(uncle, Color::Black);
				SetColor(parent, Color::Black);
				SetColor(grandParent, Color::Red);
				node = grandParent;
			}
			else
			{
				if (node == parent->Left)
				{
					RotateRight(_root, parent);
					node = parent;
					parent = node->Parent;
				}
				RotateLeft(_root, grandParent);
				const Color color = grandParent->Color;
				grandParent->Color = parent->Color;
				parent->Color = color;
				node = parent;
			}
		}
	}
	SetColor(_root, Color::Black);
}

void RBTree::RotateLeft(RBNode*& root, RBNode*& node)
{
	RBNode* rightChild = node->Right;
	node->Right = rightChild->Left;

	if (node->Right != nullptr)
	{
		node->Right->Parent = node;
	}

	rightChild->Parent = node->Parent;

	if (node->Parent == nullptr)
	{
		root = rightChild;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = rightChild;
	}
	else
	{
		node->Parent->Right = rightChild;
	}

	rightChild->Left = node;
	node->Parent = rightChild;
}

void RBTree::RotateRight(RBNode*& root, RBNode*& node)
{
	RBNode* leftChild = node->Left;
	node->Left = leftChild->Right;

	if (node->Left != nullptr)
	{
		node->Left->Parent = node;
	}

	leftChild->Parent = node->Parent;

	if (node->Parent == nullptr)
	{
		root = leftChild;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = leftChild;
	}
	else
	{
		node->Parent->Right = leftChild;
	}

	leftChild->Right = node;
	node->Parent = leftChild;
}