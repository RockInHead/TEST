#ifndef AVLNODE_H
#define AVLNODE_H

struct AVLNode
{
	//�������� ��������.
	int Data;

	//������ ��������.
	size_t Height = 1;

	//��������� �� ����� �������.
	AVLNode* Left;

	//��������� �� ������ �������.
	AVLNode* Right;

	//�������������.
	AVLNode() : Data(-1),Left(nullptr), Right(nullptr) {}
	AVLNode(int data) : Data(data), Left(nullptr), Right(nullptr) {}
};
#endif