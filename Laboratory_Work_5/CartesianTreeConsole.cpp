#include <iostream>
#include "CartesianTreeConsole.h"
#include"Validator.h"
#include"CartesianTree.h"
#include"Colors.h"
using namespace std;

void MenuCartesianTree(CartesianTree& tree)
{
    cout << LIGHT_BLUE << "Cartesian Tree:" << RESET << endl;
    ShowCartesianTree(tree.GetRoot(), true);
    cout << endl;

    cout << "Size:" << LIGHT_YELLOW << tree.GetSize() << RESET << endl << endl;
    cout << "[1]" << " - Add new element not optimazed" << endl;
    cout << "[2]" << " - Remove element by value not optimazed" << endl;
    cout << "[3]" << " - Add new element optimazed" << endl;
    cout << "[4]" << " - Remove element by value optimazed" << endl;
    cout << "[5]" << " - Clear Tree" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Cartesian Tree" << endl;
}

//Вызвать консольное меню для дерева.
void CartesianTreeConsole(CartesianTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int chosenElement;
    while (stackState)
    {
        MenuCartesianTree(tree);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 5);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value:";
            newElement = ReadIntegerInput();
            tree.AddElementNotOptimazed(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElementNotOptimazed(deletedElement);
            system("cls");
            break;
        case 3:
            cout << "Enter a value:";
            newElement = ReadIntegerInput();
            tree.AddElementOptimazed(newElement);
            system("cls");
            break;
        case 4:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElementOptimazed(deletedElement);
            system("cls");
            break;
        case 5:
            tree.ClearTree();
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}