#include <iostream>
#include"Stack.h"
using namespace std;

const string RESET = "\033[0m";  // Сброс цвета
const string RED = "\033[31m";   // Красный
const string GREEN = "\033[32m"; // Зеленый
const string CYAN = "\033[36m";
const string LIGHT_YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string LIGHT_RED = "\033[91m";

void ShowStack(Stack stack) {
    int* array = stack.GetStack();

        for (int i = 0; i < stack.GetSize(); i++)
        {
            if (i == stack.GetSize() - 1) {

                cout<< RED << array[i] <<RESET << " ";
            }
            else {
                cout << array[i] << " ";

            }
        }
    cout << " " << endl << endl;
    delete[] array;
}
void Menu()
{
    cout << "Choose array:" << endl<< endl;
    cout << "[1]" << " - Stack" << endl;
    cout << "[2]" << " - Ring buffer" << endl;
    cout << "[3]" << " - A Queue based on a ring buffer" << endl;
    cout << "[4]" << " - A Queue based on 2 stacks" << endl;
}

void MenuStack(Stack stack)
{
    cout << LIGHT_BLUE <<"Stack array:" << RESET << endl;
    ShowStack(stack);
    cout << "Size:" << LIGHT_YELLOW << stack.GetSize() << RESET<< endl;
    cout << "Top element:" << RED <<stack.GetTop()<< RESET <<endl << endl;
    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;
    cout <<RED <<"[0]"<< RESET << " - Exit the Stack" << endl;
}
int ValidCin()
{
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

int ValidInputMenu(int numbOfFirstCommand,int numbOfLastCommnad)
{
    int Input;
    while ((!(cin >> Input)) || Input > numbOfLastCommnad || Input < numbOfFirstCommand) {

        cout << "\x1b[2K";
        cout << "\x1b[1A";
        cout << "\r";
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Input;
}

void StackConsole() {
    Stack stack = Stack();
    bool stackState = true;
    int commandNumber;
    int newElement;
    while (stackState)
    {
        MenuStack(stack);
        int commandNumber;
        commandNumber = ValidInputMenu(0,4);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ValidCin();
            stack.Push(newElement);
            system("cls");
            break;
        case 2:
            stack.Pop();
            system("cls");
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

int main()
{
    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1,4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            StackConsole();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

