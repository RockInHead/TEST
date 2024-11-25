#include <iostream>
#include"List.h"

using namespace std;
const string RESET = "\033[0m";  // Сброс цвета
const string RED = "\033[31m";   // Красный
const string GREEN = "\033[32m"; // Зеленый
const string CYAN = "\033[36m";
const string LIGHT_YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string LIGHT_RED = "\033[91m";
void ShowArray(List list)
{
    int* array = list.GetList();
    if (array)
        for (int i = 0; i < list.GetSize(); i++)
        {
            if (i==0) {
                cout<< GREEN << array[i]<< RESET<<" ";
            }
            else if (i==list.GetSize()-1) {
                cout << RED << array[i] << RESET << " ";

            }else{
                cout << array[i] << " ";
            }
        }
    cout << " " << endl;
    delete[] array;
};
void Menu(List list)
{
    cout << CYAN << "Current array:" << RESET << endl;
    ShowArray(list);
    cout << "Size:";
    cout << LIGHT_YELLOW << list.GetSize()<< RESET << endl;
    cout << "Head:";
    cout << GREEN << list.GetHead()<< RESET <<" ";
    cout << "Tail:";
    cout << RED << list.GetTail()<<RESET << endl << endl;
    cout << LIGHT_BLUE << "[1]"<< RESET<<" - Add new Elemenet in the end" << endl;
    cout << LIGHT_BLUE << "[2]" << RESET << " - Add new Elemenet in the start" << endl;
    cout << LIGHT_BLUE << "[3]" << RESET << " - Insert a new element before by index" << endl;
    cout << LIGHT_BLUE << "[4]" << RESET << " - Insert a new element after by index" << endl;
    cout << LIGHT_BLUE << "[5]" << RESET << " - Linear Search" << endl;
    cout << LIGHT_BLUE << "[6]" << RESET << " - Delete Element by index" << endl;
    cout << LIGHT_BLUE << "[7]" << RESET << " - Delete Element by value" << endl;
    cout << LIGHT_BLUE << "[8]" << RESET << " - Sort" << endl;
    cout << LIGHT_RED << "[0]"<<RESET<< " - Exit" << endl;
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
    int seacrhingElement;
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
            
            cout << "Enter a index of element:";
            indexOfElement = ValidCin();
            cout << "Enter a new element:";
            newElement = ValidCin();
            list.InsertBefore(newElement, indexOfElement);
            system("cls");
            
            break;
        case 4:
            cout << "Enter a index of element:";
            indexOfElement = ValidCin();
            cout << "Enter a new element:";
            newElement = ValidCin();
            list.InsertAfter(newElement, indexOfElement);
            system("cls");
            break;
        case 5:
            cout << "Enter seacrhing element:";
            seacrhingElement = ValidCin();
            indexOfElement = list.LinearSearch(seacrhingElement);
            system("cls");
            if (indexOfElement != -1) {
                cout << "Index of '" << seacrhingElement << "' is " << indexOfElement << endl << endl;
            }
            else {
                cout << "Element wasn't found :(. Try another element." << endl << endl;
            }
            break;
            break;
        case 6:
            cout << "Enter the index of the item to delete:";
            indexOfElement = ValidCin();
            list.DeleteNodeIndex(indexOfElement);
            system("cls");
            break;
        case 7:
            list.SwapNodes(list._head, list._head->next);
            system("cls");
            break;
        case 8:
            list.SortList();
            system("cls");
            break;
            break;

        case 0:
            programState = false;
            break;
        }
    }
}

