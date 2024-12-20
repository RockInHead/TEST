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

////Выводит дерево в консоль.
void Show1(RBNode const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);
//
//Показать меню для дерева.
////Выводит дерево в консоль.
//Показать меню для дерева.
//Показать меню для дерева.
void Show2(RBNode* root, int space = 0);

//Показать меню для дерева.
//Показать текущее дерево.
void ShowRedBlackTree(RBTree& tree);

//Показать меню для дерева.
void MenuRedBlackTree(RBTree& tree);

//Вызвать консольное меню для дерева.
void RedBlackTreeConsole(RBTree& tree);


#endif 

