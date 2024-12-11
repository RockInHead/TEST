#include <iostream>
#include "HashTableConsole.h"
#include"Validator.h"
#include"HashTable.h"
#include"Colors.h"
using namespace std;

//Показать текущую хэш-таблицу в столбик.
void ShowHashTable(HashTable& hash) {
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

       /* array[i] = nullptr;
        delete array[i];*/

    }
    cout << " " << endl;
    /*delete array;*/
    array = nullptr;
    delete[] array;
}
//Показать меню для стэка.
void MenuHashTable(HashTable& hash)
{
    cout << LIGHT_BLUE << "Hash Table:" << RESET << endl;
    ShowHashTable(hash);
    cout << "Size:" << LIGHT_YELLOW << hash.GetSize() << RESET << endl;
    cout << "Capacity:" << RED << hash.GetCapacity() << RESET << endl << endl;
    cout << "[1]" << " - Put" << endl;
    cout << "[2]" << " - Delete element by Key" << endl;
    cout << "[3]" << " - Searching Element by Key" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}

//Вызвать консольное меню для стэка.
void HashTableConsole(HashTable& hash) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    string key;
    int popedElement;
    while (stackState)
    {
        MenuHashTable(hash);
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
            /*cout<< hash.PearsonHash(key)<<endl<< endl ;
            system("pause");*/

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
            cout << "Element with key " << key << " is " << hash.SearchingValue(key) << endl<< endl;
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}