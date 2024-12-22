#include"RBTree.h"

//���������� ������� ������ ������.
RBNode* RBTree::GetRoot() {
	return _root;
}

//����������� �� ���������.
RBTree::RBTree() :_size(0), _root(nullptr) {}

//��������� ������� ������ ������.
int RBTree::CalculateHeight(RBNode* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = CalculateHeight(node->Left);
	int rightHeight = CalculateHeight(node->Right);
	return std::max(leftHeight, rightHeight) + 1;
}

//���������� ������ ������.
int RBTree::GetHeight() {
	return CalculateHeight(_root);
}


// ���������� ���� ����. ���� ���� ����� nullptr, ���������� ������ ����.
Color RBTree::GetColor(RBNode* node)
{
	if (node == nullptr)
	{
		return Color::Black;
	}
	return node->Color;
}

// ������������� ���� ���� ������. ���� ���� ����� nullptr, �������� ������������.
void RBTree::SetColor(RBNode*& node, const Color color)
{
	if (node == nullptr)
	{
		return;
	}
	node->Color = color;
}
//��������� ����������� ������� ������.
int RBTree::FindMin() {
	if (_root == nullptr)
	{
		return 0;
	}
	return MinValueNode(_root)->Data;
}

//���������� ������������ ������� ������.
int RBTree::FindMax() {
	if (_root == nullptr)
	{
		return 0;
	}
	RBNode* temp = _root;
	while (temp->Right != nullptr)
	{
		temp = temp->Right;
	}
	return temp->Data;
}

//���������� �������� � ������.
void RBTree::AddElement(int data) {
	RBNode* node = new RBNode(data);
	_root = InsertNode(_root, node);
	FixInsertRBTree(node);
	_size++;

}


// ��������� ����� ���� �� ����� root. ���������� ����� ������.
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

