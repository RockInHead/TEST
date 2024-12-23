#include <iostream>
#include "AVLTreeConsole.h"
#include"Validator.h"
#include"ConsoleColors.h"
using namespace std;

//Вывод дерева в консоль.
void ShowTree(
    AVLNode const* node,
    bool high, int foundedElement, vector<string> const& lpref, vector<string> const& cpref, vector<string> const& rpref, bool root, bool left, shared_ptr<vector<vector<string>>> lines) {
    if (!node) return;
    typedef vector<string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = make_shared<vector<VS>>();

    if (node->Left)
        ShowTree(node->Left, high,foundedElement, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })),
            VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })),
            VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
            false, true, lines);

    auto sval = "[" + to_string(node->Data) + "]";
    string coloredSval;

    // Если элемент равен foundedElement, окрашиваем скобки в зеленый
    if (node->Data == foundedElement) {
        coloredSval = DARK_GREEN + "[" + to_string(node->Data) + "]" + RESET;
    }

    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);

    for (size_t i = 0; i < sval.size(); ++i) {
        string colored;
        // Если элемент равен foundedElement, окрашиваем скобки независимо от их позиции
        if (node->Data == foundedElement && (i == 0 || i == sval.size() - 1)) {
            // Окрашиваем символы скобок
            colored = DARK_GREEN + string(1, sval[i]) + RESET; 
        }
        else {
            // Окрашиваем остальные символы
            colored = LIGHT_YELLOW + string(1, sval[i]) + RESET; 
        }
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }

    if (node->Right)
        ShowTree(node->Right, high,foundedElement, VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
            VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })),
            VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })),
            false, false, lines);

    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                }
                else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            cout << out[i] << endl;
    }
}

//Показать текущее дерево.
void ShowAVLTree(AVLTree& tree, int foundedElement) {
    ShowTree(tree.GetRoot(), true, foundedElement);
}

//Показать меню для дерева.
void MenuAVLTree(AVLTree& tree, int foundedElement)
{
    cout << MAGENTA << "AVL Tree:" << RESET << endl;
    ShowAVLTree(tree, foundedElement);
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
        commandNumber = ValidateCommandInput(0, 4);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value:";
            newElement = ReadIntegerInput();
            tree.AddElement(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElement(deletedElement);
            system("cls");
            break;
        case 3:
            cout << "Enter a value:";
            cin >> seacrhingElement;
            foundedElement = tree.FindValue(seacrhingElement);
            system("cls");
            break;
        case 4:
            tree.ClearTree();
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}