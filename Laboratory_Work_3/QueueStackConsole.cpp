#include <iostream>
#include"Validator.h"
#include"QueueStackConsole.h"

using namespace std;

//Показать текущий очередь в строку.
void ShowQueue(QueueStack& queue) {
    int* array = queue.GetQueueStack();

    for (int i = 0; i < queue.GetSize(); i++)
    {
        cout << array[i] << " ";
    }
    cout << " " << endl << endl;
    delete[] array;
}
//Показать меню для очереди.
void MenuQueue(QueueStack& queue)
{
    cout << LIGHT_BLUE << "Queue array:" << RESET << endl;
    ShowQueue(queue);
    cout << "Size:" << LIGHT_YELLOW << queue.GetSize() << RESET << endl << endl;
    /*cout << "Tail:" << queue.GetTail() << "  ";
    cout << "Head:" << queue.GetHead() << endl << endl;*/

    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the queue" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Queue" << endl;
}


//Вызвать консольное меню для очереди.
void QueueStackConsole(QueueStack& queue) {
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
            if (popedElement != -1) {
                cout << "Poped element is " << popedElement << endl << endl;
            }
            else {
                cout << "Queue is empty!" << endl << endl;
            }
            break;
        case 3:
            queue.ClearQueue();
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}