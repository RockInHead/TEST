#include <iostream>
#include"List.h"
#include <chrono>
#include <ctime>
#include"ConsoleColors.h"
using namespace std;

//Выводит текущий список в консоль.
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
}

//Выводит меню для дейтствий над списком.
void Menu(List list)
{
    cout << CYAN << "Current array:" << RESET << endl;
    ShowArray(list);
    cout << endl << "Size:";
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
    cout << LIGHT_BLUE << "[7]" << RESET << " - Sort" << endl;
    cout << LIGHT_RED << "[0]"<<RESET<< " - Exit" << endl;
}

//Валидация вводимых значений для элементов.
int ReadIntegerInput()
{
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

//Валидация вводимых значений строки.Только цифры от 0 до 8.
int ValidateCommandInput(List list)
{
    int input = ReadIntegerInput();
    while (input > 7 || input < 0) {
        system("cls");
        Menu(list);
        cout << "Invalid input. Please enter an existing command! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        input = ReadIntegerInput();
    }
    return input;
}

//Создает список заданным размером.
void CreateListOfSize(List&  list, int size)
{
    for (int i = 0; i < size; i++) {
        list.AddNodeAtEnd(7);
    }

}

//Точка входа в программу.
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
        commandNumber = ValidateCommandInput(list);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
            list.AddNodeAtEnd(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
            list.AddNodeAtStart(newElement);
            system("cls");
            break;
        case 3:
            cout << "Enter a index of element:";
            indexOfElement = ReadIntegerInput();
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
            list.InsertBefore(newElement, indexOfElement);
            system("cls");
            break;
        case 4:
            cout << "Enter a index of element:";
            indexOfElement = ReadIntegerInput();
            cout << "Enter a new element:";
            newElement = ReadIntegerInput();
            list.InsertAfter(newElement, indexOfElement);
            system("cls");
            break;
        case 5:
            cout << "Enter seacrhing element:";
            seacrhingElement = ReadIntegerInput();
            indexOfElement = list.LinearSearch(seacrhingElement);
            system("cls");
            if (indexOfElement != -1) {
                cout << "Index of '" << seacrhingElement << "' is " << indexOfElement << endl << endl;
            }
            else {
                cout << "Element wasn't found :(. Try another element." << endl << endl;
            }
            break;
        case 6:
            cout << "Enter the index of the item to delete:";
            indexOfElement = ReadIntegerInput();
            list.DeleteNodeIndex(indexOfElement);
            system("cls");
            break;
        case 7:
            list.SortList();
            system("cls");
            break;
        case 0:
            programState = false;
            break;
        }
    }
}

