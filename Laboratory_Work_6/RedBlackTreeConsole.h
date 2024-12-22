#ifndef BINARYTREECONSOLE_H
#define BINARYTREECONSOLE_H
#include <iostream>
#include"Colors.h"
#include <vector>
#include <string>
#include <iostream>
#include"RBTree.h"
#include "Symbols.h"

using namespace std;

//Выводит текущее дерево к консоль.
void ShowTree(RBNode const* node, bool high, int foundedElement, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

//Показать текущее дерево.
void ShowRedBlackTree(RBTree& tree,int foundedElement);

//Показать меню для дерева.
void MenuRedBlackTree(RBTree& tree,int foundedElement);

//Вызвать консольное меню для дерева.
void RedBlackTreeConsole(RBTree& tree);


#endif 

