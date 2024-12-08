#include <iostream>
#include "HashTableConsole.h"
#include"Validator.h"

using namespace std;

//Показать текущий стэк в строку.
//void ShowHashTable() {
//   /* int* array = stack.GetStack();*/
//
//    for (int i = 0; i < stack.GetSize(); i++)
//    {
//        if (i == stack.GetSize() - 1) {
//
//            cout << RED << array[i] << RESET << " ";
//        }
//        else {
//            cout << array[i] << " ";
//
//        }
//    }
//    cout << " " << endl << endl;
//    delete[] array;
//}
//Показать меню для стэка.
void MenuHashTable()
{
    cout << LIGHT_BLUE << "Hash Table:" << RESET << endl;
    /*ShowStack(stack);*/
    /*cout << "Size:" << LIGHT_YELLOW << stack.GetSize() << RESET << endl;
    cout << "Top element:" << RED << stack.GetTop() << RESET << endl << endl;*/
    cout << "[1]" << " - Put" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}

//Вызвать консольное меню для стэка.
void HashTableConsole() {
    bool stackState = true;
    int commandNumber;
    int newElement;
    string key;
    int popedElement;
    while (stackState)
    {
        MenuHashTable();
        int commandNumber;
        commandNumber = ValidInputMenu(0, 3);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a key:";
            cin >> key;
            //newElement = ValidCin();
            /*stack.Push(newElement);*/
            cout << "Enter a value:";
            newElement = ValidCin();

            system("cls");
            break;
        case 2:
          /*  popedElement = stack.Pop();
            system("cls");
            if (popedElement != -1) {
                cout << "Poped element is " << popedElement << endl << endl;
            }
            else {
                cout << "Stack is empty!" << endl << endl;
            }*/
            break;
        case 3:
            /*stack.ClearStack();
            system("cls");*/
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}