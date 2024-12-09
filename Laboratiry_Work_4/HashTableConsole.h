#ifndef HASHTABLECONSOLE_H
#define HASHTABLECONSOLE_H

#include <iostream>
#include"Colors.h"
#include"HashTable.h"
using namespace std;

//Показать текущую хэш таблицу в строку.
void ShowHashTable(HashTable& hash);

//Показать меню для хэш таблицы.
void MenuHashTable(HashTable& hash);

//Вызвать консольное меню для хэш таблицы.
void HashTableConsole(HashTable& hash);


#endif 
