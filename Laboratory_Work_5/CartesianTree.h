#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H

#include <iostream>
#include "CartesianNode.h"
class CartesianTree {
private:
	//Указатель на корень дерева.
	CartesianNode* _root;

	//Количество элементов в дереве.
	int _size;

	//Инициализиурет корень дерева.
	void InitRoot(int data);

	//Функция вставки элемента дерева.
	void Insert(CartesianNode*& node, int key,int priority);

	//Вычисляет текущую высоту дерева.
	int CalculateHeight(CartesianNode* node);

	//Удаляет элемент дерева.
	void DeleteNode(CartesianNode*& node, int data);

	//Функция слияния 2ух деревьев.
	static CartesianNode* Merge(CartesianNode* a, CartesianNode* b);

	//Деление дерева по ключу.
	static void Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b);

public:


	//Возврщает количество элементов в дереве.
	int GetSize();

	//Возвращает высоту дерева.
	int GetHeight();

	//Возвращает текущий корень дерева.
	CartesianNode* GetRoot();

	//Конструктор по умолчанию.
	CartesianTree();

	//Добавление элемента в дерево.
	void AddElementNotOptimazed(int key);

	//Удаление элемента по значению.
	void DeleteElementNotOptimazed(int key);

	
	//Добавление элемента в дерево.
	void AddElementOptimazed(int key);

	//Удаление элемента по значению.
	void DeleteElementOptimazed(int key);


	//Возврщает минимальный элемент дерева.
	int FindMin();

	//Возвращает максимальный элемент дерева.
	int FindMax();

};
#endif
