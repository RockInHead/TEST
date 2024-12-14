#include <iostream>
#include "BinaryTreeConsole.h"
#include"Validator.h"
#include"BinaryTree.h"
#include"Colors.h"
#include"Node.h"

using namespace std;
// Функция для обхода дерева на заданном уровне
void dump4(Node const* node, bool high, std::vector<std::string> const& lpref , std::vector<std::string> const& cpref , std::vector<std::string> const& rpref , bool root , bool left , std::shared_ptr<std::vector<std::vector<std::string>>> lines ) {
    if (!node) return;
    typedef std::vector<std::string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = std::make_shared<std::vector<VS>>();
    if (node->Left)
        dump4(node->Left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })), VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), false, true, lines);
    auto sval = std::to_string(node->Data);
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i)
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { std::string(1, sval[i]) }));
    if (node->Right)
        dump4(node->Right, high, VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);
    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            std::string line;
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
            std::cout << out[i] << std::endl;
    }
}



void dump3(Node* root, int space = 0) {
    if (!root)
        return;
    enum { COUNT = 2 };
    space += COUNT;
    dump3(root->Right, space);
    for (int i = COUNT; i < space; ++i)
        cout << "  ";
    cout << root->Data << endl;
    dump3(root->Left, space);
}



void PrintLevel(Node* root, int level,BinaryTree& tree) {
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        
        /*for (int i = 0; i < tree.GetSize(); i++) {
            cout << " ";
        }*/
        std::cout << root->Data << " "; // Выводим данные узла
    }
    else {
        PrintLevel(root->Left, level - 1, tree); // Рекурсивно обходим левое поддерево
        PrintLevel(root->Right, level - 1,tree); // Рекурсивно обходим правое поддерево
    }
}


//Показать текущую хэш-таблицу в столбик.
void ShowBinaryTree(BinaryTree& tree) {
    Node* root = tree.GetBinaryTree();
    int h = tree.GetHeight();
    for (int i = 1; i <= h; i++) {

        PrintLevel(root, i,tree); // Обрабатываем каждый уровень
        cout << " " << endl;
    }
}
//Показать меню для стэка.
void MenuBinaryTree(BinaryTree& tree)
{

    cout << LIGHT_BLUE << "Binary Tree:" << RESET << endl;
    /*ShowBinaryTree(tree);*/
    /*dump3(tree.GetBinaryTree());*/
    dump4(tree.GetBinaryTree(), true);
    cout << "Size:" << LIGHT_YELLOW << tree.GetSize() << RESET << endl;
    cout << "Height:" << RED << tree.GetHeight() << RESET << endl << endl;
    cout << "[1]" << " - Add new elemnt" << endl;
    cout << "[2]" << " - Remove element by value" << endl;
    cout << "[3]" << " - Searching Element by Key" << endl;
    cout << RED << "[0]" << RESET << " - Exit the Stack" << endl;
}

//Вызвать консольное меню для стэка.
void BinaryTreeConsole(BinaryTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    string key;
    int chosenElement;
    while (stackState)
    {
        MenuBinaryTree(tree);
        int commandNumber;
        commandNumber = ValidInputMenu(0, 3);
        switch (commandNumber)
        {
        case 1:

            cout << "Enter a value:";
            newElement = ValidCin();
            tree.AddElement(newElement);
            
            system("cls");
            break;
        case 2:
            /*cout << "Enter a key:";
            cin >> key;
            hash.DeleteElement(key);*/
            system("cls");
            break;
        case 3:
            /*cout << "Enter a key:";
            cin >> key;
            system("cls");
            chosenElement = hash.SearchingValue(key);
            if (chosenElement != -1) {
                cout << "Element with key " << key << " is " << chosenElement << endl << endl;
            }
            else {
                cout << "No such element in Dictionary" << endl << endl;
            }*/
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}