#include <iostream>
#include "StackConsole.h"
#include"Validator.h"
#include"CircularBufferConsole.h"
using namespace std;

//�������� ������� ���� � ������.
void ShowBuffer(CircularBuffer buffer) {
    int* array = buffer.GetCircularBuffer();
    for (int i = 0; i <buffer.GetSize(); ++i) {
        // ������, �� �������� ����� ������ �������� �� ������
        int index = (buffer.GetTail() + i) % buffer.GetCapacity();
        std::cout << array[index] << " ";
    }
    cout << " " << endl << endl; 


}

//�������� ���� ��� �����.
void MenuBuffer(CircularBuffer buffer)
{
    cout << MAGENTA << "Circular Buffer array:" << RESET << endl;
    ShowBuffer(buffer);

    cout << "Capacity:"<< LIGHT_YELLOW<<buffer.GetCapacity()<<RESET << endl;
    cout << "Occupied places:" << RED << buffer.GetSize() << RESET << "   "  ;
    cout << "Free places:" << GREEN <<buffer.GetFreeElements() << RESET << endl<< endl;

    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Circular Buffer" << endl;
}


//������� ���������� ���� ��� �����.
void CircularBufferConsole(CircularBuffer& buffer) {

    bool bufferState = true;
    int commandNumber;
    int newElement;
    int popedElement;
    while (bufferState)
    {
        MenuBuffer(buffer);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 3);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
            buffer.Push(newElement);
            system("cls");
            break;
        case 2:
            popedElement=buffer.Pop();
            system("cls");
            if (popedElement != -1) {
                cout << "Poped element is " << popedElement << endl << endl;
            }
            else {
                cout << "Buffer empty!"  << endl << endl;
            }
            break;
        case 3:
            buffer.ClearBuffer();
            system("cls");
            break;
        case 0:
            system("cls");
            bufferState = false;
            break;
        }
    }
}