#ifndef AVLTREECONSOLE_H
#define AVLTREECONSOLE_H
#include <iostream>
#include"Colors.h"
//#include"BinaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include"AVLTree.h"
#include "Symbols.h"


using namespace std;

////������� ������ � �������.
void Show1(AVLNode const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

void Show3(AVLNode const* node, bool high, int foundedElement, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);
//�������� ���� ��� ������.
////������� ������ � �������.
//�������� ���� ��� ������.
//�������� ���� ��� ������.
void Show2(AVLNode const* node, bool high=true, int foundedElement = -1, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);


//�������� ���� ��� ������.
//�������� ������� ������.
void ShowAVLTree(AVLTree& tree, int foundedElement);

//�������� ���� ��� ������.
void MenuAVLTree(AVLTree& tree, int foundedElement);

//������� ���������� ���� ��� ������.
void AVLTreeConsole(AVLTree& tree);


#endif 

