#include <iostream>
using namespace std;


//void ShowArray(List list)
//{
//    int* array = list.GetList();
//    if (array)
//        for (int i = 0; i < list.GetSize(); i++)
//        {
//            if (i == 0) {
//                cout << GREEN << array[i] << RESET << " ";
//            }
//            else if (i == list.GetSize() - 1) {
//                cout << RED << array[i] << RESET << " ";
//
//            }
//            else {
//                cout << array[i] << " ";
//            }
//        }
//    cout << " " << endl;
//    delete[] array;
//};
void Menu()
{
    cout << "Choose array:" << endl<< endl;
    cout << "[1]" << " - Stack" << endl;
    cout << "[2]" << " - Ring buffer" << endl;
    cout << "[3]" << " - A Queue based on a ring buffer" << endl;
    cout << "[4]" << " - A Queue based on 2 stacks" << endl;
}

void MenuStack()
{
    cout << "Stack array:" << endl << endl;
    cout << "[1]" << " - Push" << endl;
    cout << "[2]" << " - Pop" << endl;
    cout << "[3]" << " - Clearing the memory" << endl;

}
int ValidCin()
{
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}
int ValidInputMenu(int numbOfFirstCommand,int numbOfLastCommnad)
{
    int Input;
    while ((!(cin >> Input)) || Input > numbOfLastCommnad || Input < numbOfFirstCommand) {
        system("cls");
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Input;
}

void Stack() {
    bool stackState = true;
    int commandNumber;
    while (stackState)
    {
        MenuStack();
        int commandNumber;
        commandNumber = ValidInputMenu(0,4);
        switch (commandNumber)
        {
        case 1:

            cout << "Push command" << endl;
            break;
        case 2:
            cout << "Pop command" << endl;

            break;
        case 3:
            cout << "Clear the memory" << endl;
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }


    }
}

int main()
{
    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = ValidInputMenu(1,4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            Stack();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }
}

