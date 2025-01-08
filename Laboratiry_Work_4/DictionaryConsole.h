#ifndef DIACTIONARYCONSOLE_H
#define DIACTIONARYCONSOLE_H
#include <iostream>
#include"Colors.h"
#include"Dictionary.h"
using namespace std;

//Показать текущий словарь в строку.
void ShowDictionary(Dictionary& hash);

//Показать меню для словаря.
void MenuDictionary(Dictionary& hash);

//Вызвать консольное меню для слловаря.
void DictionaryConsole(Dictionary& hash);


#endif 
