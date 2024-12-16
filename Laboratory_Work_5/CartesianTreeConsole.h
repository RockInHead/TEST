#ifndef CARTESIANTREECONSOLE_H
#define CARTESIANTREECONSOLE_H
#include <iostream>
#include"Colors.h"
#include"CartesianNode.h"
#include"CartesianTree.h"
#include <vector>
#include <string>
#include <iostream>
#include "Symbols.h"
//static string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
using namespace std;

//Выводит дерево в консоль.
void Show1(CartesianNode const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

//Выводит дерево в консоль.
void Show2(CartesianTree* root, int space = 0);

//Показать текущее дерево.
void ShowCartesianTree(CartesianTree& tree);

//Показать меню для дерева.
void MenuCartesianTree(CartesianTree& tree);

//Вызвать консольное меню для дерева.
void CartesianTreeConsole(CartesianTree& tree);


#endif 