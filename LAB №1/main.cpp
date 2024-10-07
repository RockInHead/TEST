#include <iostream>

using namespace std;
struct DynamicArray{
    //Объявление массива
    int* currentArray= new int[4] {12,123,1,256};


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
                // swap(array[j+1],array[j]);
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
    //Функция выводящая символы массива в консоль
    void ShowArray(int array[]){
        for(int i=0;i<4;i++){
        cout<<array[i]<<" ";
    }
    }
 }; 

int main(){
    DynamicArray array;
    
    // for(int i=0;i<4;i++){
    //     cout<<array.currentArray[i]<<endl;
    // }
    array.ShowArray(array.currentArray);
    cout<<" "<<endl;
    
    array.SortAscending(array.currentArray);
    array.ShowArray(array.currentArray);
    cout<<" "<<endl;
    // for(int i=0;i<4;i++){
    //     cout<<array.currentArray[i]<<endl;
    // }
    

    array.SortDescending(array.currentArray);
    array.ShowArray(array.currentArray);
    // for(int i=0;i<4;i++){
    //     cout<<array.currentArray[i]<<endl;
    // }
    cout<<" "<<endl;
    

}
 
