#include <iostream>
#include <windows.h>
using namespace std;
struct DynamicArray{
    //Объявление массива
    int Capacity=4;
    int Length;
    int *currentArray= new int[Capacity]{NULL,NULL,NULL,NULL};

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
        if(array.currentArray[i]!=0){
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
    cout<<"[2] - Sort in ascending order"<< endl;
    cout<<"[3] - Sort in descendin order"<< endl;
    cout<<"[4] - Add new Elemenet in the start"<< endl;
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
        array.SortAscending(array.currentArray);
        system("cls");

        // ShowArray(array.currentArray);
        break;
    case 3:
        array.SortDescending(array.currentArray);
        system("cls");

        // ShowArray(array.currentArray);
        break;
    case 4:
        array.ExpandArray();
        array.AddElmentStart(array.currentArray);
        system("cls");

        // array.ShowLength();
        // ShowArray(array.currentArray);
        break;
    case 0:
        ProgramState=false;
        break;
    case 5:
        system("cls");

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
 
