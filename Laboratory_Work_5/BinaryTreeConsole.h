#ifndef BINARYTREECONSOLE_H
#define BINARYTREECONSOLE_H
#include <iostream>
#include"Colors.h"
#include"BinaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include "Symbols.h"


using namespace std;

//Выводит дерево в консоль.
void Show1(Node const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

//Выводит дерево в консоль.
void Show2(BinaryTree* root, int space = 0);

//Показать текущее дерево.
void ShowBinaryTree(BinaryTree& tree);

//Показать меню для дерева.
void MenuBinaryTree(BinaryTree& tree);

//Вызвать консольное меню для дерева.
void BinaryTreeConsole(BinaryTree& tree);


#endif 
