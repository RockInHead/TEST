#ifndef PRINTTREECONSOLE_H
#define PRINTTREECONSOLE_H
#include"Symbols.h"
#include"Node.h"
#include"CartesianNode.h"
#include <vector>
#include <string>
#include <iostream>
#include"Colors.h"

//Выводит бинарное дерево в консоль.
//Основа взята из:https://ru.stackoverflow.com/questions/1222314/Как-вывести-бинарное-дерево-в-красивом-виде
void ShowBinaryTree(
	Node const* node,
	bool high = true,
	vector<string> const& lpref = vector<string>(),
	vector<string> const& cpref = vector<string>(),
	vector<string> const& rpref = vector<string>(),
	bool root = true,
	bool left = true,
	shared_ptr<vector<vector<string>>> lines = nullptr);

//Выводит декартово дерево в консоль.
//Основа взята из:https://ru.stackoverflow.com/questions/1222314/Как-вывести-бинарное-дерево-в-красивом-виде
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
