#include"HashTable.h"
#include <iostream>

using namespace std;

//Изменяет вместимость хеш-таблицы, создавая новую хеш-таблицу.
void  HashTable::ResizeHashTable()
{
    if (_size == _capacity)
    {
        CreateNewHashTable(static_cast<int>(_capacity * _growthFactor));
    }
    else if (static_cast<int>(_size < _capacity / _growthFactor) && (_capacity != MinCapacity))
    {
        CreateNewHashTable(static_cast<int>(_capacity/_growthFactor));
    }
}
//Создает новую хеш-таблицу с новой вместимостью. Переуказывает указатель на новую хеш-таблицу.
void HashTable::CreateNewHashTable(int capacity)
{
    Node** newTable = new Node * [capacity];
    for (int i = 0; i < capacity; ++i) {
        newTable[i] = nullptr;
    }

    // Перемещение элементов из старой таблицы в новую
    for (int i = 0; i < _capacity; ++i) {
        Node* current = _hashTable[i];
        while (current != nullptr) {
            int newIndex = PearsonHash(current->Key , capacity) ;
            Node* newNode = new Node(current->Key, current->Value);
            if (newTable[newIndex] == nullptr)
            {
                newTable[newIndex] = newNode;
            }
            else
            {
                Node* temp = newTable[newIndex];
                while (temp->Next != nullptr)
                {
                    temp = temp->Next;

                }
                temp->Next = newNode;
                newNode->Prev = temp;
            }
            current = current->Next;
        }
    }

    // Удалить старую таблицу
    for (int i = 0; i < _capacity; ++i) {
        Node* current = _hashTable[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->Next;
            delete temp; // Освободить память
        }
    }

    delete[] _hashTable; // Освобождаем память старой таблицы
    _hashTable = newTable; // Переключаем на новую таблицу
    _capacity = capacity; // Обновляем вместимость
}
//Получить текущую хеш-таблицу.
Node** HashTable::GetHashTable() {
    Node** temp = _hashTable;
    return temp;
}

//Получить текущий размер хеш-таблицы.
int HashTable::GetSize() {
    return _size;
}

//Получить вместимость текущий хеш-таблицы.
int  HashTable::GetCapacity() {
    return _capacity;
}

//Конструктор по умолчанию.
HashTable::HashTable() :_capacity(5), _size(0) {
    _hashTable = new Node*[_capacity]();
    for (int i = 0; i < _capacity; i++)
    {
        _hashTable[i] = nullptr;
    }
}

//Проверяет, если у элементов одинаковые ключи, то приравнивает value перевого элемента value второго элемента.
bool HashTable::CompareKeys(Node* nodeFirst, Node* nodeSecond) {
    if (nodeFirst->Key == nodeSecond->Key) {
        nodeFirst->Value = nodeSecond->Value;
        return true;
    }
    return false;
}

//Добавить элемент в хэш-таблицу.
void HashTable::Put(string key, int data) {
    int index = PearsonHash(key,_capacity);
    Node* newNode = new Node(key, data);

    if (_hashTable[index] == nullptr)
    {
        _hashTable[index] = newNode;
    }
    else
    {
        Node* current = _hashTable[index];

        if (CompareKeys(current, newNode)) return;
       
        while (current->Next != nullptr)
        {
            current = current->Next;

            if (CompareKeys(current->Prev,newNode)||CompareKeys(current, newNode)) return;
        }
        current->Next = newNode;
        newNode->Prev = current;
    }
    _size++;
    ResizeHashTable();

}

//Удаляем элемент по ключу.
void HashTable::DeleteElement(string key) {
    if (_size!=0)
    {
        int index = PearsonHash(key,_capacity);
        Node* temp = _hashTable[index];
        if (temp != nullptr) {
            Node* head = _hashTable[index];
            while (temp->Key != key) {
                if (temp->Next != nullptr) {
                    temp = temp->Next;
                }
                else {
                    return;
                }

            }
            if (temp->Prev == nullptr && temp->Next == nullptr) {
                head = nullptr;
            }
            else if (temp->Next == nullptr) {
                temp->Prev->Next = nullptr;
            }
            else if (temp->Prev == nullptr && temp->Next != nullptr) {
                temp = head;
                head = temp->Next;
            }
            else if (temp->Next != nullptr) {
                temp->Next->Prev = temp->Prev;
            }
            if (temp->Prev != nullptr) {
                temp->Prev->Next = temp->Next;
            }
            temp = nullptr;

            _hashTable[index] = head;
            _size--;
            ResizeHashTable();
        }
    }
}

//Простая хеш-функция.
int HashTable::Hash(string key)
{
    int hashValue = 0;
    for (char c : key)
    {
        hashValue += static_cast<int>(c);
    }
    return hashValue % 5;
}

//Хеш-функция Пирсона. Возвращает хеш, учитывая вместимость хеш-таблицы.
unsigned int HashTable::PearsonHash(string key, int capacity)
{
     static const unsigned char table[256] =
     { 98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219,
       61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115,
       90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10,
      237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121,
      123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55,
       59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222,
      197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186,
       39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99,
      154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254,
      133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139,
      189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44,
      183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12,
      221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166,
        3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117,
      238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110,
       43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239
         };

     unsigned int hash = 0;
     for (char c : key)
     {
         hash = table[hash ^ static_cast<unsigned char>(c)] % capacity;
     }
     return hash;
 }

//Ищет значение по ключу. Возврщает значение элемента.
int HashTable::SearchingValue(string key)
{
    int index = PearsonHash(key,_capacity);
    Node* current = _hashTable[index];

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            return current->Value;
        }
        current = current->Next;
    }

    return -1; // Возвращаем -1, если значение не найдено
}