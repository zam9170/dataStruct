#include <iostream>
#include <queue>
using namespace std;
// macros...
#define read(x) int x; cin >> x
#define deb(x) cout << #x << ' ' << x << endl

template <typename T>
class treeNode {
public:
    T val;
    treeNode<T>* left;
    treeNode<T>* right;
    // constructor...
    treeNode(T val) {
        this->val = val;
        left = right = nullptr;
    }
    ~treeNode() {
        delete this->left;
        delete this->right;
    }
};
treeNode<int>* readTree() {
    read(val);
    if (val == -1)
        return nullptr;
    // now use queue...
    queue<treeNode<int>*> q;
    treeNode<int>* root = new treeNode<int>(val);
    q.push(root);

    while (q.empty() == false) {
        treeNode<int>* curr_node = q.front();
        // input of children...
        read(leftVal);
        if (leftVal != -1){
            curr_node->left = new treeNode<int>(leftVal);
            q.push(curr_node->left);
        }
        read(rightVal);
        if (rightVal != -1) {
            curr_node->right = new treeNode<int>(rightVal);
            q.push(curr_node->right);
        }
        q.pop();
    }
    return root;
}
void printTree(treeNode<int>* root) {
    if (!root) return ;

    queue<treeNode<int>*> q;
    q.push(root);

    while (q.empty() == false) {
        treeNode<int>* curr_node = q.front();
        // print info of curr_node...
        cout << curr_node->val << ": ";
        if (curr_node->left) {
            cout << 'L' << curr_node->left->val << ' ';
            q.push(curr_node->left);
        }
        if (curr_node->right) {
            cout << 'L' << curr_node->right->val;
            q.push(curr_node->right);
        }
        cout << endl;

        q.pop();
    }
}
int main() {

    treeNode<int>* root = readTree();

    printTree(root);

    delete root;

    return 0;
}
