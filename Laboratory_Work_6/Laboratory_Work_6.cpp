#include <iostream>
#include"Validator.h"
#include"ConsoleColors.h"
#include"RedBlackTreeConsole.h"
#include"AVLTreeConsole.h"

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose Tree:" << endl << endl;
    cout << "[1]" << RED << " - Red-Black Tree" << RESET << endl;
    cout << "[2]" << MAGENTA << " - AVL Tree" << RESET << endl;
    cout << RED << "[0]" << RESET << " - Exit the Program" << endl;
}

//Точка входа в программу.
int main()
{
    RBTree rbTree = RBTree();
    AVLTree avlTree = AVLTree();

    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidateCommandInput(0, 2);
        switch (arrayType)
        {
        case 1:
            system("cls");
            RedBlackTreeConsole(rbTree);
            break;
        case 2:
            system("cls");
            AVLTreeConsole(avlTree);
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

