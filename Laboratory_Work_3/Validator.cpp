#include"Validator.h"

//��������� �������� �������� ��� ���������.
int ReadIntegerInput()
{
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

//��������� ������� �������. ������� ������� �� numbOfFirstCommand � �� numbOfLastCommnad.
int ValidateCommandInput(int numbOfFirstCommand, int numbOfLastCommnad)
{
    int input = ReadIntegerInput();
    while (input > numbOfLastCommnad || input < numbOfFirstCommand) {
        cout << "\x1b[2K";
        cout << "\x1b[1A";
        cout << "\r";
        cout << "Invalid input. Please enter an existing command! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        input = ReadIntegerInput();
    }
    return input;

}