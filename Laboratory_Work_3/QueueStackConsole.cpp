#include <iostream>
#include"Validator.h"
#include"QueueStackConsole.h"
using namespace std;

//�������� ������� ������� � ������.
void ShowQueue(QueueStack& queue) {
    int* array = queue.GetQueueStack();

    for (int i = 0; i < queue.GetSize(); i++)
    {
        if(i==0){
            cout<<GREEN << array[i]<<RESET << " ";
        }
        else if (i==queue.GetSize()-1) {
            cout << RED << array[i] << RESET << " ";
        }
        else {
            cout << array[i] << " ";
        }
    }
    cout << " " << endl << endl;
    delete[] array;
}

//�������� ���� ��� �������.
void MenuQueue(QueueStack& queue)
{
    cout << LIGHT_CYAN << "Queue based on 2 Stacks:" << RESET << endl;
    ShowQueue(queue);
    cout << "Size:" << LIGHT_YELLOW << queue.GetSize() << RESET << endl << endl;

    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the queue" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Queue" << endl;
}

//������� ���������� ���� ��� �������.
void QueueStackConsole(QueueStack& queue) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int popedElement = -1;
    while (stackState)
    {
        MenuQueue(queue);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 3);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
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