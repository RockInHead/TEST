#include"RBTree.h"

//Возвращает текущий корень дерева.
RBNode* RBTree::GetRoot() {
	return _root;
}

//Конструктор по умолчанию.
RBTree::RBTree() :_size(0), _root(nullptr) {}

//Вычисляет текущую высоту дерева.
int RBTree::CalculateHeight(RBNode* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = CalculateHeight(node->Left);
	int rightHeight = CalculateHeight(node->Right);
	return std::max(leftHeight, rightHeight) + 1;
}

//Возвращает высоту дерева.
int RBTree::GetHeight() {
	return CalculateHeight(_root);
}


// Возвращает цвет узла. Если узел равен nullptr, возвращает черный цвет.
Color RBTree::GetColor(RBNode* node)
{
	if (node == nullptr)
	{
		return Color::Black;
	}
	return node->Color;
}

// Устанавливает цвет узла дереве. Если узел равен nullptr, операция игнорируется.
void RBTree::SetColor(RBNode*& node, const Color color)
{
	if (node == nullptr)
	{
		return;
	}
	node->Color = color;
}
//Возврщает минимальный элемент дерева.
int RBTree::FindMin() {
	if (_root == nullptr)
	{
		return 0;
	}
	return MinValueNode(_root)->Data;
}

//Возвращает максимальный элемент дерева.
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

//Добавление элемента в дерево.
void RBTree::AddElement(int data) {
	RBNode* node = new RBNode(data);
	_root = InsertNode(_root, node);
	FixInsertRBTree(node);
	_size++;

}


// Вставляет новый узел по корню root. Возвращает новый корень.
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

