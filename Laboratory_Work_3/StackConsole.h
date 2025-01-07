#ifndef STACKCONSOLE_H
#define STACKCONSOLE_H
#include <iostream>
#include"Stack.h"
#include"Colors.h"
using namespace std;

//Показать текущий стэк в строку.
void ShowStack(Stack stack);

//Показать меню для стэка.
void MenuStack(Stack stack);

//Вызвать консольное меню для стэка.
void StackConsole(Stack& stack);

#endif