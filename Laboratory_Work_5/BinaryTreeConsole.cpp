#include <iostream>
#include "BinaryTreeConsole.h"
#include"Validator.h"
#include"BinaryTree.h"
#include"Colors.h"
using namespace std;

//Выводит меню для работы с деревом.
void MenuBinaryTree(BinaryTree& tree)
{
    cout << LIGHT_BLUE << "Binary Tree:" << RESET << endl;
    ShowBinaryTree(tree.GetRoot(), true);
    cout << endl;
    
    cout << "Size:" << LIGHT_YELLOW << tree.GetSize() << RESET << endl;
    cout << "Height:" << RED << tree.GetHeight() << RESET << endl ;
    cout << "Min Element:" << GREEN << tree.FindMin() << RESET;
    cout << "  Max Element:" << RED << tree.FindMax() << RESET << endl << endl;

    cout << "[1]" << " - Add new elemnt" << endl;
    cout << "[2]" << " - Remove element by value" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Binary Tree" << endl;
}

//Вызвать консольное меню для дерева.
void BinaryTreeConsole(BinaryTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int chosenElement;
    while (stackState)
    {
        MenuBinaryTree(tree);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 2);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value:";
            newElement = ReadIntegerInput();
            tree.AddElement(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElement(deletedElement);
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}