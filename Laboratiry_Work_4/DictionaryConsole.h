#ifndef DIACTIONARYCONSOLE_H
#define DIACTIONARYCONSOLE_H

#include <iostream>
#include"Colors.h"
#include"Dictionary.h"
using namespace std;

//Показать текущую хэш таблицу в строку.
void ShowDictionary(Dictionary& hash);

//Показать меню для хэш таблицы.
void MenuDictionary(Dictionary& hash);

//Вызвать консольное меню для хэш таблицы.
void DictionaryConsole(Dictionary& hash);


#endif 
