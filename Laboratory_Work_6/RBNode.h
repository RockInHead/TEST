#ifndef RBNODE_H
#define RBNODE_H

//Вспомогательное перечисление для цветов элемента.
enum class Color
{
	Red,
	Black,
	DoubleBlack
};

struct RBNode
{
	//Значение элемента.
	int Data;

	//Цвет элемента.
	Color Color ;
	
	//Указатель на левый элемент.
	RBNode* Left;

	//Указатель на правый элемент.
	RBNode* Right;
	
	//Указатель на родителя элемента.
	RBNode* Parent;

	//Конуструкторы.
	RBNode() : Data(-1),Color(Color::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
	RBNode(int data) : Data(data),Color(Color::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};
#endif