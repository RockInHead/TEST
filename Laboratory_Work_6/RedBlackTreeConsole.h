#ifndef RBTREECONSOLE_H
#define RBTREECONSOLE_H
#include <iostream>
#include"ConsoleColors.h"
#include"RBTree.h"
#include"PrintTreeConsole.h"
#include"Validator.h"

using namespace std;

//Показать меню для дерева.
void MenuRedBlackTree(RBTree& tree,int foundedElement);

//Вызвать консольное меню для дерева.
void RedBlackTreeConsole(RBTree& tree);

#endif 

