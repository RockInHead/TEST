#include <iostream>
#include"Validator.h"
#include"Colors.h"
#include"RBTree.h"
#include"RedBlackTreeConsole.h"
//#include"BinaryTree.h"
//#include "BinaryTreeConsole.h"
//#include"CartesianTreeConsole.h"
//#include"CartesianTree.h"
//using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose Tree:" << endl << endl;
    cout << "[1]" << RED << " - Red-Black Tree" << RESET << endl;
    cout << "[2]" << MAGENTA << " - AVL Tree" << RESET << endl;
}

int main()
{
    RBTree rbTree = RBTree();
    //CartesianTree cartesianTree = CartesianTree();

    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1, 4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            RedBlackTreeConsole(rbTree);
            break;
        case 2:
            system("cls");
          /*  CartesianTreeConsole(cartesianTree);*/
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

