#include <iostream>
#include "CartesianTreeConsole.h"
#include"Validator.h"
#include"CartesianTree.h"
#include"Colors.h"


using namespace std;

//Выводит дерево в консоль.
void Show1(CartesianNode const* node, bool high, vector< string> const& lpref, vector< string> const& cpref, vector< string> const& rpref, bool root, bool left, shared_ptr< vector< vector< string>>> lines) {
    if (!node) return;
    typedef  vector< string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = make_shared< vector<VS>>();
    if (node->Left)
        Show1(node->Left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })), VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), false, true, lines);

    auto sval = "[" + to_string(node->Key) +";"+ to_string(node->Priority) + "]";
    string coloredSval = CYAN + sval + RESET;
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i) {
        string colored = CYAN + string(1, sval[i]) + RESET;
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }
    if (node->Right)
        Show1(node->Right, high, VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);
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

//Выводит дерево в консоль.
void Show2(CartesianNode* root, int space = 0) {
    if (!root)
        return;
    enum { COUNT = 2 };
    space += COUNT;
    Show2(root->Right, space);
    for (int i = COUNT; i < space; ++i)
        cout << "  ";
    cout<<"(" << root->Key <<";"<<root->Priority<<")" << endl;
    Show2(root->Left, space);
}


//Показать текущее дерево.
void ShowCartesianTree(CartesianTree& tree) {
    Show1(tree.GetRoot(), true);
}
//Показать меню для дерева.
void MenuCartesianTree(CartesianTree& tree)
{
    cout << LIGHT_BLUE << "Cartesian Tree:" << RESET << endl;
    ShowCartesianTree(tree);
    cout << endl;

    cout << "Size:" << LIGHT_YELLOW << tree.GetSize() << RESET << endl;
    /*cout << "Height:" << RED << tree.GetHeight() << RESET << endl;
    cout << "Min Element:" << GREEN << tree.FindMin() << RESET;
    cout << "  Max Element:" << RED << tree.FindMax() << RESET << endl << endl;*/

    cout << "[1]" << " - Add new elemnt" << endl;
    cout << "[2]" << " - Remove element by value" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}

//Вызвать консольное меню для дерева.
void CartesianTreeConsole(CartesianTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int chosenElement;
    while (stackState)
    {
        MenuCartesianTree(tree);
        int commandNumber;
        commandNumber = ValidInputMenu(0, 3);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value:";
            newElement = ValidCin();
            tree.AddElementNotOptimazed(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElementNotOptimazed(deletedElement);
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}