#include"AVLTree.h"

//Конструктор по умолчанию.
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
int AVLTree::GetTreeHeight() {
	return CalculateHeight(_root);
}

//Возвращает минимальный элемент дерева.
int AVLTree::FindMin() {
	if (_root == nullptr)
	{
		return 0;
	}
	return FindMinimal(_root)->Data;
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

//Возврщает корень дерева.
AVLNode* AVLTree::GetRoot() {
	return _root;
}

//Добавляет новый элемент в дерево.
void AVLTree::AddElement(int data) {
	_root = Insert(_root, data);
	_size++;
}

//Вставка нового ключа в дерево. Если дерево становится несбалансированным после вставки, выполняется балансировка.
AVLNode* AVLTree::Insert(AVLNode* treeNode, const int data)
{
	if (!treeNode)
	{
		treeNode = new AVLNode(data);
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

// Проверяет фактор баланса узла и выполняет вращения при необходимости.
AVLNode* AVLTree::Balance(AVLNode* treeNode)
{
	FixHeight(treeNode);
	//Перегруз вправо.
	if (GetBalanceFactor(treeNode) == 2)
	{
		//Дополнительный поворот сначала вправо.
		if (GetBalanceFactor(treeNode->Right) < 0)
		{
			treeNode->Right = RotateRight(treeNode->Right);
		}
		return RotateLeft(treeNode);
	}

	//Перегруз влево.
	if (GetBalanceFactor(treeNode) == -2)
	{
		//Дополнительный поворот сначала влево.
		if (GetBalanceFactor(treeNode->Left) > 0)
		{
			treeNode->Left = RotateLeft(treeNode->Left);
		}
		return RotateRight(treeNode);
	}

	return treeNode;
}

//Обновляет высоту узла. Высота - максимальная высота его поддеревьев + 1.
void AVLTree::FixHeight(AVLNode* treeNode)
{
	int heightLeft = GetHeight(treeNode->Left);
	int heightRight = GetHeight(treeNode->Right);
	treeNode->Height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

//Возвращает высоту для элемента. Если элемента не сущесвует, то возвращает -1.
int AVLTree::GetHeight(AVLNode* treeNode)
{
	return treeNode ? treeNode->Height : -1;
}

// Вычисляет фактор баланса, то есть разницц между высотой левого и правого поддеревьев.
int AVLTree::GetBalanceFactor(AVLNode* treeNode)
{
	return treeNode==nullptr? 0:(GetHeight(treeNode->Right) - GetHeight(treeNode->Left));
}

//Левый поворот для узла.
AVLNode* AVLTree::RotateLeft(AVLNode* treeNode)
{
	AVLNode* current = treeNode->Right;

	treeNode->Right = current->Left;
	current->Left = treeNode;

	FixHeight(treeNode);
	FixHeight(current);

	return current;
}

//Правый поворот для узла.
AVLNode* AVLTree::RotateRight(AVLNode* treeNode)
{
	AVLNode* current = treeNode->Left;

	treeNode->Left = current->Right;
	current->Right = treeNode;

	FixHeight(treeNode);
	FixHeight(current);

	return current;
}

//Удаление элемента по значению.
void AVLTree::DeleteElement(int data) {
	_root = Remove(_root, data);
}

//Удаляет узел с вводимым ключом и выполняет балансировку при необходимости.
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
	else 
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

//Находит мимнимальный узел в поддереве.
AVLNode* AVLTree::FindMinimal(AVLNode* treeNode)
{
	return treeNode->Left ? FindMinimal(treeNode->Left) : treeNode;
}

//Удаляет минимальный узел в поддереве и делает балансировку.
AVLNode* AVLTree::RemoveMinimal(AVLNode* treeNode)
{
	if (treeNode->Left == nullptr)
	{
		return treeNode->Right;
	}

	treeNode->Left = RemoveMinimal(treeNode->Left);

	return Balance(treeNode);
}

//Возвращает значение искомого элемента.
int AVLTree::FindValue(int data) {
	if (_size != 0) {
		AVLNode* foundNode = FindNode(_root, data);
		if (foundNode != nullptr) {
			return foundNode->Data;
		}
		return -1;
	}
}

// Возвращает указатель на найденный узел или nullptr, если узел не найден.
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

//Удаляет все ветви у node.
void AVLTree::FreeTree(AVLNode*& node)
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
void AVLTree::ClearTree() {
	if (_size != 0) {
		FreeTree(_root);
		_size = 0;
	}
}