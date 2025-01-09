#ifndef PRINTTREECONSOLE_H
#define PRINTTREECONSOLE_H
#include"Symbols.h"
#include"Node.h"
#include"CartesianNode.h"
#include <vector>
#include <string>
#include <iostream>
#include"Colors.h"

//������� �������� ������ � �������.
//������ ����� ��:https://ru.stackoverflow.com/questions/1222314/���-�������-��������-������-�-��������-����
void ShowBinaryTree(
	Node const* node,
	bool high = true,
	vector<string> const& lpref = vector<string>(),
	vector<string> const& cpref = vector<string>(),
	vector<string> const& rpref = vector<string>(),
	bool root = true,
	bool left = true,
	shared_ptr<vector<vector<string>>> lines = nullptr);

//������� ��������� ������ � �������.
//������ ����� ��:https://ru.stackoverflow.com/questions/1222314/���-�������-��������-������-�-��������-����
void ShowCartesianTree(
	CartesianNode const* node,
	bool high = true,
	vector<string> const& lpref = vector<string>(),
	vector<string> const& cpref = vector<string>(),
	vector<string> const& rpref = vector<string>(),
	bool root = true,
	bool left = true,
	shared_ptr<vector<vector<string>>> lines = nullptr);

#endif 
