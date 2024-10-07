#include <iostream>
using namespace std;
int main(){

        //Массив из 10 элементов
    double array[10]={412.2,36.6,64.5,39.4,21.0,-23.0,94.0,-36.0,0.5,13.7};
    cout << "Неотсортированный массив из 10 элементов:" << endl;
    string array_string;
    for(int i = 0;i<10;i++){
        cout << array[i]<<" ";

        // array_string.append(" "+to_string(array[i]));
    }
        // cout << array_string << endl;
        // array_string="";
    cout << "" << endl;
    cout << "Отсортированный по возрастанию массив из 10 элементов:" << endl;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(array[j]>array[j+1]){
                swap(array[j+1],array[j]);
            }
        }
    }
    for(int i = 0;i<10;i++){
        cout << array[i]<<" ";
        // printf("%f",array[i]);

        // array_string.append(" "+to_string(array[i]));
    }
delete[] array;

}