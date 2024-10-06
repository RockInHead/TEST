#include <iostream>
#include <string>
using namespace std;
int main()
{
int a = 5;
int b = 4;
cout << "Address of a: " << &a << endl;
cout << "Address of b: " << &b << endl; 

double c = 13.5; 
cout << "Address of c: " << &c << endl;

bool d = true;
cout << "Address of d: " << &d << endl;
 }