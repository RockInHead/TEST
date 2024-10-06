#include <iostream>
#include <string>
using namespace std;

int main()
 {
    //Массив из 10 элементов
    int array[10]={412,36,64,39,21,-23,94,-36,0,13};
    cout << "Неотсортированный массив из 10 элементов:" << endl;
    string array_string;
    for(int i = 0;i<10;i++){
        array_string.append(" "+to_string(array[i]));
    }
        cout << array_string << endl;
        array_string="";
    cout << "Отсортированный по возрастанию массив из 10 элементов:" << endl;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(array[j]>array[j+1]){
                swap(array[j+1],array[j]);
            }
        }
    }
    for(int i = 0;i<10;i++){
        array_string.append(" "+to_string(array[i]));
    }
     cout << array_string << endl;

 }