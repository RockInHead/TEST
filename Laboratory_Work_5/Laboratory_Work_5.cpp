#include <iostream>
#include"Validator.h"
#include"Colors.h"
#include"BinaryTree.h"
#include "BinaryTreeConsole.h"
#include"CartesianTreeConsole.h"
#include"CartesianTree.h"
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
    BinaryTree binaryTree = BinaryTree();
    CartesianTree cartesianTree = CartesianTree();

    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1, 2);
        switch (arrayType)
        {
        case 1:
            system("cls");
            BinaryTreeConsole(binaryTree);
            break;
        case 2:
            system("cls");
            CartesianTreeConsole(cartesianTree);
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

