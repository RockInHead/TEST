#ifndef PRINTTREECONSOLE_H
#define PRINTTREECONSOLE_H
#include"Symbols.h"
#include"ConsoleColors.h"
#include <vector>
#include <string>
#include <iostream>
#include"RBNode.h"
#include"AVLTree.h"

//������� AVL ������ � �������.
//���������� ����� ��:https://ru.stackoverflow.com/questions/1222314/���-�������-��������-������-�-��������-����
void ShowAVLTree(
	AVLNode const* node,
	bool high = true,
	int foundedElement = -1,
	vector<string> const& lpref = vector<string>(),
	vector<string> const& cpref = vector<string>(),
	vector<string> const& rpref = vector<string>(),
	bool root = true,
	bool left = true,
	shared_ptr<vector<vector<string>>> lines = nullptr);

//������� AVL ������ � �������.
//���������� ����� ��: https://ru.stackoverflow.com/questions/1222314/���-�������-��������-������-�-��������-����
void ShowRBTree(
	RBNode const* node,
	bool high,
	int foundedElement,
	vector<string> const& lpref = vector<string>(),
	vector<string> const& cpref = vector<string>(),
	vector<string> const& rpref = vector<string>(),
	bool root = true,
	bool left = true,
	shared_ptr<vector<vector<string>>> lines = nullptr);


#endif 

