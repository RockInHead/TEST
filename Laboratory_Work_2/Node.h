#include <iostream>
struct Node {
	//Хранимые данные. В нашем случае число.
	int data;
	//Указатель на следуйщий элемент списка.
	struct Node* next;
	//Указатель на предыдущий элемент списка.
	struct Node* prev;

};