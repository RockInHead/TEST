#include <iostream>
#include "DictionaryConsole.h"
#include"Validator.h"
#include"Dictionary.h"
#include"Colors.h"
using namespace std;

//Показать текущую хэш-таблицу в столбик.
void ShowDictionary(Dictionary& hash) {
    Node** array = hash.GetHashTable();
    cout << " ";
    for (int i = 0; i < hash.GetCapacity(); i++)
    {
        cout<<RED << i <<RESET <<":[";
        if (array[i] != nullptr) {
            cout << "(" << array[i]->Key << "," << array[i]->Value << ")";
            Node* temp = array[i]->Next;
            while (temp!= nullptr) {
                cout << ";(" << temp->Key << "," << temp->Value << ")";
                temp = temp->Next;
            }
        }
        cout << "]" << endl;
        cout << " ";
    }
    cout << " " << endl;

    array = nullptr;
    delete[] array;
}
//Показать меню для стэка.
void MenuDictionary(Dictionary& hash)
{
    cout << LIGHT_BLUE << "Hash Table:" << RESET << endl;
    ShowDictionary(hash);
    cout << "Size:" << LIGHT_YELLOW << hash.GetSize() << RESET << endl;
    cout << "Capacity:" << RED << hash.GetCapacity() << RESET << endl << endl;
    cout << "[1]" << " - Put" << endl;
    cout << "[2]" << " - Delete element by Key" << endl;
    cout << "[3]" << " - Searching Element by Key" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}

//Вызвать консольное меню для стэка.
void DictionaryConsole(Dictionary& hash) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    string key;
    int chosenElement;
    while (stackState)
    {
        MenuDictionary(hash);
        int commandNumber;
        commandNumber = ValidInputMenu(0, 3);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a key:";
            cin >> key;
            cout << "Enter a value:";
            newElement = ValidCin();
            hash.Put(key, newElement);

            system("cls");
            break;
        case 2:
            cout << "Enter a key:";
            cin >> key;
            hash.DeleteElement(key);
            system("cls");
            break;
        case 3:
            cout << "Enter a key:";
            cin >> key;
            system("cls");
            chosenElement = hash.SearchingValue(key);
            if (chosenElement != -1) {
                cout << "Element with key " << key << " is " << chosenElement << endl << endl;
            }
            else {
                cout<<"No such element in Dictionary" << endl << endl;
            }
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}