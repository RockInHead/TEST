#include"PrintTreeConsole.h"

//Выводит бинарное дерево в консоль.
void ShowBinaryTree(
    Node const* node, bool high, 
    vector< string> const& lpref, 
    vector< string> const& cpref, 
    vector< string> const& rpref, 
    bool root, 
    bool left, 
    shared_ptr<vector<vector<string>>> lines) {

    if (!node) return;
    typedef  vector< string> VS;
    auto VSCat = [](VS const& a, VS const& b) {
        auto r = a; 
        r.insert(r.end(), 
        b.begin(), 
        b.end());
        return r; };

    if (root) lines = make_shared< vector<VS>>();

    if (node->Left) {
        ShowBinaryTree(
            node->Left, 
            high, 
            VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })),
            VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })),
            VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
            false, true, lines);
    }

    auto sval = "[" + to_string(node->Data) + "]";
    string coloredSval = CYAN + sval + RESET;
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);

    for (size_t i = 0; i < sval.size(); ++i) {
        string colored = CYAN + string(1, sval[i]) + RESET;
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }

    if (node->Right) {
        ShowBinaryTree(
            node->Right, 
            high, 
            VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
            VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })),
            VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })),
            false, false, lines);
    }

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
        for (size_t i = 0; i < out.size(); ++i) {
            cout << out[i] << endl;
        }
    }
}


//Выводит декартово дерево в консоль.
void ShowCartesianTree(
    CartesianNode const* node,
    bool high, vector< string> const& lpref,
    vector< string> const& cpref,
    vector< string> const& rpref,
    bool root, bool left,
    shared_ptr< vector< vector< string>>> lines) {

    if (!node) return;

    typedef  vector< string> VS;
    auto VSCat = [](VS const& a, VS const& b) { 
        auto r = a;
        r.insert(r.end(),b.begin(), b.end());
        return r; };

    if (root) lines = make_shared< vector<VS>>();

    if (node->Left) {
        ShowCartesianTree(
            node->Left, 
            high,
            VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })),
            VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })),
            VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
            false, true, lines);
    }

    auto sval = "[" + to_string(node->Key) + ";" + to_string(node->Priority) + "]";
    string coloredSval = sval;
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);

    for (size_t i = 0; i < sval.size(); ++i) {
        string colored = CYAN + string(1, sval[i]) + RESET;
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }

    if (node->Right) {
        ShowCartesianTree(
            node->Right, high,
            VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })),
            VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })),
            VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })),
            false, false, lines);
    }

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
        {
            cout << out[i] << endl;
        }
    }
}