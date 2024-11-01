#include <iostream>
#include <windows.h>
using namespace std;
struct DynamicArray
{
    // Объявление массива

    //Вместимость текущего массива
    int Capacity = 4;
    //Кол-во элементов в текущем массиве
    int Length=0;
    int* currentArray = new int[Capacity] {NULL, NULL, NULL, NULL};
    // Функция увеличения массива
    void ExpandArray()
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
     void ReduceArray(){
         if (Length<=Capacity/2 && Capacity!=4) 
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
    void AddElement(int array[],int NewElement)
    {
        for (int i = 0; i < Capacity; i++)
        {
            if (array[i] == NULL)
            {
                //cout << "Enter a new element:";
                //cin >> array[i];
                array[i] = NewElement;
                Length++;
                break;
                break;
            }
        }
    }
    // Функция вставки элемента вначало
    void AddElmentStart(int array[])
    {
        int newElement;
        cout << "Enter a new element:";
        cin >> newElement;
        for (int i = Length + 1; i > 0; i--)
        {
            array[i] = array[i - 1];
        }
        array[0] = newElement;
        Length++;
    }
    // Функция вставки элемента по индексу
    void Insert(int array[])
    {
        int newElement;
        int indexOfElement;
        cout << "Enter a index of elemnt:";
        cin >> indexOfElement;
        cout << "Enter a new element:";
        cin >> newElement;
        for (int i = Length + 1; i > indexOfElement; i--)
        {

            array[i] = array[i - 1];
        }
        array[indexOfElement] = newElement;
        Length++;
    }
    // Функция удаления элемента по индексу
    void DeleteElementIndex(int array[])
    {
        int indexOfElement;
        cout << "Enter the index of the item to delete:";
        cin >> indexOfElement;
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
    void DeleteElementValue(int array[])
    {
        int DeletedElement;
        int indexOfElement;
        cout << "Enter the item to delete:";
        cin >> DeletedElement;
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
    void LinearSearch(int array[])
    {
        int seacrhingElement;
        cout << "Enter seacrhing elemnt:";
        cin >> seacrhingElement;
        for (int i = 0; i < Capacity; i++)
        {
            if (array[i] == seacrhingElement)
            {
                cout << "Index of seacrhing element is ";
                cout << i << endl;
            }
        }
    }
    // Функция бинарного поиска
    int BinarySearch(int array[], int target) {
        // Создаем копию массива
        //int* array = new int[Length];
        //for (int i = 0; i < Length; i++) {
        //    array[i] = originalArray[i];
        //}

        // Сортируем массив
        MergeSort(array);

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

    void MergeSort(int array[])
    {
        // Вызов вспомогательной функции с нулевыми индексами
        MergeSortHelper(array, 0, Length - 1);
    }

    void MergeSortHelper(int array[], int left, int right)
    {
        if (left < right)
        {
            // Находим середину массива
            int mid = left + (right - left) / 2;

            // Рекурсивно сортируем две половины
            MergeSortHelper(array, left, mid);
            MergeSortHelper(array, mid + 1, right);

            // Сливаем отсортированные половины
            Merge(array, left, mid, right);
        }
    }
    void Merge(int array[], int left, int mid, int right)
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

    // Функция сортировки массива по возрастанию
    void SortAscending(int array[])
    {
        for (int i = 0; i < Capacity; i++)
        {
            for (int j = 0; j < Capacity - 1; j++)
            {
                // for(int j=1;j<)
                if (array[j] > array[j + 1])
                {
                    int element = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = element;
                }
            }
        }
    }
    // Функция сортировки массива по убыванию
    void SortDescending(int array[])
    {
        for (int i = 0; i < Capacity; i++)
        {
            for (int j = 0; j < Capacity - 1; j++)
            {
                // for(int j=1;j<)
                if (array[j] < array[j + 1])
                {
                    int element = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = element;
                }
            }
        }
    }
};
// Функция выводящая массив в консоль
void ShowArray(DynamicArray array)
{
    if (array.currentArray)
        for (int i = 0; i < array.Capacity; i++)
        {
            if (array.currentArray[i] != NULL)
            {
                cout << array.currentArray[i] << " ";
            }
        }
    cout << " " << endl;
};
// Функция возвращающая количество элементов в массиве
void ShowLength(DynamicArray array)
{
    cout << array.Length << endl;
}
// Функция вывод меню в консоль
void Menu(DynamicArray array)
{
    cout << "Current array:";
    ShowArray(array);
    cout << "Array length:";
    ShowLength(array);
    cout << "Capacity:";
    cout << array.Capacity << endl;
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
int main()
{
    DynamicArray array;

    int CommandNumber;
    bool ProgramState = true;

    while (ProgramState)
    {

        Menu(array);
        cin >> CommandNumber;
        switch (CommandNumber)
        {
        case 1:
            int NewElement;
            array.ExpandArray();
            cout << "Enter a new element:";
            cin >> NewElement;
            array.AddElement(array.currentArray,NewElement);


            system("cls");
            break;
        case 2:
            array.ExpandArray();
            array.AddElmentStart(array.currentArray);
            system("cls");
            break;
        case 3:
            array.ExpandArray();
            array.Insert(array.currentArray);
            system("cls");
            break;
        case 4:
            array.LinearSearch(array.currentArray);

            break;
        case 5:
            
            array.DeleteElementIndex(array.currentArray);
            array.ReduceArray();

            system("cls");
            break;
        case 6:
            //array.ExpandArray();
            array.DeleteElementValue(array.currentArray);
            array.ReduceArray();
            system("cls");
            break;
        case 7:
            array.MergeSort(array.currentArray);
            // array.SortAscending(array.currentArray);
            system("cls");
            break;
        case 8:
            int target;
            int res;
            /*array.SortDescending(array.currentArray)*/
            cout << "Searching element:";
            cin >> target;
            res=array.BinarySearch(array.currentArray,target);
            system("cls");
            cout << "Index of seaching element is " << res << endl;


            break;

        case 0:
            ProgramState = false;
            break;
        }
    }
}

