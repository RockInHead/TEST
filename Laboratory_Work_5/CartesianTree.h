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
	
	//Сливает 2 деерва в 1.
	static CartesianNode* Merge(CartesianNode* a, CartesianNode* b);

	//Деление дерева по ключу.
	static void Split(CartesianNode* node, int key, CartesianNode*& a, CartesianNode*& b);

	//Функция вставки элемента дерева.
	void Insert(CartesianNode*& node, int key,int priority);

	//Удаляет элемент по ключу.
	void Remove(CartesianNode*& node, int key);

	//Удаляет все ветви у node.
	void FreeTree(CartesianNode*& node);

	

public:
	//Удаляет все элементы дерева.
	void ClearTree();

	//Возврщает количество элементов в дереве.
	int GetSize();

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
};
#endif
