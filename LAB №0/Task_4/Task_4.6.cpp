#include <iostream>
#include <string>
using namespace std;
void Foo(double* a)
 {
 cout << "Address in pointer: " << a << endl;
 cout << "Address of pointer: " << &a << endl;
 cout << "Value in pointer address: " << *a << endl;
*a = 15.0;
 cout << "New value in pointer address: " << *a << endl;
 }
int main()
{
double value = 5.0;
double* pointer = &value;
cout << "Address of value in main(): " << &value << endl;
cout << "Address in pointer in main(): " << pointer << endl;
cout << "Address of pointer in main(): " << &pointer << endl;
cout << "Value of a in main(): " << value << endl;
cout << endl;
Foo(pointer);
cout << endl;
cout << "Value of a in main(): " << value << endl;
}