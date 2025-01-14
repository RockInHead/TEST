#include"PrintTreeConsole.h"
using namespace std;

//Выводит AVL дерево в консоль.
void ShowAVLTree(
    AVLNode const* node,
    bool high,
    int foundedElement,
    vector<string> const& lpref,
    vector<string> const& cpref,
    vector<string> const& rpref,
    bool root,
    bool left,
    shared_ptr<vector<vector<string>>> lines) 
{
    if (!node)
    {
        return;
    }

    typedef vector<string> VS;
    auto VSCat = [](VS const& a, VS const& b)
                   { auto r = a;
                    r.insert(r.end(), b.begin(), b.end());
                    return r; };

    if (root)
    {
        lines = make_shared<vector<VS>>();
    }

    if (node->Left) 
    {
        ShowAVLTree(node->Left,
                    high,
                    foundedElement,
                    VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })),
                    VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })),
                    VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
                    false, true, lines);
    }

    auto sval = "[" + to_string(node->Data) + "]";
    string coloredSval;

    // Если элемент равен foundedElement, окрашиваем скобки в зеленый
    if (node->Data == foundedElement) 
    {
        coloredSval = DARK_GREEN + "[" + to_string(node->Data) + "]" + RESET;
    }

    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);

    for (size_t i = 0; i < sval.size(); ++i) 
    {
        string colored;
        // Если элемент равен foundedElement, окрашиваем скобки независимо от их позиции
        if (node->Data == foundedElement && (i == 0 || i == sval.size() - 1)) 
        {
            // Окрашиваем символы скобок
            colored = DARK_GREEN + string(1, sval[i]) + RESET;
        }
        else 
        {
            // Окрашиваем остальные символы
            colored = LIGHT_YELLOW + string(1, sval[i]) + RESET;
        }

        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }

    if (node->Right) 
    {
        ShowAVLTree(node->Right, high,
                    foundedElement,
                    VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
                    VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })),
                    VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })),
                    false, false, lines);
    }

    if (root) 
    {
        VS out;
        for (size_t l = 0;; ++l) 
        {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
            {
                if (l < (*lines).at(i).size())
                {
                    line += lines->at(i)[l];
                    last = false;
                }
                else line += " ";
            }

            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
        {
            cout << out[i] << endl;
        }
    }
}

//Выводит AVL дерево в консоль.
void ShowRBTree(RBNode const* node,
    bool high,
    int foundedElement,
    vector<string> const& lpref,
    vector<string> const& cpref,
    vector<string> const& rpref,
    bool root,
    bool left,
    shared_ptr<vector<vector<string>>> lines)
{
    if (!node)
    {
        return;
    }

    typedef vector<string> VS;
    auto VSCat = [](VS const& a, VS const& b)
                    { auto r = a;
                    r.insert(r.end(), b.begin(), b.end());
                    return r; };

    if (root)
    {
        lines = make_shared<vector<VS>>();
    }

    string color;
    if (node->Color == Colors::Red)
    {
        color = RED;
    }
    else
    {
        color = DARK_BLUE;
    }

    if (node->Left) 
    {
        ShowRBTree(node->Left,
                    high,
                    foundedElement,
                    VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })),
                    VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })),
                    VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
                    false, true, lines);
    }

    auto sval = "[" + to_string(node->Data) + "]";
    string coloredSval = (node->Data == foundedElement ? GREEN : color) + to_string(node->Data) + RESET;
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);

    for (size_t i = 0; i < sval.size(); ++i)
    {
        string colored = (node->Data == foundedElement
                          && (i == 0 || i == sval.size() - 1)) ? GREEN
                          + string(1, sval[i]) + RESET : color + string(1, sval[i]) + RESET;
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }
    if (node->Right)
    {
        ShowRBTree(node->Right,
                    high,
                    foundedElement,
                    VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
                    VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })),
                    VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })),
                    false, false, lines);
    }

    if (root)
    {
        VS out;
        for (size_t l = 0;; ++l)
        {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size())
                {
                    line += lines->at(i)[l];
                    last = false;
                }
                else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
        {
            cout << out[i] << endl;
        }
    }
}