//���������� �������� ������ ����� ������� ��������. ��������� �������� � ���������� ����� ��� �������������� ���������� ��������� ������.
void RBTree::FixInsertRBTree( RBNode*& node)
{
	RBNode* parent = nullptr;
	RBNode* grandParent = nullptr;
	while (node != _root && GetColor(node) == Color::Red && GetColor(node->Parent) == Color::Red)
	{
		parent = node->Parent;
		grandParent = parent->Parent;
		// ���� �������� � ����� ������ �������
		if (parent == grandParent->Left)
		{
			RBNode* uncle = grandParent->Right;
			// ������ 1: ���� ������� � ������ �������������.
			if (GetColor(uncle) == Color::Red)
			{
				SetColor(uncle, Color::Black);
				SetColor(parent, Color::Black);
				SetColor(grandParent, Color::Red);
				node = grandParent;
			}
			else
			{
				// ������ 2: ���� �������� ������ ������� � ������� ������.
				if (node == parent->Right)
				{
					RotateLeft(_root, parent);
					node = parent;
					parent = node->Parent;
				}
				// ������ 3: ���� �������� ����� ������� � ������� �������.
				RotateRight(_root, grandParent);
				const Color color = grandParent->Color;
				grandParent->Color = parent->Color;
				parent->Color = color;
				node = parent;
			}
		}
		// �� ��, ��� � ����, �� ��� ������, ����� �������� � ������ ������.
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
	// ������������� ������ � ������ ����.
	SetColor(_root, Color::Black);
}

// ������������ ��������� ������ ������ ��������� ����. ���� �������� ���� ����� ���������� ������� �������.
void RBTree::RotateLeft(RBNode*& root, RBNode*& node)
{
	RBNode* rightChild = node->Right;
	node->Right = rightChild->Left;

	if (node->Right != nullptr)
	{
		node->Right->Parent = node;
	}

	rightChild->Parent = node->Parent;

	//�������� ������ ���������, ���� ��� �������� ��� node.
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

// ������������ ��������� ������� ������ ��������� ����. ���� �������� ���� ����� ���������� ������ �������.
void RBTree::RotateRight(RBNode*& root, RBNode*& node)
{
	RBNode* leftChild = node->Left;
	node->Left = leftChild->Right;

	if (node->Left != nullptr)
	{
		node->Left->Parent = node;
	}

	leftChild->Parent = node->Parent;

	//�������� ������ ���������, ���� ��� �������� ��� node.
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

//�������� �������� �� ��������.
void RBTree::DeleteElement(int data) {
	/*DeleteValue(_root, data);*/
	RBNode* node = DeleteNode(_root, data);
	FixDeleteRBTree(_root, node);
}

//void RBTree::DeleteValue(RBNode*& root, const int data)
//{
//	RBNode* node = DeleteNode(root, data);
//	FixDeleteRBTree(root, node);
//}

// ���� ���� �� �������� � ������� ��� �� ������. ���������� ��������� �� ��������� ����.
RBNode* RBTree::DeleteNode(RBNode*& root, const int data)
{
	// ���� �� ������.
	if (root == nullptr)
	{
		return root;
	}

	if (data < root->Data)
	{
		return DeleteNode(root->Left, data);
	}

	if (data > root->Data)
	{
		return DeleteNode(root->Right, data);
	}
	// ���� ���� ����� ������ ��� �� ������ �������.
	if (root->Left == nullptr || root->Right == nullptr)
	{
		return root;
	}

	// ���� � ���� ��� �������, ������� ���� � ����������� ��������� � ������ ���������.
	RBNode* temp = MinValueNode(root->Right);
	root->Data = temp->Data;

	// ������� ���� � ����������� ���������.
	return DeleteNode(root->Right, temp->Data);
}

// ������� ���� � ����������� ��������� � ���������. ���������� ��������� �� ���� ����.
RBNode* RBTree::MinValueNode(RBNode*& node)
{
	RBNode* pointer = node;

	while (pointer->Left != nullptr)
	{
		pointer = pointer->Left;
	}

	return pointer;
}

// ���������� �������� ������ ����� �������� ����, ������� �������������� ������. node - ����, ������� ��� ������.
void RBTree::FixDeleteRBTree(RBNode*& root, RBNode*& node)
{
	// ��������, �������� �� ���� ������ ��� �������.
	if (DeleteCase1(root, node) == 1)
	{
		return;
	}

	// ���� �������� ���� ��� ��� ������ �������, ��������������� ������ ��� ����� ������.
	if (GetColor(node) == Color::Red
		|| GetColor(node->Left) == Color::Red
		|| GetColor(node->Right) == Color::Red)
	{
		// ������������ ������ 2.
		DeleteCase2(root, node);
	}
	// ���� �������� ���� � ��� ���� ������.
	else if (GetColor(node) != Color::Red
		&& GetColor(node->Left) != Color::Red
		&& GetColor(node->Right) != Color::Red)
	{
		RBNode* sibling = nullptr;
		RBNode* parent = nullptr;
		RBNode* pointer = node;

		// �������� �������� ���� ��� "������� ������".
		SetColor(pointer, Color::DoubleBlack);

		while (pointer != root && GetColor(pointer) == Color::DoubleBlack)
		{
			parent = pointer->Parent;
			if (pointer == parent->Left)
			{
				// ���� ��� ���� � ����� ������, ������������ ������ 3.
				if (DeleteCase3(root, sibling, parent, pointer) == 1)
				{
					break;
				}

			}
			// ���� ���� � ������ ������.
			else if (pointer != parent->Left)
			{
				// ������������ ������ 4.
				if (DeleteCase4(root, sibling, parent, pointer) == 1)
				{
					break;
				}
			}
		}

		// ������� ���� � ����������� ������.
		if (node == node->Parent->Left)
		{
			node->Parent->Left = nullptr;
		}
		else if (node == node->Parent->Right)
		{
			node->Parent->Right = nullptr;
		}
		delete node;

		// ������������� ������ ������ � ������ ����.
		SetColor(root, Color::Black);
	}
}

// ������������ ������ 1 �������� ���� � ������.
// ������� ������ ������, ���� �� ����������, ��� ���������� 1, ���� ���� �������.
inline int RBTree::DeleteCase1(RBNode*& root, RBNode*& node)
{
	if (node == nullptr)
	{
		return 1;
	}

	// ���� ��������� ���� � ������
	if (node == root)
	{
		// ���������, ���� �� � ����� �������
		if (node->Left == nullptr && node->Right == nullptr)
		{
			delete root;
			root = nullptr;
			_size--;
			return 1;
			
		}

		// ���� � ����� ���� �������, ��������� ������
		RBNode* current = root;
		root = root->Left != nullptr ? root->Left : root->Right;

		// ������������� ����� ������ ��� ������
		SetColor(root, Color::Black);
		root->Parent = nullptr;

		// ����������� ������ �� ������� �����.
		delete current;
		_size--;
		return 1;
		
	}
	// �������� �� ���������.
	return 0;
}

// ������������ ������ 2 �������� ���� � ������.
// ������� ����, ������� ����� ������ ��� �� ������ �������, �������� ����������� ������� � ��������� ���������� ����.
inline void RBTree::DeleteCase2(RBNode*& root, RBNode*& node)
{
	RBNode* child = node->Left != nullptr ? node->Left : node->Right;

	// ���� ��������� ���� � ����� ������� ��������
	if (node == node->Parent->Left)
	{
		node->Parent->Left = child;
		if (child != nullptr)
		{
			child->Parent = node->Parent;
		}
		SetColor(child, Color::Black);
		delete node;
	}
	// ���� ��������� ���� � ������ ������� ��������.
	else if (node == node->Parent->Right)
	{
		node->Parent->Right = child;
		if (child != nullptr)
		{
			child->Parent = node->Parent;
		}
		SetColor(child, Color::Black);
		delete node;
	}
	_size--;

}

// ������������ ������ 3 �������� ���� � �����-������� ������.
// ����� ���� ���� �������� �������. ���������� 1, ���� ���� ��� �����, ����� 0.
inline int RBTree::DeleteCase3(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer)
{
	// �������� �����.
	sibling = parent->Right;

	// ���� ���� �������
	if (GetColor(sibling) == Color::Red)
	{
		SetColor(sibling, Color::Black);
		SetColor(parent, Color::Red);
		RotateLeft(root, parent);
	}
	// ���� ���� ������.
	else if (GetColor(sibling) != Color::Red)
	{
		if (GetColor(sibling->Left) == Color::Black &&
			GetColor(sibling->Right) == Color::Black)
		{
			SetColor(sibling, Color::Red);
			if (GetColor(parent) == Color::Red)
			{
				SetColor(parent, Color::Black);
			}
			else if (GetColor(parent) != Color::Red)
			{
				SetColor(parent, Color::DoubleBlack);
			}
			pointer = parent;
		}
		else if (GetColor(sibling->Left) != Color::Black
			|| GetColor(sibling->Right) != Color::Black)
		{
			if (GetColor(sibling->Right) == Color::Black)
			{
				SetColor(sibling->Left, Color::Black);
				SetColor(sibling, Color::Red);
				RotateRight(root, sibling);
				sibling = parent->Right;
			}
			SetColor(sibling, parent->Color);
			SetColor(parent, Color::Black);
			SetColor(sibling->Right, Color::Black);
			RotateLeft(root, parent);

			_size--;
			// ����������.
			return 1;
		}
	}
	// �� ������� ���������.
	return 0;

}

// ������������ ������ 4 �������� ���� � ������.
// ����� ���� ���� �������� ������, �� � ���� ���� ���� �� ���� ������� �������.
inline int RBTree::DeleteCase4(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer)
{
	// �������� �����.
	sibling = parent->Left;

	// ���� ���� �������.
	if (GetColor(sibling) == Color::Red)
	{
		SetColor(sibling, Color::Black);
		SetColor(parent, Color::Red);
		RotateRight(root, parent);
	}
	// ���� ���� ������.
	else if (GetColor(sibling) == Color::Black)
	{
		if (GetColor(sibling->Left) == Color::Black &&
			GetColor(sibling->Right) == Color::Black)
		{
			SetColor(sibling, Color::Red);
			if (GetColor(parent) == Color::Red)
			{
				SetColor(parent, Color::Black);
			}
			else if (GetColor(parent) == Color::Black)
			{
				SetColor(parent, Color::Black);
			}
			pointer = parent;
		}
		// ���� ���� �� ���� ������� ����� �������.
		else if (GetColor(sibling->Left) != Color::Black
			|| GetColor(sibling->Right) != Color::Black)
		{
			if (GetColor(sibling->Left) == Color::Black)
			{
				SetColor(sibling->Right, Color::Black);
				SetColor(sibling, Color::Red);
				RotateLeft(root, sibling);
				sibling = parent->Left;
			}
			SetColor(sibling, parent->Color);
			SetColor(parent, Color::Black);
			SetColor(sibling->Left, Color::Black);
			RotateRight(root, parent);

			_size--;
			// ����������.
			return 1;
		}
	}
	
	// �� ������� ���������.
	return 0;

}

//���������� �������� �������� ��������.
int RBTree::FindValue(int data) {
	if (_size != 0) {
		RBNode* foundNode = FindNode(_root, data);
		if (foundNode != nullptr) {
			return foundNode->Data;
		}
		return -1;
	}
}

//���������� ��������� �� ��������� ���� ��� nullptr, ���� ���� �� ������.
RBNode* RBTree::FindNode(RBNode* node, const int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Data == data)
	{
		return node;
	}

	if (node->Data > data)
	{
		return FindNode(node->Left, data);
	}

	return FindNode(node->Right, data);
}


//������� ��� ����� � node.
void RBTree::FreeTree(RBNode*& node)
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

//������� ��� �������� ������.
void RBTree::ClearTree() {
	if (_size != 0) {
		FreeTree(_root);
		_size = 0;
	}
}