#ifndef BINARYTREECONSOLE_H
#define BINARYTREECONSOLE_H

#include <iostream>
#include"Colors.h"
#include"BinaryTree.h"
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#include <memory>
#define   UNICODE
#include <windows.h>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <locale.h>
#endif
static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
//static string ch_hor = "\u2500" /*─*/, ch_ver = "\u2502" /*│*/, ch_ddia = "\u250C" /*┌*/, ch_rddia = "\u2510" /*┐*/, ch_udia = "\u2514" /*└*/, ch_ver_hor = "\u251C\u2500" /*├─*/, ch_udia_hor = "\u2514\u2500" /*└─*/, ch_ddia_hor = "\u250C\u2500" /*┌─*/, ch_ver_spa = "\u2502 " /*│ */;
using namespace std;

void dump4(Node const* node, bool high = true, std::vector<std::string> const& lpref = std::vector<std::string>(), std::vector<std::string> const& cpref = std::vector<std::string>(), std::vector<std::string> const& rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr);

void dump3(BinaryTree* root, int space = 0);

void PrintLevel(Node* root, int level,BinaryTree& tree);

//Показать текущую хэш таблицу в строку.
void ShowBinaryTree(BinaryTree& tree);

//Показать меню для хэш таблицы.
void MenuBinaryTree(BinaryTree& tree);

//Вызвать консольное меню для хэш таблицы.
void BinaryTreeConsole(BinaryTree& tree);


#endif 
