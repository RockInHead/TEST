#include <iostream>
using namespace std;
int* ReadArray(int count)
{
int* values = new int[count];
for (int i = 0; i < count; i++)
{
cin >> values[i];
}
return values;
}

 int CountPositiveValues(int* values, int count)
 {
 int result = 0;
 for (int i = 0; i < count; i++)
 {
 if (values[i] > 0)
 {
 result++;
 }
 }
 return result;
 }

 int main()
 {
 int count = 15;
 int* values = ReadArray(count);
 cout << "Count is: " << CountPositiveValues(values, count) << endl;

//  count = 20;
//  values = ReadArray(count);
//  cout << "Count is: " << CountPositiveValues(values, count) << endl;

//  delete[] values;
 }