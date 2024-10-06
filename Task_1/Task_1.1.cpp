#include <iostream>

using namespace std;

void Breakpoints()
{
double add = 1.0;
double sum = 0.0;

for (int i = 0; i < 10; i++)
{
    sum += add * i;
    add *= 1.1;
}
cout << "Total sum is " << sum << endl;
 }

int main()
 {
 Breakpoints();
 }
