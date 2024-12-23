#ifndef RBNODE_H
#define RBNODE_H
#include"Colors.h"

struct RBNode
{
	//�������� ��������.
	int Data;

	//���� ��������.
	Colors Color;
	
	//��������� �� ����� �������.
	RBNode* Left;

	//��������� �� ������ �������.
	RBNode* Right;
	
	//��������� �� �������� ��������.
	RBNode* Parent;

	//�������������.
	RBNode() : Data(-1),Color(Colors::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
	RBNode(int data) : Data(data),Color(Colors::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};
#endif