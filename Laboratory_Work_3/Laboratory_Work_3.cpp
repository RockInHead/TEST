#include <iostream>
#include"Stack.h"
using namespace std;


//void ShowArray(List list)
//{
//    int* array = list.GetList();
//    if (array)
//        for (int i = 0; i < list.GetSize(); i++)
//        {
//            if (i == 0) {
//                cout << GREEN << array[i] << RESET << " ";
//            }
//            else if (i == list.GetSize() - 1) {
//                cout << RED << array[i] << RESET << " ";
//
//            }
//            else {
//                cout << array[i] << " ";
//            }
//        }
//    cout << " " << endl;
//    delete[] array;
//};

void ShowStack(Stack stack) {
    int* array = stack.GetStack();

        for (int i = 0; i < stack.GetSize(); i++)
        {
            
                cout << array[i] << " ";
           
        }
    cout << " " << endl;
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
    cout << "Stack array:" << endl;
    ShowStack(stack);
    cout << "Size:" << stack.GetSize() << endl;
    cout << "Top element:" << stack.GetTop()<< endl;
    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;

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
    /*int (*Menu)(void) = NULL;*/
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
            cout << "Clear the memory" << endl;
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
        }
    }
}

