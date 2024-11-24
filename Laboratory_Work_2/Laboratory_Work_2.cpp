#include <iostream>
#include"List.h"

using namespace std;

void ShowArray(List list)
{
    int* array = list.GetList();
    if (array)
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << array[i] << " ";
        }
    cout << " " << endl;
    delete[] array;
};
void Menu(List list)
{
    cout << "Current array:" << endl;
    ShowArray(list);
    cout << "Size:";
    cout << list.GetSize() << endl;
    cout << "Tail:";
    cout << list.GetTail() << endl;
    cout << "[1] - Add new Elemenet in the end" << endl;
    cout << "[2] - Add new Elemenet in the start" << endl;
    cout << "[3] - Insert a new element before by index" << endl;
    cout << "[4] - Insert a new element after by index" << endl;
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
    int deletedElement;
    int indexOfElement;
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
            break;
        case 2:
            cout << "Enter a new element:";
            newElement = ValidCin();
            list.AddNodeAtStart(newElement);
            system("cls");
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
           
            break;
        case 6:
            cout << "Enter the index of the item to delete:";
            indexOfElement = ValidCin();
            list.DeleteNodeIndex(indexOfElement);
            system("cls");
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

