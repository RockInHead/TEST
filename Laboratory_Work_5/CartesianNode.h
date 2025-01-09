#ifndef CARTESIANNODE_H
#define CARTESIANNODE_H
#include <iostream>

//���� ��� ����������� ������, �������� ����, ���������
//� ��������� �� ����� � ������ ������� ������.
struct CartesianNode
{
    //�������� ����������� �� ������ �� ������.
    int start = 0;
    int end = 20;
    int x = rand() % (end - start + 1) + start;

    //���� ��������.
    int Key;

    //��������� ��������.
    int Priority;

    //��������� �� ����� ������� ������.
    CartesianNode* Left;

    //��������� �� ������ ������� ������.
    CartesianNode* Right;

    //������������
    CartesianNode() : Key(-1),Priority(x), Left(nullptr), Right(nullptr) {}
    CartesianNode(int key) : Key(key), Priority(x), Left(nullptr), Right(nullptr) {}
};
#endif
