#ifndef AVLTREECONSOLE_H
#define AVLTREECONSOLE_H
#include <iostream>
#include"ConsoleColors.h"
#include"AVLTree.h"
#include"PrintTreeConsole.h"
#include"Validator.h"

using namespace std;

//Показать меню для дерева.
void MenuAVLTree(AVLTree& tree, int foundedElement);

//Вызвать консольное меню для дерева.
void AVLTreeConsole(AVLTree& tree);


#endif 

