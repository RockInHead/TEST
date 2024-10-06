#include <iostream>
void func(int)
{
std::cout << "Called func(int)" << std::endl;
}
void func(char*)
{
std::cout << "Called func(char*)" << std::endl;
}
int main()
{
// func(NULL); // Неоднозначность: может вызвать func(int) или func(char*)
func(nullptr); // Однозначно вызывает func(char*)
return 0;
}