//Поправялет свойства дерева после вставки элемента. Выполняет повороты и перекраску узлов для восстановления правильной структуры дерева.
void RBTree::FixInsertRBTree( RBNode*& node)
{
	RBNode* parent = nullptr;
	RBNode* grandParent = nullptr;
	while (node != _root && GetColor(node) == Color::Red && GetColor(node->Parent) == Color::Red)
	{
		parent = node->Parent;
		grandParent = parent->Parent;
		// Если родитель — левый ребёнок дедушки
		if (parent == grandParent->Left)
		{
			RBNode* uncle = grandParent->Right;
			// Случай 1: Дядя красный — просто перекрашиваем.
			if (GetColor(uncle) == Color::Red)
			{
				SetColor(uncle, Color::Black);
				SetColor(parent, Color::Black);
				SetColor(grandParent, Color::Red);
				node = grandParent;
			}
			else
			{
				// Случай 2: Узел является правым ребёнком — поворот налево.
				if (node == parent->Right)
				{
					RotateLeft(_root, parent);
					node = parent;
					parent = node->Parent;
				}
				// Случай 3: Узел является левым ребёнком — поворот направо.
				RotateRight(_root, grandParent);
				const Color color = grandParent->Color;
				grandParent->Color = parent->Color;
				parent->Color = color;
				node = parent;
			}
		}
		// То же, что и выше, но для случая, когда родитель — правый ребёнок.
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
	// Устанавливаем корень в черный цвет.
	SetColor(_root, Color::Black);
}

// Поворачивает поддерево налево вокруг заданного узла. Если заданный узел имеет ненулевого правого ребенка.
void RBTree::RotateLeft(RBNode*& root, RBNode*& node)
{
	RBNode* rightChild = node->Right;
	node->Right = rightChild->Left;

	if (node->Right != nullptr)
	{
		node->Right->Parent = node;
	}

	rightChild->Parent = node->Parent;

	//Обновяем корень поддерева, если нет родителя для node.
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

// Поворачивает поддерево направо вокруг заданного узла. Если заданный узел имеет ненулевого левого ребенка.
void RBTree::RotateRight(RBNode*& root, RBNode*& node)
{
	RBNode* leftChild = node->Left;
	node->Left = leftChild->Right;

	if (node->Left != nullptr)
	{
		node->Left->Parent = node;
	}

	leftChild->Parent = node->Parent;

	//Обновяем корень поддерева, если нет родителя для node.
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

//Удаление элемента по значению.
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

// Ищет узел по значению и удаляет его из дерева. Возвращает указатель на удаляемый узел.
RBNode* RBTree::DeleteNode(RBNode*& root, const int data)
{
	// Узел не найден.
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
	// Если узел имеет одного или ни одного ребенка.
	if (root->Left == nullptr || root->Right == nullptr)
	{
		return root;
	}

	// Если у узла два ребенка, находим Узел с минимальным значением в правом поддереве.
	RBNode* temp = MinValueNode(root->Right);
	root->Data = temp->Data;

	// Удаляем узел с минимальным значением.
	return DeleteNode(root->Right, temp->Data);
}

// Находит узел с минимальным значением в поддереве. Возвращает указатель на этот узел.
RBNode* RBTree::MinValueNode(RBNode*& node)
{
	RBNode* pointer = node;

	while (pointer->Left != nullptr)
	{
		pointer = pointer->Left;
	}

	return pointer;
}

// Исправляет свойства дерева после удаления узла, вызывая соответсвующие случаи. node - узел, который был удален.
void RBTree::FixDeleteRBTree(RBNode*& root, RBNode*& node)
{
	// Проверка, является ли узел корнем или нулевым.
	if (DeleteCase1(root, node) == 1)
	{
		return;
	}

	// Если удалённый узел или его ребёнки красные, восстанавливаем дерево для этого случая.
	if (GetColor(node) == Color::Red
		|| GetColor(node->Left) == Color::Red
		|| GetColor(node->Right) == Color::Red)
	{
		// Обрабатываем случай 2.
		DeleteCase2(root, node);
	}
	// Если удалённый узел и его дети чёрные.
	else if (GetColor(node) != Color::Red
		&& GetColor(node->Left) != Color::Red
		&& GetColor(node->Right) != Color::Red)
	{
		RBNode* sibling = nullptr;
		RBNode* parent = nullptr;
		RBNode* pointer = node;

		// Помечаем удалённый узел как "двойной черный".
		SetColor(pointer, Color::DoubleBlack);

		while (pointer != root && GetColor(pointer) == Color::DoubleBlack)
		{
			parent = pointer->Parent;
			if (pointer == parent->Left)
			{
				// Если наш узел — левый ребёнок, обрабатываем случай 3.
				if (DeleteCase3(root, sibling, parent, pointer) == 1)
				{
					break;
				}

			}
			// Если узел — правый ребёнок.
			else if (pointer != parent->Left)
			{
				// Обрабатываем случай 4.
				if (DeleteCase4(root, sibling, parent, pointer) == 1)
				{
					break;
				}
			}
		}

		// Удаляем узел и освобождаем память.
		if (node == node->Parent->Left)
		{
			node->Parent->Left = nullptr;
		}
		else if (node == node->Parent->Right)
		{
			node->Parent->Right = nullptr;
		}
		delete node;

		// Устанавливаем корень дерева в черный цвет.
		SetColor(root, Color::Black);
	}
}

// Обрабатывает случай 1 удаления узла в дереве.
// Удаляет корень дерева, если он существует, или возвращает 1, если узел нулевой.
inline int RBTree::DeleteCase1(RBNode*& root, RBNode*& node)
{
	if (node == nullptr)
	{
		return 1;
	}

	// Если удаляемый узел — корень
	if (node == root)
	{
		// Проверяем, есть ли у корня потомки
		if (node->Left == nullptr && node->Right == nullptr)
		{
			delete root;
			root = nullptr;
			_size--;
			return 1;
			
		}

		// Если у корня есть потомки, обновляем корень
		RBNode* current = root;
		root = root->Left != nullptr ? root->Left : root->Right;

		// Устанавливаем новый корень как черный
		SetColor(root, Color::Black);
		root->Parent = nullptr;

		// Освобождаем память от старого корня.
		delete current;
		_size--;
		return 1;
		
	}
	// Удаление не произошло.
	return 0;
}

// Обрабатывает случай 2 удаления узла в дереве.
// Удаляет узел, который имеет одного или ни одного потомка, связывая оставшегося ребенка с родителем удаляемого узла.
inline void RBTree::DeleteCase2(RBNode*& root, RBNode*& node)
{
	RBNode* child = node->Left != nullptr ? node->Left : node->Right;

	// Если удаляемый узел — левый ребенок родителя
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
	// Если удаляемый узел — правый ребенок родителя.
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

// Обрабатывает случай 3 удаления узла в черно-красном дереве.
// Когда брат узла является красным. Возвращает 1, если узел был удалён, иначе 0.
inline int RBTree::DeleteCase3(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer)
{
	// Получаем брата.
	sibling = parent->Right;

	// Если брат красный
	if (GetColor(sibling) == Color::Red)
	{
		SetColor(sibling, Color::Black);
		SetColor(parent, Color::Red);
		RotateLeft(root, parent);
	}
	// Если брат черный.
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
			// Исправлено.
			return 1;
		}
	}
	// Не удалось исправить.
	return 0;

}

// Обрабатывает случай 4 удаления узла в дереве.
// Когда брат узла является черным, но у него есть хотя бы один красный ребенок.
inline int RBTree::DeleteCase4(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer)
{
	// Получаем брата.
	sibling = parent->Left;

	// Если брат красный.
	if (GetColor(sibling) == Color::Red)
	{
		SetColor(sibling, Color::Black);
		SetColor(parent, Color::Red);
		RotateRight(root, parent);
	}
	// Если брат черный.
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
		// Если хотя бы один ребенок брата красный.
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
			// Исправлено.
			return 1;
		}
	}
	
	// Не удалось исправить.
	return 0;

}

//Возвращает значение искомого элемента.
int RBTree::FindValue(int data) {
	if (_size != 0) {
		RBNode* foundNode = FindNode(_root, data);
		if (foundNode != nullptr) {
			return foundNode->Data;
		}
		return -1;
	}
}

//Возвращает указатель на найденный узел или nullptr, если узел не найден.
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


//Удаляет все ветви у node.
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

//Удаляет все элементы дерева.
void RBTree::ClearTree() {
	if (_size != 0) {
		FreeTree(_root);
		_size = 0;
	}
}