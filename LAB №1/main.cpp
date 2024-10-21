#include <iostream>
#include <windows.h>
using namespace std;
struct DynamicArray{
    //Объявление массива
    int *currentArray= new int[4]{NULL,NULL,NULL,NULL};
    int Capacity=4;
    int Length;
    // void ExpandArray(int array[]){
    //     if(Length>Capacity){
    //         int previousArray= *currentArray;
    //         currentArray= new int[Length+4];

    //         for(int i=0;i<Length;i++){
    //         currentArray[i]=previousArray[i];
    //         }

    //         for(int j=Length;j<Length+4;j++){
    //             currentArray[j]=NULL;
    //         }
    //         Capacity=Length+4;
    //     }

    // }
    void AddElement(int array[]){
        for(int i=0;i<4;i++){
            if(array[i]==NULL){
                cout<<"Enter a new element:";
                cin>>array[i];
                Length++;
                break;
                break;
            }
        }
    }

    //Функция возвращающая количество элементов в массиве
    // int Length(int array[]){
    //     return sizeof(array)/sizeof(array[0]);
    // }

    //Функция сортировки массива по возрастанию
    void SortAscending(int array[])
    {
        for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
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
        for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
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
 //Функция выводящая символы массива в консоль
    void ShowArray(int array[]){
        for(int i=0;i<4;i++){
        if(array[i]!=0){
            cout<<array[i]<<" ";
        }
    }
    cout<<" "<<endl;
    };
void Menu(int array[]){
    cout<<"Current array:";
    ShowArray(array);
    cout<<"[1] - Add new Elemenet"<< endl;
    cout<<"[2] - Sort in ascending order"<< endl;
    cout<<"[3] - Sort in descendin order"<< endl;
    cout<<"[4] - Show array"<< endl;
    cout<<"[0] - Exit"<< endl;
}
int main(){



    DynamicArray array;
    int CommandNumber;

    bool ProgramState=true;

    while(ProgramState){
    Menu(array.currentArray);
    cin>>CommandNumber;
    switch (CommandNumber)
    {
    case 1:
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
        ShowArray(array.currentArray);
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
 
