#include <iostream>
#include <string>
using namespace std;
void RoundToTens(int& value){
if(value%10<5){
    value=(value/10)*10;
}
else{
    value=(value/10+1)*10;

}
}
int main()
{
int a = 36;
int *b= &a;


cout<<"Число "<<a<<" округлили до ";
RoundToTens(*b);
cout<<a<<endl;

}