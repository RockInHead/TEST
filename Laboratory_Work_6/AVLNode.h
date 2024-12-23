#ifndef AVLNODE_H
#define AVLNODE_H

struct AVLNode
{
	//�������� ��������.
	int Data;

	//������ ��������.
	int Height;

	//��������� �� ����� �������.
	AVLNode* Left;

	//��������� �� ������ �������.
	AVLNode* Right;

	//�������������.
	AVLNode() : Data(-1),Height(0),Left(nullptr), Right(nullptr) {}
	AVLNode(int data) : Data(data), Height(0), Left(nullptr), Right(nullptr) {}
};
#endif