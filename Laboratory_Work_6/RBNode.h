#ifndef RBNODE_H
#define RBNODE_H
#include"Colors.h"

struct RBNode
{
	//�������� ��������.
	int Data;

	//���� ��������.
	Colors Colors ;
	
	//��������� �� ����� �������.
	RBNode* Left;

	//��������� �� ������ �������.
	RBNode* Right;
	
	//��������� �� �������� ��������.
	RBNode* Parent;

	//�������������.
	RBNode() : Data(-1),Colors(Colors::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
	RBNode(int data) : Data(data),Colors(Colors::Red), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};
#endif