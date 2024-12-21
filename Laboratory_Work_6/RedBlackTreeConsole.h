#ifndef BINARYTREECONSOLE_H
#define BINARYTREECONSOLE_H
#include <iostream>
#include"Colors.h"
//#include"BinaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include"RBTree.h"
#include "Symbols.h"


using namespace std;

////������� ������ � �������.
void Show1(RBNode const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

void Show3(RBNode const* node, bool high, int foundedElement, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);
//�������� ���� ��� ������.
////������� ������ � �������.
//�������� ���� ��� ������.
//�������� ���� ��� ������.
void Show2(RBNode* root, int space = 0);

//�������� ���� ��� ������.
//�������� ������� ������.
void ShowRedBlackTree(RBTree& tree,int foundedElement);

//�������� ���� ��� ������.
void MenuRedBlackTree(RBTree& tree,int foundedElement);

//������� ���������� ���� ��� ������.
void RedBlackTreeConsole(RBTree& tree);


#endif 

