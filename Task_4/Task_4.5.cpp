#include <iostream>
#include <string>
using namespace std;
int main()
{
int a = 5;
int* pointer = &a;

cout << "Address of a: " << &a << endl;
cout << "Address in pointer: " << pointer << endl;
cout << "Address of pointer: " << &pointer << endl;

cout << endl;
*pointer = 7;
cout << "Value in a: " << a << endl;
cout << "Value by pointer address: " << *pointer << endl;
}