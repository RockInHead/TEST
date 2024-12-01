#include"QueueCircularBufferConsole.h"
#include <iostream>
#include"Validator.h"

using namespace std;

//Показать текущий стэк в строку.
void ShowQueue(QueueCircularBuffer queue) {
    int* array = queue.GetQueue();

    for (int i = 0; i < queue.GetSize(); i++)
    {
        
            cout << array[i] << " ";

        
    }
    cout << " " << endl << endl;
    /*delete[] array;*/
}
//Показать меню для стэка.
void MenuQueue(QueueCircularBuffer queue)
{
    cout << LIGHT_BLUE << "Queue array:" << RESET << endl;
    ShowQueue(queue);
    cout << "Size:" << LIGHT_YELLOW << queue.GetSize() << RESET << endl;
    cout << "Tail:" << queue.GetTail() << "  ";
    cout << "Head:" << queue.GetHead() << endl << endl;

    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the queue" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Queue" << endl;
}


//Вызвать консольное меню для стэка.
void QueueConsole(QueueCircularBuffer& queue) {
    /*Stack stack = Stack();*/
    bool stackState = true;
    int commandNumber;
    int newElement;
    int popedElement = -1;
    while (stackState)
    {
        MenuQueue(queue);
        int commandNumber;
        commandNumber = ValidInputMenu(0, 4);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ValidCin();
            queue.Enqueue(newElement);
            system("cls");
            break;
        case 2:
            popedElement = queue.Dequeue();
            system("cls");
            if (popedElement != -1 ) {
                cout << "Poped element is " << popedElement << endl << endl;
            }
            else {
                cout<< "Queue is empty!" << endl << endl;
            }
            break;
        case 3:
         
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}