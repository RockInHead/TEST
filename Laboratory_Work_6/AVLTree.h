#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "AVLNode.h"

class AVLTree {
private:
	int _rotationCount; // Счетчик для поворотов


	//Указатель на корень дерева.
	AVLNode* _root;

	//Количество элементов в дереве.
	int _size;

	//Вычисляет текущую высоту дерева.
	int CalculateHeight(AVLNode* node);

	//Вставка нового ключа в дерево. Если дерево становится несбалансированным после вставки, выполняется балансировка.
	AVLNode* Insert(AVLNode* treeNode, int key);

	// Проверяет фактор баланса узла и выполняет вращения при необходимости.
	AVLNode* Balance(AVLNode* treeNode);

	//Обновляет высоту узла. Высота - максимальная высота его поддеревьев + 1.
	void FixHeight(AVLNode* treeNode);

	//Возвращает высоту для элемента.
	int GetHeight(AVLNode* treeNode);

	// Вычисляет фактор баланса, то есть разницц между высотой левого и правого поддеревьев.
	int GetBalanceFactor(AVLNode* treeNode);

	//Правый поворот для узла.
	AVLNode* RotateRight(AVLNode* treeNode);

	//Левый поворот для узла.
	AVLNode* RotateLeft(AVLNode* treeNode);

	//Удаляет узел с вводимым ключом и выполняет балансировку при необходимости.
	AVLNode* Remove(AVLNode* treeNode, int key);

	//Находит мимнимальный узел в поддереве.
	AVLNode* FindMinimal(AVLNode* treeNode);

	//Удаляет минимальный узел в поддереве и делает балансировку.
	AVLNode* RemoveMinimal(AVLNode* treeNode);

	//Возвращает указатель на найденный узел или nullptr, если узел не найден.
	AVLNode* FindNode(AVLNode* node, int key);

	//Удаляет все ветви у node.
	void FreeTree(AVLNode*& node);

public:

	//Возвращает высоту дерева.
	int GetTreeHeight();

	//Возвращает текущий корень дерева.
	AVLNode* GetRoot();

	//Конструктор по умолчанию.
	AVLTree();

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

	int GetRotationCount();
};
#endif