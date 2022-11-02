/*
    note: 
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define read(x) int x; cin >> x
#define deb1(x) cout <<#x <<' ' <<x <<'\n'
#define deb2(x, y) cout <<#x <<' ' <<x <<',' <<#y <<' ' <<y <<'\n'
#define mod 1000000007

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
class listNode {
public:
    string key;
    T val;
    listNode *nxt;

    listNode(string key, T val, listNode<T> *nxt = nullptr) {
        this->key = key;
        this->val = val;
        this->nxt = nxt;
    }
    ~listNode() {
        delete this->nxt;
    }
};
template <typename T>
class hashmap {

    listNode<T> **bucket;
    int key_count, totalSize;

    // hashing function...
    int bucketIdx(string key) {
        int hashcode = 0, pow = 1;
        for (char x: key) {
            hashcode += x * pow;
            pow *= pow;
            hashcode %= totalSize;
            pow %= totalSize;
        }
        return hashcode;
    }

public:
    hashmap(int n = 5) {
        bucket = new listNode<T>*[n];
        totalSize = n;
        key_count = 0;

        for (int i = 0; i < totalSize; ++i)
            bucket[i] = nullptr;
    }
    ~hashmap() {
        for (int i = 0; i < totalSize; ++i)
        delete bucket[i];
        delete [] bucket;
    }

    void push(string key, T val = 0) {

        int idx = bucketIdx(key);
        listNode<T> *loc = bucket[idx];

        // search for the key if it's already present.
        while (loc) {
            if (loc->key == key)
                break;
            loc = loc->nxt;
        }
        if (!loc) {
            bucket[idx] = new listNode<T>(key, val, bucket[idx]);
            ++key_count;
        }
        else loc->val = val;
    }
    void pop(string key) {

        int idx = bucketIdx(key);

        listNode<T>
        *loc = bucket[idx],
        *prv = nullptr;

        while (loc) {
            if (loc->key == key)
                break;
            prv = loc;
            loc = loc->nxt;
        }
        if (!loc) return;
        // prv -> nullptr then, key is present at the head of the list.
        if (prv)
            prv->nxt = loc->nxt;
        else
            bucket[idx] = loc->nxt;

        loc->nxt = nullptr;
        key_count += -1;
        return delete loc;
    }
    bool contains(string key) { // return true only if the key is present in the map.

        int idx = bucketIdx(key);
        listNode<T> *loc = bucket[idx];

        // search for the key...
        while (loc) {
            if (loc->key == key)
                return true;
            loc = loc->nxt;
        }
        return false;
    }
    T key_val(string key) { // return value corresponding to key

        int idx = bucketIdx(key);
        listNode<T> *loc = bucket[idx];

        // search for the key...
        while (loc) {
            if (loc->key == key)
                return loc->val;
            loc = loc->nxt;
        }
        return 0;
    }
    void show_map() { // display whole map in key:val format.
        cout << "map status:\n";
        for (int i = 0; i < totalSize; ++i) {
            listNode<T> *loc = bucket[i];
            while (loc)
                cout << loc->key << ':' << loc->val << '\n',
                loc = loc->nxt;
        }
    }
    void clean() { // cleaning...
        for (int i = 0; i < totalSize; ++i)
        delete bucket[i];
        delete [] bucket;

        // reset data members.
        totalSize = 5;
        key_count = 0;
        bucket = new listNode<T>*[totalSize];
        for (int i = 0; i < totalSize; ++i)
            bucket[i] = nullptr;
    }
    int count_key() {
        return key_count;
    }
    int show_hash(string key) {
        return bucketIdx(key);
    }
};


int main() {
    fastio();
    int T(1);

    cin >> T;

    hashmap<int> m;

    while (T--) {
        string input;
        cin >> input;

        for (char c: input) {
            string x(1, c);
            if (m.contains(x))
                m.push(x, m.key_val(x)+1);
            else
                m.push(x, 1);
        }
        m.show_map();
        m.clean();
    }
    return 0;
}