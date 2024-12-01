#include <iostream>
#include"Colors.h"
#include"Stack.h"
#include "StackConsole.h"
#include"Validator.h"
#include"CircularBuffer.h"
#include"CircularBufferConsole.h"
#include"QueueCircularBufferConsole.h"

using namespace std;

void Menu()
{
    cout << "Choose array:" << endl<< endl;
    cout << "[1]" << " - Stack" << endl;
    cout << "[2]" << " - Ring buffer" << endl;
    cout << "[3]" << " - A Queue based on a ring buffer" << endl;
    cout << "[4]" << " - A Queue based on 2 stacks" << endl;
}

int main()
{
    CircularBuffer buffer= CircularBuffer();
    Stack stack = Stack();
    QueueCircularBuffer queue = QueueCircularBuffer();
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

            break;
        case 0:
            programState = false;
            break;
        }
    }
}

