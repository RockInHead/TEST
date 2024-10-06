#include <iostream>
using namespace std;
int main()
{
bool *array {new bool[10]{true,false,true,false,true,false,false,true,true,false}};

for(int i=0;i<10;i++){
    cout<<" "<<array[i];
}
 delete[] array;
}
