#include <iostream>
#include "StackConsole.h"
#include"Validator.h"
#include"CircularBufferConsole.h"

using namespace std;

//Показать текущий стэк в строку.
void ShowBuffer(CircularBuffer buffer) {
    int* array = buffer.GetCircularBuffer();
    for (int i = 0; i <buffer.GetSize(); ++i) {
        // Индекс, по которому нужно читать элементы из буфера
        int index = (buffer.GetTail() + i) % buffer.GetCapacity();
        std::cout << array[index] << " ";
    }
    cout << " " << endl << endl; 


}
//Показать меню для стэка.
void MenuBuffer(CircularBuffer buffer)
{
    cout << LIGHT_BLUE << "Buffer array:" << RESET << endl;
    ShowBuffer(buffer);

    cout << "Capacity:"<<buffer.GetCapacity() << endl;
    cout << "Occupied places:" << RED << buffer.GetSize() << RESET << "   "  ;
    cout << "Free places:" << GREEN <<buffer.GetFreeElements() << RESET << endl;

    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}


//Вызвать консольное меню для стэка.
void CircularBufferConsole(CircularBuffer& buffer) {

    bool bufferState = true;
    int commandNumber;
    int newElement;
    int popedElement;
    while (bufferState)
    {
        MenuBuffer(buffer);
        int commandNumber;
        commandNumber = ValidInputMenu(0, 4);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ValidCin();
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