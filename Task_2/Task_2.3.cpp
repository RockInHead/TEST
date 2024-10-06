#include <iostream>
#include <string>
using namespace std;
int main(){
 char Symbols[8];
 cout <<"Пожалуйста введите значения 8 символов, для каждого элемента массива)"<< endl;  
 for(int i;i<8;i++){
    cout<<"a["<<i<<"]: ";
    cin>>Symbols[i];
 }
    cout <<"Ваш массив:"<< endl;  
    for(int i = 0;i<8;i++){
        cout << Symbols[i]<<"-"<<int(Symbols[i])<<" ";
    }
    cout << endl;
    for(int i = 0;i<8;i++){
        if((int(Symbols[i])>=65 && int(Symbols[i])<=90) || (int(Symbols[i])>=97 && int(Symbols[i])<=122)){
            cout << Symbols[i]<< " ";
        }
    }

 }