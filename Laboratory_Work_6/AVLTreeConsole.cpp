#include "AVLTreeConsole.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функция для добавления нескольких элементов
void AddMultipleElements(AVLTree& tree) {
    int n;
    cout << "Enter number of elements to add: ";
    cin >> n;

    auto totalStart = high_resolution_clock::now(); // Начало общего замера времени

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < n; ++i) {
        int newElement = rand() % n; // Генерация случайного числа от 0 до 99
        tree.AddElement(newElement); // Добавляем элемент
    }

    auto totalStop = high_resolution_clock::now(); // Конец общего замера времени
    auto totalDuration = duration_cast<microseconds>(totalStop - totalStart); // Считаем общее время

    system("cls");

    cout << "Total time taken to add " << n << " elements: " << totalDuration.count() << " microseconds" << endl;
}

//Показать меню для дерева.
void MenuAVLTree(AVLTree& tree, int foundedElement)
{
    cout << MAGENTA << "AVL Tree:" << RESET << endl;
    /*ShowAVLTree(tree.GetRoot(), true, foundedElement);*/
    cout << endl;

    cout << "Height:" << LIGHT_YELLOW << tree.GetTreeHeight() << RESET << endl;
    cout << "Min Element:" << GREEN << tree.FindMin() << RESET;
    cout << "  Max Element:" << RED << tree.FindMax() << RESET << endl << endl;

    cout << "[1]" << " - Add new elemnt" << endl;
    cout << "[2]" << " - Remove element by value" << endl;
    cout << "[3]" << " - Find element by value" << endl;
    cout << "[4]" << " - CLear AVL Tree" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Tree" << endl;
}

//Вызвать консольное меню для дерева.
void AVLTreeConsole(AVLTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int seacrhingElement;
    int foundedElement = -1;
    while (stackState)
    {
        MenuAVLTree(tree, foundedElement);
        int commandNumber;
        commandNumber = ValidateCommandInput(0, 5);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value: ";
            newElement = ReadIntegerInput();

            {
                auto start = high_resolution_clock::now();
                tree.AddElement(newElement);
                auto stop = high_resolution_clock::now();
                auto durationMicro = duration_cast<microseconds>(stop - start);
                auto durationNano = duration_cast<nanoseconds>(stop - start);

                system("cls");

                cout << "Time taken to add " << newElement << ": "
                    << durationMicro.count() << " microseconds ("
                    << durationNano.count() << " nanoseconds)" << endl;

                cout << "Rotation count is " << tree.GetRotationCount() << endl << endl;

            }


            break;

            /*cout << "Enter a value:";
            newElement = ReadIntegerInput();
            tree.AddElement(newElement);
            system("cls");
            break;*/
        case 2:

            cout << "Enter a value: ";
            cin >> deletedElement;
            {
                auto start = high_resolution_clock::now();
                tree.DeleteElement(deletedElement);
                auto stop = high_resolution_clock::now();
                auto durationMicro = duration_cast<microseconds>(stop - start);
                auto durationNano = duration_cast<nanoseconds>(stop - start);

                system("cls");

                cout << "Time taken to delete " << deletedElement << ": "
                    << durationMicro.count() << " microseconds ("
                    << durationNano.count() << " nanoseconds)" << endl;

                cout << "Rotation count is " << tree.GetRotationCount() << endl << endl;

            }

            break;



            /*cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElement(deletedElement);
            system("cls");
            break;*/
        case 3:
            cout << "Enter a value: ";
            cin >> seacrhingElement;

            {
                auto start = high_resolution_clock::now();
                foundedElement = tree.FindValue(seacrhingElement);
                auto stop = high_resolution_clock::now();
                auto durationMicro = duration_cast<microseconds>(stop - start);
                auto durationNano = duration_cast<nanoseconds>(stop - start);

                system("cls");


                cout << "Time taken to find " << seacrhingElement << ": "
                    << durationMicro.count() << " microseconds ("
                    << durationNano.count() << " nanoseconds)" << endl;

                cout << "Rotation count is " << tree.GetRotationCount() << endl << endl;

            }

            break;


            /*cout << "Enter a value:";
            cin >> seacrhingElement;
            foundedElement = tree.FindValue(seacrhingElement);
            system("cls");
            break;*/
        case 4:
            tree.ClearTree();
            system("cls");
            break;
        case 5:
            AddMultipleElements(tree);
            /* system("cls");*/
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}