#include "AVLTreeConsole.h"
using namespace std;

//Показать меню для дерева.
void MenuAVLTree(AVLTree& tree, int foundedElement)
{
    cout << MAGENTA << "AVL Tree:" << RESET << endl;
    ShowAVLTree(tree.GetRoot(), true, foundedElement);
    cout << endl;

    cout << "Height:" << LIGHT_YELLOW << tree.GetTreeHeight() << RESET << endl;
    cout << "Min Element:" << GREEN << tree.FindMin() << RESET;
    cout << "  Max Element:" << RED << tree.FindMax() << RESET << endl << endl;

    cout << "[1]" << " - Add new elemnt" << endl;
    cout << "[2]" << " - Remove element by value" << endl;
    cout << "[3]" << " - Find element by value" << endl;
    cout << "[4]" << " - CLear AVL Tree" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Tree" << endl;
}

//Вызвать консольное меню для дерева.
void AVLTreeConsole(AVLTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int seacrhingElement;
    int foundedElement = -1;
    while (stackState)
    {
        MenuAVLTree(tree, foundedElement);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 4);
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
        case 3:
            cout << "Enter a value:";
            cin >> seacrhingElement;
            foundedElement = tree.FindValue(seacrhingElement);
            system("cls");
            break;
        case 4:
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