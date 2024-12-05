#include <iostream>
#include"Colors.h"
#include"Stack.h"
#include "StackConsole.h"
#include"Validator.h"
#include"CircularBuffer.h"
#include"CircularBufferConsole.h"
#include"QueueCircularBufferConsole.h"
#include"QueueStackConsole.h"
using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose array:" << endl<< endl;
    cout << "[1]" << CYAN <<" - Stack"<<RESET << endl;
    cout << "[2]"<< MAGENTA << " - Circular Buffer"<<RESET << endl;
    cout << "[3]"<< LIGHT_GREEN << " - A Queue based on a Circular Buffer"<<RESET << endl;
    cout << "[4]"<< LIGHT_CYAN << " - A Queue based on 2 Stacks"<<RESET << endl;
}

int main()
{
    Stack stack = Stack();
    CircularBuffer buffer= CircularBuffer();
    QueueCircularBuffer queue = QueueCircularBuffer();
    QueueStack queueStack = QueueStack();

    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1,4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            StackConsole(stack);
            break;
        case 2:
            system("cls");
            CircularBufferConsole(buffer);
            break;
        case 3:
            system("cls");
            QueueConsole(queue);
            break;
        case 4:
            system("cls");
            QueueStackConsole(queueStack);
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

