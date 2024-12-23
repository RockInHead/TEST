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

//Вывод дерева в консоль.
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

//Показать текущее дерево.
void ShowAVLTree(AVLTree& tree, int foundedElement);

//Показать меню для дерева.
void MenuAVLTree(AVLTree& tree, int foundedElement);

//Вызвать консольное меню для дерева.
void AVLTreeConsole(AVLTree& tree);


#endif 

