#include "DynamicArray.h"
using namespace std;

//�������� ������� ����� �������
int DynamicArray::GetLength() {
    return _length;
}

//�������� ������� �������������� �������
int DynamicArray::GetCapacity() {
    return _capacity;
}

//�������� ������
int* DynamicArray::GetArray() {
    return _currentArray;
}

//���������� �� ���������
DynamicArray::DynamicArray() : _capacity(4), _length(0),_growthFactor(2) {
    _currentArray = new int[_capacity](); 
}

//�������� ������ �������, �������� ����� ������
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

//������� ����� ������� � ����� ������������. 
//������������� ��������� �� ����� ��������� ������.
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

// ������� ���������� �������� � ����� �������
void DynamicArray::AddElement( int newElement)
{
    
    ResizeArray();
    _currentArray[_length] = newElement;
    _length++;
    ResizeArray();

}

// ������� ������� �������� �������
void DynamicArray::AddElmentStart(int newElement)
{
    ResizeArray();
    for (int i = _length; i > 0; i--)
    {
        _currentArray[i] = _currentArray[i - 1];
    }
    _currentArray[0] = newElement;
    _length++;
    ResizeArray();
}

// ������� ������� �������� �� �������
void DynamicArray::Insert( int newElement, int indexOfElement)
{
    if (indexOfElement<=_length && indexOfElement >= 0) {
        ResizeArray();
        _length++;

        for (int i = _length - 1; i > indexOfElement; i--)
        {

            _currentArray[i] = _currentArray[i - 1];
        }
        _currentArray[indexOfElement] = newElement;
        ResizeArray();
    }

}

//������� �������� �������� �� �������
void DynamicArray::DeleteElementIndex( int indexOfElement)
{

    if (indexOfElement < _length && indexOfElement>=0) {

        for (int i = indexOfElement; i <= _length - 1; i++)
        {
            if (_currentArray[i] == _currentArray[_length - 1])
            {
                break;
            }
            _currentArray[i] = _currentArray[i + 1];
        }
        _length--;
        ResizeArray();
    }
}

//������� �������� �������� �� ��������
void DynamicArray::DeleteElementValue( int DeletedElement)
{
    int indexOfElement=-1;
    for (int i = 0; i < _capacity; i++)
    {
        if (_currentArray[i] == DeletedElement)
        {
            indexOfElement = i;
            break;
        }
    }
    if (indexOfElement !=-1 && _length!=0) {
        for (int i = indexOfElement; i <= _length - 1; i++)
        {
            if (_currentArray[i] == _currentArray[_length - 1])
            {

                break;
            }
            _currentArray[i] = _currentArray[i + 1];

        }
        _length--;
        ResizeArray();
    }
}

// ������� ��������� ������ �������� � �������
int DynamicArray::LinearSearch( int seacrhingElement)
{

    for (int i = 0; i < _length; i++)
    {
        if (_currentArray[i] == seacrhingElement)
        {
            return i;
            break;
        }
    }
    return -1;
}

//������� ����������� ��������
void DynamicArray::Merge( int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������� ��������� �������
    int* L = new int[n1];
    int* R = new int[n2];

    // �������� ������ �� ��������� ������� L[] � R[]
    for (int i = 0; i < n1; i++)
        L[i] = _currentArray[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = _currentArray[mid + 1 + j];

    // ������� ��������� ������� ������� � array[left..right]
    int i = 0;    
    int j = 0;    
    int k = left; 

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

    // �������� ���������� �������� L[], ���� ����
    while (i < n1)
    {
        _currentArray[k] = L[i];
        i++;
        k++;
    }

    // �������� ���������� �������� R[], ���� ����
    while (j < n2)
    {
        _currentArray[k] = R[j];
        j++;
        k++;
    }

    // ����������� ������
    delete[] L;
    delete[] R;
}

//��������������� ������� ��� ���������� �������.
void DynamicArray::MergeSortHelper( int left, int right)
{
    if (left < right)
    {
        // ������� �������� �������
        int mid = left + (right - left) / 2;

        // ���������� ��������� ��� ��������
        DynamicArray::MergeSortHelper( left, mid);
        DynamicArray::MergeSortHelper( mid + 1, right);

        // ������� ��������������� ��������
        DynamicArray::Merge( left, mid, right);
    }
}

//���������� ������� � ������� MergeSort
void DynamicArray::MergeSort()
{
    // ����� ��������������� ������� � �������� ���������
    DynamicArray::MergeSortHelper( 0, _length - 1);
}

//������� ��������� ������
int DynamicArray::BinarySearch( int target) {
  
    DynamicArray::MergeSort();

    // ��������� �������� �����
    int left = 0;
    int right = _length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (_currentArray[mid] == target) {
            
            return mid; 
        }
        if (_currentArray[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}
