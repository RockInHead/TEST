#include "DynamicArray.h"
#include <iostream>
//#include <windows.h>
using namespace std;

//Функция вывода массива в строку.
void ShowArray(DynamicArray array)
{
    if (array.GetArray())
        for (int i = 0; i < array.GetLength(); i++)
        {
                cout << array.GetArray()[i] << " ";
        }
    cout << " " << endl;
};
// Функция возвращающая количество элементов в массиве
void ShowLength(DynamicArray array)
{
    cout << array.GetLength() << endl;
}
// Функция вывод меню в консоль
void Menu(DynamicArray array)
{
    cout << "Current array:";
    ShowArray(array);
    cout << "Array length:";
    ShowLength(array);
    cout << "Capacity:";
    cout << array.GetCapacity() << endl;
    cout << "[1] - Add new Elemenet in the end" << endl;
    cout << "[2] - Add new Elemenet in the start" << endl;
    cout << "[3] - Add new Elemenet by index " << endl;
    cout << "[4] - Linear Search" << endl;
    cout << "[5] - Delete Element by index" << endl;
    cout << "[6] - Delete Element by value" << endl;
    cout << "[7] - Merge Sort" << endl;
    cout << "[8] - Binary Search" << endl;
    cout << "[0] - Exit" << endl;
}
//Валидация вводимых значений строки.Только цифры от 0 до 8.
int ValidInputMenu(DynamicArray array)
{
    int Input;
    while ((!(cin >> Input)) || Input > 8 || Input < 0) {
        system("cls");
        Menu(array);
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Input;
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
int main()
{
    /*DynamicArray array = DynamicArray();*/
    DynamicArray array;

    int сommandNumber;
    bool programState = true;
    int newElement;
    int deletedElement;
    int seacrhingElement;
    int index;
    while (programState)
    {
        int сommandNumber;
        Menu(array);
        сommandNumber=ValidInputMenu(array);
    

        switch (сommandNumber)
        {
        case 1:
            cout << "Enter a new element:";
            newElement=ValidCin();
            array.AddElement(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a new element:";
            newElement = ValidCin();
            array.AddElmentStart(newElement);
            system("cls");
            break;
        case 3:
            int indexOfElement;
            cout << "Enter a index of element:";
            indexOfElement = ValidCin();
            cout << "Enter a new element:";
            newElement = ValidCin();
            array.Insert(newElement,indexOfElement);
            system("cls");
            break;
        case 4:
            cout << "Enter seacrhing element:";
            seacrhingElement = ValidCin();
            index=array.LinearSearch(seacrhingElement);
            system("cls");
            if (index != -1) {
                cout << "Index of '" << seacrhingElement << "' is " << index << endl << endl;
            }
            else {
                cout << "Element wasn't found :(. Try another element." << endl << endl;
            }
            break;
        case 5:
            cout << "Enter the index of the item to delete:";
            indexOfElement = ValidCin();
            array.DeleteElementIndex(indexOfElement);
            system("cls");
            break;
        case 6:
            cout << "Enter the element to delete:";
            deletedElement = ValidCin();
            array.DeleteElementValue(deletedElement);
            system("cls");
            break;
        case 7:
            array.MergeSort();
            system("cls");
            break;
        case 8:
            int target;
            int res;
            cout << "Searching element:";
            target = ValidCin();
            res=array.BinarySearch(target);
            system("cls");
            if (res != -1) {
                cout << "Index of '" << target << "' is " << res << endl << endl;
            }
            else {
                cout << "Element wasn't found :(. Try another element." << endl << endl;
            }
            break;

        case 0:
            programState = false;
            break;
        }
    }
}

