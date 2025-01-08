#include <iostream>
#include"Validator.h"
#include"Colors.h"
#include "DictionaryConsole.h"
#include"Dictionary.h"
using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose data structure:" << endl << endl;
    cout << "[1]" << MAGENTA << " - Dictionary" << RESET << endl;
    cout << "[0]" << LIGHT_RED << " - Exit" << RESET << endl;

}

//Точка входа в программу.
int main()
{
    Dictionary hash =  Dictionary();
    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidateCommandInput(0,1);
        switch (arrayType)
        {
        case 1:
            system("cls");
            DictionaryConsole(hash);
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

