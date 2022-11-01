#include <iostream>
#include <vector>
#define deb(x) cout << #x << ' ' << x << '\n';
using namespace std;

class pqueue {
    vector<int> heap;
public:
    // constructor and destructor...
    pqueue() {
        heap = vector<int>(0);
    }
    ~pqueue() {
        heap.clear();
    }
    int size() {
        return heap.size();
    }
    bool empty() {
        return heap.empty();
    }
    int max() {
        return heap.empty() ? INT_MIN : heap[0];
    }
    // operation functions
    void push(int val) {
        // push element...
        heap.emplace_back(val);
        // now, preform reheapification upwards...
        int curr = heap.size() - 1, prnt = (curr - 1) / 2;
        while (curr > 0 && heap[curr] > heap[prnt]) {
            swap(heap[curr], heap[prnt]);
            curr = prnt;
            prnt = (curr - 1) / 2;
        }
    }
    void reheapification_downwards(int curr_node = 0) {

        while (true) {
            int max_node = curr_node,
            l = curr_node * 2 + 1,
            r = curr_node * 2 + 2;
            if (l < heap.size() && heap[max_node] < heap[l])
                max_node = l;
            if (r < heap.size() && heap[max_node] < heap[r])
                max_node = r;
            if (max_node == curr_node)
                break;
            swap(heap[max_node], heap[curr_node]);
            curr_node = max_node;
        }
    }
    int pop() {
        if (this->empty()) return INT_MIN;
        // remove top most node...
        int ans = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        // now, preform reheapification downward...
        reheapification_downwards();
        return ans;
    }
};
int main() {

    pqueue pq = pqueue();
    // input...
    int n, val;
    cin >> n;

    while (n--)
        cin >> val,
        pq.push(val);

    cout << "size: " << pq.size() << '\n';

    while (pq.empty() == false)
        cout << pq.max() << ' ',
        pq.pop();

    return 0;
}
