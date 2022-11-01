#include <iostream>
using namespace std;
// macros...
#define updateHeight(root) root->height = 1 + max(getHeight(root->left), getHeight(root->right))
#define deb(x) cout << #x << ' ' << x << '\n'
#define read(x) int x; cin >> x

class node {
public:
    int val, height;
    node *left, *right;

    node(int val, int height = 1) {
        this->val = val;
        this->height = height;
        this->left = this->right = nullptr;
    }
    ~node() {
        delete this->left;  // It's okay to call delete nullptr
        delete this->right;
    }
};
class avl_tree {
// member data
    node* root;
// member function
    int getHeight(node* curr) {
        if (!curr)
            return 0;
        else return curr->height;
    }
    int balanceFactor(node* curr) {
        if (!curr)
            return 0;
        return getHeight(curr->left) - getHeight(curr->right);
    }
    // rotations...
    node* rrotation(node* curr) {
        node* pivot = curr->left;
        curr->left = pivot->right;
        pivot->right = curr;
        // update heights...
        updateHeight(curr);
        updateHeight(pivot);
        return pivot;
    }
    node* lrotation(node* curr) {
        node* pivot = curr->right;
        curr->right = pivot->left;
        pivot->left = curr;
        // update heights...
        updateHeight(curr);
        updateHeight(pivot);
        return pivot;
    }
public:
    avl_tree() {
        this->root = nullptr;
    }
    ~avl_tree() {
        delete this->root;
    }
    // methods on AVL Tree...
    node* insertAVL(int val, node* curr) {
        if(!curr)
            return new node(val);
        if (val > curr->val)
            curr->right = insertAVL(val, curr->right);
        else if (val < curr->val)
            curr->left = insertAVL(val, curr->left);
        else
            return curr;

        updateHeight(curr);
        // balance factor checking...
        int bfact = balanceFactor(curr);
        if (bfact > 1) {  // Tree is left skewed...
            if (balanceFactor(curr->left) == -1)
                curr->left = lrotation(curr->left);
            curr = rrotation(curr);
        }
        else if (bfact < -1) {   // Tree is right skewed...
            if (balanceFactor(curr->right) == 1)
                curr->right = rrotation(curr->right);
            curr = lrotation(curr);
        }
        return curr;
    }
    void insertAVL(int val) {
        this->root = insertAVL(val, this->root);
    }
    node* deleteAVL(int val, node* curr) {
        if (!curr)
            return nullptr;
        // find the node...
        if (val > curr->val)
            curr->right = deleteAVL(val, curr->right);
        else if (val < curr->val)
            curr->left = deleteAVL(val, curr->left);
        else {
            if (curr->left == curr->right)  // is a leaf node...
                return nullptr;
            else if (!curr->left || !curr->right)
                return curr->left ? curr->left : curr->right;
            else {
                node* predecessor = curr->left;
                while(predecessor->right)
                    predecessor = predecessor->right;

                curr->val = predecessor->val;
                curr->left = deleteAVL(predecessor->val, curr->left);
            }
        }
        updateHeight(curr);
        // now, check of balance factor...
        int bfact = balanceFactor(curr);
        if (bfact > 1) {  // Tree is left skewed...
            if (balanceFactor(curr->left) == -1)
                curr->left = lrotation(curr->left);
            curr = rrotation(curr);
        }
        else if (bfact < -1) {   // Tree is right skewed...
            if (balanceFactor(curr->right) == 1)
                curr->right = rrotation(curr->right);
            curr = lrotation(curr);
        }
        return curr;
    }
    void deleteAVL(int val) {
        this->root = deleteAVL(val, this->root);
    }
    void printTree(node* curr) {
        if (!curr)
            return ;
        cout << curr->val << ':';
        if (curr->left)
            cout << 'L' << curr->left->val << ' ';
        if (curr->right)
            cout << 'R' << curr->right->val;

        cout << endl;
        printTree(curr->left);
        printTree(curr->right);
    }
    void printTree() {
        cout << '\n';
        printTree(this->root);
        cout << '\n';
    }
};
/* <----------------------------- main() ---------------------------------->
test cases
10
0 1 1 3 4 5 10 23 40 50
2
0 1

5
984 286 587 377 286
2
286 587

7
4 2 6 1 3 5 7
4
4 1 3 6

11
54 44 86 43 46 78 88 50 61 83 89
8
46 86 88 61 89 78 54 83
*/
int main() {

    avl_tree t1;

    read(n);
    while (n--) {
        read(x);
        t1.insertAVL(x);
    }
    t1.printTree();

    read(n2);
    while (n2--) {
        read(x2);
        t1.deleteAVL(x2);
    }
    t1.printTree();

    return 0;
}
