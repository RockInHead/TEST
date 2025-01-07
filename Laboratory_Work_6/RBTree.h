#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
#include "RBNode.h"
#include "Colors.h"
class RBTree {
private:
	//Указатель на корень дерева.
	RBNode* _root;
	
	//Количество элементов в дереве.
	int _size;

	// Вставляет новый узел по корню root. Возвращает новый корень.
	RBNode* InsertNode(RBNode*& root, RBNode*& node);

	//Поправялет свойства дерева после вставки элемента. 
	// Выполняет повороты и перекраску узлов для восстановления правильной структуры дерева.
	void FixInsertRBTree( RBNode*& node);

	// Возвращает цвет узла. Если узел равен nullptr, возвращает черный цвет.
	Colors GetColor(RBNode* node);

	// Устанавливает цвет узла дереве. Если узел равен nullptr, операция игнорируется.
	void SetColor(RBNode*& node, const Colors color);

	// Поворачивает поддерево налево вокруг заданного узла. 
	// Если заданный узел имеет ненулевого правого ребенка.
	void RotateLeft(RBNode*& root, RBNode*& node);

	// Поворачивает поддерево направо вокруг заданного узла. 
	// Если заданный узел имеет ненулевого левого ребенка.
	void RotateRight(RBNode*& root, RBNode*& node);

	// Ищет узел по значению и удаляет его из дерева. 
	// Возвращает указатель на удаляемый узел.
	RBNode* DeleteNode(RBNode*& root, int data);

	// Находит узел с минимальным значением в поддереве. 
	// Возвращает указатель на этот узел.
	RBNode* MinValueNode(RBNode*& node);

	// Исправляет свойства дерева после удаления узла, вызывая соответсвующие случаи.
	void FixDeleteRBTree(RBNode*& root, RBNode*& node);

	// Обрабатывает случай 1 удаления узла в дереве.
	// Удаляет корень дерева, если он существует, или возвращает 1, если узел нулевой.
	inline int RemoveWhenNodeExist(RBNode*& root, RBNode*& node);

	// Обрабатывает случай 2 удаления узла в дереве.
	// Удаляет узел, который имеет одного или ни одного потомка, связывая оставшегося ребенка с родителем удаляемого узла.
	inline void RemoveWhenNodeHaveOneChild(RBNode*& root, RBNode*& node);

	// Обрабатывает случай 3 удаления узла в черно-красном дереве.
	// Когда брат узла является красным. Возвращает 1, если узел был удалён, иначе 0.
	inline int RemoveWhenSiblingRed(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer);

	// Обрабатывает случай 4 удаления узла в дереве.
	// Когда брат узла является черным, но у него есть хотя бы один красный ребенок.
	inline int RemoveWhenSiblingBlackAndHaveRedChild(RBNode*& root, RBNode*& sibling, RBNode*& parent, RBNode*& pointer);

	//Возвращает указатель на найденный узел или nullptr, если узел не найден.
	RBNode* FindNode(RBNode* node, const int data);

	//Вычисляет текущую высоту дерева.
	int CalculateHeight(RBNode* node);

	//Удаляет все ветви у node.
	void FreeTree(RBNode*& node);

public:
	//Возвращает высоту дерева.
	int GetHeight();

	//Возвращает текущий корень дерева.
	RBNode* GetRoot();

	//Конструктор по умолчанию.
	RBTree();

	//Добавление элемента в дерево.
	void AddElement(int data);

	//Удаление элемента по значению.
	void DeleteElement(int data);

	//Возврщает минимальный элемент дерева.
	int FindMin();

	//Возвращает максимальный элемент дерева.
	int FindMax();

	//Возвращает значение искомого элемента.
	int FindValue(int data);

	//Очищает всё дерево.
	void ClearTree();
};
#endif
