#include <iostream>
#include <string>
#include <math.h>

using namespace std;
double GetPower(double base, int exponent)
{
 return pow(base,exponent);
}
void DemoGetPower(double base, int exponent)
{
cout<<base<<" ^ "<<exponent<<" = "<<GetPower(base,exponent)<< endl;
}
int main(){
DemoGetPower(2,5);
DemoGetPower(25,2);

}