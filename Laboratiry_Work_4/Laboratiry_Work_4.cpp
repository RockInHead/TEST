#include <iostream>
#include"Validator.h"
#include"Colors.h"
#include "HashTableConsole.h"
#include"HashTable.h"
using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose array:" << endl << endl;
    cout << "[1]" << CYAN << " - Hash table" << RESET << endl;
    cout << "[2]" << MAGENTA << " - Dictionary" << RESET << endl;
}

int main()
{
    HashTable hash =  HashTable();
    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1, 4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            HashTableConsole(hash);
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

