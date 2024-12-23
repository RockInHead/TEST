#ifndef AVLTREECONSOLE_H
#define AVLTREECONSOLE_H
#include <iostream>
#include"ConsoleColors.h"
#include <vector>
#include <string>
#include <iostream>
#include"AVLTree.h"
#include "Symbols.h"
using namespace std;

//����� ������ � �������.
void ShowTree(
	AVLNode const* node,
	bool high=true,
	int foundedElement = -1,
	vector<string> const& lpref = vector<string>(),
	vector<string> const& cpref = vector<string>(),
	vector<string> const& rpref = vector<string>(),
	bool root = true,
	bool left = true,
	shared_ptr<vector<vector<string>>> lines = nullptr);

//�������� ������� ������.
void ShowAVLTree(AVLTree& tree, int foundedElement);

//�������� ���� ��� ������.
void MenuAVLTree(AVLTree& tree, int foundedElement);

//������� ���������� ���� ��� ������.
void AVLTreeConsole(AVLTree& tree);


#endif 

