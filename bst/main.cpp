#include <iostream>
using namespace std;
// macros...
#define deb(x) cout << #x << ' ' << x << endl
#define read(x) int x; cin >> x

template <typename T>
class treeNode {
public:
    int val;
    treeNode<T>* left;
    treeNode<T>* right;

    treeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
    ~treeNode() {
        delete left;
        delete right;
    }
};
template <typename T>
class bst {
    treeNode<T>* root;
public:
    bst() {
        this->root = nullptr;
    }
    ~bst() {
        delete this->root;
    }

    void printBST(treeNode<T>* node) {
        if (node) {
            cout << node->val << ':';
            if (node->left)
                cout << 'L' << node->left->val << ' ';
            if (node->right)
                cout << 'R' << node->right->val;

            cout << endl;
            printBST(node->left);
            printBST(node->right);
        }
    }
    void printBST() {
        return printBST(this->root);
    }
    treeNode<T>* insertBST(T val, treeNode<T>* node) {
        if (!node)
            return new treeNode<T>(val);

        if (val < node->val)
            node->left = insertBST(val, node->left);
        else
            node->right = insertBST(val, node->right);

        return node;
    }
    treeNode<T>* insertBST(T val) {
        root = insertBST(val, this->root);
    }
    treeNode<T>* removeBST(T val, treeNode<T>* node) {
        if (!node)
            return node;
        if (val > node->val)
            node->right = removeBST(val, node->right);
        else if (val < node->val)
            node->left = removeBST(val, node->left);
        else {
            if (node->left == node->right) // is leaf node...
                return nullptr;
            else if (!node->left or !node->right)   // has only one child...
                return node->left ? node->left : node->right;
            else {
                treeNode<T> *predecessor = node->left, *parent = nullptr;
                while (predecessor->right)
                    parent = predecessor, predecessor = predecessor->right;

                node->val = predecessor->val;
                // now delete predecessor...
                parent ? parent->right = predecessor->left : node->left = predecessor->left;
            }
        }
        return node;
    }
    treeNode<T>* removeBST(int val) {
        root = removeBST(val, this->root);
    }
};
/*

<-------------------------------------------------- main() --------------------------------------------------------->
test case 1:
14
10 5 15 3 7 13 20 1 4 12 14 16 21 2

test case 2:
6
50 30 70 40 60 80

*/
int main() {

    bst<int> t1;

    read(n);
    while (n--) {
        read(x);
        t1.insertBST(x);
    }
    t1.printBST();
    
    // for test case 1...
    cout << '\n';
    t1.removeBST(20);
    t1.printBST();
    cout << '\n';
    t1.removeBST(15);
    t1.printBST();

    return 0;
}
