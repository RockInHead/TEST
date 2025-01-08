#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>

using namespace std;

//Валидация вводимых значений для элементов.
int ReadIntegerInput();

//Валидация вводмых комманд. Команды начиная от numbOfFirstCommand и до numbOfLastCommnad.
int ValidateCommandInput(int numbOfFirstCommand, int numbOfLastCommnad);


#endif 