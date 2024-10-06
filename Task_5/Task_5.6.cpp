#include <iostream>
using namespace std;

int IndexOfArray(int array[],int number){
int fin;
for(int i=0;i<10;i++){
    if(array[i]==number){
        fin= i;
        break;
    }
    else{
    fin= -1;
    }
}
return fin;
}

int main(){

    //Массив из 10 элементов
    int array[10]={412,36,64,39,21,-23,94,-36,0,13};
    cout << "Неотсортированный массив из 10 элементов:" << endl;
    for(int i = 0;i<10;i++){
        cout << array[i]<<" ";
    }
    cout << "" << endl;
    int fin=IndexOfArray(array,13);
    cout<<fin;
    
return 0;
delete[] array;

}