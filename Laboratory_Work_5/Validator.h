#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>

using namespace std;

//Валидация вводимых значений для элементов.
int ValidCin();

//Валидация вводмых комманд. Команды начиная от numbOfFirstCommand и до numbOfLastCommnad.
int ValidInputMenu(int numbOfFirstCommand, int numbOfLastCommnad);


#endif 