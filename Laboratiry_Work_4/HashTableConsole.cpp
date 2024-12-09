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
            if (array[i]->Next != nullptr) {
                cout << ";(" << array[i]->Next->Key << "," << array[i]->Next->Value << ")";
            }
        }
        cout << "]" << endl;

        cout << " ";

       /* array[i] = nullptr;
        delete array[i];*/

    }
    cout << " " << endl << endl;
    /*delete array;*/
    array = nullptr;
    delete[] array;
}
//Показать меню для стэка.
void MenuHashTable(HashTable& hash)
{
    cout << LIGHT_BLUE << "Hash Table:" << RESET << endl;
    ShowHashTable(hash);
    /*cout << "Size:" << LIGHT_YELLOW << stack.GetSize() << RESET << endl;
    cout << "Top element:" << RED << stack.GetTop() << RESET << endl << endl;*/
    cout << "[1]" << " - Put" << endl;
    cout << "[2]" << " - Get" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;
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
            //newElement = ValidCin();
            /*stack.Push(newElement);*/
            cout << "Enter a value:";
            newElement = ValidCin();

            hash.Put(key, newElement);
            /*cout << hash.Hash(key)<< endl;*/
            cout<< hash.PearsonHash(key)<<endl<< endl ;
            system("pause");
            /*cin >> "Write";*/
            /*cout<< hash.GetNode("g");*/
            system("cls");
            break;
        case 2:
            cout << "Enter a key:";
            cin >> key;
            system("cls");
            cout << "Element with key " << key << " is " << hash.GetNode(key) << endl<< endl;
            break;
        case 3:
            /*stack.ClearStack();
            system("cls");*/
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}