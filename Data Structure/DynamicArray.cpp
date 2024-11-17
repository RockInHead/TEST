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
    int Capacity = 4;
    //Кол-во элементов в текущем массиве
    int Length = 0;
    int* currentArray = new int[Capacity] {NULL, NULL, NULL, NULL};

    DynamicArray::DynamicArray() : Capacity(4), Length(0) {
        currentArray = new int[Capacity](); // Инициализация массива нулями
    }
    // Функция увеличения массива
    void DynamicArray::ExpandArray()
    {
        if (Length == Capacity)
        {
            int* expandedArray = new int[Capacity * 2];

            for (int i = 0; i < Capacity * 2; i++)
            {
                expandedArray[i] = NULL;
            }
            for (int i = 0; i < Length; i++)
            {
                expandedArray[i] = currentArray[i];
            }
            Capacity *= 2;
            delete[] currentArray;
            currentArray = expandedArray;
        }
    }
    void DynamicArray::ReduceArray() {
        if (Length <= Capacity / 2 && Capacity != 4)
        {
            int* reducedArray = new int[Capacity / 2];

            for (int i = 0; i < Capacity / 2; i++)
            {
                reducedArray[i] = NULL;
            }
            for (int i = 0; i < Length; i++)
            {
                reducedArray[i] = currentArray[i];
            }
            Capacity /= 2;
            delete[] currentArray;
            currentArray = reducedArray;
        }
    }

    // Функция добавления элемента в конец массива
    void DynamicArray::AddElement(int array[], int newElement)
    {
        for (int i = 0; i < Capacity; i++)
        {
            if (array[i] == NULL)
            {
                //cout << "Enter a new element:";
                //cin >> array[i];
                array[i] = newElement;
                Length++;
                break;
                break;
            }
        }
    }
    // Функция вставки элемента вначало
    void DynamicArray::AddElmentStart(int array[], int newElement)
    {
        /*int newElement;
        cout << "Enter a new element:";
        cin >> newElement;*/
        for (int i = Length + 1; i > 0; i--)
        {
            array[i] = array[i - 1];
        }
        array[0] = newElement;
        Length++;
    }
    // Функция вставки элемента по индексу
    void DynamicArray::Insert(int array[], int newElement, int indexOfElement)
    {

        Length++;
        //ExpandArray();
        for (int i = Length - 1; i > indexOfElement; i--)
        {

            array[i] = array[i - 1];
        }
        array[indexOfElement] = newElement;
    }
    // Функция удаления элемента по индексу
    void DynamicArray::DeleteElementIndex(int array[], int indexOfElement)
    {
        //int indexOfElement;
        //cout << "Enter the index of the item to delete:";
        //cin >> indexOfElement;
        array[indexOfElement] = NULL;
        for (int i = indexOfElement; i <= Length - 1; i++)
        {
            if (array[i] == array[Length - 1])
            {
                array[i] = NULL;
                break;
            }
            array[i] = array[i + 1];
        }
        Length--;
    }
    // Функция удаления элемента по значению
    void DynamicArray::DeleteElementValue(int array[], int DeletedElement)
    {
        /*int DeletedElement;*/
        int indexOfElement;
        /*cout << "Enter the item to delete:";
        cin >> DeletedElement;*/
        for (int i = 0; i < Capacity; i++)
        {
            if (array[i] == DeletedElement)
            {
                array[i] = NULL;
                indexOfElement = i;
                break;
            }
        }
        for (int i = indexOfElement; i <= Length - 1; i++)
        {
            if (array[i] == array[Length - 1])
            {
                array[i] = NULL;
                break;
            }
            array[i] = array[i + 1];

        }
        Length--;
    }
    // Функция линейного поиска элемента в массиве
    int DynamicArray::LinearSearch(int array[], int seacrhingElement)
    {
        /*int seacrhingElement;
        cout << "Enter seacrhing elemnt:";
        cin >> seacrhingElement;*/
        for (int i = 0; i < Length; i++)
        {
            if (array[i] == seacrhingElement)
            {
                /*cout << "Index of seacrhing element is ";
                cout << i << endl;*/
                return i;
                break;
            }
        }
    }
    void DynamicArray::Merge(int array[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Создаем временные массивы
        int* L = new int[n1];
        int* R = new int[n2];

        // Копируем данные во временные массивы L[] и R[]
        for (int i = 0; i < n1; i++)
            L[i] = array[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = array[mid + 1 + j];

        // Сливаем временные массивы обратно в array[left..right]
        int i = 0;    // Индекс первого подмассива
        int j = 0;    // Индекс второго подмассива
        int k = left; // Индекс сливаемого подмассива

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                array[k] = L[i];
                i++;
            }
            else
            {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // Копируем оставшиеся элементы L[], если есть
        while (i < n1)
        {
            array[k] = L[i];
            i++;
            k++;
        }

        // Копируем оставшиеся элементы R[], если есть
        while (j < n2)
        {
            array[k] = R[j];
            j++;
            k++;
        }

        // Освобождаем память
        delete[] L;
        delete[] R;
    }
    void DynamicArray::MergeSortHelper(int array[], int left, int right)
    {
        if (left < right)
        {
            // Находим середину массива
            int mid = left + (right - left) / 2;

            // Рекурсивно сортируем две половины
            DynamicArray::MergeSortHelper(array, left, mid);
            DynamicArray::MergeSortHelper(array, mid + 1, right);

            // Сливаем отсортированные половины
            DynamicArray::Merge(array, left, mid, right);
        }
    }
    void DynamicArray::MergeSort(int array[])
    {
        // Вызов вспомогательной функции с нулевыми индексами
        DynamicArray::MergeSortHelper(array, 0, Length - 1);
    }

   
   


    // Функция бинарного поиска
    int DynamicArray::BinarySearch(int array[], int target) {
        // Создаем копию массива
        //int* array = new int[Length];
        //for (int i = 0; i < Length; i++) {
        //    array[i] = originalArray[i];
        //}

        // Сортируем массив
        DynamicArray::MergeSort(array);

        // Выполняем бинарный поиск
        int left = 0;
        int right = Length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == target) {
                // Освобождаем память
                return mid; // Возвращаем индекс найденного элемента
            }
            if (array[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // Освобождаем память
        return -1; // Элемент не найден
    }

    

    //// Функция сортировки массива по возрастанию
    //void SortAscending(int array[])
    //{
    //    for (int i = 0; i < Capacity; i++)
    //    {
    //        for (int j = 0; j < Capacity - 1; j++)
    //        {
    //            // for(int j=1;j<)
    //            if (array[j] > array[j + 1])
    //            {
    //                int element = array[j];
    //                array[j] = array[j + 1];
    //                array[j + 1] = element;
    //            }
    //        }
    //    }
    //}
    //// Функция сортировки массива по убыванию
    //void SortDescending(int array[])
    //{
    //    for (int i = 0; i < Capacity; i++)
    //    {
    //        for (int j = 0; j < Capacity - 1; j++)
    //        {
    //            // for(int j=1;j<)
    //            if (array[j] < array[j + 1])
    //            {
    //                int element = array[j];
    //                array[j] = array[j + 1];
    //                array[j + 1] = element;
    //            }
    //        }
    //    }
    //}
//};