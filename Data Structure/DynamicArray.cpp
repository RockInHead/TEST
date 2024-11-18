#include "DynamicArray.h"
#include <iostream>
#include <windows.h>
#include <stdexcept>
using namespace std;
//using namespace DYNAMIC_ARRAY_H;
//struct DynamicArray
//{
    // Объявление массива

    //Вместимость текущего массива
    int _capacity ;
    //Кол-во элементов в текущем массиве
    int _length ;
    //Фактор роста
    int _growthFactor;
    

    //Получить текущую длину массива
    int DynamicArray::GetLength() const {
        return _length;
    }

    //Получить текущую вместитеьность массива
    int DynamicArray::GetCapacity() const {
        return _capacity;
    }

    //Получить массив
    int* DynamicArray::GetArray() const {
        return _currentArray;
    }

    //Констуктор по умолчанию
    DynamicArray::DynamicArray() : _capacity(4), _length(0),_growthFactor(2) {
        _currentArray = new int[_capacity](); // Инициализация массива нулями
    }

    // Функция увеличения массива
    void DynamicArray::ExpandArray()
    {
        if (_length == _capacity)
        {
            int* expandedArray = new int[_capacity * _growthFactor];

            /*for (int i = 0; i < _capacity * 2; i++)
            {
                expandedArray[i] = NULL;
            }*/
            for (int i = 0; i < _length; i++)
            {
                expandedArray[i] = _currentArray[i];
            }
            _capacity *= _growthFactor;
            delete[] _currentArray;
            _currentArray = expandedArray;
        }
    }
    // Функция уменьшения массива
    void DynamicArray::ReduceArray() {
        if (_length <= _capacity / _growthFactor && _capacity != MinCapacity)
        {
            int* reducedArray = new int[_capacity / _growthFactor];

           /* for (int i = 0; i < _capacity / _growthFactor; i++)
            {
                reducedArray[i] = NULL;
            }*/
            for (int i = 0; i < _length; i++)
            {
                reducedArray[i] = _currentArray[i];
            }
            _capacity /= _growthFactor;
            delete[] _currentArray;
            _currentArray = reducedArray;
        }
    }
    void  DynamicArray::ResizeArray()
    {
        if (_length == _capacity)
        {
            CreateNewArray(_capacity * _growthFactor);
        }
        else if ((_length < _capacity / _growthFactor) && (_capacity  != MinCapacity))
        {
            CreateNewArray(_capacity / _growthFactor);

        }
    }
    void DynamicArray::CreateNewArray(int capacity) 
    {
        int* newArray = new int[capacity];
        for (int i = 0; i < _length; i++) {
            newArray[i] = _currentArray[i];
        }
        _capacity = capacity;
        delete[] _currentArray;
        _currentArray = newArray;
    }
    // Функция добавления элемента в конец массива
    void DynamicArray::AddElement( int newElement)
    {
        
        ResizeArray();
        _currentArray[_length] = newElement;
        _length++;
        //for (int i = 0; i < _capacity; i++)
        //{
        //    if (_currentArray[i] == NULL)
        //    {
        //        //cout << "Enter a new element:";
        //        //cin >> array[i];
        //        _currentArray[i] = newElement;
        //        _length++;
        //        break;
        //        break;
        //    }
        //}
        ResizeArray();

    }
    // Функция вставки элемента вначало
    void DynamicArray::AddElmentStart(int newElement)
    {
        /*int newElement;
        cout << "Enter a new element:";
        cin >> newElement;*/
        ResizeArray();
        for (int i = _length; i > 0; i--)
        {
            _currentArray[i] = _currentArray[i - 1];
        }
        _currentArray[0] = newElement;
        _length++;
        ResizeArray();
    }
    // Функция вставки элемента по индексу
    void DynamicArray::Insert( int newElement, int indexOfElement)
    {
        if (indexOfElement<=_length && indexOfElement >= 0) {
            ResizeArray();
            _length++;
            //ExpandArray();
            for (int i = _length - 1; i > indexOfElement; i--)
            {

                _currentArray[i] = _currentArray[i - 1];
            }
            _currentArray[indexOfElement] = newElement;
            ResizeArray();
        }

    }
    // Функция удаления элемента по индексу
    void DynamicArray::DeleteElementIndex( int indexOfElement)
    {
        //int indexOfElement;
        //cout << "Enter the index of the item to delete:";
        //cin >> indexOfElement;
        if (indexOfElement < _length && indexOfElement>=0) {
            /*_currentArray[indexOfElement] = NULL;*/

            for (int i = indexOfElement; i <= _length - 1; i++)
            {
                if (_currentArray[i] == _currentArray[_length - 1])
                {
                    /*_currentArray[i] = NULL;*/
                    break;
                }
                _currentArray[i] = _currentArray[i + 1];
            }
            _length--;
            ResizeArray();
        }
    }
    // Функция удаления элемента по значению
    void DynamicArray::DeleteElementValue( int DeletedElement)
    {
        /*int DeletedElement;*/
        int indexOfElement=-1;
        /*cout << "Enter the item to delete:";
        cin >> DeletedElement;*/
        for (int i = 0; i < _capacity; i++)
        {
            if (_currentArray[i] == DeletedElement)
            {
                /*_currentArray[i] = NULL;*/
                indexOfElement = i;
                break;
            }
        }
        if (indexOfElement !=-1) {
            for (int i = indexOfElement; i <= _length - 1; i++)
            {
                if (_currentArray[i] == _currentArray[_length - 1])
                {
                    /*_currentArray[i] = NULL;*/
                    break;
                }
                _currentArray[i] = _currentArray[i + 1];

            }
            _length--;
            ResizeArray();
        }
    }
    // Функция линейного поиска элемента в массиве
    int DynamicArray::LinearSearch( int seacrhingElement)
    {
        /*int seacrhingElement;
        cout << "Enter seacrhing elemnt:";
        cin >> seacrhingElement;*/
        for (int i = 0; i < _length; i++)
        {
            if (_currentArray[i] == seacrhingElement)
            {
                /*cout << "Index of seacrhing element is ";
                cout << i << endl;*/
                return i;
                break;
            }
        }
        return -1;
    }
    //Функция объединения массивов
    void DynamicArray::Merge( int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Создаем временные массивы
        int* L = new int[n1];
        int* R = new int[n2];

        // Копируем данные во временные массивы L[] и R[]
        for (int i = 0; i < n1; i++)
            L[i] = _currentArray[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = _currentArray[mid + 1 + j];

        // Сливаем временные массивы обратно в array[left..right]
        int i = 0;    // Индекс первого подмассива
        int j = 0;    // Индекс второго подмассива
        int k = left; // Индекс сливаемого подмассива

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                _currentArray[k] = L[i];
                i++;
            }
            else
            {
                _currentArray[k] = R[j];
                j++;
            }
            k++;
        }

        // Копируем оставшиеся элементы L[], если есть
        while (i < n1)
        {
            _currentArray[k] = L[i];
            i++;
            k++;
        }

        // Копируем оставшиеся элементы R[], если есть
        while (j < n2)
        {
            _currentArray[k] = R[j];
            j++;
            k++;
        }

        // Освобождаем память
        delete[] L;
        delete[] R;
    }
    //Вспомогательная функция для сортировки массива.
    void DynamicArray::MergeSortHelper( int left, int right)
    {
        if (left < right)
        {
            // Находим середину массива
            int mid = left + (right - left) / 2;

            // Рекурсивно сортируем две половины
            DynamicArray::MergeSortHelper( left, mid);
            DynamicArray::MergeSortHelper( mid + 1, right);

            // Сливаем отсортированные половины
            DynamicArray::Merge( left, mid, right);
        }
    }
    //Сортировка массива с помощью MergeSort
    void DynamicArray::MergeSort()
    {
        // Вызов вспомогательной функции с нулевыми индексами
        DynamicArray::MergeSortHelper( 0, _length - 1);
    }
    // Функция бинарного поиска
    int DynamicArray::BinarySearch( int target) {
        // Создаем копию массива
        //int* array = new int[_length];
        //for (int i = 0; i < _length; i++) {
        //    array[i] = originalArray[i];
        //}

        // Сортируем массив
        DynamicArray::MergeSort();

        // Выполняем бинарный поиск
        int left = 0;
        int right = _length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (_currentArray[mid] == target) {
                // Освобождаем память
                return mid; // Возвращаем индекс найденного элемента
            }
            if (_currentArray[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // Освобождаем память
        return -1; // Элемент не найден
    }
