#include <iostream>
#include"Validator.h"
#include"Colors.h"
//#include "DictionaryConsole.h"
//#include"Dictionary.h"
using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose Tree:" << endl << endl;
    cout << "[1]" << CYAN << " - Binary Tree" << RESET << endl;
    cout << "[2]" << MAGENTA << " - Cartesian Tree" << RESET << endl;
}

int main()
{
    /*Dictionary hash = Dictionary();*/
    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1, 4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            
            break;
        case 2:
            system("cls");

            break;
        case 0:
            programState = false;
            break;
        }
    }
}

