#include <iostream>
#include <string>
using namespace std;

int main()
 {
    //Массив из 10 элементов
    double array[10]={412.0,36.0,64.0,39.0,21.0,-23.0,94.0,-36.0,0.0,13.0};
    cout << "Неотсортированный массив из 10 элементов:" << endl;
    string array_string;
    for(int i = 0;i<10;i++){
        array_string.append(" "+to_string(array[i]));
    }
        cout << array_string << endl;
    double number;
    cout <<"Ваше число?";
    cin >> number;
    cout <<"Ваше число: "<< number << endl;
    int counter=0;
    for(int i;i<10;i++){
        if(array[i]>=number){
            counter+=1;
        }
    }
    cout <<"Количество элементов массива, которые больше или равны "<< number<<": "<< counter<< endl;
 }