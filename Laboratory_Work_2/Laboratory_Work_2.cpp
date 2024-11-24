#include <iostream>
#include"List.h"

using namespace std;
//Валидация вводимых значений строки.Только цифры от 0 до 8.
void ShowArray(List list)
{
    int* array = list.GetList();
    if (array)
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << array[i] << " ";
        }
    cout << " " << endl;
};
void Menu(List list)
{
    cout << "Current array:" << endl;
    ShowArray(list);
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
int ValidInputMenu(List list)
{
    int Input;
    while ((!(cin >> Input)) || Input > 8 || Input < 0) {
        system("cls");
        Menu(list);
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
    int newElement;
    while (programState)
    {
        int commandNumber;
        Menu(list);
        commandNumber = ValidInputMenu(list);

        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ValidCin();
            list.AddNodeAtEnd(newElement);
            
            system("cls");
            /*list.GetSize();*/
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

