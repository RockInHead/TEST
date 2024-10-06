#include <iostream>
using namespace std;
int main(){
int size;
cout<<"Введите положительное число:";
cin>>size;
char *array {new char[size]};
for(int i=0;i<size;i++){
    cout<<"a["<<i<<"]: ";
    cin>>array[i];
     }
cout <<"Ваш массив:"<< endl;  
for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
    } 
delete[] array;
}