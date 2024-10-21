#include <iostream>
#include <windows.h>
using namespace std;
struct DynamicArray{
    //Объявление массива
    int Capacity=4;
    int Length;
    int *currentArray= new int[Capacity]{NULL,NULL,NULL,NULL};
    //Функция увеличения массива
    void ExpandArray(){
        if(Length==Capacity){
            int *expandedArray= new int[Capacity*2];

            for(int i=0;i<Capacity*2;i++)
            {
                expandedArray[i]=NULL;
            }
            for(int i=0;i<Length;i++){
                expandedArray[i]=currentArray[i];
            }
            Capacity*=2;
            delete [] currentArray;
            currentArray=expandedArray;
        }
    }
    //Функция добавления элемента в конец массива
    void AddElement(int array[]){
        for(int i=0;i<Capacity;i++){
            if(array[i]==NULL){
                cout<<"Enter a new element:";
                cin>>array[i];
                Length++;
                break;
                break;
            }
        }
    }
    //Функция вставки элемента вначало
    void AddElmentStart(int array[])
    {
        int newElement;
        cout<<"Enter a new element:";
        cin>>newElement;
        for(int i=Length+1;i>0;i--){
            array[i]=array[i-1];
        }
        array[0]=newElement;
        Length++;
    }
    //Функция вставки элемента по индексу
    void Insert(int array[])
    {
        int newElement;
        int indexOfElement;
        cout<<"Enter a index of elemnt:";
        cin>>indexOfElement;
        cout<<"Enter a new element:";
        cin>>newElement;
        for(int i=Length+1;i>indexOfElement;i--){
            array[i]=array[i-1];
        }
        array[indexOfElement]=newElement;
        Length++;
    }
    //Функция удаления элемента по индексу
    void DeleteElementIndex(int array[])
    {
        int indexOfElement;
        cout<<"Enter the index of the item to delete:";
        cin>>indexOfElement;
        array[indexOfElement]=NULL;
        for(int i=indexOfElement;i<Length;i++){
            array[i]=array[i+1];
        }
        Length--;
    }
    //Функция удаления элемента по значению
    void DeleteElementValue(int array[])
    {
        int DeletedElement;
        int indexOfElement;
        cout<<"Enter the item to delete:";
        cin>>DeletedElement;
        for(int i=0;i<Capacity;i++){
            if(array[i]==DeletedElement){
                array[i]=NULL;
                indexOfElement=i;
            }
        }
        for(int i=indexOfElement;i<Length;i++){
            array[i]=array[i+1];
        }
        Length--;
    }
    //Функция линейного поиска элемента в массиве
    void LinearSearch(int array[]){
        int seacrhingElement;
        cout<<"Enter seacrhing elemnt:";
        cin>>seacrhingElement;
        for(int i=0;i<Capacity;i++){
            if(array[i]==seacrhingElement){
            cout<<"Index of seacrhing element is ";
            cout<<i<<endl;
            }
        }
    }
    //Функция сортировки массива по возрастанию
    void SortAscending(int array[])
    {
        for(int i=0;i<Capacity;i++){
        for(int j=0;j<Capacity-1;j++){
            // for(int j=1;j<)
            if(array[j]>array[j+1]){
                int element= array[j];
                array[j]=array[j+1];
                array[j+1]=element;
            }
        }
    }
    }
    //Функция сортировки массива по убыванию
    void SortDescending(int array[])
    {
        for(int i=0;i<Capacity;i++){
        for(int j=0;j<Capacity-1;j++){
            // for(int j=1;j<)
            if(array[j]<array[j+1]){
                int element= array[j];
                array[j]=array[j+1];
                array[j+1]=element;
            }
        }
    }
    }
    
 }; 
 //Функция выводящая массив в консоль
    void ShowArray(DynamicArray array){
        if(array.currentArray)
        for(int i=0;i<array.Capacity;i++){
        if(array.currentArray[i]!=NULL){
            cout<<array.currentArray[i]<<" ";
        }
    }
    cout<<" "<<endl;
    };
//Функция возвращающая количество элементов в массиве
void ShowLength(DynamicArray array){
    cout<<array.Length<<endl;
}
//Функция вывод меню в консоль
void Menu(DynamicArray array){
    cout<<"Current array:";
    ShowArray(array);
    cout<<"Array length:";
    ShowLength(array);
    cout<<"Capacity:";
    cout<<array.Capacity<<endl;
    cout<<"[1] - Add new Elemenet in the end"<< endl;
    cout<<"[2] - Add new Elemenet in the start"<< endl;
    cout<<"[3] - Add new Elemenet by index "<< endl;
    cout<<"[4] - Linear Search"<< endl;
    cout<<"[5] - Delete Element by index"<< endl;
    cout<<"[6] - Delete Element by value"<< endl;
    
    cout<<"[7] - Sort in ascending order"<< endl;
    cout<<"[8] - Sort in descendin order"<< endl;

    cout<<"[0] - Exit"<< endl;
}
int main(){
    DynamicArray array;
    
    int CommandNumber;
    bool ProgramState=true;

    while(ProgramState){
    Menu(array);
    cin>>CommandNumber;
    switch (CommandNumber)
    {
    case 1:
        array.ExpandArray();
        array.AddElement(array.currentArray);
        system("cls");
        // array.ShowArray(array.currentArray);
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
        // system("cls");
        break;
    case 5:
        array.DeleteElementIndex(array.currentArray);
        system("cls");
        break;
    case 6:
        array.DeleteElementValue(array.currentArray);
        system("cls");
        break;
    case 7:
        array.SortAscending(array.currentArray);
        system("cls");
        break;
    case 8:
        array.SortDescending(array.currentArray);
        system("cls");
        break;

    case 0:
        ProgramState=false;
        break;
    }
    }
    // array.AddElement(array.currentArray);
    // array.ShowArray(array.currentArray);
    // // cout<<" "<<endl;
    
    // array.SortAscending(array.currentArray);
    // array.ShowArray(array.currentArray);
    // // cout<<" "<<endl;

    // array.SortDescending(array.currentArray);
    // array.ShowArray(array.currentArray);
    // // cout<<" "<<endl;
    // // int len = array.Length(array.currentArray);
    // // cout<<len<<endl;
    // cout<<array.Length;

}
 
