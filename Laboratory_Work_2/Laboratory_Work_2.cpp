#include <iostream>
#include"List.h"

using namespace std;
//Валидация вводимых значений строки.Только цифры от 0 до 8.

void Menu()
{
    cout << "Current array:" << endl;
    /*ShowArray(array);*/
    cout << "Array length:" << endl;
    /*ShowLength(array);*/
    cout << "Capacity:" << endl;
    /*cout << array.GetCapacity() << endl;*/
    cout << "[1] - Add new Elemenet in the end" << endl;
    cout << "[2] - Add new Elemenet in the start" << endl;
    cout << "[3] - Insert a new element before by index" << endl;
    cout << "[4] - Insert a new element before by index" << endl;
    cout << "[5] - Linear Search" << endl;
    cout << "[6] - Delete Element by index" << endl;
    cout << "[7] - Delete Element by value" << endl;
    cout << "[8] - Sort" << endl;
    cout << "[0] - Exit" << endl;
}
int ValidInputMenu()
{
    int Input;
    while ((!(cin >> Input)) || Input > 8 || Input < 0) {
        system("cls");
        Menu();
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Input;
}
int main()
{
    List list = List();
    bool programState = true;
    while (programState)
    {
        int commandNumber;
        Menu();
        commandNumber = ValidInputMenu();

        switch (commandNumber)
        {
        case 1:
            list.AddNodeAtEnd(36);
            list.AddNodeAtEnd(5);
            list.AddNodeAtEnd(2);
            list.AddNodeAtEnd(124);


            list.GetList();
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
           
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;

        case 0:
          
            break;
        }
    }
}

