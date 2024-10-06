#include <iostream>
#include <string>
#include <math.h>
using namespace std;
double GetPower(double base, int exponent){
 return pow(base,exponent);
}
int main(){
cout <<"2 ^ 3 = "<<GetPower(2,3)<<endl;
cout <<"10 ^ 6 = "<<GetPower(10,6)<<endl;
cout <<"8.1 ^ 3 = "<<GetPower(8.1,3)<<endl;

}