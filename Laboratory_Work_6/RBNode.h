#ifndef RBNODE_H
#define RBNODE_H
#include"Colors.h"

struct RBNode
{
	//Значение элемента.
	int Data;

	//Цвет элемента.
	Colors Colors ;
	
	//Указатель на левый элемент.
	RBNode* Left;

	//Указатель на правый элемент.
	RBNode* Right;
	
	//Указатель на родителя элемента.
	RBNode* Parent;

	//Конуструкторы.
	RBNode() : Data(-1),Colors(Colors::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
	RBNode(int data) : Data(data),Colors(Colors::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};
#endif