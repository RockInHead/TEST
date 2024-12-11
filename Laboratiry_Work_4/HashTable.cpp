#include"HashTable.h"
#include <iostream>

void  HashTable::ResizeHashTable()
{
    if (_size == _capacity)
    {
        CreateNewHashTable(_capacity * _growthFactor);
    }
    else if ((_size < _capacity / _growthFactor) && (_capacity != MinCapacity))
    {
        CreateNewHashTable(_capacity/_growthFactor);

    }
}
void HashTable::CreateNewHashTable(int capacity)
{
    Node** newTable = new Node * [capacity];
    for (int i = 0; i < capacity; ++i) {
        newTable[i] = nullptr;
    }

    // Перемещение элементов из старой таблицы в новую
    for (int i = 0; i < _capacity; ++i) {
        Node* current = _table[i];
        while (current != nullptr) {
            int newIndex = PearsonHash(current->Key , capacity) ;
            Node* newNode = new Node(current->Key, current->Value);
            //newNode = newTable[newIndex];
            //newTable[newIndex] = newNode;
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
        Node* current = _table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->Next;
            delete temp; // Освободить память
        }
    }

    delete[] _table; // Освобождаем память старой таблицы
    _table = newTable; // Переключаем на новую таблицу
    _capacity = capacity; // Обновляем вместимость





    /*Node* newHashTable = new Node[capacity];
    for (int i = 0; i < _capacity; i++) {
        int index = PearsonHash(_table[i]->Key);
        newHashTable[index] = _table[i];
    }*/
    /*for (int i = 0; i < _size; i++) {
        newHashTable[i] = _currentArray[i];
    }
    _capacity = capacity;
    delete[] _currentArray;
    _currentArray = newArray;*/
}

using namespace std;
Node** HashTable::GetHashTable() {
    Node** temp = _table;
    return temp;
}

int HashTable::GetSize() {
    return _size;
}

int  HashTable::GetCapacity() {
    return _capacity;
}


HashTable::HashTable() :_capacity(5), _size(0) {
    _table = new Node*[_capacity]();
    for (int i = 0; i < _capacity; i++)
    {
        _table[i] = nullptr;
    }
}

bool HashTable::CompareKeys(Node* nodeFirst, Node* nodeSecond) {
    if (nodeFirst->Key == nodeSecond->Key) {
        nodeFirst->Value = nodeSecond->Value;
        return true;
    }
    return false;
}

void HashTable::Put(string key, int data) {
    int index = PearsonHash(key,_capacity);
    Node* newNode = new Node(key, data);

    if (_table[index] == nullptr)
    {
        _table[index] = newNode;
    }
    else
    {
        Node* current = _table[index];

        if (CompareKeys(current, newNode)) {
            return;
        }
        while (current->Next != nullptr)
        {
            current = current->Next;

            if (CompareKeys(current->Prev,newNode)||CompareKeys(current, newNode)) {
                return;
            }
        }
        current->Next = newNode;
        newNode->Prev = current;
    }
    _size++;
    ResizeHashTable();

}

void HashTable::DeleteElement(string key) {

    //if (_size == 0) {
    //    return; // Если таблица пустая, ничего не делаем
    //}

    //int index = PearsonHash(key, _capacity);
    //Node* temp = _table[index];
    //// Перебираем элементы списка по этому индексу
    //while (temp != nullptr) {
    //    temp->Prev = nullptr;

    //    if (temp->Key == key) {
    //        // Найден ключ, удаляем элемент
    //        if (temp->Prev) {
    //            temp->Prev->Next = temp->Next; // Привязываем предыдущий узел к следующему
    //        }
    //        else {
    //            _table[index] = temp->Next; // Если это голова списка, перемещаем голову
    //        }

    //        if (temp->Next) {
    //            temp->Next->Prev = temp->Prev; // Привязываем следующий узел к предыдущему
    //        }

    //        delete temp; // Освобождаем память
    //        _size--; // Уменьшаем размер таблицы

    //        ResizeHashTable(); // Пересчитываем таблицу, если нужно
    //        return; // Ушли после успешного удаления
    //    }
    //    temp = temp->Next; // Переходим к следующему элементу
    //}




    //int index = PearsonHash(key,_capacity); // Вычисляем индекс по ключу
    //Node* current = _table[index]; // Начало списка узлов по индексу

    //// Поиск узла с заданным ключом
    //while (current != nullptr) {
    //    if (current->Key == key) { // Если ключ совпадает
    //        if (current->Prev != nullptr) {
    //            current->Prev->Next = current->Next; // Изменяем указатель предыдущего узла
    //        }
    //        else {
    //            _table[index] = current->Next; // Если это первый элемент
    //        }
    //        if (current->Next != nullptr) {
    //            current->Next->Prev = current->Prev; // Изменяем указатель следующего узла
    //        }
    //        delete current; // Освобождаем память для узла
    //        _size--; // Уменьшаем размер
    //        ResizeHashTable(); // Вызываем функцию изменения размера, если необходимо
    //        return; // Завершаем выполнение, так как ключ был найден и удалён
    //    }
    //    current = current->Next; // Переход к следующему узлу
    //}

    //// Если ключ не найден, функция завершится без каких-либо изменений



    if (_size!=0)
    {
        int count=1;
        int index = PearsonHash(key,_capacity);
        Node* temp = _table[index];
        if (temp != nullptr) {
            Node* head = _table[index];
            head->Prev = nullptr;
            Node* prev = new Node();
            while (temp->Key != key) {
                prev = temp;
                if (temp->Next != nullptr) {
                    temp = temp->Next;
                }
                else {
                    return;
                }
                count++;
            }
            if (temp->Prev == nullptr && temp->Next == nullptr) {
                head = nullptr;
                /*temp = nullptr;*/
            }
            else if (temp->Next == nullptr) {
                temp->Prev->Next = nullptr;
                /*temp = nullptr;*/
            }
            else if (temp->Prev == nullptr && temp->Next != nullptr) {
                temp = head;
                head = temp->Next;
                /*temp = nullptr;*/
            }
            else if (temp->Next != nullptr) {
                temp->Next->Prev = temp->Prev;
                /*head = temp->Prev;*/
                /*temp = nullptr;*/
            }
            if (temp->Prev != nullptr) {
                temp->Prev->Next = temp->Next;
            }
            temp = nullptr;

            _table[index] = head;
            _size--;
            ResizeHashTable();
        }
    }
}

int HashTable::Hash(string key)
{
    int hashValue = 0;
    for (char c : key)
    {
        hashValue += static_cast<int>(c);
    }
    return hashValue % 5;
}
unsigned int HashTable::PearsonHash(string key, int capacity)
{
     static const unsigned char table[256] =
     { 98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219, //  1
       61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115, //  2
       90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10, //  3
      237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121, //  4
      123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55, //  5
       59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222, //  6
      197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186, //  7
       39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99, //  8
      154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254, //  9
      133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139, // 10
      189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44, // 11
      183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12, // 12
      221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166, // 13
        3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117, // 14
      238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110, // 15
       43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239
         };

     unsigned int hash = 0;
     for (char c : key)
     {
         hash = table[hash ^ static_cast<unsigned char>(c)] % capacity;
     }
     return hash;
 }

int HashTable::SearchingValue(string key)
{
    int index = PearsonHash(key,_capacity);
    Node* current = _table[index];

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