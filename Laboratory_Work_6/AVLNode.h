#ifndef AVLNODE_H
#define AVLNODE_H

struct AVLNode
{
	//Значение элемента.
	int Data;

	//Высота элемента.
	int Height;

	//Указатель на левый элемент.
	AVLNode* Left;

	//Указатель на правый элемент.
	AVLNode* Right;

	//Конуструкторы.
	AVLNode() : Data(-1),Height(-1),Left(nullptr), Right(nullptr) {}
	AVLNode(int data) : Data(data), Height(1), Left(nullptr), Right(nullptr) {}
};
#endif