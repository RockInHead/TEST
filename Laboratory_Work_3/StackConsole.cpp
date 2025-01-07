#include <iostream>
#include "StackConsole.h"
#include"Validator.h"
using namespace std;

//Показать текущий стэк в строку.
void ShowStack(Stack stack) {
    int* array = stack.GetStack();

    for (int i = 0; i < stack.GetSize(); i++)
    {
        if (i == stack.GetSize() - 1) {

            cout << RED << array[i] << RESET << " ";
        }
        else {
            cout << array[i] << " ";

        }
    }
    cout << " " << endl << endl;
    delete[] array;
}
//Показать меню для стэка.
void MenuStack(Stack stack)
{
    cout << LIGHT_BLUE << "Stack array:" << RESET << endl;
    ShowStack(stack);
    cout << "Size:" << LIGHT_YELLOW << stack.GetSize() << RESET << endl;
    cout << "Top element:" << RED << stack.GetTop() << RESET << endl << endl;
    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}

//Вызвать консольное меню для стэка.
void StackConsole(Stack& stack) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int popedElement;
    while (stackState)
    {
        MenuStack(stack);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 3);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
            stack.Push(newElement);
            system("cls");
            break;
        case 2:
            popedElement = stack.Pop();
            system("cls");
            if (popedElement != -1) {
                cout << "Poped element is " << popedElement << endl << endl;
            }
            else {
                cout << "Stack is empty!" << endl << endl;
            }
            break;
        case 3:
            stack.ClearStack();
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}