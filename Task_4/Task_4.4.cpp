#include <iostream>
#include <string>
using namespace std;
void Foo(double a)
{
cout << "Address of a in Foo(): " << &a << endl;
cout << "Value of a in Foo(): " << a << endl;
a = 15.0;
cout << "New value of a in Foo(): " << a << endl;
}
int main()
{
double a = 5.0;
cout << "Address of a in main(): " << &a << endl;
cout << "Value of a in main(): " << a << endl;
cout << endl;
Foo(a);
cout << endl;
cout << "Value of a in main(): " << a << endl;
}